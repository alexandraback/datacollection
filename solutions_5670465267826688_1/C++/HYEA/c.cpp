#include<cstdio>
const int prodarr[4][4]={
	{1,2,3,4},
	{2,-1,4,-3},
	{3,-4,-1,2},
	{4,3,-2,-1},
};
int prod(int a,int b)
{
	int ans=1;
	if(a<0)
	{
		ans*=-1;
		a*=-1;
	}
	if(b<0)
	{
		ans*=-1;
		b*=-1;
	}
	return ans*prodarr[a-1][b-1];
}
char str[10010];
int arr[10010];
bool tmain()
{
	//1=1, i=2, j=3, k=4
	int L,X;
	scanf("%d%d",&L,&X);
	scanf("%s",str);
	int allprod=1;
	for(int i=0;i<L;i++)
	{
		if(str[i]=='i') arr[i]=2;
		if(str[i]=='j') arr[i]=3;
		if(str[i]=='k') arr[i]=4;
		allprod=prod(allprod,arr[i]);
	}
	if(allprod==1) return false;
	if(allprod==-1 && X%2==0 ) return false;
	if(allprod!=1 && allprod!=-1 && X%4!=2) return false;
	int nowstate=1;
	int i;
	for(i=0;i<4*L && nowstate!=2 ;i++)
		nowstate= prod(nowstate,arr[i%L]);
	if(i==4*L) return false;
	nowstate=1;
	for(;i<8*L && nowstate!=3 ;i++)
		nowstate= prod(nowstate,arr[i%L]);
	if(i==8*L) return false;
	if(i>=X*L) return false;
	return true;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		printf("Case #%d: ",i);
		if(tmain())
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}