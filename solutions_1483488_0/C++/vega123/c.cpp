#include<iostream>
#include<stdio.h>
using namespace std;
int visited[2000005];
int f(int a)
{
	int tmp=0;
	while(a){
		tmp++;
		a/=10;
	}
	if(tmp==0)return 1;
	return tmp;
}
int g(int num,int B,int cur)
{
	int i;
	int tmp=1;
	int fro,bac;
	int mulbac=1;
	int newcur;
	for(i=0;i<num;i++)
		mulbac*=10;
	int ans=0;
	for(i=1;i<num;i++)
	{
		tmp*=10;
		mulbac/=10;
		fro=cur/tmp;
		bac=cur%tmp;
		newcur=bac*mulbac+fro;
		if(newcur>cur&&newcur<=B&&(!visited[newcur]))
		{
			ans++;
			//printf("%d,%d\n",cur,newcur);
			visited[newcur]=1;
		}
	}
	return ans;

}
int main()
{
	int i,t,j;
	int A,B;
	//freopen("out.txt","w",stdout);
	scanf("%d",&t);
	for(i=1;i<=t;i++)
	{
		memset(visited,0,sizeof(visited));
		scanf("%d%d",&A,&B);
		int numofdit=f(A);
		int ans=0;
		for(j=A;j<=B;j++)
			if(!visited[j])
			{
				int m=g(numofdit,B,j);
				ans+=(m+1)*m/2;
			}
		printf("Case #%d: %d\n",i,ans);
	}
	return 0;
}