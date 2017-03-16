#include<bits/stdc++.h>
using namespace std;

int DP[1000001];

int revFunc(int x)
{
    int y=0;
    int c=x;
    while(c%10==0)
	return x-1;
    while(c>0)
    {
	y=y*10+c%10;
	c/=10;
    }
    if(y<x)
	return y;
    return x-1;
}

int main()
{
    int T;cin>>T;for(int t=0;t<T;t++)
    {
	long long int N;cin>>N;

	//cout<<revFunc(N)<<endl;

	DP[1]=1;
	for(int i=2;i<=N;i++)
	{
	    DP[i]=min(DP[i-1],DP[revFunc(i)])+1;
	    //cout<<i<<" "<<DP[i]<<endl;
	}
	cout<<"Case #"<<t+1<<": "<<DP[N]<<endl;
    }
    return 0;
}
