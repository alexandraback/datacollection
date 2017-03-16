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
#define debug(x) cout << #x << " = " << (x) << "\n"
typedef long long LL;

int main(){
	int t;
	cin >> t;
	FORE(z,1,t){
		int a, b;
		cin >> a >> b;
		LL ans = 0;
		FORE(n,a,b){
			char s[100];
			sprintf(s,"%d",n);
			int len = strlen(s);
			set<int> ms;
			FOR(i,0,len-1){
				rotate(s,s+1,s+len);
				int m;
				sscanf(s,"%d",&m);
				if (s[0]!='0' && n<m && m<=b)
					ms.insert(m);
			}
			ans += ms.size();
		}
		printf("Case #%d: %lld\n",z,ans);
	}
	return 0;
}
