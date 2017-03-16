#include <iostream>
#include <vector>
#include <set>
using namespace std;
using vi=vector<int>;
int compute(vi& p,int h){
	int r=h;
	for(int i=0;i<(int)p.size();i++)
		r+=(p[i]-1)/h;
	return r;
}
int main(){
	int T;
	cin>>T;
	for(int t=1,d;t<=T;t++){
		cin>>d;
		vi p(d);
		for(int i=0;i<d;i++)
			cin>>p[i];
		int r=1001;
		for(int h=1;h<=1000;h++)
			r=min(r,compute(p,h));
		cout<<"Case #"<<t<<": "<<r<<'\n';
	}
}
