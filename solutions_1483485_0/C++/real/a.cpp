#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cctype>
#include <numeric>
#include <queue>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <iterator>
#define FOR(i,s,e) for(int i=(s);i<(int)(e);i++)
#define FOE(i,s,e) for(int i=(s);i<=(int)(e);i++)
#define ALL(x) (x).begin(), (x).end()
#define CLR(s) memset(s,0,sizeof(s))
#define PB push_back
#define ITER(v)      __typeof((v).begin())
#define FOREACH(i,v) for(ITER(v) i=(v).begin();i!=(v).end();i++)
using namespace std;
typedef long long LL;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
#define x first
#define y second

char s[1000];
char mp[1000] = "yhesocvxduiglbkrztnwjpfmaq";

int main() {
	int t; scanf("%d", &t); gets(s); FOE(ca,1,t) {	
		gets(s);
		printf("Case #%d: ", ca);		
		for (int i = 0; s[i]; i++) {
			if (s[i] != ' ') s[i] = mp[s[i]-'a'];
		}
		puts(s);
	}
	return 0;
}
