#include <iostream>
#include <fstream>
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;


inline int length(int a){
	int rez = 0;
	while(a>0){ a/=10; rez++; }
	return rez;
}

int f[]={0,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
set<int> all;
set<int> distinct;

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int a, b;
		cin>>a>>b;
		long long rez = 0;
		all.clear();
		for(int z=a; z<=b; z++){
			if(all.find(z)!=all.end()) continue;
			int len = length(z);
			int c = z;
			distinct.clear();
			distinct.insert(c);
			for(int k=1; k<len; k++){
				int dg = c%10;
				c/=10;
				dg*=f[len-1];
				c+=dg;
				if(a<=c && c<=b) distinct.insert(c);
			}
			long long tmp = distinct.size();
			rez+=(tmp*(tmp-1)/2);
			all.insert(distinct.begin(),distinct.end());
		}
		cout<<"Case #"<<testnum+1<<": "<<rez<<endl;
	}
	return 0;
}
