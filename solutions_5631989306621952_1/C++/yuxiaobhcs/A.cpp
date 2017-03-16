#include<stdio.h>
#include<cstring>
using namespace std;
int main() {
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);

    int T;
    char s[1010],res[1010],head[1010];
    scanf("%d",&T);
    for (int cas=1; cas<=T; cas++) {
        scanf("%s",s);
        printf("Case #%d: ",cas);
        int cnt=0,len=strlen(s),i,j=0;
        char h=s[0];
        res[cnt++]=s[0];
        for (i=1; i<len; i++) {
            if (s[i]>=h) {
                head[j++]=s[i];
                h=s[i];
            } else {
                res[cnt++]=s[i];
            }
        }
        for (; j>0; j--) {
            printf("%c",head[j-1]);
        }
        res[cnt]='\0';
        printf("%s\n",res);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
