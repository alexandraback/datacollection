#include <string>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cctype>
#include <queue>
#include <climits>
#include <sstream>
#include <cassert>
#include <iostream>
#include <cstdio>
#include <iostream>
using namespace std;

#define REP(i,n) for(int i=0; i<(n); i++)
#define FOR_EACH(it,v) for(__typeof((v).begin()) it = (v).begin(); it!=(v).end(); ++it)
#define show(x) cout << #x << ": " << x << endl;

template<typename T>
ostream& operator<<(ostream &o, const vector<T>&v){
    FOR_EACH(x, v){
        if(x==v.begin()) o << "[";
        else o << ", ";
        o << *x;
    }
    o << "]";
    return o;
}

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int>VI;
typedef vector<vector<int> >VII;

LL wei[30];

int dig(char c){
    return c-'A'+1;
}

LL gethash(string s){
    LL res = 0;
    //printf("%d %s\n",s.length(), s.c_str());
    for(int i=0; i<s.length(); i++) res += wei[i] * dig(s[i]);
    return res;
}

set<LL>S;

char buf[4400];
void init(){
    wei[0] = 1;
    for(int i=1; i<30; i++) wei[i] = 29*wei[i-1];

    FILE* f = fopen("garbled_email_dictionary.txt", "r");
    while(fscanf(f, "%s", buf)==1){
        S.insert(gethash(buf));
    }
}

int dp[4400];
const int inf = 10000;

int getcost(const char* s, int d){
    LL h = 0;
    int r = 0;
    for(int i=0; i<d; i++){
        h += wei[i] * dig(s[i]);
    }
    if(S.count(h)>0) return 0;

    for(int i=0; i<d; i++){
        for(char x = 'a'; x<='z'; x++){
            LL h2 = h;
            h2 += wei[i] * (dig(x) - dig(s[i]));
            if(S.count(h2)>0) return 1;
        }
    }
    for(int i=0; i<d; i++){
        for(int j=i+5; j<d; j++){

            for(char x = 'a'; x<='z'; x++){
                for(char y = 'a'; y<='z'; y++){

                    LL h2 = h;
                    h2 += wei[i] * (dig(x) - dig(s[i]));
                    h2 += wei[j] * (dig(y) - dig(s[j]));

                    if(S.count(h2)>0) return 2;
                }
            }

        }
    }
    return inf;
}

void solve(){
    scanf("%s", buf+1);
    int n = strlen(buf+1);
    dp[0] = 0;
    for(int i=1; i<=n; i++){
        dp[i] = inf;
        for(int d=1; d<=10 && d<=i; d++){
            int c = getcost(buf+i-d+1, d);
            dp[i] = min(dp[i], dp[i-d] + c);
        }
    }
    printf("%d\n", dp[n]);
}

int main(int argc,char *argv[]) {
    init();
    int T; scanf("%d", &T);
    for(int t=1; t<=T; t++){
        printf("Case #%d: ", t);
        solve();
    }
}
