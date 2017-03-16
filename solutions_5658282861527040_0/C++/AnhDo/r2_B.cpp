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


#define IN "B-small-attempt0.in"
#define OUT "output.txt"
int main(){
    freopen(IN,"r",stdin);
    freopen(OUT,"w",stdout);
    int nTest;
    //----------- Code ----------
    scanf("%d\n",&nTest);
    For(Test,1,nTest){
        printf("Case #%d: ",Test);
        int A, B, K;
        scanf("%d%d%d",&A,&B,&K);
        int res = 0;
        rep(a,A)rep(b,B)if((a&b)<K)res++;
        cout<<res<<endl;
    }
    return 0;
}
