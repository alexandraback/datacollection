#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <memory.h>
#include <cmath>
#include <string>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <numeric>

using namespace std;

typedef vector <int> VI;
typedef vector <VI> VVI;
typedef pair <int, int> pnt;
typedef pair <int, int> PII;
typedef long long LL;
typedef unsigned long long ULL;

#define FOR(i,a,b) for (int i=(a); i<(b); ++i)
#define FI(i,a) FOR(i,0,a)
#define pb push_back
#define sz size()
#define mp make_pair
#define MEMS(a,b) memset(a,b,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define V(t) vector<t>
#define VV(t) vector<vector<t> >

VVI a;
int x[22];

int main()
{
#ifdef vvRabbits
	clock_t c_beg = clock();
	//freopen("in.txt","r",stdin);
	//*
	freopen("jam.txt","r",stdin);
	freopen("jam.out","w",stdout);
	//*/
#else
	//freopen("jam.txt","r",stdin);
	//freopen("jam.out","w",stdout);
#endif
	
	int tn;
	cin >> tn;
	FI(it,tn)	
	{
		a.clear();
		a.resize(2000010,VI());
		int n;
		cin >> n;
		FI(i,n) cin >> x[i];
		VI l,r;
		bool f=false;
		printf("Case #%d:\n",it+1);
		FI(mask,(1<<n))
		{
			int sum=0;
			FI(i,n) if (mask&(1<<i)) sum+=x[i];
			a[sum].pb(mask);
			if (a[sum].size()>1) FI(i,a[sum].size()-1) if (!(a[sum][i]&mask))
			{
				l.clear();
				r.clear();
				FI(j,n) 
				{
					if (mask&(1<<j)) l.pb(x[j]);
					if (a[sum][i]&(1<<j)) r.pb(x[j]);
				}
			
				FI(i,l.sz) printf("%d%c",l[i],(i+1==l.sz)?'\n':' ');
				FI(i,r.sz) printf("%d%c",r[i],(i+1==r.sz)?'\n':' ');
				f=true;
				break;
			}
			if (f) break;
		}
		
		
		if (!f) cout <<"Impossible\n";
		


		

	}



	

#ifdef vvRabbits
	fprintf(stderr,"*** Time: %.3lf ***\n",(clock()-c_beg)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}