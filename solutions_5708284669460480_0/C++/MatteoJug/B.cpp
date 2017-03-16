#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair

int F[255];
char _K[105], _L[105];
int K,L,S;
double KK, FP[105];
vi PRE;

pair<int, double> MEMO[105][105][2];

pair<int, double> foo(int c, int s, int h){
    if (MEMO[c][s][h].ff != -1) return MEMO[c][s][h];
    //~ cout<<c<<","<<s<<","<<h<<endl;
    double p = 0;
    int can = 0;
    if (c == 0) return mp(1,1);
    if (s < L) return mp(0,0);
    if (s == L){
        if (c == 1){
            p += FP[0];
            can = 1;
        }
    }
    if (s > L){
        auto tmp = foo(c-1, s-L, 1);
        can = max(can, tmp.ff);
        p += foo(1, L, 0).ss*tmp.ss;
    }
    if (h){
        for (int pre : PRE){
            auto tmp = foo(c-1, s-(L-pre-1), 1);
            can = max(can, tmp.ff);
            p += FP[pre]*tmp.ss;
        }
    }
    auto tmp = foo(c, s-1, 0);
    can = max(can, tmp.ff);
    p += tmp.ss;
    //~ cout<<c<<","<<s<<","<<h<<" -> "<<can<<","<<p<<endl;
    return MEMO[c][s][h] = mp(can,min(1.0,p));
}
int main(){
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    
    int _T;
    scanf("%d", &_T);
    for (int _t = 1; _t <= _T; _t++){
        scanf("%d%d%d", &K, &L, &S);
        scanf("%s%s", _K, _L);
        memset(F, 0, sizeof F);
        KK = K;
        for (int i = 0; i < K; i++)
            F[_K[i]]++;
        int e = 0;
        for (int i = 0; i < L; i++)
            if (F[_L[i]] == 0)
                e = 1;
        if (e){
            printf("Case #%d: 0.0\n", _t);
            continue;
        }
        for (int i = 0; i <= S; i++)
            for (int j = 0; j <= S; j++)
                MEMO[i][j][0] = MEMO[i][j][1] = mp(-1,0);
        FP[L] = 1;
        for (int i = L-1; i >= 0; i--){
            FP[i] = F[_L[i]]/KK * FP[i+1];
        }
        PRE.clear();
        for (int i = 1, j; i < L; i++){
            j = 1;
            for (int k = 0; k+i < L; k++)
                if (_L[i+k] != _L[k]){
                    j = 0;
                    break;
                }
            if (j == 1) PRE.pb(i);
        }
        //~ cout<<"@"<<foo(1, L, 0).ss<<endl;
        int mx = 0;
        double p = 0, r = 0;
        for (int i = S; i; i--){
            auto t = foo(i, S, 0);
            //~ cout<<i<<" -> "<<t.ss<<endl;
            if (t.ff) mx = max(mx, i);
            p += t.ss - r;
            r = -r + t.ss;
        }
        printf("Case #%d: %lf\n", _t, mx-p);
    }
    return 0;
}
