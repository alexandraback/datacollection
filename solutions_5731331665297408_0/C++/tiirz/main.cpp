#define _USE_MATH_DEFINES
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#include <utility>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
#include <bitset>
#define  pb push_back
#define mp make_pair
#define pii pair< pair<int,int> , pair<int,int> >
#define rep(i,s,n) for(int i=s;i<n;++i)

typedef long long ll;
typedef unsigned long long ull;
using namespace std;
int buf_i;
int in(){
    scanf("%d", &buf_i);
    return buf_i;
}
const int INF=~(1<<31);
const ll LINF=~(1LL<<63);

const double eps=1e-6;
ll gcd(ll a, ll b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}
ll lcm(ll a, ll b){
    return a/gcd(a,b)*b;
}
vector<char> u;
vector<string> zip;

int main(){
#ifdef SSU
    freopen("in4.txt","r", stdin);
    freopen("outcj4.txt", "w", stdout);
#else
    //  freopen("g.in","r", stdin);
    // freopen("g.out", "w", stdout);
#endif

    int T=in();
    for(int t=0;t<T;++t){
        printf("Case #%d: ",t+1);
        int n=in();
        int m=in();
        zip.clear();
        for(int i=0;i<n;++i){
            string s;
            cin>>s;
            zip.pb(s);
        }
        vector<vector<int> > g(n, vector<int>());
        for(int i=0;i<m;++i){
            int a=in()-1, b=in()-1;
            g[a].pb(b);
            g[b].pb(a);
        }
        vector<int> w;
        string res="-1";
        for(int i=0;i<n;++i) w.pb(i);
        do{
            stack<int> v;
            v.push(w[0]);
            string cur=zip[v.top()];
            for(int i=1;i<w.size();++i){
                int to=w[i];
                while(!v.empty()){
                    int from=v.top();
                    for(int j=0;j<g[from].size();++j){
                        if(g[from][j]==to){
                            v.push(to);
                            cur+=zip[to];
                            goto ok;
                        }
                    }
                    v.pop();
                }
                ok:
                if(cur.size()==n*5){
                    if(res=="-1" || cur<res){
                        res=cur;
                    }
                }
            }
            if(cur.size()==n*5){
                if(res=="-1" || cur<res){
                    res=cur;
                }
            }

        }while(next_permutation(w.begin(), w.end()));
        cout<<res<<endl;

    }











    return 0;
}
