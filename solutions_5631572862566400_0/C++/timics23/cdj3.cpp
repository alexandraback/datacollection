#include<stdio.h>
#include<iostream>
#include<map>
#include<vector>
#define pb push_back
using namespace std;
string S,s;
int N,T;
int viz[1010];
vector<int> g[1010];
int nr = 0;
int best;
int root;
int h[1010];
int check(vector<int> v) {
    int ret = 0;
    for(int j=1;j<v.size();++j) {
    int ok = 1;
    for(int i=0;i<=j;++i){
        int nx = i+1;
        int pv = i-1;
        if(i==0) pv = j;
        if(i==j) nx = 0;

        if(h[v[i]] == v[nx] || h[v[i]] == v[pv])
            continue;
        ok=0;
        }
        if(ok)
        ret = max(ret,j+1);
    }
    return ret;
}
int main() {
    freopen("input.in","r",stdin);
    freopen("output.out","w",stdout);
    cin>>T;
    for(int t=1;t<=T;++t) {
        cin >> N;
        for(int i=1;i<=N;++i) g[i].clear();
        for(int i=1;i<=N;++i) {
            int x;
            cin>>x;
            h[i] = x;    
        }
        vector<int> v;
    int best = 0;
    for (int i = 1; i <= N; ++i)
        v.push_back(i);
    do {
        best = max(best,check(v));
    } while (next_permutation(v.begin(), v.end()));
        cout<<"Case #"<<t<<": ";
        cout<<best;
        cout << endl;
        
    }
}
