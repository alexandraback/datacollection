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

	ll N = 1000000007;
	int n;
	scanf("%d\n", &n);
	multiset<string> A;
	int tab[200] = {0};
	int tab2[200] = {0};
	FOR(i,n)
	{
		scanf("%s", buf);
		string s = string(buf);
		char prev=s[0];
		int j=0;
		buf2[j++] = prev;
		FORB(i,1,s.length())
		{
			if(s[i] != prev)
			{
				prev = s[i];
				buf2[j++] = prev;
			}
		}
		buf2[j]=0;
		s = string(buf2);
		int n = s.size();
		if(n==1)
		{
			tab2[s[0]]++;
		continue;
		}


		FORB(i,1, n-1)
		{
			tab[s[i]]++;
		}
		A.insert(s);
	}

	string begin;
	string end;	

	int countB;
	int countE;

	ll out = 1;
	for(char c = 'a'; c <= 'z'; c++)
	{
		countB = 0;
		countE = 0;
		FOREACH(multiset<string>, it, A)
		{
			if(it->at(0) == c)
			{
				begin = *it;
				countB++;
			}
			if(it->at(it->size()-1) == c)
			{
				end = *it;
				countE++;
			}
		}
		if(countB > 1 || countE > 1 || (countB + countE > 0 && tab[c] > 0) || (countB ==1 && countE == 1 && begin == end) || tab[c] > 1)
		{
			return 0;
		}
		else if(countB ==1 && countE == 1)
		{
			A.erase(begin);
			A.erase(end);
			A.insert(end + begin);
			FORB(i,2,tab2[c]+1)
			{
				out = out * i;
				out = out % N;
			}
			tab2[c]=0;
		}
		else if(countB ==1 || countE == 1)
		{
			FORB(i,2,tab2[c]+1)
			{
				out = out * i;
				out = out % N;
			}
			tab2[c]=0;
		}
		else if(tab2[c] > 0)
		{
			FORB(i,2,tab2[c]+1)
			{
				out = out * i;
				out = out % N;
			}
			tab2[c]=0;
			buf[0]= c;
			buf[1] = 0;
			A.insert(string(buf));
		}
	}
	n = A.size();
	FORB(i,2,n+1)
	{
				out = out * i;
				out = out % N;
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
