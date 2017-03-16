#include <bits/stdc++.h>
#define fr(i,a,b) for(int i =(a); i < (b); ++i)
#define frr(i,a,b) for(int i =(a); i >= (b); --i)
#define cl(a,b) memset(a, b, sizeof a)

using namespace std;

int pd[1000100];
int inverso[1000100];

int inv(int num) {
    ostringstream os; os << num;
    string act = os.str();
    int novo = 0;
    frr(i,act.size()-1,0) {
        novo *= 10;
        novo += (act[i]-'0');
    }
    //cout << novo << endl;
    return novo;
}

int go(int fim) {
    pd[fim+1] = 0;
    frr(i,fim,1) {
        pd[i] = 1+pd[i+1];
        int ql = inverso[i];
        if(ql > i && ql <= fim) pd[i] = min(1+pd[ql], pd[i]);
    }
    return pd[1];
}

int main() {
    fr(i,1,1000001) inverso[i] = inv(i);
    int T; scanf("%d", &T);
    for(int cases = 1; T--; ++cases) {
        int n; scanf("%d", &n);
        printf("Case #%d: %d\n", cases, go(n));
    }
    return 0;
}