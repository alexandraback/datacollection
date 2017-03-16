#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long ll;
#define INF (1<<29)

int main(){
	int T, i, tc;
	string s, u="yhesocvxduiglbkrztnwjpfmaq", t;
	cin >> T;
	getline(cin,s);
	for(tc=1;tc<=T;tc++){
		t="";
		getline(cin,s);
		REP(i,s.length()){
			if(s[i]!=' ')t+=u[s[i]-'a'];
			else t+=" ";
		}
		printf("Case #%d: ",tc);
		cout << t << endl;
	}
	return 0;
}

