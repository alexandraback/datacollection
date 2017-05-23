#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;
int mv[2000001];
char S[30];

void trans(int id,int len)
{
	for(int i=0;i<len;i++)
		S[len+i]=S[i];
	S[len<<1]=0;
	int i,j,k;
	for(i=0,j=1,k=0;i<len && j<len && k<len;)
	{
		if(S[i+k]==S[j+k]) k++;
		else
		{
			if(S[i+k]>S[j+k]) i+=k+1;
			else j+=k+1;
			if(i==j) j++;
			k=0;
		}
	}
	S[i+len]=0;
	mv[id]=atoi(S+i);
}
LL count(LL N)
{
	LL num,b,e;

	num=0;
	sort(mv,mv+N);
	for(b=e=0;b<N;b=e+1,++e)
	{
		while(e+1<N && mv[e]==mv[e+1])
			e++;
		num+=(e-b)*(e-b+1)/2;
	}
	return num;
}
int main()
{	
	int T,low,hi,N,len;

	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	scanf("%d",&T);
	for(int cnb=1;cnb<=T;cnb++)
	{
		scanf("%d%d",&low,&hi);
		N=hi-low+1;
		itoa(low,S,10);
		len=strlen(S);
		for(int i=0;i<N;i++)
		{
			itoa(low+i,S,10);
			trans(i,len);
		}
		printf("Case #%d: %lld\n",cnb,count(N));
	}
}