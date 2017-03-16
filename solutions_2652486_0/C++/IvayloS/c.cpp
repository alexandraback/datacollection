#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;

///////////////////////////////Randomc
#ifndef RANDOMC_H
#define RANDOMC_H


// Define 32 bit signed and unsigned integers.
// Change these definitions, if necessary, to match a particular platform
#if defined(_WIN16) || defined(__MSDOS__) || defined(_MSDOS) 
// 16 bit systems use long int for 32 bit integer
typedef long int           int32;   // 32 bit signed integer
typedef unsigned long int  uint32;  // 32 bit unsigned integer
#else
// Most other systems use int for 32 bit integer
typedef int                int32;   // 32 bit signed integer
typedef unsigned int       uint32;  // 32 bit unsigned integer
#endif

// Define 64 bit signed and unsigned integers, if possible
#if (defined(__WINDOWS__) || defined(_WIN32)) && (defined(_MSC_VER) || defined(__INTEL_COMPILER))
// Microsoft and other compilers under Windows use __int64
typedef __int64            int64;   // 64 bit signed integer
typedef unsigned __int64   uint64;  // 64 bit unsigned integer
#define INT64_DEFINED               // Remember that int64 is defined
#elif defined(__unix__) && (defined(_M_IX86) || defined(_M_X64))
// Gnu and other compilers under Linux etc. use long long
typedef long long          int64;   // 64 bit signed integer
typedef unsigned long long uint64;  // 64 bit unsigned integer
#define INT64_DEFINED               // Remember that int64 is defined
#else
// 64 bit integers not defined
// You may include definitions for other platforms here
#endif

void EndOfProgram(void);               // System-specific exit code (userintf.cpp)

void FatalError(char * ErrorText);     // System-specific error reporting (userintf.cpp)

class CRandomMersenne {                // Encapsulate random number generator
#if 0
  // Define constants for type MT11213A:
#define MERS_N   351
#define MERS_M   175
#define MERS_R   19
#define MERS_U   11
#define MERS_S   7
#define MERS_T   15
#define MERS_L   17
#define MERS_A   0xE4BD75F5
#define MERS_B   0x655E5280
#define MERS_C   0xFFD58000
#else    
  // or constants for type MT19937:
#define MERS_N   624
#define MERS_M   397
#define MERS_R   31
#define MERS_U   11
#define MERS_S   7
#define MERS_T   15
#define MERS_L   18
#define MERS_A   0x9908B0DF
#define MERS_B   0x9D2C5680
#define MERS_C   0xEFC60000
#endif
public:
  CRandomMersenne(uint32 seed) {      // Constructor
    RandomInit(seed); LastInterval = 0;}
  void RandomInit(uint32 seed);       // Re-seed
  void RandomInitByArray(uint32 seeds[], int length); // Seed by more than 32 bits
  int IRandom (int min, int max);     // Output random integer
  int IRandomX(int min, int max);     // Output random integer, exact
  double Random();                    // Output random float
  uint32 BRandom();                   // Output random bits
private:
  void Init0(uint32 seed);            // Basic initialization procedure
  uint32 mt[MERS_N];                  // State vector
  int mti;                            // Index into mt
  uint32 LastInterval;                // Last interval length for IRandomX
  uint32 RLimit;                      // Rejection limit used by IRandomX
  enum TArch {LITTLE_ENDIAN1, BIG_ENDIAN1, NONIEEE}; // Definition of architecture
  TArch Architecture;                 // Conversion to float depends on architecture
};    


class CRandomMother {             // Encapsulate random number generator
public:
  void RandomInit(uint32 seed);       // Initialization
  int IRandom(int min, int max);      // Get integer random number in desired interval
  double Random();                    // Get floating point random number
  uint32 BRandom();                   // Output random bits
  CRandomMother(uint32 seed) {   // Constructor
    RandomInit(seed);}
protected:
  uint32 x[5];                        // History buffer
};

#endif

void CRandomMersenne::Init0(uint32 seed) {
  // Detect computer architecture
  union {double f; uint32 i[2];} convert;
  convert.f = 1.0;
  if (convert.i[1] == 0x3FF00000) Architecture = LITTLE_ENDIAN1;
  else if (convert.i[0] == 0x3FF00000) Architecture = BIG_ENDIAN1;
  else Architecture = NONIEEE;

  // Seed generator
  mt[0]= seed;
  for (mti=1; mti < MERS_N; mti++) {
    mt[mti] = (1812433253UL * (mt[mti-1] ^ (mt[mti-1] >> 30)) + mti);
  }
}

void CRandomMersenne::RandomInit(uint32 seed) {
  // Initialize and seed
  Init0(seed);

  // Randomize some more
  for (int i = 0; i < 37; i++) BRandom();
}


void CRandomMersenne::RandomInitByArray(uint32 seeds[], int length) {
  // Seed by more than 32 bits
  int i, j, k;

  // Initialize
  Init0(19650218);

  if (length <= 0) return;

  // Randomize mt[] using whole seeds[] array
  i = 1;  j = 0;
  k = (MERS_N > length ? MERS_N : length);
  for (; k; k--) {
    mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1664525UL)) + seeds[j] + j;
    i++; j++;
    if (i >= MERS_N) {mt[0] = mt[MERS_N-1]; i=1;}
    if (j >= length) j=0;}
  for (k = MERS_N-1; k; k--) {
    mt[i] = (mt[i] ^ ((mt[i-1] ^ (mt[i-1] >> 30)) * 1566083941UL)) - i;
    if (++i >= MERS_N) {mt[0] = mt[MERS_N-1]; i=1;}}
  mt[0] = 0x80000000UL;  // MSB is 1; assuring non-zero initial array

  // Randomize some more
  mti = 0;
  for (int i = 0; i <= MERS_N; i++) BRandom();
}


uint32 CRandomMersenne::BRandom() {
  // Generate 32 random bits
  uint32 y;

  if (mti >= MERS_N) {
    // Generate MERS_N words at one time
    const uint32 LOWER_MASK = (1LU << MERS_R) - 1;       // Lower MERS_R bits
    const uint32 UPPER_MASK = 0xFFFFFFFF << MERS_R;      // Upper (32 - MERS_R) bits
    static const uint32 mag01[2] = {0, MERS_A};

    int kk;
    for (kk=0; kk < MERS_N-MERS_M; kk++) {    
      y = (mt[kk] & UPPER_MASK) | (mt[kk+1] & LOWER_MASK);
      mt[kk] = mt[kk+MERS_M] ^ (y >> 1) ^ mag01[y & 1];}

    for (; kk < MERS_N-1; kk++) {    
      y = (mt[kk] & UPPER_MASK) | (mt[kk+1] & LOWER_MASK);
      mt[kk] = mt[kk+(MERS_M-MERS_N)] ^ (y >> 1) ^ mag01[y & 1];}      

    y = (mt[MERS_N-1] & UPPER_MASK) | (mt[0] & LOWER_MASK);
    mt[MERS_N-1] = mt[MERS_M-1] ^ (y >> 1) ^ mag01[y & 1];
    mti = 0;
  }

  y = mt[mti++];

#if 1
  // Tempering (May be omitted):
  y ^=  y >> MERS_U;
  y ^= (y << MERS_S) & MERS_B;
  y ^= (y << MERS_T) & MERS_C;
  y ^=  y >> MERS_L;
#endif

  return y;
}


double CRandomMersenne::Random() {
  // Output random float number in the interval 0 <= x < 1
  union {double f; uint32 i[2];} convert;
  uint32 r = BRandom();               // Get 32 random bits
  // The fastest way to convert random bits to floating point is as follows:
  // Set the binary exponent of a floating point number to 1+bias and set
  // the mantissa to random bits. This will give a random number in the 
  // interval [1,2). Then subtract 1.0 to get a random number in the interval
  // [0,1). This procedure requires that we know how floating point numbers
  // are stored. The storing method is tested in function RandomInit and saved 
  // in the variable Architecture.

  // This shortcut allows the compiler to optimize away the following switch
  // statement for the most common architectures:
#if defined(_M_IX86) || defined(_M_X64) || defined(__LITTLE_ENDIAN__)
  Architecture = LITTLE_ENDIAN1;
#elif defined(__BIG_ENDIAN__)
  Architecture = BIG_ENDIAN1;
#endif

  switch (Architecture) {
   case LITTLE_ENDIAN1:
     convert.i[0] =  r << 20;
     convert.i[1] = (r >> 12) | 0x3FF00000;
     return convert.f - 1.0;
   case BIG_ENDIAN1:
     convert.i[1] =  r << 20;
     convert.i[0] = (r >> 12) | 0x3FF00000;
     return convert.f - 1.0;
   case NONIEEE: default: ;
  } 
  // This somewhat slower method works for all architectures, including 
  // non-IEEE floating point representation:
  return (double)r * (1./((double)(uint32)(-1L)+1.));
}


int CRandomMersenne::IRandom(int min, int max) {
  // Output random integer in the interval min <= x <= max
  // Relative error on frequencies < 2^-32
  if (max <= min) {
    if (max == min) return min; else return 0x80000000;
  }
  // Multiply interval with random and truncate
  int r = int((max - min + 1) * Random()) + min; 
  if (r > max) r = max;
  return r;
}


int CRandomMersenne::IRandomX(int min, int max) {
  // Output random integer in the interval min <= x <= max
  // Each output value has exactly the same probability.
  // This is obtained by rejecting certain bit values so that the number
  // of possible bit values is divisible by the interval length
  if (max <= min) {
    if (max == min) return min; else return 0x80000000;
  }
#ifdef  INT64_DEFINED
  // 64 bit integers available. Use multiply and shift method
  uint32 interval;                    // Length of interval
  uint64 longran;                     // Random bits * interval
  uint32 iran;                        // Longran / 2^32
  uint32 remainder;                   // Longran % 2^32

  interval = uint32(max - min + 1);
  if (interval != LastInterval) {
    // Interval length has changed. Must calculate rejection limit
    // Reject when remainder = 2^32 / interval * interval
    // RLimit will be 0 if interval is a power of 2. No rejection then
    RLimit = uint32(((uint64)1 << 32) / interval) * interval - 1;
    LastInterval = interval;
  }
  do { // Rejection loop
    longran  = (uint64)BRandom() * interval;
    iran = (uint32)(longran >> 32);
    remainder = (uint32)longran;
  } while (remainder > RLimit);
  // Convert back to signed and return result
  return (int32)iran + min;

#else
  // 64 bit integers not available. Use modulo method
  uint32 interval;                    // Length of interval
  uint32 bran;                        // Random bits
  uint32 iran;                        // bran / interval
  uint32 remainder;                   // bran % interval

  interval = uint32(max - min + 1);
  if (interval != LastInterval) {
    // Interval length has changed. Must calculate rejection limit
    // Reject when iran = 2^32 / interval
    // We can't make 2^32 so we use 2^32-1 and correct afterwards
    RLimit = (uint32)0xFFFFFFFF / interval;
    if ((uint32)0xFFFFFFFF % interval == interval - 1) RLimit++;
  }
  do { // Rejection loop
    bran = BRandom();
    iran = bran / interval;
    remainder = bran % interval;
  } while (iran >= RLimit);
  // Convert back to signed and return result
  return (int32)remainder + min;

#endif
}

CRandomMersenne rander(43);

vector<vector<int> > pos;
int r,n,m,k;

void pc() {
  for (int i=2;i<=m;++i) {
    for(int j=i;j<=m;++j){ 
      for (int l=j;l<=m;++l){
        vector<int> tmp;
        tmp.push_back(i);
        tmp.push_back(j);
        tmp.push_back(l);
        pos.push_back(tmp);
      }
    }
  }
}

bool can(const vector<int>& a, const vector<int>& b, double& prob) {
  int lim = b.size();
  prob = 1.0;
  for (int i=0;i<a.size();++i){
    int cnt = 0;
    for(int j=0;j<(1<<lim);++j) {
      int prod = 1;
      for (int l=0;l<lim;++l){
        if(j&(1<<l)) {
          prod *= b[l];
        }
      }

      if (prod == a[i]) {
        cnt++;
      }
    }

    if (cnt == 0) {
      return false;
    }
    prob = prob * double(cnt) / double(1 << lim);
  }

  return true;
}
vector<int> solve(const vector<int>& temp) {
  vector<pair<double, int> > a;

  for (int i=0;i<pos.size();++i) {
    double prob;
    if(can(temp, pos[i], prob)) {
      a.push_back(mpair(prob, i));
    }
  }

  double sum = 0.0;
  for (int i=0;i<a.size();++i) {
    sum += a[i].first;
  }
  

  double chance = rander.Random();
  double ac = 0;
  for (int i=0;i<a.size();++i) {
    if (ac  + a[i].first > chance) {
      return pos[a[i].second];
    } else{
      ac += a[i].first;
    }
  }

  if ( a.size() > 0) {
    return pos[a.back().second];
  } else {
    return pos[0];
  }
}
int main()
{
  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  int nt;
  cin>>nt;
  for(int it=1;it<=nt;it++)
  {
    cin >> r >> n >> m >> k;
    pos.clear();
    pc();
    vector<string> res;
    for (int i=0;i<r;++i) {
      vector<int> a(k);
      for (int j=0;j<k;++j) {
        scanf("%d", &a[j]);
      }

      vector<int> temp = solve(a);
      string ans;
      for (int it=0;it<temp.size();++it) {
        ans.push_back(temp[it] + '0');
      }
      res.push_back(ans);
    }
    cout<<"Case #"<<it<<":\n";
    for (int i=0;i<res.size();++i) {
      printf("%s\n", res[i].c_str());
    }
  }
  return 0;
}
