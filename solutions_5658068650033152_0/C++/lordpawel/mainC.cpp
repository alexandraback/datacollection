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

char buf[200];
char buf2[200];


ll solve()
{

	int n;
	int m;
	int k;
	scan(n);
	scan(m);
	scan(k);
	if (m > n) swap(n,m);
	if(k<=4 || m <=2) return k;

	int suma;
	int min = n*m;
	int diff, pole;
	
	pole = 5;
	suma = 4;
	int wys = 3;
	if(pole < k)
	{
		diff = k - pole;
	}
	else diff = 0;
	if(suma + diff < min)
	{
		min = suma + diff;
	}
	for(int i=4;i<=n;i++)
	{
		if(i%2==1 && i<=m)
		{
			wys=i;
		}
		pole+=wys;
		suma+=2;
		if(pole < k)
		{
			diff = k - pole;
		}
		else diff = 0;
		if(suma + diff < min)
		{
			min = suma + diff;
		}
	}
	if(m==3) return min;

	pole = 8;
	suma = 6;
	wys = 4;
	if(pole < k)
	{
		diff = k - pole;
	}
	else diff = 0;
	if(suma + diff < min)
	{
		min = suma + diff;
	}
	for(int i=4;i<=n;i++)
	{
		if(i%2==1 && i+1<=m)
		{
			wys=i +1;
		}
		pole+=wys;
		suma+=2;
		if(pole < k)
		{
			diff = k - pole;
		}
		else diff = 0;
		if(suma + diff < min)
		{
			min = suma + diff;
		}
	}



	return min;
}

int main()
{
    int T;
	scan(T);
	//P = primes(1000002);
	FOR(i,T)
	{
		ll a = solve();
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
