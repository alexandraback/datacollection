#include<inttypes.h>
#include<cstdio>
#include<vector>
#include<map>
#include<set>
#include<time.h>
#include<iostream>

using namespace std;

class CRandomMother {                  // Encapsulate random number generator
public:
   void RandomInit(int seed);          // Initialization
   int IRandom(int min, int max);      // Get integer random number in desired interval
   double Random();                    // Get floating point random number
   uint32_t BRandom();                 // Output random bits
   CRandomMother(int seed) {           // Constructor
      RandomInit(seed);}
protected:
   uint32_t x[5];                      // History buffer
};

// Output random bits
uint32_t CRandomMother::BRandom() {
  uint64_t sum;
  sum = (uint64_t)2111111111UL * (uint64_t)x[3] +
     (uint64_t)1492 * (uint64_t)(x[2]) +
     (uint64_t)1776 * (uint64_t)(x[1]) +
     (uint64_t)5115 * (uint64_t)(x[0]) +
     (uint64_t)x[4];
  x[3] = x[2];  x[2] = x[1];  x[1] = x[0];
  x[4] = (uint32_t)(sum >> 32);                  // Carry
  x[0] = (uint32_t)sum;                          // Low 32 bits of sum
  return x[0];
} 


// returns a random number between 0 and 1:
double CRandomMother::Random() {
   return (double)BRandom() * (1./(65536.*65536.));
}


// returns integer random number in desired interval:
int CRandomMother::IRandom(int min, int max) {
   // Output random integer in the interval min <= x <= max
   // Relative error on frequencies < 2^-32
   if (max <= min) {
      if (max == min) return min; else return 0x80000000;
   }
   // Assume 64 bit integers supported. Use multiply and shift method
   uint32_t interval;                  // Length of interval
   uint64_t longran;                   // Random bits * interval
   uint32_t iran;                      // Longran / 2^32

   interval = (uint32_t)(max - min + 1);
   longran  = (uint64_t)BRandom() * interval;
   iran = (uint32_t)(longran >> 32);
   // Convert back to signed and return result
   return (int32_t)iran + min;
}


// this function initializes the random number generator:
void CRandomMother::RandomInit (int seed) {
  int i;
  uint32_t s = seed;
  // make random numbers and put them into the buffer
  for (i = 0; i < 5; i++) {
    s = s * 29943829 - 1;
    x[i] = s;
  }
  // randomize some more
  for (i=0; i<19; i++) BRandom();
}

int R, N, M, K, T;

map< long long, set< long long > > S;

const int ITER = 100000;
// const int ITER = 100000; <- one minute

CRandomMother *RR;
int a[12];

int counter;
long long number, product;

void Go(int depth, int last)
{
	int l1;
	int flag;

	if(depth == N)
	{
		counter++;
		number = 0;
		for(l1 = 0; l1 < N; l1++) number = number * 10 + a[l1];

		for(flag = 0; flag < (1<<N); flag++)
		{
			product = 1;
			for(l1 = 0; l1 < N; l1++)
			{
				if(flag & (1 << l1))
				{
					product *= a[l1];
				}
			}
			S[product].insert(number);
		}
	}
	else
	{
		for(l1 = last; l1 <= M; l1++)
		{
			a[depth] = l1;
			Go(depth + 1, l1);
		}
	}
}

void Init(void)
{
	Go(0, 2);
}

void Anal(void)
{
	map< long long, set< long long > >::iterator it;

	long long val = 0;
	int maxe = 0;

	cerr << "S.size() : " << S.size() << endl;
	for(it = S.begin(); it != S.end(); ++it)
	{
		int curr = (int)it->second.size();
		val += curr;
		if(curr > maxe) maxe = curr;
	}
	cerr << "sum of S[i].size() : " << val << endl;
	cerr << "max of S[i].size() : " << maxe << endl;
}

set<long long> Union(const set<long long> &me, const set<long long> &you)
{
	set<long long> ret;

	set<long long>::iterator it;
	
	for(it = me.begin(); it != me.end(); ++it)
	{
		if(you.count(*it) > 0)
		{
			ret.insert(*it);
		}
	}
	
	return ret;
}

int main(void)
{
	int l0, l1;

	T = 1;
	R = 8000;
	N = 12;
	M = 8;
	K = 12;

	RR = new CRandomMother(time(0));

	Init();

	Anal();

	fprintf(stderr, "done!\n");

	cin >> T;

	cin >> R;
	cin >> N;
	cin >> M;
	cin >> K;

	cout << "Case #1:" << endl;
	for(l0 = 1; l0 <= R; l0++)
	{
//		cerr << "Working.. " << l0 << endl;
		set<long long> wow;
		for(l1 = 1; l1 <= K; l1++)
		{
			cin >> product;

			if(l1 == 1) wow = S[product];
			else wow = Union(wow, S[product]);
		}

		if(wow.size() == 0)
		{
			cerr << "Oops.." << endl;
			for(l1 = 1; l1 <= N; l1++)
			{
				cout << RR->IRandom(2, M);
			}
			cout << endl;
		}
		else
		{
			int the_size = (int)wow.size();
			int the_index = RR->IRandom(1, the_size);
			int index = 1;
			set<long long>::iterator it;
			for(it = wow.begin(); it != wow.end(); ++it)
			{
				if(index == the_index)
				{
					cout << (*(it)) << endl;
					break;
				}
				index++;
			}
		}
		cout.flush();
	}


//	scanf("%d %d %d %d",
	return 0;
}
