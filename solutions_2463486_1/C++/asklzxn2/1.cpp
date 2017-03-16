#include<cstdio>
#include<iostream>
using namespace std;
long long i,Cnt,T,L,R,Ans,Case,len;
long long A[1000005],B[20];
bool palindrome(long long i)
{
	long long j;
	len=0;
	for(;i;i/=10) B[++len]=i%10;
	for(j=1;j<=len/2;++j)
		if(B[j]!=B[len-j+1])
			return 0;
	return 1;
}
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	for(i=1;i<=10000000;++i)
	{
		if(palindrome(i)&&palindrome(i*i))
			A[++Cnt]=i*i;
	}
	for(cin>>T;T--;)
	{
		++Case;
		cin>>L>>R;
		Ans=0;
		for(i=1;i<=Cnt;++i)
			if(A[i]>=L&&A[i]<=R)
				++Ans;
		cout<<"Case #"<<Case<<": "<<Ans<<endl;
	}
	return 0;
}
