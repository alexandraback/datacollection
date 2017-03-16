#include <bits/stdc++.h>
#define mt make_tuple
using namespace std;
typedef long long ll;
typedef tuple<int,int,int> sol;

const int S = 20;
const int inf = 1e9;
int n, ps;
char c[S], j[S], p[S];
vector<int> p_c, p_j;
sol ans, loc;

void gen(char * s, int i){
    if(i == n) {
        int x = 0; for(int i=0;i<ps;i++) x *= 10, x += (p[i]-'0');
        if(s == c) p_c.push_back(x);
        else p_j.push_back(x);
        return;
    }
    if(s[i] != '?') {
        p[ps++] = s[i];
        gen(s,i+1);
        --ps;
        return;
    }
    for(int d=0;d<10;d++) {
        p[ps++] = '0' + d;
        gen(s,i+1);
        --ps;
    }
}

void display(int x){
    for(ps = 0;x;x/=10) p[ps++] = x%10;
    while(ps < n) p[ps++] = 0;
    while(ps) putchar('0'+p[--ps]);
}

int tcn, tc;
int main(){
    assert('9' < '?');
    scanf(" %d", &tcn);
    while(tcn--){
        printf("Case #%d: ", ++tc);
        p_c.clear(); p_j.clear();
        scanf(" %s %s", c, j);
        n = strlen(c);
        gen(c, ps=0); gen(j, ps=0);
        ans = mt(inf, inf, inf);
        for(int x : p_c)
            for(int y : p_j) {
                loc = mt(abs(x-y), x, y);
                ans = min(ans, loc);
            }
        display(get<1>(ans)); putchar(' ');
        display(get<2>(ans)); putchar('\n');
    }
}
