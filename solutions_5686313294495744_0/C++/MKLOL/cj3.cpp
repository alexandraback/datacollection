#include<bits/stdc++.h>
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int N,M;
string dig[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[4400];
int RET;
string s1[2020],s2[2020];
void verif() {
    map<string,int> h1,h2;
    int ret = 0;
    for(int i=1;i<=N;++i) {
        if(!cnt[i]) ++ret;
        else {
            h1[s1[i]]++;
            h2[s2[i]]++;
        }
    }

    for(int i=1;i<=N;++i) {
        if(!cnt[i]){
            if(!h1[s1[i]]) return;
            if(!h2[s2[i]]) return;
        }
    }

    RET = max(RET,ret);
}
void backx(int x) {
    if(x == N+1) {
        verif();
    } else {
        cnt[x]=1;
        backx(x+1);
        cnt[x]=0;
        backx(x+1);
    }
}
int main() {
    freopen("test.in","r",stdin);
    freopen("testL.out","w",stdout);
    int T;
    cin >> T;
    for (int tt=1;tt<=T;++tt) {
        cin >> N;
        for(int i=1;i<=N;++i) {
            cin >> s1[i] >> s2[i];
        }
        RET = 0;
        backx(1);

        printf("Case #%d: %d\n",tt, RET);

    }
}
