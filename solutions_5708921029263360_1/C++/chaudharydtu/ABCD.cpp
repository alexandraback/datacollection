#include <iostream>
using namespace std;

int main() {
	int T,i,J,P,S,K,F,x,y,z,l;
	cin>>T;
	for(i=1;i<=T;i++)
	{
	    cin>>J>>P>>S>>K;
	    if(K<S)
	    F=J*P*K;
	    else
	    {
	        F=J*P*S;
	        K=S;
	    }
	    cout<<"Case #"<<i;
	    cout<<": "<<F<<"\n";
	    l=1;
	    for(x=1;x<=J;x++)
	    {
	        l=x;
	        for(y=1;y<=P;y++)
	        {
	            
	            for(z=1;z<=K;z++)
	            {
	               
	                cout<<x<<" "<<y<<" "<<l<<"\n";
	                if(l==S)
	                l=1;
	                else
	                l++;
	            }
	            
	            
	            
	        }
	        
	    }
	    
	    
	}
	
	
	
	
	return 0;
}
