#include<iostream>
#include<vector>
using namespace std;

int main(){
	
	long int t,i1,i,j,r,c,w;
	cin>>t;
	
	for (i1=1;i1<=t;i1++){
		cin>>r;
		cin>>c;
		cin>>w;
		int dif = c-w;
		if (w==1)
			cout<<"Case #"<<i1<<": "<<c*r<<endl;
		else if (c == w)
						cout<<"Case #"<<i1<<": "<<c+(r-1)<<endl;
		else if(c-w <= w)
						cout<<"Case #"<<i1<<": "<<w+r<<endl;
		
		else {
			if(c%w==0)
				cout<<"Case #"<<i1<<": "<<(c/w)*r+(w-1)<<endl;
		
			else 		cout<<"Case #"<<i1<<": "<<(c/w)*r+w<<endl;
		}

	}
	


}

