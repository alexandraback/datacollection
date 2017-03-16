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

void solve(){
    int N;cin>>N;
    vector<vector<int>> s(2*N-1,vector<int>(N));
    for(int i=0;i<2*N-1;i++) for(int j=0;j<N;j++) cin >> s[i][j];

    map<int,int> cnt;
    for(int i=0;i<2*N-1;i++) for(int j=0;j<N;j++){
        cnt[s[i][j]]++;
    }

    vector<int> ans;

    for(auto x : cnt){
        int key = x.first;
        int value = x.second;
        if(value%2!=0) ans.PB(key);
    }

    sort(ALL(ans));
    for(int i=0;i<ans.size()-1;i++) cout << ans[i] << " ";
    cout << ans[ans.size()-1] << endl;
}

int main(){
    int T;cin>>T;
    for(int i=1;i<=T;i++){
        printf("Case #%d: ",i);
        solve();
    }
}
