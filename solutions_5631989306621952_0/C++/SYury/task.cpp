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
#define cont continue
#define brk break
#define ins insert
#define era erase

string s, ans;

int t, n;

int main(){
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> t;
    getline(cin, s);
    F(g, 0, t){
        getline(cin, s);
        ans = "";
        n = s.length();
        ans += s[0];
        F(i, 1, n){
            if(s[i] >= ans[0])
                ans = s[i] + ans;
            else
                ans = ans + s[i];
        }
        printf("Case #%d: %s\n", g + 1, ans.c_str());
    }
    ret 0;
}
