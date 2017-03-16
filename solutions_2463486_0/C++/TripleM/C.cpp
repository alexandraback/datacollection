#include <iostream>
using namespace std;
int digs[100];
bool ispal(long long x) {
    int dc = 0;
    while (x) {digs[dc++]=x%10;x/=10;}
    for (int i=0; i+i<dc; i++) if (digs[i]!=digs[dc-i-1]) return false;
    return true;
}
long long valid[39];
int main() {
    int ct = 0;
    for (long long i=1; i<=10000000; i++) {
        if (ispal(i) && ispal(i*i)) {
            valid[ct++]=i*i;
        }
    }
    int T; scanf("%d",&T); for (int t=1; t<=T; t++) {
        long long A,B; scanf("%I64d %I64d",&A,&B);
        int ans = 0;
        for (int i=0; i<ct; i++) if (valid[i]>=A && valid[i]<=B) ans++;
        printf("Case #%d: %d\n",t,ans);
    }
}
