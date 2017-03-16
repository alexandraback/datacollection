#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<string.h>
#include<vector>
#include<math.h>
#include<limits.h>
#include<deque>
#define si(n) scanf("%d",&n)
#define sl(n) scanf("%lld",&n)
#define ss(n) scanf("%s",n)
#define sf(n) scanf("%f",&n)

#define pi(n) printf("%d\n",n)
#define pl(n) printf("%lld\n",n)
#define ps(n) printf("%s\n",n)
#define pf(n) printf("%f\n",n)

#define ll long long int
#define r0 return 0
#define INF INT_MAX
#define FR(i,a,b) for(i=a;i<b;i++)
#define decit int i,j,k
int M=1000000000+7;
using namespace std;

ll b[50],glb=0;
ll bin(ll n,ll B)
{
	int i=0,j;
	ll x=1,tmp=n;
	while(n && i<B-2)
	{
		b[i++]=n%2;
		n=n>>1;
		//cout<<n<<endl;
		x=x*2;
	}
	//cout<<"hi"<<endl;
/*	FR(j,0,i)
		cout<<b[j];
	cout<<" ff "<<n<<endl;
*/
	if(tmp==x)
		{glb=1;return 1;}
	if(n!=0)
		return -1;
	return 1;
}

int main()
{
    int t,it;
    decit;
    si(t);
    FR(it,1,t+1)
    {
		ll ans[100][100];
        ll B,M;
        cin>>B>>M;
        FR(i,0,B+1)
        	b[i]=0;
    	glb=0;
    	int flag=bin(M,B);
    	cout<<"Case #"<<it<<": ";
	    
    	if(flag==-1)
    	{cout<<"IMPOSSIBLE\n";continue;}
      	else
      		cout<<"POSSIBLE\n";
      	FR(i,0,B)
      	{
      		FR(j,0,B)
      		{
      			ans[i][j]=0;
      		}
      	}
      	FR(i,1,B-1)
      	{
      		FR(j,i+1,B)
      		{
      			ans[i][j]=1;
      		}
      	} 
      	FR(i,0,B-2)
      	{
      		ans[0][B-2-i]=b[i];
     	}
     	if(glb==1)
     	{
			FR(i,1,B)
      		{
      			ans[0][i]=1;
     		}
     	}
     	FR(i,0,B)
      	{
      		FR(j,0,B)
      		{
      			cout<<ans[i][j];
      		}
      		cout<<endl;
      	}
    }
    return 0;
}