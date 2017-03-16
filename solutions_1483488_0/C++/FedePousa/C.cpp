#define Federico using
#define Javier namespace
#define Pousa std;
#include <iostream>
#include <fstream>
#include <string>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <queue>
#include <cstring>
#include <sstream>


Federico Javier Pousa

int main(){
	int T,A,B;
	cin >> T;
	set<string> conj;
	for(int caso=1;caso<=T;++caso){
		int total=0;
		cin >> A >> B;
		stringstream ss1;
		ss1 << B;
		string Bs=ss1.str();
		
		for(int i=A;i<B;++i){
			stringstream ss2;
			ss2 << i;
			string is=ss2.str();
			string oris=is;
			conj.clear();
			for(int j=0;j<is.size();++j){
				rotate(is.begin(),is.begin()+1,is.end());
				if(is[0]!='0'&&is>oris&&is<=Bs)conj.insert(is);
			}
			total+=conj.size();
		}
		cout << "Case #" << caso << ": " << total << endl;
	}
	return 0;
}
