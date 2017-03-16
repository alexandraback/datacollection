#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 2000000000

int mat[52][52];

int main(){
    ios_base::sync_with_stdio(false);
    freopen("C:\\in.txt", "r", stdin);
    freopen("C:\\GCJ_1C_2016\\1c_out.txt", "w", stdout);
    int TC;
    cin >> TC;
    int cas = 1;
    while(TC--){
        memset(mat, 0, sizeof(mat));
        ll b,m;
        cin >> b >> m;
        ll maxx = (1LL) << (b-2);
        if(m>maxx){
            cout << "Case #" << cas++ <<  ": IMPOSSIBLE" << endl;
        } else {
            for(int i=0; i<b; ++i){
                for(int j=i+1; j<b; ++j){
                    mat[i][j] = 1;
                }
            }
            if(m!=maxx){
                mat[0][b-1] = 0;
                for(int i=0; i<b; ++i){

                    if(m>>i & (1LL)){


                    } else {
                        mat[0][b-2-i] = 0;
                    }
                }
            }
            cout << "Case #" << cas++ <<  ": POSSIBLE" << endl;
            for(int i=0; i<b; ++i){
                for(int j=0; j<b; ++j){
                    cout << mat[i][j];
                }
                cout << endl;
            }
        }
    }
    return 0;
}
