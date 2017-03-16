#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <map>
#include <set> 
#include <sstream>
#include <fstream>
#include <utility>
#include <string>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
#define REP(i,a) for(int i=0;i<a;i++)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORD(i,a,b) for(int i=a;i>=b;i--)
#define FOREACH(it,c) for(typeof((c).begin()) it=(c).begin();it!=(c).end();++it)
#define SIZE(c) (int)c.size()
#define ALL(c) (c).begin(),(c).end() 
typedef pair<int, int> PII;
const int INF = 1000000000;
vector<string> words[15];
string str;
map<PII, int> m;
int go(int idx, int last){
	if(last < idx - 6) last = idx - 6;
	if(m.find(PII(idx, last)) != m.end()) return m[PII(idx, last)];
	if(idx == SIZE(str)){
		return 0;
	}
	int ret = INF;
	for(int i = idx; i < SIZE(str); i ++){
		int len = i - idx + 1;		
		if(len > 10) break;
		for(int j = 0; j < SIZE(words[len]); j ++){
			int lst = last, need = 0;
			bool ok = true;
			for(int k = 0; k < len; k ++){
				if(str[k + idx] != words[len][j][k]){
					if(idx + k >= lst + 5){
						lst = idx + k;
						need ++;
					}
					else{
						ok = false;
						break;
					}
				}
			}
			if(ok){
				ret = min(ret, need + go(idx + len, lst));
			}
		}
	}
	return m[PII(idx, last)] = ret;
}
int main() {
	ifstream fin("dict.txt");
	//freopen("c.in", "r", stdin); 
	freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	//freopen("C-small-attempt1.in", "r", stdin); freopen("C-small-attempt1.out", "w", stdout);
	//freopen("C-small-attempt2.in", "r", stdin); freopen("C-small-attempt2.out", "w", stdout);
	//freopen("C-small-attempt3.in", "r", stdin); freopen("C-small-attempt3.out", "w", stdout);
	
	//freopen("C-large.in", "r", stdin); freopen("C-large.out", "w", stdout);
	string w;
	int c = 0;
	while(fin>>w){
		words[SIZE(w)].push_back(w);
		c ++;
	}
	int nT;
	cin>>nT;
	for (int t=1; t<=nT; t++) {
		cin>>str;
		m.clear();
		cout<<"Case #"<<t<<": "<<go(0, -10)<<endl;
	}
	return 0;
}
