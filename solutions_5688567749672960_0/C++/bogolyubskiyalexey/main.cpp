#include<iostream>
#include<algorithm>
using namespace std;

const int inf = 1000*1000*10;
int T[inf];

int rev(int n)
{
	int v = 0;
	while(n)
	{
		v = v*10+(n%10);
		n/=10;
	}
	return v;
}


void solve(int test)
{
	int N;
	scanf("%d",&N);
	printf("Case #%d: %d\n",test,T[N]);
	
}

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	T[1]=1;
	for(int i = 2; i <= inf; i++)
	{
		if(T[i])
		{
			T[i]=min(T[i],T[i-1]+1);
		}
		else T[i]= T[i-1]+1;
		int j = rev(i);
		if(j <= i) continue;
		if(T[j])
		{
			T[j] = min(T[j], T[i]+1);
		}
		else T[j]=T[i]+1;
	}
	int tt;
	scanf("%d",&tt);
	for(int i = 1; i<=tt;i++) solve(i);
	return 0;
}