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
double d,t,v,x0,x;
int A;
double a[100];

int main()
{
	freopen("inputB.txt","r",stdin);
	freopen("outputB.txt","w",stdout);

	cin >> TT;
	FOR(T,0,TT)
	{

		printf("Case #%d:\n",T+1);
		cin >> d >> n >> A;
		if (n == 1)
		{
			cin >> t >> x0;
			v = 0;
		}else
			if (n == 2)
			{
				cin >> t >> x0;
				cin >> t >> x;
				v = (x-x0)/t;
			}


		FOR(i,0,A)
		{
			cin >> a[i];
			t = v + sqrt(v*v + 2*x0*a[i]);
			t /= a[i];

			if ((v*t + x0)>=d)
			{
				double res = sqrt(2*d/a[i]);
				printf("%.9f\n",res);
			}else
			{
				double res = (d-x0)/v;
				printf("%.9f\n",res);
			}


		}

	}
	return 0;
}