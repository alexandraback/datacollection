#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int test;
    cin>>test;
    for(int i=1;i<=test;i++) {
        printf("Case #%i: ",i);
        int r,c,w;
        cin>>r>>c>>w;
        int res=0;
        while (r>0) {
            if (r>1) res+=c/w;
            if (r==1) {
                int pos=w;
                while (c-pos>w) {
                    ++res;
                    pos+=w;
                }
                if (pos==c) res+=w; else res+=w+1;
            }
            --r;
        }
        printf("%i\n",res);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
