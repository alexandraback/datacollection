#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
#define mp make_pair
#define fst first
#define snd second
#define fr(i, a, b) for(int i=a; i<b; i++)

int f[1005];
bool isa(int a, int b) {
    return f[a] == b || f[b]==a;
}

bool is(int a, int b, int c) {
    return f[b]==a||f[b]==c;
}
bool ok(vector<int> & a, int b, int e) {
    if(e-b==1) {
        return isa(a[b], a[e]);
    }
    //bool res = true;
    for(int i=b+1; i<=e-1; i++) {
        if(!is(a[i-1], a[i], a[i+1])) return false;
    }
    if(!is(a[e], a[b], a[b+1])) return false;
    if(!is(a[e-1], a[e], a[b])) return false;
    return true;
}
void main2() {
    int n;
    cin >> n;
    memset(f, 0, sizeof f);
    for(int i=1; i<=n; i++) {
        cin >> f[i];

    }
    vector<int> res;
    int ret = 1;
    for(int i=1; i<=n; i++) res.push_back(i);
    do {
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {

                if(ok(res, i, j)) ret = max(ret, j-i+1);
            }
        }
        if(ret==n) break;
      //if(ret == 4) cout<<res[0]<<res[1]<<res[2]<<res[3]<<endl;
    }while(next_permutation(res.begin(), res.end()));
    cout << ret << endl;

}

int main() {
    int T;
    cin>>T;
    for(int i=1; i<=T; i++) {
        cout<<"Case #"<<i<<": ";
        main2();
    }
}
