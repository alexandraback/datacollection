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
string str;
string in[5], out[5];
char match[30];
char conv[] = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
/*void crack(){
	REP(i, 3) getline(cin, str), in[i] = str;
	getline(cin, str);
	REP(i, 3) getline(cin, str), out[i] = str;
	REP(i, 30) match[i] = 'A';
	REP(i, 3){
		istringstream iss(in[i]);
		istringstream iss2(out[i]);
		string a, b;
		while(iss>>a){
			iss2>>b;
			REP(j, SIZE(a)){
				match[a[j] - 'a'] = b[j]; 
			}
		}
	}
	for(char c = 'a'; c <= 'z'; c ++){
		cout<<match[c - 'a']<<",";
	}
}*/
int main() {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("a-small.out", "w", stdout);
	//crack();
	int T;
	cin>>T;
	getline(cin, str);
	for(int t = 1; t <= T; t ++){
		getline(cin, str);
		cout<<"Case #"<<t<<": ";
		REP(i, SIZE(str)){
			if(str[i] != ' ') str[i] = conv[str[i] - 'a'];
			cout<<str[i];
		}
		cout<<endl;
	}
	return 0;
}
