#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<iostream>
#include<string>
#include<cstring>
#include<cassert>
#include<ctime>
#include<vector>
#include<list>
#include<stack>
#include<deque>
#include<queue>
#include<map>
#include<utility>
#include<set>
#include<algorithm>

using namespace std;
typedef long long lint;
typedef long double ldb;

const int inf = 1000000000;
const int maxe = 300010;

#define X first
#define Y second
#define F(i, l, r) for(auto i = l; i != r; i++)
#define Df(i, l, r) for(auto i = l; i != r; i--)
#define pb push_back
#define rs resize
#define mk make_pair
#define asg assign
#define all(x) x.begin(),x.end()
#define ret return

int t, n;
string s;

int solve(){
    char last = s[0];
    int ops = 0;
    F(i, 1, n){
        if(s[i] != last){
            ops++;
            last = s[i];
        }
    }
    if(last == '-')
        ops++;
    ret ops;
}

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    getline(cin, s);
    F(i, 0, t){
        getline(cin, s);
        n = s.length();
        printf("Case #%d: %d\n", i + 1, solve());
    }
    ret 0;
}
