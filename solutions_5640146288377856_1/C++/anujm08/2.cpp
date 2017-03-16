#include <iostream>
using namespace std;


int main()
{
	int T,t=1,C,R,W,ans,lambda;
	cin>>T;
	while(t<=T)
	{
		cin>>R>>C>>W;
		if((C+1)%W==0)
			lambda = (C+1)/W-1;
		else
			lambda = (C+1)/W;
		ans= R*lambda + W-1;
		if(C%W)
			ans+=1;
		cout<<"Case #"<<t<<": "<<ans<<endl; 
		t++;
	}
	return 0;
}
