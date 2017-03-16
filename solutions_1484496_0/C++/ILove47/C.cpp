#pragma comment(linker,  "/STACK:16777216")
#include <algorithm>
#include <cstring>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <iterator>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <locale>
#include <climits>

using namespace std;

typedef long long ll;
typedef unsigned long long Ull;

#define VI vector <int>
#define FOR(i, a, b) for(int (i) = (a); (i) < (b); ++(i))
#define RFOR(i, a, b) for(int (i) = (a)-1; (i) >= (b); --(i))
#define CLEAR(a) memset((a), , sizeof(a))
#define INF 1000000000
#define PB push_back
#define ALL(c) (c).begin(),  (c).end()
#define pi 2*acos(0.0)
#define SQR(a) (a)*(a)
#define MP make_pair
#define MOD 1000000007
#define EPS 1e-7
#define INF 2000000000


int T,TT,n,k,l,r,p,res,S;
int a[100];
map<int,int> M;
bool b = 0;
int main()
{
	freopen("inputC.txt","r",stdin);
	freopen("outputC.txt","w",stdout);

	cin >> TT;
	FOR(T,0,TT)
	{
		M.clear();
		cin >> n;
		FOR(i,0,n)
			cin >> a[i];
		b = 0;
		FOR(mask,0,1<<n)
		{
			if (b)break;
			int s = 0;
			FOR(i,0,n)
				if (mask & (1<<i))
					s += a[i];
			map<int,int>::iterator it = M.find(s);
			if (it != M.end())
			{
				if (!(it->second & mask))
				{
					printf("Case #%d:\n",T+1);
					FOR(i,0,n)
						if (it->second & (1<<i))
							cout << a[i] << " ";
					cout << endl;
					FOR(i,0,n)
						if (mask & (1<<i))
							cout << a[i] << " ";
					cout << endl;
					b = 1;
				}
			}else
			{
				M[s] = mask;
			}
		}
		if (!b)
		{
			printf("Case #%d:\n",T+1);
			cout << "Impossible\n";
		}



		
	}
	return 0;
}