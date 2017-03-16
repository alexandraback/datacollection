/*
 * Bidhan Roy
 * University of Dhaka
 */

using namespace std;

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <list>
#include <ctime>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

#define rep(i,n) for(__typeof(n) i=0; i<(n); i++)
#define foreach(i,n) for(__typeof((n).begin())i =(n).begin();i!=(n).end();i++)
#define inf (1<<30)
#define eps 1e-9
#define pb push_back
#define ins insert
#define mp make_pair
#define sz(x) ((int)x.size())
#define clr clear()
#define all(x) x.begin(),x.end()
#define xx first
#define yy second
#define sqr(x) ((x)*(x))
#define mem(x,val) memset((x),(val),sizeof(x));
#define read(x) freopen(x,"r",stdin);
#define rite(x) freopen(x,"w",stdout);
#define chk(a,k) ((bool)(a&(1<<(k))))
#define off(a,k) (a&(~(1<<(k))))
#define on(a,k) (a|(1<<(k)))

typedef long long i64;
typedef unsigned long long ui64;
typedef string st;
typedef vector<int> vi;
typedef vector<st> vs;
typedef map<int,int> mii;
typedef map<st,int> msi;
typedef map<int,st> mis;
typedef set<int> si;
typedef set<st> ss;
typedef pair<i64,i64> pii;
typedef vector<pii> vpii;

#define mx 300

int dp[mx][mx][mx];
int path[mx][mx][mx];

struct data{
    int x,y,m;
    data(){}
    data(int _x,int _y,int _m){
        x=_x;
        y=_y;
        m=_m;
    }
    void set(int _x,int _y,int _m){
        x=_x;
        y=_y;
        m=_m;
    }
    bool operator < (const data &b) const {
        if(x==b.x){
            if(y==b.y) return m<b.m;
            return y<b.y;
        }
        return x<b.x;
    }
};

int main(){
	double cl = clock();
    cl = clock() - cl;
    read("B.in");
    rite("cout.txt");
    int test,kas=0;
    cin>>test;
    while(test--){
        printf("Case #%d: ",++kas);
        int X,Y;
        cin>>X>>Y;
        map<data,int> vis;
        queue<data> q;
        data start(0,0,1);
        vis[start]=0;
        data now;
        q.push(start);
        while(!q.empty()){
            data top=q.front(); q.pop();
            //if(vis.find(top)!=vis.end()) continue;
            int x=top.x;
            int y=top.y;
            int m=top.m;
            if(x==X && y==Y) {
                //cout<<"here"<<endl;
                now=top;
                break;
            }
            data temp(x-m,y,m+1);
            if(vis.find(temp)==vis.end()) {
                vis[temp]=1;
                q.push(temp);
            }
            temp.set(x+m,y,m+1);
            if(vis.find(temp)==vis.end()) {
                vis[temp]=2;
                q.push(temp);
            }
            temp.set(x,y+m,m+1);
            if(vis.find(temp)==vis.end()) {
                vis[temp]=3;
                q.push(temp);
            }
            temp.set(x,y-m,m+1);
            if(vis.find(temp)==vis.end()) {
                vis[temp]=4;
                q.push(temp);
            }
        }
        st ans;
        while(vis[now]){
            if(vis[now]==1){
                now.m--;
                now.x+=now.m;
                ans+='W';
            }
            else if(vis[now]==2){
                now.m--;
                now.x-=now.m;
                ans+='E';
            }
            else if(vis[now]==3){
                now.m--;
                now.y-=now.m;
                ans+='N';
            }
            else if(vis[now]==4){
                now.m--;
                now.y+=now.m;
                ans+='S';
            }
        }
        reverse(all(ans));
        cout<<ans<<endl;
    }
    fprintf(stderr, "Total Execution Time = %lf seconds", cl / CLOCKS_PER_SEC);
    return 0;
}
