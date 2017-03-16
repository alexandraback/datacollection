#include<cstdio>
#include<cstring>

using namespace std;

char p[105];

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int t, i, n, ans, cases;
    scanf("%d", &t);
    for(cases=1;cases<=t;cases++){
        scanf("%s", p);
        n=strlen(p);
        p[n]='+';
        p[n+1]='\0';
        ans=0;
        for(i=0;i<n;i++){
            if(p[i]!=p[i+1]) ans++;
        }
        printf("Case #%d: %d\n", cases, ans);
    }
}
