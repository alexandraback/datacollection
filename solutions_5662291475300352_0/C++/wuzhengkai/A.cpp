#include <iostream>
#include <cstdio>
#include <cstdlib>
#define LL long long

using namespace std;

int tt;
int n;
int st[1010];
LL h[1010],m[1010];
LL ans;


int main() {
#ifndef ONLINE_JUDGE
    freopen("/users/xiaodao/desktop/Exercise/in.txt", "r", stdin);
    freopen("/users/xiaodao/desktop/Exercise/out.txt", "w", stdout);
#endif
    
    scanf("%d",&tt);
    
    for (int ii=1;ii<=tt;++ii) {
        cin >> n;
        
        for (int i=0;i<n;++i) {
            cin >> st[i] >> h[i] >> m[i];
            m[i]*=360;
        }
        
        ans=(LL)1<<50;
        for (int i=0;i<n;++i) {
            LL now=m[i]-m[i]/360*st[i];
            for (int j=0;j<h[i];++j,now+=360-st[i]) {
                LL cur=0;
                for (int k=0;k<n;++k) {
                    LL nn=m[k];
                    for(int l=0;l<h[k];++l,nn+=360) {
                        LL cc=(now+nn/360*st[k])/nn;
                        //cout << now << " " << nn << " " << cc << " " << cur << endl;
                        if (cc==0) {
                            cur+=h[k]-l;
                            break;
                        }
                        //if (cc>1 && cc*nn==now+nn/360*st[k]) cc--;
                        cur+=cc-1;
                    }
                }
                //cout << now << " " << cur << endl;
                ans=min(ans,cur);
            }
        }
        printf("Case #%d: ",ii);
        cout << ans << endl;
    }
}