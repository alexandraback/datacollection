#include <iostream>
#include <math.h>
using namespace std;
 
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,i,r,c,w,d,e;
	cin>>t;
	for(i=1;i<=t;i++)
	{
			cin>>r;
			cin>>c;
			cin>>w;
			if (c==w)
			  cout<<"Case #"<<i<<": "<<(c+r-1)<<endl;
			//else if((r==1)&&(c!=w))
			  //cout<<"Case #"<<i<<": "<<(c-w+1)<<endl;
			else
			 {
			 	if((c%w)==0)
			 	{
			 	  d=c/w;
			 	  e=r*d;
			 	  cout<<"Case #"<<i<<": "<<(e+w-1)<<endl;
			    }
			 	else
			 	{
				  d=c/w;  
			 	  e=r*d;
			 	  cout<<"Case #"<<i<<": "<<(e+w)<<endl;
			    }
             }
    }
	return 0;
}
