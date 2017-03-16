#include <bits/stdc++.h>

using namespace std;

int y, k,c, s;
long long h[101];



int main()
{
freopen("4.in","r",stdin);
freopen("4.out","w",stdout);
cin >> y;
for(int x=1;x<=y;x++) {
    cin >> k >> c >> s;
    h[0]=1;
    for(int i=1;i<=c;i++) h[i]=h[i-1]*k;
    cout << "Case #" << x << ":";
    if(k>c*s) cout << " IMPOSSIBLE" << endl;
    else {
        int db=0;
        for(int i=0;i<s && db<k;i++) {
            long long l=1;
            for(int j=0;j<c;j++,db++) {
                if(db<k) l+=db*h[j];
            }
            cout << " " << l;
        }
        cout << endl;
    }
}
    return 0;
}
