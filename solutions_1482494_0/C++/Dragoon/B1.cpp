#pragma warning(disable:4786)
#include<math.h>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<utility>
#include<algorithm>
#include<string.h>
#include<stdio.h>
#include<set>
#include<stdlib.h>
#include<sstream>
#include<functional>
#include<queue>
#include<stack>
using namespace std;

#define MAX(A,B) ((A)>(B)?(A):(B))
#define MIN(A,B) ((A)<(B)?(A):(B))
#define ABS(A) ((A)>0?(A):(-(A)))
#define S(X) ((X)*(X))

typedef pair<int,int> PII;

//int dr[]={-1,0,1,0};
//int dc[]={0,1,0,-1};
//int dr[]={-2,-2,-1,1,2,2,1,-1};
//int dc[]={-1,1,2,2,1,-1,-2,-2};

typedef __int64 LL;
#define I64d "%I64d"

vector<PII> L, H;
int done[1005];
int a[1002],b[1002];

int main()
{
//	freopen("B-small-attempt0.in","r",stdin);	freopen("B-small-attemptt0.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);	freopen("z.out","w",stdout);
	freopen("B-small-attempt2.in","r",stdin);	freopen("B-small-attemptt2.out","w",stdout);
//	freopen("B-large.in","r",stdin);			freopen("B-large.out","w",stdout);

	int T, ks;
	int i, j, star, cnt, n, ans, cnts, x, y;
	PII X;

	scanf("%d",&T);
	for(ks=1;ks<=T;ks++)
	{

		L.clear();
		H.clear();

		scanf("%d",&n);
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&a[i],&b[i]);
			L.push_back( PII(a[i],i) );
			H.push_back( PII(b[i],i) );
			done[i] = 0;
		}

		sort(L.begin(),L.end());
		sort(H.begin(),H.end());

		ans = 1000000;
		for(i=0;i<(1<<n);i++)
		{
			cnts = 0;
			for(j=0;j<n;j++)
				if((1<<j)&i)
					cnts++;

			if(ans < cnts+n) continue;

			L.clear();
			H.clear();

			for(j=0;j<n;j++)
			{
				H.push_back(PII(b[j],j));
				if( (1<<j)&i )
					L.push_back( PII(a[j],j) );
				done[j] = 0;
			}

			sort(L.begin(),L.end());
			sort(H.begin(),H.end());
			
			star = cnt = 0;
			x = y = 0;
			while(y<n)
			{
				if(H[y].first<=star)
				{
					if(done[H[y].second]==1) star++;
					else star+=2;

					done[H[y].second] = 2;
					cnt++;
					y++;
				}
				else if(x<cnts && L[x].first<=star)
				{
					if(done[L[x].second]==2) {x++; continue;}
					done[L[x].second] = 1;
					star++;
					cnt++;
					x++;
				}
				else
					break;

			}

			if(star==2*n)
			{
				ans = MIN(ans, cnts+n);
			}

		}


		printf("Case #%d: ",ks);
		if(ans==1000000)
			printf("Too Bad\n");
		else
			printf("%d\n",ans);
	}

	return 0;
}