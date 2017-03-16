#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,n) for(int i=0;i<n;++i)
#define FORB(i,b,n) for(int i=b;i<n;++i)
#define REV(i,n) for(int i=n;i>=0;--i)
#define FOREACH(T, it, v) for(T::iterator it = v.begin(); it !=v.end(); ++it)
#define print(STRING,INT) printf("%s= %d\n", STRING, INT)
#define scan(INT) scanf("%d", &INT)
#define PB(X) push_back(X)


typedef long long ll;
typedef unsigned int u32;
typedef unsigned int uint;
typedef unsigned int uInt;

const int INF = (0u - 11)/2;

typedef set<int> SI;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<long long> VL;
typedef set<long long> SL;
typedef map<int, int> MII;



int DEBUG = 1;

void log(char* S, long long a)
{
    if(DEBUG)
    {
        printf("%s= %lld\n", S, a);
    }
}


VI primes(int range = 10001)
{
    VI primes;
    primes.push_back(2);
    primes.push_back(3);
    primes.push_back(5);
    primes.push_back(7);
    for(int i = 9; i< range;i++)
    {
        int j=0;
        int flag = false;
        while((long long )primes[j]*primes[j]<= i)
        {
            if(i%primes[j++]==0)
            {
                flag = true;
                break;
            }
        }
        if(flag == false) primes.push_back(i);
    }
    return primes;
}

int solve()
{
//	int N = P.size();
	int N = 1000002;
	long long a, b;
		char c;
	scanf("%lld", &a);


	scanf("%c", &c);
	scanf("%lld", &b);
	FORB(i,2,N)
	{
	//	while(a%P[i] == 0 && b%P[i] == 0)
		while(a%i == 0 && b%i == 0)
		{
			a=a/i;
			b=b/i;
		}
	}
int 	out = 1;
	long long K = 1;
	while(K<10000000000000)
	{
		if(b == K) break;
		K*=2;
	}
	if(K>=10000000000000)
		return -1;

	while(a*2 < b)
	{
		b/=2;
		out++;
	}
	return out;
}

int main()
{
    int T;
	scan(T);
	//P = primes(1000002);
	FOR(i,T)
	{
		int a = solve();
		if(a== -1)
		{
			cout << "Case #" << i+1 << ": " << "impossible" << endl;
		}
		else
		{
			cout << "Case #" << i+1 << ": " << a << endl;
		}

	}



    return 0;
}
