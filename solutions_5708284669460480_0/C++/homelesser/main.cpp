#include <iostream>
#include <cstdio>
using namespace std;

int T;
int K,L,S;
char k[10],s[10],l[10];
double total, sum, c;


void dfs(int depth)
{
    if(depth == S) {
        c++;
        s[depth] = 0;
        int cnt = 0;
        for (int i=0; i<S; i++) {
            bool f = true;
            for (int j=0; j<L; j++) {
                if (s[i+j]!=l[j]) {
                    f = false;
                    break;
                }
            }
            if (f) {
                cnt ++;
            }
        }
        if (cnt > total) {
            total = cnt;
        }
        sum += cnt;
        return;
    }
    for (int i=0; i<K; i++) {
        s[depth] = k[i];
        dfs(depth+1);
    }
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w",stdout);
    scanf("%d",&T);
    for (int cas = 1; cas <=T; cas ++) {
        scanf("%d%d%d",&K,&L,&S);
        scanf("%s",k);
        scanf("%s",l);
        total = 0;
        sum = 0;
        c = 0;
        dfs(0);
        printf("Case #%d: %.9lf\n", cas, total - sum / c);
    }
    return 0;
}
