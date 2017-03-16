#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cassert>

using namespace std;

#define ri(X) scanf("%d", &(X))
#define pi(X) printf("%d", (X))
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define lint long long
#define pii pair<int,int>
#define inf 1e9
#define linf 1e18
#define X first
#define Y second
#define all(X) (X).begin(),(X).end()
#define uni(X) X.erase(unique(X.begin(), X.end()), X.end());


int n;
string s;

int solve(){
    int res = 0;
    int num = s[0]-'0';
    for(int i = 1; i <= n; i++){
        if(num < i){
            res+=i-num;
            num+=i-num;
        }
        num += (s[i]-'0');
    }
    return res;
}

int main(){
    int T;
    cin >> T;
    for(int t= 0; t < T; t++){
        cin >> n >> s;
        printf("Case #%d: %d\n", t+1, solve());
        
    }
    return 0;
}
