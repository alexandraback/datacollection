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

int T, A, B, K;

int solveBrute() {
    int ans = 0;
    for(int a = 0; a < A; a++)
        for(int b = 0; b < B; b++)
            if((a & b) < K)
                ans++;
    return ans;
}

long long mem[60][2][2][2];
long long go(int p, bool sa, bool sb, bool sk) {
    if(p == -1)
        return sk && sa && sb;
    if(mem[p][sa][sb][sk] > -1)
        return mem[p][sa][sb][sk];
    
    bool a = (A & (1LL << p)) > 0;
    bool b = (B & (1LL << p)) > 0;
    bool k = (K & (1LL << p)) > 0;
    
    if(sk && sa && sb) {
        return (1LL << (2 * p + 2));
    }
    
    long long ret = 0;
    for(int ta = 0; ta < 2; ta++)
        for(int tb = 0; tb < 2; tb++) {
            if(ta > a && !sa) continue;
            if(tb > b && !sb) continue;
            int tk = (ta & tb);
            if(tk > k && !sk) continue;
            
            bool nsa = sa || (ta < a);
            bool nsb = sb || (tb < b);
            bool nsk = sk || (tk < k);
            ret += go(p - 1, nsa, nsb, nsk);
        }
    
    mem[p][sa][sb][sk] = ret;
    return ret;
}

long long solve() {
    int len = 40;
    while((K & (1LL << len)) == 0 && (A & (1LL << len)) == 0 && (B & (1LL << len)) == 0) 
        len--;
    
    for(int i = 0; i <= len; i++)
        for(int a = 0; a < 2; a++)
            for(int b = 0; b < 2; b++)
                for(int k = 0; k < 2; k++)
                    mem[i][a][b][k] = -1;
    long long ans = go(len, false, false, false);
    return ans;
}

int main() {
	freopen("date.in", "r", stdin);
	freopen("date.out","w", stdout);
	
	scanf("%d", &T);
	for(int t = 1; t <= T; t++) {
	    scanf("%d %d %d", &A, &B, &K);
//        int ans = solveBrute();
        long long ans2 = solve(); 
//        printf("Case #%d: %d\n", t, ans);
        printf("Case #%d: %I64d\n", t, ans2);
	}
	
	return 0;
}
