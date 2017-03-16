#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <memory.h>
using namespace std;
typedef long long ll;

const int N = 11;

vector<int> g[N];
string z[N];

int n;
string ans;

void init(int n){
    for(int i=0;i<n;++i) g[i].clear();
}

void calc(vector<int>&p){
    vector<int> st;
    string res;
    for(int k=0;k<n;++k){
        int v = p[k];
        if(k){
            bool ok = false;
            for(int j=(int)st.size()-1;j>=0;--j){
                int t = st[j];
                int x = -1;
                for(int l=0;l<g[t].size();++l) if(g[t][l]==v){
                    x = l;
                    break;
                }
                if(x!=-1){
                    ok = true;
                    st.resize(j+1);
                    break;
                }
            }
            if(!ok) return ;
        }
        st.push_back(v);
        res+=z[v];
    }
    ans = min(ans, res);
}

void solve(int test){
    
    int m;
    cin>>n>>m; 
    
    init(n);
    
    for(int i=0;i<n;++i) cin>>z[i];
    for(int k=0;k<m;++k){
        int i,j;
        cin>>i>>j;
        --i;--j;
        g[i].push_back(j);
        g[j].push_back(i);
    }
    
    ans = " ";
    ans[0] = '9' + 1;
    
    vector<int> p(n);
    for(int i=0;i<n;++i) p[i] = i;
    do{
        calc(p);
    }while(next_permutation(p.begin(), p.end()));
    
    cout<<"Case #"<<test<<": ";
    
    cout<<ans;
    
    cout<<endl;
}

int main(){
    freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
    
    int tn;
    cin>>tn;
    for(int ti=1;ti<=tn;++ti){
        cerr<<ti<<"..."<<endl;
        solve(ti);
        cerr<<ti<<" ok."<<endl;
    }
    
    
    return 0;
}

