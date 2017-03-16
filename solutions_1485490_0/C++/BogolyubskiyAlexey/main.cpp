#include<iostream>
using namespace std;
#define MAX_S 200
long long a[MAX_S],b[MAX_S]; 
int A[MAX_S],B[MAX_S];
int N,M;
long long answer;
void rec(long long aa,int AA,long long bb,int BB,int i,int j,long long cnt)
{
	if(AA==BB)
	{
		long long z=min(aa,bb);
		cnt+=z;
		aa-=z;
		bb-=z;
	}
	answer=max(cnt,answer);
	int k;
	//берем коробки
	for(k=i;k<N;k++)
	{
		if(AA==A[k]) rec(aa+a[k],AA,bb,BB,k+1,j,cnt);
		else rec(a[k],A[k],bb,BB,k+1,j,cnt);
	}
	//берем игрушки
	for(k=j;k<M&&aa;k++)
		if(AA==B[k])
		{
			rec(aa,AA,b[k],B[k],i,k+1,cnt);
			break;
		}
}

void solve(int T)
{
	int i;
	scanf("%d%d",&N,&M);
	for(i=0;i<N;i++) scanf("%I64d%d",&a[i],&A[i]);
	for(i=0;i<M;i++) scanf("%I64d%d",&b[i],&B[i]);
	answer=0;
	rec(0,-1,0,-1,0,0,0);
	printf("Case #%d: %I64d\n",T,answer);
}
int main()
{
	int i,T;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&T);
	for(i=1;i<=T;i++) solve(i);
	return 0;
}