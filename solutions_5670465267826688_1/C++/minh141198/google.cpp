#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

typedef pair <bool, char> bc;

#define X first
#define Y second

bc mul(char a, char b){
    if(a == '1') return bc(0, b);
    if(b == '1') return bc(0, a);
    if(a == b) return bc(1, '1');
    string s;
    s += a;
    s += b;
    if(s == "ij") return bc(0, 'k');
    if(s == "ik") return bc(1, 'j');
    if(s == "ji") return bc(1, 'k');
    if(s == "jk") return bc(0, 'i');
    if(s == "ki") return bc(0, 'j');
    if(s == "kj") return bc(1, 'i');
}

bc operator * (const bc &x, const bc &y){
    bc z = mul(x.Y, y.Y);
    return bc(x.X ^ y.X ^ z.X, z.Y);
}

bc Pow(bc a, long long b){
    if(b == 0) return bc(0, '1');
    bc tmp = Pow(a, b/2);
    if(b%2) return tmp*tmp*a;
    return tmp*tmp;
}

const int N = 10004;
char s[N];
int n, b[4][2], in[256];
string abc = "1ijk";
long long x;

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int tc;
    scanf("%d", &tc);
    for(int cs = 1; cs <= tc; cs ++){
        scanf("%d %lld", &n, &x);
        scanf("%s", s);
        set <bc> st;
        bc cur(0, '1');
        memset(b, 0x3f, sizeof b);
        for(int i = 0; i < n; i ++){
            for(int j = 0; j < 4; j ++)
                for(int k = 0; k < 2; k ++) if(bc(k, abc[j]) * cur == bc(0, 'i'))
                    b[j][k] = min(b[j][k], i);
            cur = cur * bc(0, s[i]);
        }

        bc all = cur;
        cur = bc(0, '1');
        long long l = (long long) 1e17, r = (long long) 1e17;
        for(int i = 0; i < 4; i ++) in[abc[i]] = i;
        for(int i = 0; i < 10; i ++){
            if(b[in[cur.Y]][cur.X] < n){
                l = i*n + b[in[cur.Y]][cur.X];
                break;
            }
            st.insert(cur);
            cur = cur * all;
            if(st.find(cur) != st.end()) break;
        }
        st.clear();

        memset(b, 0xff, sizeof b);

        cur = bc(0, '1');
        for(int i = n-1; i >= 0; i --){
            for(int j = 0; j < 4; j ++)
                for(int k = 0; k < 2; k ++) if(cur * bc(k, abc[j]) == bc(0, 'k'))
                    b[j][k] = max(b[j][k], i);
            cur = bc(0, s[i]) * cur;
        }


        cur = bc(0, '1');
        for(int i = 0; i < 10; i ++){
            if(b[in[cur.Y]][cur.X] >= 0){
                r = i*n + n - 1 - b[in[cur.Y]][cur.X];
                break;
            }
            st.insert(cur);
            cur = all * cur;
            if(st.find(cur) != st.end()) break;
        }
        if(l + r <= x*n && Pow(all, x) == bc(1, '1')) printf("Case #%d: YES\n", cs);
        else printf("Case #%d: NO\n", cs);
    }
    return 0;
}
