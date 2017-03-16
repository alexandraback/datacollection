#include <bits/stdc++.h>
using namespace std;

 
 
 
int d[1000007];

int qu[3000007];
int qb,qe;


int rev(int x)
{
	int ret=0;
	while(x!=0)
	{
		ret=ret*10+(x%10);
		x/=10;
	}
	return ret;
}

void go(int x,int w)
{
	if(x>1000000)return;
	if(d[x]!=0)return;
	d[x]=w; 
	qu[qe]=x;qe++;
}

int main()
{ 
	int i,n,t;
	
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	 
	 
	 
	for(i=1;i<=1000000;i++)d[i]=0;
	 
	d[1]=1;
	qu[0]=1;qb=0;qe=1;
	
	
	while(qb!=qe)
	{
		t = qu[qb];qb++;
		 
		
		go(t+1,d[t]+1);
		go(rev(t),d[t]+1);
	} 
	
	cin>>t;
	 
	for(i=1;i<=t;i++)
	{
		cin>>n;
		printf("Case #%d: %d\n",i,d[n]);
	}



}
