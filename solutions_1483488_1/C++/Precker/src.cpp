#include<iostream>
#include<vector>
#include<set>
using namespace std;

int expp(int n)
{
	int res=1;
	while(n--)
	{
		res*=10;
	}
	return res;
}

int calc(int n,int A,int B)
{
	int res=0;
	int tmp=n;
	int bits=0;
	while(tmp>0)
	{
		bits++;
		tmp/=10;
	}
	tmp=n;
	set<int> datas;
	for(int i=0;i<bits-1;i++)
	{
		tmp=tmp/10+tmp%10*expp(bits-1);
		//cout<<tmp<<endl;
		if(tmp<n&&tmp>=A&&tmp<=B)
		{
			datas.insert(tmp);
		}
	}
	res=datas.size();
	return res;
}


int main()
{
	int T,A,B,n,m;
	cin>>T;
	int num=1;
	while(T--)
	{
		cin>>A>>B;//A<B;
		int tmp;
		int res=0;
		for(n=A;n<=B;n++)
		{
			res+=calc(n,A,B);
		}
		printf("Case #%d: %d\n",num++,res);
	}
	return 0;
}