#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char v[5] = {'a','e','i','o','u'},s[1100000];
int f[1100000];
int main()
{
    freopen("A2.in","r",stdin);
    freopen("A2.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int cas = 1; cas <= T; cas++){
        int len ,n,i;
        char ch;
        scanf(" %s%d",s,&n);
        int clen = 0,pos = -1;
        memset(f,0,sizeof(f));
        len = strlen(s);
        for (i = 0;i < len; i++){
            int j;
            f[i] = 0;
            int flag = 0;
            for (j = 0;j < 5; j++)
                if (s[i]==v[j]){flag =1; break;}
            if (flag==1){
                clen = 0;
            }
            else {
                //if (clen==0) pos = i;
                clen++;
                if (clen == n){
                    pos = i-n+1;
                    clen--;
                }
                //printf("%d %d %d\n",i,clen,pos);
            }
            if (pos>-1) f[i] = pos+1;
        }
        long long ans=0;
        for (i = 0;i < len; i++) ans += f[i];
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
