#include<cstdio>
#include<cstring>
int num[1005],a,b;
bool ispa(int x) {
    char s[10];
    sprintf(s, "%d", x);
    for(int i=0;i<strlen(s);i++) {
        if (s[i]!=s[strlen(s)-1-i]) return false;
    }
    return true;
}
int main() {
    int T;
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    scanf("%d", &T);
    num[0] = 0;
    for (int i=1;i<=1001;i++) {
        if (ispa(i) && ispa(i*i) && i*i<=1000) {
            num[i*i]=1;
        }
        num[i] = num[i-1]+num[i];
    }
    for (int t=1;t<=T;t++) {
        scanf("%d%d",&a,&b);
        printf("Case #%d: %d\n", t, num[b]-num[a-1]);
    }
}
