#include<iostream>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int iiii=1; iiii<=t; iiii++){
		int r, c, w;
		cin>>r>>c>>w;
		int min = c/w;
		min *= r;
		min += w;
		if(c%w == 0) min--;
		cout<<"Case #"<<iiii<<": "<<min<<endl;
	}
}
