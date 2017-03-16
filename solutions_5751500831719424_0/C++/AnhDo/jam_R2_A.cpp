/*
*********************
** @Author lion_IT **
*********************
*/
//------ Library --------
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
//------ Containers -------
#include <vector>
#include <stack>
#include <queue>
#include <map>
//-------------------------
#define For(i,a,b) for(int i = int(a); i <= int(b); i++)
#define Ford(i,b,a) for(int i = int(b); i >= int(a); i--)
#define rep(i,n) for(int i = 0; i < int(n);i++)
#define repd(i,n) for(int i = int(n)-1; i >=0 ;--i)
#define fi first
#define se second
#define mp make_pair
#define pii pair<int, int>
#define VI vector<int>
#define pb push_back
#define PI acos(-1)

#define BUG(a) cout<<a
#define BUG_(a) cout<<a<<endl
typedef long long llint;
struct Point{
    int x, y;
    Point(){
        x = 0, y = 0;
    }
    Point(int _x,int _y){
        x = _x;
        y = _y;
    }
};
using namespace std;

    int n;
    vector<int> a[122];
    string s[122];
    vector<char> v;

int Solve(){
    v.clear();
    //cout<<" OK " <<endl;
    rep(i,s[1].size())if(v.size()==0||s[1][i]!=v[v.size()-1])v.pb(s[1][i]);
    //cout<<" OK " <<endl;
    rep(j,v.size())a[j].clear();
    For(i,1,n){
        int x = -1;
        rep(j,v.size()){
            x++;
            int l = x;
            if(x>=s[i].size()||v[j]!=s[i][x])return -1;
            while((x<s[i].size())&&((x==s[i].size()-1)||(s[i][x]==s[i][x+1])))x++;
            a[j].pb(x-l);
        }
        if(x<s[i].size())return -1;
    }
    //cout<<"OK 1 "<<endl;
    int ret = 0;
    rep(j,v.size()){
        sort(a[j].begin(), a[j].end());
        int tmp = 111*111*111, tmp1 = 0, tmp2 = 0;
        rep(i,a[j].size())tmp2 += a[j][i];
        rep(i,a[j].size()){
            tmp = min(tmp, i*a[j][i]-tmp1+tmp2-(n-i)*a[j][i]);
            tmp1 += a[j][i];
            tmp2 -= a[j][i];
        }
        ret += tmp;
    }
    return ret;
}
#define IN "A-small-attempt0.in"
#define OUT "output.txt"
int main(){
    freopen(IN,"r",stdin);
    freopen(OUT,"w",stdout);
    int nTest;
    //----------- Code ----------
    scanf("%d\n",&nTest);
    For(Test,1,nTest){
        printf("Case #%d: ",Test);
        scanf("%d\n",&n);
        For(i,1,n){
            char c[122];
            scanf("%s\n", &c);
            s[i]="";
            rep(j,122){
                if(c[j]=='\0')break;
                s[i] = s[i] + c[j];
            }
            //cout<<s[i]<<endl;
        }
        int res = Solve();
        if(res>=0)cout<<res<<endl;
            else cout<<"Fegla Won"<<endl;
    }
    return 0;
}
