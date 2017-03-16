#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;
int T;
long long A,B;
//vector<long long> V;
long long V[1000];
int iV;
bool judge(long long x)
{
	char str[100];
	int icount=0;
	while(x)
	{
		str[icount++] = x%10;
		x/=10;
	}
	for(int i = 0; i <= icount/2;++i)
		if(str[i]!=str[icount-1-i])return false;
	return true;
}
void init()
{
	for(long long i = 1;i<=10000000; ++i)
	{
		if(judge(i)&&judge(i*i))V[iV++]=(i*i);
	}
	//cout<<iV<<endl;
	//cout<<V[iV-1]<<endl;
}
int ifind(long long b)
{
	for(int i = 0; i < iV; ++i)
		if(b<V[i])return i;
	return iV;
}
int main()
{
	freopen("C-large-1.in","r",stdin);
	freopen("C.out","w",stdout);
	init();
	scanf("%d",&T);
	for(int i = 0; i < T; ++i)
	{
		scanf("%lld%lld",&A,&B);
		cout<<"Case #"<<i+1<<": "<<ifind(B)-ifind(A-1)<<endl;
	}
	return 0;
}