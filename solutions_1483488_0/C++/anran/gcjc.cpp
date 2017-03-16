#include <iostream>
using namespace std;

int a,b;
int getlen(int x)
{
	int res=0;
	while(x>0){
		x/=10;
		res++;
	}
	return res;
}
int pow(int b,int p)
{
	int r=1;
	while(p--)r=r*b;
	return r;
}
int TEN[]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int get(int x)
{
	int left=x;
	int len=getlen(x);
	int back[10];
	int top=0;
	int res=0;
	for(int i=1;i<len;i++)
	{
		back[i]=x%TEN[i]*TEN[len-i]+x/TEN[i];
		bool flag=true;
		for(int j=1;j<i;j++)
			if(back[j]==back[i])
			{
				flag=false;
				break;
			}
		if(flag&&back[i]>left&&back[i]<=b)res++;
	}
	return res;
}
int main()
{
	freopen("C:\\1.txt","w",stdout);
	freopen("1.in","r",stdin);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a>>b;
		int t=0;
		for(int j=a;j<=b;j++)
			t+=get(j);
		printf("Case #%d: %d\n",i+1,t);
	}
}