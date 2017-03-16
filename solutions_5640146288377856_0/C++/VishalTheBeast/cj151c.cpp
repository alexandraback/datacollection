#include <bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,l;
    int t,v;
    cin>>t;
    for(v=0;v<t;v++)
    {
    	cin>>i>>j>>k;
    	l=0;
    	if(k==1)
    		l=i*j;
    	else if(j==k)
    		l=j;
    	else
    	{
    		if(j%k==0)
    			l--;
    		l+=(j/k);
    		l+=(k);
    	}
    	cout<<"Case #"<<v+1<<": "<<l<<endl;
    }
	return 0;
}