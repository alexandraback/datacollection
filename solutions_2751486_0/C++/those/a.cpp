#include<stdio.h>
#include<string.h>
typedef long long LL;

char s[2000000];
int n, m, a[2000000], ps[2000000];

int main(){
    int ca; scanf("%d",&ca);
    for (int tt=1; tt<=ca; tt++){
        scanf("%s",s); 
        scanf("%d",&m);
        n = strlen(s);
        memset(ps,0,sizeof(ps));
        for (int i=0; i<n; i++){
            a[i] = s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u';
            ps[i+1] = ps[i] + a[i];
        }
        LL ans = 0;
        bool ok=true;
        int p = 0;
        for (int i=0; i<n-m+1 && ok; i++){
            while (p-i<m-1 || ps[p+1]-ps[p+1-m] > 0){
                if (p>=n){ ok=false; break; }
                p++;
            }
            if (!ok) break;
            ans += (n-p);
        }
        printf("Case #%d: %lld\n", tt, ans);
    }
    return 0;
}
