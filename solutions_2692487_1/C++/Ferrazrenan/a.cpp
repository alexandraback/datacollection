#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cfloat>
#include <climits>
#include <cctype>
#include <cmath>
#include <cassert>
#include <ctime>

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <bitset>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define eps 1e-10
#define inf 0x3f3f3f3f

#define fr(x,y,z) for(int x = (y); x < (z); x++)

#define console cout
#define dbg(x) console << #x << " == " << x << endl
#define print(x) console << x << endl

int T;
long long M[111];
map<long long,long long> mem[111];
int iniSize;
int n;

void read(){
	scanf("%d %d",&iniSize,&n);
	for(int i = 0; i < n; i++){
		scanf("%lld",&M[i]);
		mem[i].clear();
	}
	sort(M,M+n);
}

int dp(int ind, long long s){
	
	if(ind == n){
		return 0;
	}
	else if(mem[ind].find(s) == mem[ind].end()){
		int mini;

		if(M[ind]  >= s)
			mini = dp(ind+1, s) + 1;
		else
			mini = dp(ind+1, s + M[ind]);

		if(s > 1){
			long long ss = s;
			int cc = 0;
			while(ss <= M[ind]){
				ss += ss-1;
				cc++;
			}
		
			int cost = dp(ind + 1, ss + M[ind]) + cc;
			if(mini > cost) mini = cost;
		}

		mem[ind][s] = mini;
	}
	
	return mem[ind][s];
}

void process(int c){
	printf("Case #%d: %d\n",c, dp(0,iniSize));
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("saida.txt","w",stdout);
	
	scanf("%d",&T);
	for(int i = 0; i < T; i++){
		read();
		process(i+1);
	}
	return 0;
}
