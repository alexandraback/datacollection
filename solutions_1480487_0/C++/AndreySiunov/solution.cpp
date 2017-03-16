#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <list>
#include <string>
#include <algorithm>
#include <set>
#include <cmath>
#include <vector>
#include <map>
#include <iterator>
#include <sstream>
#include <list>
#include <set>
#include <stack>
#include <bitset>
#include <ctime>

#pragma comment(linker, "/STACK:256000000")

#define EPS 1e-7
#define PI 3.1415926535897932384626433832795

using namespace std;

int aabs(int a){
	if (a<0) return -a;
	return a;
}

int gcd(int a, int b){
	while (a>0 && b>0){
		if (a>b){
			a%=b;
		}
		else{
			b%=a;
		}
	}
	return a+b;
}

void calc(){
	int n;
	cin>>n;
	double a[213],s=0;
	for (int i=0;i<n;i++){
		cin>>a[i];
		s+=a[i];
	}
	cout.setf(ios::fixed);
	cout.precision(5);
	for (int i=0;i<n;i++){
		double l=0,r=1;
		for (int j=0;j<100;j++){
			double m=(l+r)/2;
			bool pp=0;
			double mm=0;
			for (int k=0;k<n;k++){
				if (k!=i){
					if (a[i]+s*m-a[k]>0){
						mm+=(a[i]+s*m-a[k])/s;
					}
				}
			}
			if (mm+m>1){
				r=m;
			}
			else{
				l=m;
			}
		}
		cout<<l*100<<' ';
	}
	cout<<endl;
}

int main(){
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);

	//begin code
	//ios::sync_with_stdio(0);
	int t;
	cin>>t;
	for (int i=1;i<=t;i++){
		cout<<"Case #"<<i<<": ";
		calc();
	}
	//end code

	return 0;
}