#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int i,t,l,j,c,s,d;
    string A;
    cin>>t;
    for(i=0;i<t;++i)
    {
    	cin>>l;
    	cin>>A;
    	l++;
    	for(j=0;j<l;++j)
    		A[j] -= '0';
    	c = A[0];
    	s = 0;
    	for(j=1;j<l;++j)
    	{
    		d = j-c;
    		if(d>0)
    		{
    			s += d;
    			c += A[j]+d;
    		}
    		else
    		{
    			c += A[j];
    		}
    	}
    	cout<<"Case #"<<i+1<<": "<<s<<endl;
    }
    return 0;
}	