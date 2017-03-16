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

const string ary[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};

void solve(){
    string s;
    cin >> s;
    map<char,int> c;
    rep(i,s.size()) c[s[i]]++;

    vi ans(10,0);

    int c2 = 0;
    c2 = c['W'];
    c['T'] -= c2;
    c['W'] -= c2;
    c['O'] -= c2;
    ans[2] = c2;
    int c4 = 0;
    c4 = c['U'];
    c['F'] -= c4;
    c['O'] -= c4;
    c['U'] -= c4;
    c['R'] -= c4;
    ans[4] = c4;
    int c6 = c['X'];
    c['S'] -= c6;
    c['I'] -= c6;
    c['X'] -= c6;
    ans[6] = c6;


    for(int i=0;i<10;i++){
        string a = ary[i];
        int t=INF;
        for(int j=0;j<a.size();j++){
            t = min(t,c[a[j]]);
        }
        ans[i]+=t;
        for(int j=0;j<a.size();j++){
            c[a[j]] -= t;
        }
    }

    for(int i=0;i<10;i++) for(int j=0;j<ans[i];j++) cout << i;
    cout << endl;
}

int main(){
    int t;cin>>t;
    rep(i,t){
        printf("Case #%d: ",i+1);
        solve();
    }
    return 0;
}
