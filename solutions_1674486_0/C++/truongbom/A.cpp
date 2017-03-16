#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>

#define For(i,n) for(int i = 0;i<n;i++)
#define Fors(var,start,finish) for(int var = start, var <=finish, var++)

using namespace std;

const int maxn = 10010;
const int maxm = 20;
int n,m,ntest;
int v[maxn];
bool res = false;
vector<int> c[maxn];

bool d[maxn];

void solve(){
    For(i,n){
        memset(d,0,sizeof(d));
        memset(v,0,sizeof(v));
        queue<int> q;
        q.push(i);
        d[i] = true;
        res = false;
        while(!q.empty()){
            if (res) break;
            int cur = q.front();
            q.pop();
            int tsize = c[cur].size();
            For(j,tsize){
                if (!d[c[cur][j]]){
                    q.push(c[cur][j]);
                    v[c[cur][j]]++;
                    d[c[cur][j]] = true;
                } else{
                    v[c[cur][j]]++;
                    if (v[c[cur][j]] >=2 ){
                        res = true;
                        break;
                    }
                }
            }
        }   
        if (res) break;
    }
    if (res) cout<<"Yes"; else cout<<"No";
}

void input(){
    cin>>n;
    int temp;
    For(i,n){
        c[i].clear();
        cin>>m;
        For(j,m){
            cin>>temp;
            c[i].push_back(temp-1);
        }
    }
}


int main(){
//    freopen("A.in","r",stdin);
    cin>>ntest;
    For(i,ntest){
        input();
        cout<<"Case #"<<i+1<<": ";
        solve();
        cout<<endl;
    }
    return 0;
}
