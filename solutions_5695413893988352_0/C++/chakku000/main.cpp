#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <climits>
#include <cassert>
using namespace std;

#define REP(i,n) for(int i=0;i<n;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define INF INT_MAX/3
#define LINF LLONG_MAX/3
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define ALL(v) (v).begin(),(v).end()
#define debug(x) cout<<#x<<":"<<x<<endl
#define debug2(x,y) cout<<#x","<<#y":"<<x<<","<<y<<endl

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vvi;

bool ok(const int a,const string b){
    string t = to_string(a);
    while(t.size()!=b.size()) t="0"+t;

    for(int i=0;i<b.size();i++){
        if(b[i]=='?') continue;
        else if(t[i]!=b[i]) return false;
    }
    return true;
}

string t_s(int n,int sz){
    string s=to_string(n);
    while(s.size()!=sz) s = "0"+s;
    return s;
}

void solve(){
    string s1,s2;
    cin >> s1 >> s2;
    int n=s1.size();
    int mx = pow(10,n) + 0.001;

    int d = INF;
    int a=-1,b=-1;

    for(int i=0;i<mx;i++) for(int j=0;j<mx;j++){
        if(ok(i,s1) && ok(j,s2)){
            int dif = abs(i-j);
            if(d>dif){
                d=dif;
                a=i;
                b=j;
            }
        }
    }

    printf("%s %s\n",t_s(a,n).c_str(),t_s(b,n).c_str());
}

int main(){
    int t;
    cin>> t;
    rep(i,t){
        printf("Case #%d: ",i+1);
        solve();
    }
}
