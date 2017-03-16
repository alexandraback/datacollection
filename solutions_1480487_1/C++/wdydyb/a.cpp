#include<iostream>
#include<complex>
#include<cstring>
#include<sstream>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<vector>
#include<string>
#include<deque>
#include<stack>
#include<queue>
#include<set>
#include<map>
#include<list>
#include<functional>
#include<algorithm>
using namespace std;
int main(){
	int t;
	cin>>t;
	int cnt=1;
	while(t--){
		int n;
		cin>>n;
		vector<double> v(n);
		double x=0;
		for(int i=0;i<n;i++){
			cin>>v[i];
			x+=v[i];
		}
		//double stan=2*x/(double)n;
		double y=x*2/(double)n;
		vector<bool> c(n);
		double x2=0;
		double nn=0;
		for(int i=0;i<n;i++){
			if(y<v[i])
			c[i]=true;
			else{
				x2+=v[i];
				nn++;
			}
		}
		double z=0;
		double y2=(x2+x)/(double)nn;
		cout<<"Case #"<<cnt++<<":";
		//cout<<y<<endl;
		for(int i=0;i<n;i++){
			if(c[i])
			printf(" %.6lf",z);
			else
			printf(" %.6lf",100*(y2-v[i])/x);
			//cout<<" "<<100*(y-v[i])/x;
		}
		cout<<endl;
	}
	return 0;
}