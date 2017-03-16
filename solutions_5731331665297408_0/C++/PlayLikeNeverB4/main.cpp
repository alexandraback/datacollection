#include <cstdio>
#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <string>
#include <ctime>
#include <cassert>
#include <utility>

using namespace std;

#define MAXN 8

int T, N, M, a, b;
bool A[MAXN][MAXN];
string S[MAXN];
string mem[1 << MAXN];

bool ok(int mask, int t) {
    for(int i = 0; i < N; i++)
        if((mask & (1 << i)) > 0 && A[i][t])
            return true;
    return false;
}

string go(int mask) {
    if(mem[mask].size() > 0)
        return mem[mask];
    if(mask == (1 << N) - 1)
        return "";
    
    string ret = "" + (char)('9' + 1);
    for(int i = 0; i < N; i++)
        if(mask == 0 || ((mask & (1 << i)) == 0 && ok(mask, i))) {
            ret = min(ret, S[i] + go(mask | (1 << i)));
        }
    
    mem[mask] = ret;
    return ret;
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
	
	cin >> T;
	for(int t = 1; t <= T; t++) {
	    cin >> N >> M;
        for(int i = 0; i < N; i++)
            cin >> S[i];
        memset(A, false, sizeof(A));
        for(int i = 0; i < M; i++) {
            cin >> a >> b;
            a--; b--;
            A[a][b] = A[b][a] = true;
        }
	    
//        for(int mask = 0; mask < (1 << N); mask++)
//            mem[mask] = "";
//        
//        string ans = go(0);
        string ans = "" + (char)('9' + 1);
        
        vector<int> P(N, 0);
        for(int i = 0; i < N; i++)
            P[i] = i;
        stack<int> st;
        do {
            while(st.size() > 0)
                st.pop();
            st.push(P[0]);
            string crt = S[P[0]];
            bool ok = true;
            for(int i = 1; i < N && ok; i++) {
                int next = P[i];
                bool found = false;
                do {
                    int t = st.top();
                    if(A[t][next]) {
                        st.push(next);
                        crt += S[next];
                        found = true;
                    }
                    else
                        st.pop();
                } while(st.size() > 0 && !found);
                if(!found)
                    ok = false;
            }
            if(ok)
                ans = min(ans, crt);
        } while(next_permutation(P.begin(), P.end()));

        cout << "Case #" << t << ": " << ans << '\n';
	}
	
	return 0;
}
