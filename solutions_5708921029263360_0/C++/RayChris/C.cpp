#include <string>
#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cmath>
#include <stack>
#include <fstream>

using namespace std;

#define PQ priority_queue
typedef long long LL;
typedef pair<LL,LL> pll;

int T,J,P,S,K,ans;
vector<int> v[3];
map<pair<int,int>,int> chk1;
map<pair<int,int>,int> chk2;
map<pair<int,int>,int> chk3;

bool ok1(int a,int b) {
	pair<int,int> Q = make_pair(a,b);
	if (chk1.count(Q)==0 || chk1[Q]<K) return true;
	return false;
}

bool ok2(int a,int b) {
	pair<int,int> Q = make_pair(a,b);
	if (chk2.count(Q)==0 || chk2[Q]<K) return true;
	return false;
}

bool ok3(int a,int b) {
	pair<int,int> Q = make_pair(a,b);
	if (chk3.count(Q)==0 || chk3[Q]<K) return true;
	return false;
}

int main() {
	ifstream F;
	F.open ("C-small-attempt0.in");
	ofstream O;
	O.open ("C-small-out.txt");

	F >> T;
	for (int i=1;i<=T;i++) {
		for (int j=0;j<3;j++) v[j].clear();
		chk1.clear();
		chk2.clear();
		chk3.clear();
		F >> J  >> P >> S >> K;
		ans = 0;
		for (int i1=1;i1<=J;i1++) {
			for (int i2=1;i2<=P;i2++) {
				for (int i3=1;i3<=S;i3++) {
					if (ok1(i1,i2) && ok2(i2,i3) && ok3(i1,i3)) {
						//O << "TEST\n";
						pair<int,int> Q;
						Q = make_pair(i1,i2);
						if (chk1.count(Q)==0) chk1[Q] = 1;
						else chk1[Q]++;
						//O << "[" << i1 << " " << i2 << " " << chk1[Q] << "]" << endl;
						Q = make_pair(i2,i3);
						if (chk2.count(Q)==0) chk2[Q] = 1;
						else chk2[Q]++;
						//O << "[" << i2 << " " << i3 << " " << chk2[Q] << "]" << endl;
						Q = make_pair(i1,i3);
						if (chk3.count(Q)==0) chk3[Q] = 1;
						else chk3[Q]++;
						//O << "[" << i1 << " " << i3 << " " << chk3[Q] << "]" << endl;
						v[0].push_back(i1);
						v[1].push_back(i2);
						v[2].push_back(i3);
						ans++;
					}
				}
			}
		}
		O << "Case #" << i << ": " << ans << endl;
		for (int j=0;j<v[0].size();j++) {
			for (int k=0;k<3;k++) {
				if (k>0) O << " ";
				O << v[k][j];
			}
			O << endl;
		}
	}
	return 0;
}
