#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <memory.h>

using namespace std;

set<pair<int,int> > r;
int main() {
	//freopen("input.txt", "r", stdin);
	freopen("d:\\Downloads\\C-large.in", "r", stdin);
	freopen("d:\\Downloads\\C-large.out", "w", stdout);

	for (int i=10; i<2000000; i++) {
		int mm =1000000;
		if (i<1000000) mm = 100000;
		if (i<100000)  mm = 10000;
		if (i<10000)   mm = 1000;
		if (i<1000)    mm = 100;
		if (i<100)     mm = 10;
		int k = i;
		for (int j=0; j<7; j++) {
			k = (k%mm)*10+(k/mm);
			if (k<i)
				r.insert(make_pair(k,i));
		}
	}
	//cout<<r.size()<<endl;
	int N; cin>>N; 
	for (int t=1; t<=N; t++) {
		int a,b,res=0; cin>>a>>b;
		set<pair<int,int> >::iterator i;
		for (i=r.begin(); i!=r.end(); i++) 
			if (a<=i->first && i->second<=b)
				res++;
		cout<<"Case #"<<t<<": "<<res<<"\n";
	}
	return 0;
}