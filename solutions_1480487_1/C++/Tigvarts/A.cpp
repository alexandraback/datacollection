#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int n;
int s[400];
int sum;

bool good(double v, int c){
	double ssum=sum;
	double val=ssum*v + (double)s[c];
	for (int i=0; i<n; ++i){
		if (val>(double)s[i]){
			ssum-=val-(double)s[i];
		}
	}
	return ssum<0;
}

void solve(){
	cin>>n;
	sum=0;
	for (int i=0; i<n; ++i)
		cin>>s[i], sum+=s[i];
	for (int i=0; i<n; ++i){
		double mn=0,mx=1;
		for (int st=0; st<100; ++st){
			double middle=(mn+mx)/2.0;
			if (good(middle, i))
				mx=middle;
			else
				mn=middle;
		}
		cout<<' '<<mx*100.0;
	}
	cout<<endl;
}

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin>>t;
	cout<<fixed<<setprecision(10);
	for (int i=1;i<=t; ++i){
		cout<<"Case #"<<i<<":";
		solve();
	}

}