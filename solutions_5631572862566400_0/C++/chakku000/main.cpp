#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <climits>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define INF INT_MAX/3
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;
int N;
int dfs(int s,vector<bool> used,vector<int> v,bool f,int start){
//    cout << "dfs infomation" << endl;
//    cout << "s : " << s << endl;
//    cout << "used : ";
//    for(int i=0;i<used.size();i++) cout << used[i] << " ";
//    cout << endl;


    vi que;
    used[s] = true;
    que.PB(s);
    if(f==true and v[s]==start) return 1;
    if(f==true and used[v[s]]) return 0;


    for(int i=0;i<N;i++){
        int p = que[i];
        if(used[v[p]]==false){
            used[v[p]]=true;
            que.PB(v[p]);
        }else{
            break;
        }
    }

    int cnt = (int)que.size();
    int lp = que[que.size()-1];
    int llp = que[que.size()-2];
    if(f==false){
        if(v[lp]==llp){
            int ret=0;
            for(int i=0;i<N;i++){
                if(!used[i]){
                    ret = max(ret,cnt+dfs(i,used,v,true,start));
                }
            }
//            cout << "pat2 return : " << ret << endl << endl;
            return ret;
        }else if(v[lp]==s){
//            cout << "pat1 return : " << cnt << endl << endl;
            return cnt;
        }else{
//            cout << "pat3 return : " << 1 << endl << endl;
            return 1;
        }
    }else{
        if(v[lp]==llp){
            int ret=0;
            for(int i=0;i<N;i++){
                if(!used[i]){
                    ret = max(ret,cnt+dfs(i,used,v,true,start));
                }
            }
            return ret;
        }else if(v[lp]==s){
            return 1;
        }else{
            return 1;
        }
    }
}

void solve(){
    cin>>N;
    vector<int> v(N);
    for(int i=0;i<N;i++){
        int n;cin>>n;
        n--;
        v[i] = n;
    }
    int ans = 0;

    for(int i=0;i<N;i++){
        vector<bool> u(N,false);
        ans = max(ans,dfs(i,u,v,false,i));
    }
    cout << ans << endl;
}

int main(){
    int T;cin >> T;
    for(int i=1;i<=T;i++){
        printf("Case #%d: ",i);
        solve();
    }
}
