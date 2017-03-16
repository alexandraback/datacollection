#include <bits/stdc++.h>
using namespace std;
int A[20],mem[45],taken[45];
int bitsin(int a)
{
	int b=0,c,d;
	while(a>0)
	{
		if(a%2==1)
			b++;
		a/=2;
	}
	return b;
}
int main()
{
/*	#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
	#endif
  */  int x,y,z;
    int t,i,m,j,k,l,n,o,p,q,r,s;
    cin>>t;
    for(i=0;i<t;i++)
    {
    	cin>>j>>k>>l;
    	memset(mem,0,sizeof(mem));
    	memset(taken,0,sizeof(taken));
    	for(m=0;m<k;m++)
    	{
    		cin>>A[m];
    		taken[A[m]]=1;
    	}
    	int ini=k;
    	for(m=1;m<=10;m++)
    	{
    		if(taken[m]==0)
    			A[k++]=m;
    	}
    	n=1<<k;
    	s=100;
    	for(x=0;x<(1<<(k-ini));x++)
    	{
    		//cout<<x<<endl;
    		r=bitsin(x)+ini;
    		memset(mem,0,sizeof(mem));
    		for(o=1;o<n;o++)
    		{
    			q=0;
	    		for(p=0;p<k;p++)
	    		{
	    			if(o&(1<<p)&&(p<ini||(p>=ini&&(x&(1<<(p-ini))))))
	    			{
	    				q+=A[p];
	    			}
	    		}
	    	//	if(x==3)
	    	//	cout<<o<<" "<<q<<endl;
	    		if(q<=l)
	    		mem[q]=1;
	    	}
    		for(o=1;o<=l;o++)
    			if(mem[o]==0)
    				break;
    	//	cout<<o<<" "<<r<<endl;
    		if(o>l)
    			s=min(s,r-ini);
    	}
    	cout<<"Case #"<<i+1<<": "<<s<<endl;
    }
	return 0;
}