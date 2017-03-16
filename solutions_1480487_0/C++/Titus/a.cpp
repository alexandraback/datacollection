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

struct pol{
    pol(int x_, double p_){
        x = x_;
        p = p_;
        is = false;
    }
    bool is;
    int x;
    double p;
};

void solve(){
    int N;
    cin >> N;
    vector<pol> a;
    int x;
    for(int i=0; i<N; i++){
        cin >> x;
        a.push_back(pol(x, -1));
    }
    int n = N;
    int sum=0;
    for(int i=0; i<N; i++) sum+=a[i].x;
    int dsum = sum*2;
    for(int i=0; i<N+1; i++){
        for(int j=0; j<N; j++){
            if(a[j].is == false){
                if((dsum-a[j].x)/(n-1) < a[j].x){
                    a[j].is = true;
                    a[j].p = 0;
                    n--;
                    dsum = dsum - a[j].x;
                }
            }
        }
    }
    ////cout << ">" << n << "< ";
    for(int i=0; i<N; i++){
        if(a[i].is == false){
            a[i].p = (double(dsum)/n-a[i].x)/sum;
        }
    }
    for(int i=0; i<N; i++){
        cout << a[i].p*100 << " ";
    }
}

int main(){
    cout << fixed << setprecision(6);
    int T;
    cin >> T;
    for(int t=1; t<=T; t++){
        cout << "Case #" << t << ": ";
        solve();
        cout << '\n';
    }
    return 0;
}
