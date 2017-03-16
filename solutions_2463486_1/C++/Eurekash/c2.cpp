#include <iostream>

using namespace std;

typedef long long LL;

int nfair=0;
LL fair[10010];

void make1(int i,LL &x)
{
	for(x=i;i;i/=10)  x=x*10+i%10;
}

void make2(int i,LL &x)
{
	for(x=i,i/=10;i;i/=10)  x=x*10+i%10;
}

bool pal(LL x)
{
	static int s[20];
	int d;
	for(d=0;x;s[d++]=x%10,x/=10);
	for(int i=0;i<d;++i)
		if(s[d-i-1]!=s[i])  return false;
	return true;
}

int main()
{
	int T;
	for(int i=1;i<=10000;++i)
	{
		LL x=0,y;
		make1(i,x);  
		y=x*x;
		if(pal(y)) fair[nfair++]=y,cout<<x<<' '<<y<<endl;
		make2(i,x);  
		y=x*x;
		if(pal(y)) fair[nfair++]=y,cout<<x<<' '<<y<<endl;
	}
	cin>>T;
	for(int t=1;t<=T;++t)
	{
		LL a,b,cnt=0;
		cin>>a>>b;
		for(int i=0;i<nfair;++i)
			if(a<=fair[i] && fair[i]<=b)  ++cnt;
		cout<<"Case #"<<t<<": "<<cnt<<endl;
	}
	return 0;
}
