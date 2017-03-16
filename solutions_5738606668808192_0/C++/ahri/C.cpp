/*
ID: ahri1
PROG: A
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <queue>
#include <vector>

using namespace std;

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
#define EXISTS(x, s) ( (s).find((x)) != (s).end() ) 
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
template<typename T> string v_2_s(vector<T> &a) { stringstream sb; __typeof(a.begin()) i = a.begin(); if (i!=a.end()) { sb << *i; ++i; } for (; i!=a.end();++i) { sb << " " << *i; } return sb.str(); }


class Primes {
private:
  unsigned char* primesBuffer;
  
  unsigned __max_seeded;
  
  unsigned char * __on;
  unsigned char *__off;           
  
  inline bool get(unsigned x) {
    return primesBuffer[(x)>>4]&(__on[x&15]);
  }
  inline void set(int x){
    primesBuffer[(x)>>4]|=(__on[x&15]);    
  }
  inline void unset(int x) {
    primesBuffer[(x)>>4]&=(__off[x&15]);
  }
  inline void toggle(int x) {
    primesBuffer[(x)>>4]^=(__on[x&15]);
  }

  inline unsigned isqrt (unsigned long long X)
  {
    unsigned long long ret = ceil(sqrt((long double)X));
    while (ret * ret < X) ++ret;
    while (ret && (ret-1)*(ret-1)>X) --ret;
    return ret;
  }
  
  int isprime_slow(unsigned long long p) { 
    unsigned root = isqrt(p);
    for (unsigned i=0;i<PV.size() && PV[i]<=root;i++) {
      if (p%PV[i]==0) return 0;
    }
    if (PV.size() && PV.back() > root) return 1;
    
    if (p==2) return 1; if (!(p%2) || p<2) return 0;
    unsigned long long i=3;
    if (__max_seeded>0) i=__max_seeded+ ((__max_seeded&1)?0:1); 
    for (;i<=root;i+=2) {
      if (!(p%i)) return 0; 
      }
    return 1; 
  }
  
public:
  std::vector<unsigned> PV;

  int isprime(unsigned long long x) { 
    if (x<2) return 0;
    if (x<4) return 1;
    if (x>__max_seeded) return isprime_slow(x);      
    return (x&1) && get(x);
  }
  
  void sieve_e(unsigned n) {
    __max_seeded = n;
    free(primesBuffer);
    unsigned slots_needed=(n>>4)+1;
    primesBuffer=(unsigned char*)malloc(slots_needed);
    memset(primesBuffer, ~0, slots_needed);
    PV.clear(); PV.push_back(2);          
    set(3);
    PV.push_back(3);
    char iInc[]={2, 4};
    unsigned i, j, jInc, ii=0, root=isqrt(n);    
    for (i=9;i<=n;i+=6) {
      unset(i);
    }
    for (i=5;i<=root;) {
      if (get(i)){      
        j = i*i;
        PV.push_back(i);
        jInc=i<<1;
        for (;j<=n;j+=jInc) {
          unset(j);
        }
      }
      i+=iInc[ii];
      ii=1-ii;
    }
    for (;i<n;) {
      if (get(i)) PV.push_back(i);
      i+=iInc[ii];
      ii=1-ii;
    }
  }  
  void sieve_a(unsigned max_n) {
    __max_seeded = max_n;
    free(primesBuffer);
    unsigned N = ceil(sqrt((double)max_n));
    int N2 = N;
    unsigned n, r, x;
    int y;
    
    primesBuffer=(unsigned char*)malloc((max_n>>4)+1);
    memset(primesBuffer, 0, (max_n>>4)+1);
    vector<unsigned> squares(N+1);
    for (x=0;x<=N;x++) squares[x]=x*x;
    for (x = 1; x <= N; x++){
      n = squares[x]<<2;
      for (y = 1; y<=N2; y+=2){         
        r = n + squares[y];
        if (r>max_n) break;
        if (r%12 == 1 || r%12 == 5) toggle(r);
      }
      n -= squares[x];      
      for (y = (x&1)+1; y<=N2; y+=2){                  
        r = n +squares[y];
        if (r>max_n) break;
        if (r%12 == 7) toggle(r);
      }
      for (y = x-1; y > 0 ; y-=2) {
        r = n - squares[y];
        if (r>max_n) break;
        if (r%12 == 11) toggle(r);
      }    
    }
    set(3);
    PV.clear(); PV.push_back(2); PV.push_back(3);    
    for (x = 5; x <= N; x+=2){
      if (get(x)){        
        for (r = squares[x]; r < max_n; r += squares[x]<<1) unset(r);
        PV.push_back(x);
      }
    }
    for (; x < max_n; x+=2) if (get(x)) PV.push_back(x);      
  }  
  Primes(unsigned __num) {
    if (__num<10) __num=10;
    __on= (unsigned char*)malloc(16);
    __off = (unsigned char*)malloc(16);
    __on[1]=1; __on[3]=2; __on[5]=4; __on[7]=8; __on[9]=16; __on[11]=32; __on[13]=64; __on[15]=128;
    __off[1]=254; __off[3]=253; __off[5]=251; __off[7]=247; __off[9]=239; __off[11]=223; __off[13]=191; __off[15]=127;
    sieve_e(__num);
  }  
  ~Primes() {
    free(primesBuffer);
    PV.clear();
  }
};

Primes P(1 << 27);

#define MAX_N 64
#define MAX_DIGIT 10

int64 A[MAX_DIGIT + 1];
int64 pot[MAX_DIGIT + 1][MAX_N];

void init() {
	for(int i = 0; i <= MAX_DIGIT; ++i){
		pot[i][0] = 1;
	}
	for(int i = 2; i <= MAX_DIGIT; ++i) {
		for(int j = 1; j < MAX_N; ++j){
			pot[i][j] = pot[i][j - 1] * i;
		}
	}
}

void to_bases(int x, int N) {
	memset(A, 0, sizeof(A));
	A[2] = x;
	for(int i = 0; i < N; ++i){
		if (x & (1 << i)) {
			for(int j = 3; j <= MAX_DIGIT; ++j){
				A[j] += pot[j][i];
			}
		}
	}
}

string to_binary(int x, int N) {
	string ret(N, '0');
	for (int i = N - 1; i >= 0; --i)
		if (x & (1 << i))
			ret[N - i - 1] = '1';	
	return ret;
}


void solve() {
	int N, J;
	cin >> N >> J;	
	cout << endl;
	
	int limit = 1 << (N - 2);
	
	for(int i = 0; i < limit && J; ++i){
		int64 x = (1 << (N - 1)) + (i << 1) + 1;
		to_bases(x, N);
		bool ok = true;
		for(int j = 2; j <= MAX_DIGIT; ++j){
			if (P.isprime(A[j])) {
				ok = false;
				break;
			}
		}
		if (!ok)
			continue;
		--J;
		cout << to_binary(x, N);
		for(int i = 2; i <= MAX_DIGIT; ++i){
			for(int j = 0; ; ++j){
				// cerr << i << " " << j << " " << A[i] << endl;
				if (A[i] % P.PV[j] == 0) {
					cout << " " << P.PV[j];
					break;
				}
			}
		}
		cout << endl;
	}
	
	
}


int main() {

  init();

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
