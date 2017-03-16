#include <bits/stdc++.h>
using namespace std;
/*int ispal(long long int n)
{
	string s="";
	long long int r;
	while(n!=0)
	{
		r=n%10;
		s.push_back(r+'0');
		n=n/10;
	}
	string s1="";
	long long int i,len=s.length();
	for(i=len-1;i>=0;i--)
	{
		s1+=s[i];
	}
	if(s==s1)
		return 1;
	return 0;
}*/
long long int A[39]={1,2,3,11,22,101,111,121,202,212,1001,1111,2002,10001,10101,10201,11011,11111,11211,20002,20102,100001,101101,110011,111111,200002,1000001,1001001,1002001,1010101,1011101,1012101,1100011,1101011,1102011,1110111,1111111,2000002,2001002};
int main()
{
	int t,u,l;
	cin>>t;
	u=t;
	long long int B[39];
	for(l=0;l<39;l++)
	{
		B[l]=A[l]*A[l];
	}
	while(t--)
	{
		long long int a,b;
		cin>>a>>b;
		long long int i,cnt=0;
		for(i=0;i<39;i++)
		{
			if(B[i]>=a&&B[i]<=b)
				cnt++;
		}
		cout<<"Case #"<<u-t<<": "<<cnt<<endl;
	}
	return 0;
}