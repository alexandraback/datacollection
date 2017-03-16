#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <fstream>
using namespace std;
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)

#define MAXN 2000002
vector< vector<int> > cache(MAXN+2);

int str2num(string s) {int num; stringstream ss(s); ss>>num;return num;}
string num2str(int i) {stringstream ss; ss<<i; return ss.str();}

void fill(int num){
	string s = num2str(num),t;
	int r;
	for(int i = s.size()-1; i>0; i--){
		t = s.substr(i);
		t += s.substr(0, i);
		r = str2num(t);
		if(r != num && t[0] != '0') 
			cache[num].push_back(r);
	}
}

void initialize(){
	for(int i = 10; i<MAXN; i++){
		fill(i);
		if(i%50000 == 0) cout << " i = " << i << endl;
	}
}

int main(){
	ifstream in("A.txt");
	ofstream out("result.txt");
	int T; 
	in >> T;

	int cant = 0;
	initialize();
	
	for(int test = 0; test<T; test++){
		set<pair<int,int> > tot;	
		int A,B;
		in >> A >> B;
		for(int i = A; i<=B; i++){
			for(int j = 0; j<cache[i].size(); j++){
				if(cache[i][j] >=A && cache[i][j] <=B) tot.insert(make_pair(MIN(i,cache[i][j]),MAX(i,cache[i][j])));
			}
		}
		int res = tot.size();
		out << "Case #" << test+1 << ": " << res << endl;
		cout << "Case #" << test+1 << ": " << res << endl;
	}

	return 0;
}