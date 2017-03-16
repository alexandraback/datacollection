#include<iostream>
using namespace std;

int main()
{
	int a,b,k,vAnd;
	int result;
	int t;
	cin>>t;
	for(int cases = 1; cases <= t; cases ++)
	{
		cin>>a>>b>>k;
		result = 0;
		for(int i=0;i<a;i++)
			for(int j=0;j<b;j++)
			{
				vAnd = i&j;
				if(vAnd < k)
					result ++;
			}
		cout<<"Case #"<<cases<<": "<<result<<endl;
	}
}
