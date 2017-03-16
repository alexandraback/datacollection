#include <algorithm>
#include <cstdlib>
#include <climits>
#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <set>
#include <vector>
#include <iomanip>

using namespace std;

typedef unsigned char byte;
typedef unsigned int uint;
typedef long long int ll;

int N, M;
vector<ll> a, A, b, B;

ll solve_it(){
    ll Max=0;
    ll sum[3] = {};
    for(int i=0; i<M+1; i++){
        for(int j=i; j<M+1; j++){
            for(int k=0; k<3; k++) sum[k] = 0;
            for(int k=0; k<i; k++){
                if(A[0] == B[k]){
                    sum[0] += b[k];
                }
            }
            for(int k=i; k<j; k++){
                if(A[1] == B[k]){
                    sum[1] += b[k];
                }
            }
            for(int k=j; k<M; k++){
                if(A[2] == B[k]){
                    sum[2] += b[k];
                }
            }
            for(int k=0; k<3; k++){
                if(a[k] < sum[k]) sum[k] = a[k];
            }
            /*
            if(i==0 && j==1){
            cout << "sum: " << '\n';
                for(int k=0; k<3; k++){
                    cout << sum[k] << '\n';
                }
            }
            */
            ll S = sum[0] + sum[1] + sum[2];
            if(Max < S){
                Max = S;
            }
        }
    }
    return Max;
}

void solve(){
    ll Max = 0;
    cin >> N >> M;
    a.resize(N); A.resize(N); b.resize(M); B.resize(M);
    for(int i=0; i<N; i++){
        cin >> a[i] >> A[i];
    }
    for(int i=0; i<M; i++){
        cin >> b[i] >> B[i];
    }
    a.resize(3); A.resize(3);
    for(int i=N; i<3; i++){
        a[i] = 0;
        A[i] = 0;
    }
    if(A[0] == A[1]){
        a[0] = a[0] + a[1];
        a[1] = 0;
    }
    if(A[1] == A[2]){
        a[1] = a[1] + a[2];
        a[2] = 0;
    }
    if(A[0] == A[1]){
        a[0] = a[0] + a[1];
        a[1] = 0;
    }
    /*
    for(int i=0; i<3; i++){
        cout << a[i] << " " << A[i] << " ";
    }
    cout << '\n';
    */
    Max = solve_it();

    if(A[0] == A[2]){
        a[1] = 0;
        a[0] += a[2];
        a[2] = 0;
        ll asdf = solve_it();
        if(Max < asdf) Max = asdf;
    }
    cout << Max;
}

int main(){
    // cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
