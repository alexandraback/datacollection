#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
	int t, i, j, k;
	long long p, q;
	char c;

	cin>>t;
	for (i = 1; i <= t; ++i){
		cin>>p>>c>>q;

		j=0;
		while(!(q&1)){
			++j;
			q>>=1;
		}

		cout<<"Case #"<<i<<": ";
		if(p%q==0){
			k=0;
			p/=q;
			while(p>0){
				++k;
				p>>=1;
			}
			cout<<j-k+1<<endl;
		} 
		else cout<<"impossible"<<endl;
	}
	
	return 0;
}