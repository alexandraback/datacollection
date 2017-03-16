#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cstring>
using namespace std;
#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(int)(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=((int)(n)-1);i>=0;i--)

int n,k,dp[1 << 21];
int keys[128],needed[128];
vector<int> inchest[128];
const int INF = 100000;

int calc(int mask){
	int & v = dp[mask];
	if(v != -1) return v;
	if(mask == 0){
		v = 0;
		return 0;
	}

	int current[256];
	memset(current,0,sizeof(current));

	forn(i,k) current[keys[i]]++;
	forn(i,n){
		if(!(mask & (1 << i))){
			current[needed[i]]--;
			forn(j,inchest[i].size())
				current[inchest[i][j]]++;
		}
	}

	v = INF;	
	forn(i,n){
		if((mask & (1 << i)) && current[needed[i]] > 0){
			if(calc(mask ^ (1 << i)) != INF){
				v = i;
				break;
			}
		}
	}

	return v;
}

string solve()
{
	memset(dp,-1,sizeof(dp));
	int r = calc((1 << n)-1);
	if(r == INF) return "IMPOSSIBLE";
	string res = "";
	for(int start = (1 << n)-1; start > 0;){
		ostringstream ss;
		r = calc(start);
		ss << (1+r);
		start = start ^ (1 << r);
		res += ss.str();
	   	if(start) res += " ";
	}
	return res;
}

int main()
{
	int tcases; cin >> tcases;
	forsn(tcase,1,tcases+1){
		cin >> k >> n;
		forn(i,k) cin >> keys[i];
		forn(i,n){
			int t,m; cin >> t >> m;
			needed[i] = t;	
			inchest[i].clear();
			forn(j,m){ 
				int key; cin >> key;
				inchest[i].push_back(key);
			}
		}
		cout << "Case #" << tcase << ": " << solve() << endl;
	}
	return 0;
}
