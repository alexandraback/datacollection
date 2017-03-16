#include <bits/stdc++.h>
using namespace std;
int t;
int x,r,c;
int main() {
	// your code goes here
	cin>>t;
	for(int cc=1;cc<=t;++cc)
	{
		cin>>x>>r>>c;
		if(r>c)swap(r,c);
		cout<<"Case #"<<cc<<": ";
		if(x>=2*r+1 || (r*c)%x || x>c)
		{
			cout<<"RICHARD"<<endl;
			continue;
		}
		if(x<2*r-1)
		{
			cout<<"GABRIEL"<<endl;
			continue;
		}
		if(x>=7)
		{
			cout<<"RICHARD"<<endl;
			continue;
		}
		if(x==1 || x==2 || x==3)
		{
			cout<<"GABRIEL"<<endl;
			continue;
		}
		if(x==4 && r==2)
		{
			cout<<"RICHARD"<<endl;
			continue;
		}	
		
		if(x==5 && r==3 && c>=10)
		{
			cout<<"GABRIEL"<<endl;
			continue;
		}	
		if(x==5 && r==3)
		{
			cout<<"RICHARD"<<endl;
			continue;
		}	

		if(x==6 && r==3)	
		{
			cout<<"RICHARD"<<endl;
			continue;
		}	

	}
	return 0;
}