//property of varun hasija
#include<bits/stdc++.h>
using namespace std;
#define ll long long
inline void input(ll &N)
{
	ll ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();
    if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;
	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');
	N*=sign;

	return;
}
inline void Input(int &N)
{
	int ch,sign;
	N=0;

	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF)
		ch=getchar();
    if(ch=='-')
		sign=-1,ch=getchar();
	else
		sign=1;
	do
		N=(N<<3)+(N<<1)+(ch-'0');
	while((ch=getchar())>='0' && ch<='9');
	N*=sign;
	return;
}
#define max 1000001
int dp[max];
int inverse(int number)
{
     int t=0;
     for( ; number!= 0 ; )
   {
      t = t * 10;
      t = t + number%10;
      number = number/10;
   }
   return t;
}
int main()
{
    freopen("A-small-attempt0(1).in", "r",stdin);
     freopen("mm_op2.txt", "w" ,stdout);

	int i;
	for(i=1;i<=max;i++)
	{
		if(i%10==0)
		dp[i]=1+dp[i-1];
		else
		dp[i]=1+min(dp[i-1],inverse(i)<i?dp[inverse(i)]:max);
	}
    int t;
    Input(t);
    int z=t;
    while(t--)
    {
        int x;
        Input(x);
        if(x<=20)
        cout<<"Case #"<<z-t<<": "<<x<<"\n";
        else
        {
        	cout<<"Case #"<<z-t<<": "<<dp[x]<<"\n";
        }
    }
}
