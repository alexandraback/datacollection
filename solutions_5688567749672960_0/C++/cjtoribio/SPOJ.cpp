#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <list>
#include <bitset>
#include <deque>
#include <numeric>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cmath>
#include <climits>
#include <sys/time.h>

using namespace std;
typedef long long Long;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;

int dp[10000010];
string tos(int n){
	char ca[20];
	sprintf(ca, "%d", n);
	string a = ca;
	return a;
}
int toi(string n){
	if(n == "")return 0;
	int a;
	sscanf(n.c_str(), "%d", &a);
	return a;
}
string rev(string n){
	reverse(n.begin(),n.end());
	return n;
}
void bfs(int src){
	queue<int> Q;
	Q.push(src);
	memset(dp,-1,sizeof(dp));
	dp[src] = 0;
	while(Q.size()){
		int c = Q.front(); Q.pop();
		int n1 = toi(rev(tos(c)));
		if(n1 < 10000000 && dp[n1] == -1){
			dp[n1] = dp[c]+1;
			Q.push(n1);
		}
		int n2 = c + 1;
		if(n2 < 10000000 && dp[n2] == -1){
			dp[n2] = dp[c]+1;
			Q.push(n2);
		}
	}
	
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	bfs(0);
	int TC;
	cin >> TC;
	for(int tc = 1 ; tc<=TC; ++tc){
		int N;
		cin >> N;
		cout << "Case #" << tc << ": " << dp[N] << endl;
	}
}
