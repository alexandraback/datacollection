#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define fst first
#define snd second
#define fr(i, a, b) for(int i=a; i<b; i++)

int g[55][55];
void main2() {
    ll n, m;
    cin >> n >> m;
    ll total = 1 << (n-2);
    memset(g, 0, sizeof g);
    if(m > total) cout<<"IMPOSSIBLE"<<endl;
    else {
        cout<<"POSSIBLE"<<endl;
        for(int i=1; i<n; i++) g[0][i] = 1;
        g[0][n-1] = 1; m--;
        int t = 1;
        int start = n-2;
        while(1) {
            if(m <= t) {
                int b = t;
                if(b>1) b/=2; 
                int end = start+1;
                while(1) {
                    if(m >= b) {
                        g[start][end] = 1;
                        end++; m-= b;
                        if(b>1)b /= 2;
                    } else {
                        if(b>1)
                            b/=2;
                         end++;
                    }
                    if(m<=0) break;
                }
                //for(int i=n-1; i >= n-m; i--) g[start][i] = 1;

                break;
            } else {

                for(int i=start+1; i<n; i++) g[start][i] = 1;
                m -= t; t *= 2;
                start--;
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++ ) cout<<g[i][j];
            cout<<endl;
        }


    }
}

int main() {
    int T;
    cin>>T;
    for(int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<": ";
        main2();
    }
}
