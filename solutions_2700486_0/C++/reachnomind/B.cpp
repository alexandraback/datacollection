#include <iostream>

using namespace std;

int MAXN = 21;
int MAXX = 20001;

int main() {
    int T;
    cin>>T;

    double pow[MAXX];
    pow[0] = 1.0;
    for(int i=1; i<MAXX; i++) {
        pow[i] = 2.0*pow[i-1];
    }

    int C[MAXN][MAXN];
    for(int i=0; i<MAXN; i++) {
        C[i][i] = C[i][0] = 1;
    }

    for(int i=1; i<MAXN; i++) {
        for(int j=1; j<i; j++) {
            C[i][j] = C[i-1][j] + C[i-1][j-1];
        }
    }

    int sz[MAXX];
    sz[0] = 1;
    for(int i=2; i<MAXX; i+=2) {
        sz[i] = sz[i-1] + 2*i + 1;
    }

    for(int t=1; t<=T; t++) {
        int N, X, Y;
        cin>>N>>X>>Y;

        if(X<0) {
            X = -X;
        }

        double ans;
        int Z = X+Y;
        if(X == 0) {
            if(N >= sz[Z]) {
                ans = 1.0;
            } else {
                ans = 0.0;
            }
        } else {
            int ssz;
            if(Z == 0) {
                ssz = 0;
            } else {
                ssz = sz[Z-2];
            }

            int r = Y+1;
            int e = N - ssz;
            if(e > 2*r) {
                ans = 1.0;
            } if(e<r) {
                ans = 0.0;
            } else {
                ans = 0.0;
                //cout<<e<<" "<<r<<endl;
                for(int i=r; i<=e; i++) {
                    //cout<<C[e][i]<<" "<<C[2][2]<<" "<<ans<<endl;
                    ans += C[e][i];
                }
                //cout<<ans<<" "<<pow[e]<<endl;
                ans /= pow[e];
                //cout<<ans<<endl;
            }
        }

        cout<<"Case #"<<t<<": "<<ans<<endl;
    }

    return 0;
}

