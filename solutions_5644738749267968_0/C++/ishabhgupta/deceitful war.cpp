#include<iostream>
#include<fstream>
#include<cstdio>
#include<algorithm>

using namespace std;

int main()
{
    freopen("D-small-attempt0.in","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin >> t;
    for(int te=1;te<=t;te++) {
        int n;
        double a[1010],b[1010];
        cin >> n;
        for(int i=0;i<n;i++) cin >> a[i];
        for(int j=0;j<n;j++) cin >> b[j];
        cout << "Case #" << te << ": ";
        sort(a,a+n);
        sort(b,b+n);
        int ans1,ans2;
        ans1 = ans2 = 0;
        for(int i=0;i<n;i++) ans1 += (a[n-1] < b[i]);
        ans2 = ans1;
        for(int i=ans2;i<n;i++) {
            if(b[0] > a[i]) ans2++;
        }
        int ans3 = 0;
        int i = 0;
        while(ans2 < n) {
            if(b[i] < a[ans2]) {
                i++,ans2++;
                ans3++;
            } else {
                ans2++;
            }
        }
        int vis[1010] = {0};
        ans1 = ans2 = 0;
        for(int i=0;i<1010;i++) vis[i] = 0;
        for(int i=0;i<n;i++) {
            bool f = 0;
            for(int j=0;j<n;j++) {
                if(vis[j] == 0 && a[i] < b[j]) {
                    vis[j] = 1;
                    ans1++;
                    f = 1;
                    break;
                }
            }
            if(!f) {
                for(int j=0;j<n;j++) {
                    if(vis[j] == 0) {
                        vis[j] = 1;
                        break;
                    }
                }
            }
        }
        ans2 = n-ans1;
        cout << ans3 << " " << ans2 << endl;
    }
}
