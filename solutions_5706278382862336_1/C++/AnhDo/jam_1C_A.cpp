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

    llint n, m;
    char c[55];

llint Solve(){
    llint ret = -1;
    rep(i,40){
        //cout<<"( "<<n<<" "<<m<<" )"<<endl;
        n*=2;
        if(n>=2*m)return -1;
        if(n>=m){
            if(ret==-1)ret=i+1;
            n-=m;
        }
        if(n==0)return ret;
    }
    return -1;
}
#define IN "a-l.in"
#define OUT "output.txt"
int main(){
    freopen(IN,"r",stdin);
    freopen(OUT,"w",stdout);
    int nTest;
    //----------- Code ----------
    scanf("%d\n",&nTest);
    For(Test,1,nTest){
        printf("Case #%d: ",Test);
        scanf("%s\n",&c);
        n = m = 0;
        bool FIRST = true;
        rep(i,55){
            if(c[i]=='\0')break;
            if(c[i]=='/')FIRST=false;
            else{
                if(FIRST)n=n*10+c[i]-'0';
                    else m=m*10+c[i]-'0';
            }
        }
        //cout<<n<<" "<<m<<endl;
        llint res = Solve();
        if(res>=0)cout<<res<<endl;
            else cout<<"impossible"<<endl;
    }
    return 0;
}
