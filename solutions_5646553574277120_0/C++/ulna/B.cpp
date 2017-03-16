#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <algorithm>
#include <deque>
#include <vector>
#include <map>
#include <cmath>
#include <cstdlib>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <cstring>
#include <climits>
#include <ctype.h>
#include <utility>
using namespace std;

#define ft first
#define sd second
#define pb push_back
#define endl '\n'
#define cpy(a,e) memcpy(a,e,sizeof(e))
#define clr(a,e) memset(a,e,sizeof(a))
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define repd(i,n) for (int (i)=(n)-1;(i)>=0;i--)
#define reps(i,s,e) for (int (i)=(s);(i)<=(e);i++)
#define repds(i,s,e) for (int (i)=(s);(i)>=(e);i--)

struct node {
    bool used;int last,ac;
}dp[50055];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	ifstream fin;ofstream fout;
	fin.open("in.txt");fout.open("out.txt");
	int t,c,d,p;
	fin >> t;
	rep(l,t) {
		fin >> c >> d >> p;
		int res=0,v[1055];
		rep(i,d) fin >> v[i];
		for (;;) {
		clr(dp,0);
  		dp[0].used=1;
   		rep(i,d) {
      		reps(j,v[i],p) {
            	if (dp[j].used) continue;
            	if (dp[j-v[i]].used&&(dp[j-v[i]].last!=v[i]||dp[j-v[i]].ac<c)) {
                	dp[j].used=1;
                	if (dp[j-v[i]].last!=v[i]) {
                    	dp[j].ac=1;
                	} else dp[j].ac=dp[j-v[i]].ac+1;
                	dp[j].last=v[i];
            	}
        	}
   		}
   		bool update=0;
   		reps(i,1,p) {
   			if (dp[i].used) continue;
   			res++;update=1;
   			v[d++]=i;
   			break;
   		}
   		if (!update) break;
   		}
   		fout << "Case #" << l+1 << ": " << res << endl;
	}
	return 0;
}

