#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <utility>
#include <cstdlib>
#include <string>
#include <sstream>
#include <gmpxx.h>

using namespace std;

#define VS vector<string>
#define VI vector<int>
#define VVI vector< VI >
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define FORC(it,kont) for(__typeof((kont).begin()) it = (kont).begin(); it!=(kont).end(); ++it)

char buff[20000];

long long gcd( long long a, long long b)
	{
	if( b == 0 ) return a;
	return gcd(b,a%b);
	}

long long pow2( long long x)
	{
	if ( x == 1) return 1;
	if ( x % 2 == 1 ) return 0;
	return pow2(x/2);
	}

int main()
    {
    int T;
    gets(buff);
    sscanf(buff,"%d",&T);

    FOR( t, 0, T )
        {
        int sol = 0;        
	//cout << gcd(15,12) << gcd(24,40) << endl;
	long long p,q;
	string s;
	cin >> s;
	int pos = s.find('/');
	stringstream SS(s.substr(0,pos));
	SS >> p; //cout << p << endl;
	stringstream SS2(s.substr(pos+1));
	SS2 >> q; //cout << q << endl;
	long long d = gcd(p,q); p /= d; q/=d; 
	bool ok = 1;
	if (pow2(q) == 0 ) ok = 0;
	if ( ok == 0 )
		{
		printf("Case #%d: impossible\n",t+1);
		}
	else
		{
		while ( p < q )
			{
			p *= 2;
			++sol;
			}
			
	        printf("Case #%d: %d\n",t+1,sol);
		}
        }
    return 0;
    }
