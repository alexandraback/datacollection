#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int t,i,x,r,c;
    bool a;
    cin>>t;
    for(i=0;i<t;i++)
    {
    	cin>>x>>r>>c;
    	a = true;
    	if(x>=7)
    		a = false;
    	else if(x>r && x>c)
    		a = false;
    	else if((r*c)%x)
    		a = false;
    	else if((x+1)/2>min(r,c))
    		a = false;
    	else if(x<3)
    		a = true;
    	else if(x==4)
    		a = (min(r,c)>2);
    	else if(x==5)
    		a = !(min(r,c)==3 && max(r,c)==5);
    	else if(x==6)
    		a = (min(r,c)>3);
    	cout<<"Case #"<<i+1<<": ";
    	if(a)
    		cout<<"GABRIEL";
    	else
    		cout<<"RICHARD";
    	cout<<endl;
    }
    return 0;
}	
