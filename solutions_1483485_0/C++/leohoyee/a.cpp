#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional> 
#include <numeric>
using namespace std;
#define foreach(i,v) for(__typeof((v).end()) i=(v).begin();i!=(v).end();++i)
#define rforeach(i,v) for(__typeof((v).rend()) i=(v).rbegin();i!=(v).rend();++i)
#define FOR(i,b,e) for(int i=(b);i<(e);++i)
#define FORE(i,b,e) for(int i=(b);i<=(e);++i)
#define debug(x) cerr << #x << " = " << (x) << "\n"
typedef long long LL;

int main(){

	string in = "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
	string out= "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

	int t;
	cin >> t;
	string s;
	getline(cin,s);
	FORE(z,1,t){
		getline(cin,s);
		FOR(i,0,s.length()){
			if (s[i]=='q') s[i]='z';
			else if (s[i]=='z') s[i]='q';
			FOR(r,0,in.length())
				if (s[i]==in[r]){
					s[i]=out[r];
					break;
				}
		}
		printf("Case #%d: %s\n",z,s.c_str());
	}
	return 0;
}
