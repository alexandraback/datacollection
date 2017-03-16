#include<iostream>
using namespace std;

int main(){
	int t;
	cin>>t;
	cout.precision(8);
	cout.setf(ios::fixed);
	for(int i=1;i<=t;i++){
		double c,f,x;
		cin>>c>>f>>x;
		double l=0,m=x/2,r=2;
		while(1){
			l+=c/r;
			r+=f;
			if(l+x/r<m)
				m=l+x/r;
			else
				break;
		}
		cout<<"Case #"<<i<<": "<<m<<endl;
	}
	return 0;
}
