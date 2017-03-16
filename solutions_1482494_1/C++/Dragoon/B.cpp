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
//	freopen("B-small-attempt0.in","r",stdin);	freopen("B-small-attempt0.out","w",stdout);
//	freopen("B-small-attempt2.in","r",stdin);	freopen("B-small-attempt2.out","w",stdout);
//	freopen("B-small-attempt1.in","r",stdin);	freopen("B-small-attempt1.out","w",stdout);
	freopen("B-large.in","r",stdin);			freopen("B-large.out","w",stdout);

	int T, ks;
	int i, j, star, cnt, n;
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

		priority_queue<PII> PQ;

		cnt = 0;
		star = 0;

		i = j = 0;
		while(j<n)
		{
			if(H[j].first<=star)
			{
				if(done[H[j].second]==1) star++;
				else star+=2;
				done[H[j].second] = 2;
				j++;
				cnt++;
			}
			else
			{
				while(i<n && L[i].first<=star)
				{
					PQ.push( PII(b[L[i].second],L[i].second) );
					i++;
				}

				if(PQ.empty()) break;

				int flag = 0;
				while(!PQ.empty())
				{
					X = PQ.top();
					PQ.pop();

					if(done[X.second]==2) continue;

					done[X.second] = 1;
					cnt++;
					star++;
					flag = 1;
					break;
				}

				if(flag==0) break;
			}
		}

		printf("Case #%d: ",ks);
		if(star!=2*n)
			printf("Too Bad\n");
		else
			printf("%d\n",cnt);
	}

	return 0;
}