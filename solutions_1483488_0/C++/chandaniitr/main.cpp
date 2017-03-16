#include<iostream>
#include<string>
using namespace std;

unsigned long long p[10];
unsigned long long dp[2000010]={0};

void initp()
{
	p[0]=1;
	for(int i=1;i<10;++i)p[i]=p[i-1]*10;
}

unsigned long long nextnum(unsigned long long num,int dig)
{
	return (num/10)+((num%10)*p[dig-1]);
}

int numdig(unsigned long long n)
{
	int r=0;

	while(n){ ++r;n/=10; }

	return r;
}

unsigned long long solve(int low,int high)
{
	unsigned long long res=0;

	for(int i=high;i>=low;--i)
	{
		int numd=numdig(i);
		int num2=i,num3=high+1;
		
		dp[i]=0;

		for(int j=0;j<numd-1;++j)
		{
			num2=nextnum(num2,numd);
			if(num2>i && num2<=high)num3=min(num3,num2);
		}

		if(num3>i && num3<=high)dp[i]=1+dp[num3];
		res+=dp[i];
	}

	return res;
}


int main()
{
//	freopen("C:\\Users\\CHANDAN\\Desktop\\TC_arena\\out.txt","w",stdout);
//	freopen("I:\\Downloads\\C-small-attempt0.in","r",stdin);
	initp();
	int t;cin>>t;
	for(int i=1;i<=t;++i)
	{
		int l,h;cin>>l>>h;
		cout<<"Case #"<<i<<": "<<solve(l,h)<<endl;
	}
	return 0;
}