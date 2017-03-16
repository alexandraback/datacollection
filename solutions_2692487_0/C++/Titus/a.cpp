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

void solve(){
    long A, N;
    cin >> A >> N;
    vector<long> num(N);
    vector<long> need(N);
    for(int i=0; i<N; ++i){
        cin >> num[i];
    }
    if(A == 1){
        cout << N;
        return;
    }
    sort(num.begin(), num.end());
    for(int i=0; i<N; ++i){
        while(num[i] >= A){
            A = A+(A-1);
            need[i]++;
        }
        A = A + num[i];
    }
    vector<long> pref(N);
    pref[0] = need[0];
    for(int i=1; i<N; ++i){
        pref[i] = need[i] + pref[i-1];
    }
    vector<long> sol(N);
    long K = N-1;
    while(K >= 0){
        sol[K] = pref[K] + N-K-1;
        K--;
    }
    long minimum = 1000000000;
    for(int i=0; i<N; ++i){
        if(sol[i] < minimum){
            minimum = sol[i];
        }
    }
    if(N < minimum) minimum = N;
    cout << minimum;
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
