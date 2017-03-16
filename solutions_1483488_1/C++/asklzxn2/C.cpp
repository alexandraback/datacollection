#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
int i,j,T,A,B,C[2000005];
long long Ans;
int get(int a)
{
	int i,x,res=a;
	for(x=1;x*10<=a;x*=10);
	for(i=1;i<=8;++i)
	{
		a=a%10*x+a/10;
		if(a/x!=0&&a<res) res=a;
	}
	return res;
}
int main()
{
	freopen("c1.in","r",stdin);
	freopen("c1.out","w",stdout);
	scanf("%d",&T);
	for(j=1;j<=T;++j)
	{
		scanf("%d%d",&A,&B);
		memset(C,0,sizeof(C));
		for(i=A;i<=B;++i) ++C[get(i)];
		Ans=0;
		for(i=1;i<=2000000;++i)
			Ans+=(long long)C[i]*(C[i]-1)/2;
		cout<<"Case #"<<j<<": "<<Ans<<endl;
	}
	return 0;
}
