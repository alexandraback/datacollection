#include <iostream>
#include <fstream>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <list>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <climits>
#include <ctime>

#define pb       	push_back
#define fi       	first
#define se       	second
#define KARE(a)	 	( (a)*(a) )
#define MAX(a,b) 	( (a)>(b) ? (a) : (b) )
#define MIN(a,b) 	( (a)<(b) ? (a) : (b) )
#define MAX3(a,b,c)	( MAX( a,MAX(b,c) ) )
#define inf		 	1000000000
#define eps      	(1e-9)
#define esit(a,b)  	( abs( (a)-(b) ) < eps )
#define SET(A,b) memset(A,b,sizeof (A) )
#define SIZE(A) ((int)(A).size())
#define yeral() (node *)calloc(1,sizeof(node))
#define dbg(x) cerr<<#x<<":"<<x<<endl

using namespace std;

typedef long long int lint;
typedef pair<int,int> ii;

int N,res,cnt,A,ar[105],T,x,last;

int main()
{
	freopen("oku.txt","r",stdin);
	freopen("yaz.txt","w",stdout);
	scanf("%d",&T);
	for(int tt=1;tt<=T;tt++)
	{
		scanf("%d %d",&A,&N);
		for (int i = 0; i < N; i++)
			scanf("%d",&ar[i]);
		sort(ar,ar+N);
		last=0;
		if(A==1)
		{
			printf("Case #%d: %d\n",tt,N);
			continue;
		}
		res=N;
		int fl=0;
		for (int i = 0; i < N; i++)
		if(ar[i]<A)
		{
			A+=ar[i];
		}
		else
		{
			x=A;
			cnt=0;
			while(x<=ar[i])
			{
				x+=(x-1);
				cnt++;
			}
			//~ printf("x:%d A;%d cnt:%d\n",x,A,cnt);
			if( cnt <(N-i))
			{
				last+=cnt;
				//~ printf("yenilast:%d\n",last);
				A=x;
				A+=ar[i];
			}
			else
			{
				//~ printf("%d == %d\n",res,N-i+last);
				res=MIN(res,N-i+last);
				fl=1;
				break;
			}
		}
		//~ printf("Res:%d\n",res);
		if(!fl)
			res=min(res,last);
		printf("Case #%d: %d\n",tt,res);
	}
}
