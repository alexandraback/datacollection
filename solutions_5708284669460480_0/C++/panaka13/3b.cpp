#include <bits/stdc++.h>
using namespace std;

char a[103],b[103],s[103];
int n,k,len,gtmax,sl;

bool check(int sta) {
    if (sta<0) return false;
    for(int i=0;i<n;i++) if (b[i]!=s[i+sta]) return false;
    return true;
}

void dq(int d,int dem) {
    if (d==len) {
        sl+=dem;
        gtmax=max(gtmax,dem);
        return;
    }
    for(int i=0;i<k;i++) {
        s[d]=a[i];
        int td=dem;
        if (check(d-n+1)) ++td;
        dq(d+1,td);
    }
}

int main() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int test;
    cin>>test;
    for(int i=1;i<=test;i++) {
        scanf("%i%i%i\n",&k,&n,&len);
        scanf("%s\n%s\n",a,b);
        printf("Case #%i: ",i);
        gtmax=0;
        sl=0;
        dq(0,0);
        double res=sl;
        while (len>0) {
            res=res/double(k);
            --len;
        }
        res=gtmax-res;
        printf("%.9lf\n",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
