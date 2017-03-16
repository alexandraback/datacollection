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
	int a[22];
	for (int i=0;i<20;i++){
		cin>>a[i];
	}
	for (unsigned int i=0;i<3486784401;i++){
		int aa=0,bb=0;
		for (int j=0,ii=i;j<20;j++,ii/=3){
			if (ii%3==1){
				aa+=a[j];
			}
			else{
				if (ii%3==2){
					bb+=a[j];
				}
			}
		}
		if (aa>0 && bb>0 && aa==bb){
			cout<<endl;
			for (int j=0,ii=i;j<20;j++,ii/=3){
				if (ii%3==1){
					cout<<a[j]<<' ';
				}
			}
			cout<<endl;
			for (int j=0,ii=i;j<20;j++,ii/=3){
				if (ii%3==2){
					cout<<a[j]<<' ';
				}
			}
			cout<<endl;
			return;
		}
	}
	cout<<"Impossible";
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