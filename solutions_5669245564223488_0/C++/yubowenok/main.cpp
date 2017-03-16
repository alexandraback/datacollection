#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <sstream>
#include <complex>
#include <cassert>

using namespace std;

typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005

int N;
string car[15];
bool ap[26];
int main(){
	int cs;
	cin >> cs;
	REP(csn,1,cs+1){
		cerr << csn << endl;
		printf("Case #%d: ", csn);
		cin >> N;
		FILL(ap,0);
		REP(i,0,N){
			cin >> car[i];
			int len = car[i].length();
			REP(j,0,len) ap[car[i][j]-'a'] = 1;
		}
		int cnt = 0;
		REP(i,0,26) cnt += ap[i];
		int o[15];
		REP(i,0,N) o[i] = i;
			
		ll ans = 0;
		do{
			string x = "";
			REP(i,0,N) x += car[o[i]];
			x = x.substr(0, unique(x.begin(), x.end())-x.begin());
			if(x.length()==cnt) ans++;
		}while( next_permutation(o, o+N) );
		cout << ans << endl;
	}
	return 0;
}