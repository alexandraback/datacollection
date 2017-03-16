#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<cstring>
#include<vector>
#include<stack>
#include<cmath>
#include<iostream>

using namespace std;

int i, n, k, N, M, K;
int f[60][60];

int A, B, C;
char sss[100];

string s[60];

int main(){
    freopen("C-small-attempt0.in", "r", stdin);
//    freopen("C-sm.out", "w", stdout);
int a, b, c, d;
int T, R;
int chk[60];
string tp, ll;
cin >> T;
R = T;
stack<int> S;
int p[60];
while(T--){
    scanf("%d %d", &A, &B);
    k = 0;
    for(a=0;a<60;a++)for(b=0;b<60;b++) f[a][b] = 0;
    for(a=0;a<A;a++){
        scanf("%s", sss);
        s[a] = sss;
    }
    for(a=0;a<B;a++){
        scanf("%d %d", &c, &d);
        f[c][d] = f[d][c] = 1;
    }
    for(a=0;a<A;a++){
        p[a] = a+1;
    }
    k = 0;
    do{
        //printf("asdf");
        while(!S.empty())S.pop();
        n = p[0];
        ll = s[n-1];
        S.push(n);
        for(a=1;a<A;a++){
            while(!S.empty() and f[S.top()][p[a]] == 0){
                S.pop();
            }
            if(S.empty()) break;
            n = p[a];
            S.push(n);
            ll = ll+s[n-1];
        }
        if(a == A){
            //printf(" > %s\n", ll.c_str());
            if(k == 0){
                tp = ll;
            }
            tp = min(tp, ll);
            k++;
        }
    }while(next_permutation(p, p+A));

    printf("Case #%d: %s\n", R-T, tp.c_str());
}

return 0;
}
