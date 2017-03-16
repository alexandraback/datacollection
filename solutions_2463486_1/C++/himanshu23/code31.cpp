#include<iostream>
#include<cstdio>
using namespace std;

int main()
{
//	freopen("C1.in","r",stdin);
 //   freopen("outputC1.in","w",stdout);

long long int a[50]={0,1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002,10000001,10011001,10100101,10111101,11000011,11011011,11100111,11111111,20000002,100000001};
long long int b[50];
for(int i=0;i<50;i++)
{
	b[i]=a[i]*a[i];
//	cout<<b[i]<<endl;
}
int t;
cin>>t;
int q=0;
while(t--)
{
	q++;
	long long int a1,b1;
	cin>>a1>>b1;
	int count=0;
	for(int i=0;i<50;i++)
	{
		if(b[i]>=a1&b[i]<=b1)
		count++;
	}
	cout<<"Case #"<<q<<": "<<count<<endl;
	
}
return 0;
}


