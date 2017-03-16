#include <algorithm>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <complex>

using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
const int inf = 1e9;
const double eps = 1e-8;
const double pi = acos(-1.0);

int N;
vector<double> nao, ken;

void init(){
}

void input(){
    cin >> N;
    nao.clear(); ken.clear();
    nao.resize(N); ken.resize(N);
    for(int i = 0; i < N; i++)
        cin >> nao[i];
    for(int i = 0; i < N; i++)
        cin >> ken[i];
}

int cheat(){
    int ret = 0;
    vector<double> nao2;
    for(int i = 0; i < N; i++) nao2.push_back(nao[i]);
    for(int i = 0; i < N; i++){
        auto ub = upper_bound(nao2.begin(), nao2.end(), ken[i]);
        if(ub == nao2.end()) return ret;
        else{
            ret++;
            nao2.erase(ub, ub+1);
        }
    }
    
    return ret;
}

int opt(){
    int ret = 0;
    vector<double> ken2;
    for(int i = 0; i < N; i++) ken2.push_back(ken[i]);
    for(int i = 0; i < N; i++){
        auto ub = upper_bound(ken2.begin(), ken2.end(), nao[i]);
        if(ub == ken2.end()){
            ret++;
            ken2.erase(ken2.begin(), ken2.begin()+1);
        }
        else ken2.erase(ub, ub+1);
    }

    return ret;
}

void solve(){
    sort(nao.begin(), nao.end());
    sort(ken.begin(), ken.end());
    cout << cheat() << " " << opt() << endl;
}

int main(){
    int T; cin >> T;
    for(int t = 1; t <= T; t++){
        printf("Case #%d: ", t);
        init(); input();
        solve();
    }
    return 0;
}
