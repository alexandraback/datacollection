#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
using namespace std;
int main(){
	int t,te,i,j,k,a,b,typed,x;
	ifstream f1;
	ofstream f2;
	f1.open("input.txt");
	f2.open("output.txt");
	f1>>t;
	for(te=0;te<t;te++){
		f1>>a>>b>>k;
		int ans=0;
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				if((i&j)<k)ans++;
			}
		}
		f2<<"Case #"<<te+1<<": "<<ans<<"\n";
		cout<<"Case #"<<te+1<<": "<<ans<<"\n";
	}
	return 0;
}
