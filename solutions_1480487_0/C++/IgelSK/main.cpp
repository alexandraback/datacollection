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
		int n;
		cin >> n;
		int a[222];
		FI(i,n) cin >> a[i];
		int sum=0;
		FI(i,n) sum+=a[i];
		int b[222];
		FI(i,n) b[i]=a[i];
		sort(b,b+n);
		reverse(b,b+n);
		printf("Case #%d:",it+1);
		FI(i,n)
		{
			double l=0,r=1.0;
			FI(iter,200)
			{
				double m=(l+r)/2;
				bool f=true;

				double sc=a[i]+m*sum;
				double sp=0;
				FI(j,n) if (j!=i)
				{
					double cur=(sc-a[j])/double(sum);
					if (cur>0) sp+=cur;
				}
				if (sp+m>1) f=false;

				if (!f) r=m;
				else l=m;
			}
			printf(" %.15lf",100*l);
		}
		cout << endl;

		

	}



	

#ifdef vvRabbits
	fprintf(stderr,"*** Time: %.3lf ***\n",(clock()-c_beg)/double(CLOCKS_PER_SEC));
#endif

	return 0;
}