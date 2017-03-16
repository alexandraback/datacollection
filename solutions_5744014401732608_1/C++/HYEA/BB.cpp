#include<cstdio>
#include<cstring>
int B;
long long M;
int arr[404][404];
int xx[404];	
void tmain()
{
	memset(arr,0,sizeof(arr));
	memset(xx,0,sizeof(xx));
	scanf("%d%lld",&B,&M);
	for(int i=2;i<=B;i++)
		for(int j=i+1;j<=B;j++)
			arr[i][j]=1;
	M--;
	//connect 1->B
	if(M>=(1LL<<(B-2)))
	{
		puts("IMPOSSIBLE");
		return;
	}
	puts("POSSIBLE");
	arr[1][B]=1;
	for(int i=0; i<B-2; i++)
		if(M&(1LL<<i)) arr[1][B-1-i]=1;
	for(int i=1;i<=B;i++,puts(""))
		for(int j=1; j<=B; j++)
			printf("%d",arr[i][j]);
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=1; i<=T; i++)
	{
		printf("Case #%d: ",i);
		tmain();
	}
}
