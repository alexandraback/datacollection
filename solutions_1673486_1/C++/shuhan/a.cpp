#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<iomanip>
using namespace std;
vector<double> p;
double calc(int k,int n){
	double hitClear=1+n+1;
	double hitGo=0;
	double allp=1;
	double ret=0;
	for(int i=0;i<p.size();++i){
		allp*=p[i];
	}
	hitGo=(n-k+1)*allp+(n-k+1+n+1)*(1-allp);
	ret=min(hitGo,hitClear);
	allp=1;
	for(int i=0;i<k;++i){
		double now=((k-i)+(n-i))+(1-allp)*(n+1)+1;
		allp*=p[i];	
		ret=min(ret,now);
	}
	return ret;
}
int main(){
	int k;
	int n;
	int T;
	cin>>T;
	for(int i=0;i<T;++i){
		cin>>k>>n;
		p.clear();
		for(int j=0;j<k;++j){
			double t;
			cin>>t;
			p.push_back(t);
		}
		 cout.setf(ios::showpoint);
		 cout.precision(7);
		cout<<"Case #"<<i+1<<": " <<calc(k,n)<<endl;
	}
}
