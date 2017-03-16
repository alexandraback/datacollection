#include<cstdio>
using namespace std;
int main()
{
int N,T; scanf("%d",&N);
for(T=1;T<=N;T++)
{
	int a,s,n,m;
	int b[100][100],t1[100],t2[100];
	scanf("%d%d",&n,&m);
	for(a=0;a<n;a++) t1[a]=0;
	for(s=0;s<m;s++) t2[s]=0;
	for(a=0;a<n;a++) for(s=0;s<m;s++) scanf("%d",&b[a][s]);
	for(a=0;a<n;a++) for(s=0;s<m;s++) if( b[a][s]>t1[a] ) t1[a]=b[a][s];
	for(s=0;s<m;s++) for(a=0;a<n;a++) if( b[a][s]>t2[s] ) t2[s]=b[a][s];
	printf("Case #%d: ",T);
	for(a=0;a<n;a++) for(s=0;s<m;s++) if( b[a][s]<t1[a] && b[a][s]<t2[s] ) goto cannot;
	printf("YES");
	if( false ) cannot: printf("NO");
	printf("\n");
}
	return 0;
}
