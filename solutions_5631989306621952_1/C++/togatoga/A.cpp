#include <iostream>
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <numeric>
#include <sstream>
#include <algorithm>
#include <functional>
#include <limits.h>
#include <bitset>

#include <tuple>
#include <unordered_map>

#define mp       make_pair
#define mt       make_tuple
#define pb       push_back
#define rep(i,n) for(int i=0;i<(n);i++)

using namespace std;

typedef    long long          ll;
typedef    unsigned long long ull;
typedef    pair<int,int>      pii;

const int INF=1<<29;
const double EPS=1e-9;

const int dx[]={1,0,-1,0},dy[]={0,-1,0,1};
int T;

int main(){
	cin >> T;
	for (int case_id = 1; case_id <= T; case_id++){
		string S;
		cin >> S;
		string ans = "";
		ans += S[0];
		int N = S.size();
		for (int i = 1; i < N; i++){
			string f_tmp = S[i] + ans;
			string l_tmp = ans + S[i];
			if (f_tmp > l_tmp){
				ans = f_tmp;
			}else{
				ans = l_tmp;
			}
		}
		printf("Case #%d: %s\n", case_id, ans.c_str());
	}
	return 0;
}