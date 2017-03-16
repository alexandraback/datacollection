#include <bits/stdc++.h>
using namespace std;

int c,cost,n;
int a[101];

int main() {
    freopen("input.inp","r",stdin);
    freopen("output.out","w",stdout);
    int test;
    cin>>test;
    for(int i=1;i<=test;i++) {
        scanf("%i %i %i\n",&c,&n,&cost);
        for(int i=0;i<n;i++) scanf("%i",&a[i]);
        sort(a,a+n);
        long long ht=0, gt=1, res=0;
        for(int i=0;i<n;i++) {
            while (ht+1<a[i]) {
                ht+=gt*c;
                gt=ht+1;
                ++res;
            }
            ht+=1ll*a[i]*c;
            gt=max(ht+1,1ll*a[i]+1);
            if (ht>=cost) break;
        }
        while (ht<cost) {
            ++res;
            ht+=1ll*gt*c;
            gt=ht+1;
        }
        printf("Case #%i: ",i);
        cout<<res<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
