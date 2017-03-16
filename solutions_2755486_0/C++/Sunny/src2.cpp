#pragma warning(disable:4786)
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<functional>
#include<string>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<utility>
#include<fstream>
#include<sstream>
#include<cmath>
#include<stack>
#include<cstdio>
#include <ctime>


using namespace std;

#define MEM(a,b) memset(a,(b),sizeof(a))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b)  ((a) < (b) ? (a) : (b))
#define istr(S) istringstream sin(S)
#define MP make_pair
#define pb push_back
#define inf 1000000000

#define maxn 70005
#define offs 5000
#define off  300

typedef long long  LL;
//typedef __int64 LL;
typedef pair<int,int> pi;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<double> vd;

int attacks[15],deltad[15],deltap[15],deltas[15],len[15],day[15],ll[15],rr[15];
int strength[15];

int ht[2*maxn];

int main()
{
	int i,j,k,tests,cs=0,n;

	freopen("E:\\GCJ\\C-small-attempt0.in","r",stdin);
	freopen("E:\\GCJ\\C-small-attempt0.out","w",stdout);

	
	cin>>tests;

	while(tests--)
	{
		scanf("%d",&n);


		
		MEM(ht,0);

		for(i=0;i<n;i++)
		{
			cin>>day[i]>>attacks[i]>>ll[i]>>rr[i]>>strength[i]>>deltad[i]>>deltap[i]>>deltas[i];
			--rr[i];
			
		}

		int ans=0;
		while(1)
		{
			int d=inf;

			for(i=0;i<n;i++)
				if(attacks[i]>0)
					d=MIN(d,day[i]);

			if(d==inf) break;

			for(i=0;i<n;i++)
			{
				if(attacks[i]==0) continue;
				if(day[i]!=d) continue;

				int ok=0;

				for(j=ll[i];j<=rr[i] && !ok;j++)
					if(ht[j+offs]<strength[i]) ok=1;

				ans+=ok;
			}
			
			
			for(i=0;i<n;i++)
			{
				if(attacks[i]==0) continue;
				if(day[i]!=d) continue;
				--attacks[i];
				
				for(j=ll[i];j<=rr[i] ;j++)
					if(ht[j+offs]<strength[i])
						ht[j+offs]=strength[i];

				strength[i]+=deltas[i];
				ll[i]+=deltap[i];
				rr[i]+=deltap[i];
				day[i]+=deltad[i];

			}
		}
		printf("Case #%d: %d\n",++cs,ans);

	
	}



	return 0;
} 
