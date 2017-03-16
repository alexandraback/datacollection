#include <bits/stdc++.h>
using namespace std;
int mem[1000010];
int main()
{
    int t,i,j,k,l;
    cin>>t;
    int ip;
    mem[1]=1;
    for(i=0;i<1000005;i++)
    	mem[i]=1000100;
    mem[1]=1;
    for(i=2;i<1000010;i++)
    {
    	mem[i]=min(i,mem[i]);
    	mem[i+1]=min(mem[i+1],mem[i]+1);
    	j=i;
    	k=0;
    	while(j>0)
    	{
    		k=k*10+(j%10);
    		j/=10;
    	}    
    	if(k<=1000000)
    	mem[k]=min(mem[k],mem[i]+1);
  //  	cout<<k<<" "<<mem[k]<<endl;
    }
    for(i=0;i<t;i++)
    {
    	cin>>ip;
    	cout<<"Case #"<<i+1<<": "<<mem[ip]<<endl;
    }
	return 0;
}