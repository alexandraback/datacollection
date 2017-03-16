#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))
#define P1(a) (a).first
#define P2(a) (a).second
#define T1(a) (a).first
#define T2(a) (a).second.first
#define T3(a) (a).second.second
#define INF 1e20
#define EPS 1e-8

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tiii;

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;

#define maxd 1001

int d[2*maxd][2*maxd];

void init(){
    cout << setprecision(8)<< fixed;
    rep(x,2*maxd) rep(y,2*maxd) d[x][y] = 1000;
 //   memset(&d,1000,sizeof d);
    d[maxd][maxd]=0;
    rep(i,501){
        rep(x,2*maxd) rep(y,2*maxd){
            if (d[x][y]==i){
                if (x>=i+1) d[x-i-1][y] = min(i+1,d[x-i-1][y]);
                if (y>=i+1) d[x][y-i-1] = min(i+1,d[x][y-i-1]);
                if (x+i+1<2*maxd) d[x+i+1][y] = min(i+1,d[x+i+1][y]);
                if (y+i+1<2*maxd) d[x][y+i+1] = min(i+1,d[x][y+i+1]);
            }
        }
    }
 /*   rep(x,2*maxd) rep(y,2*maxd) if (d[x][y]==1000 && x-maxd>-101 && x-maxd<101 && y-maxd>-101 && y-maxd<101){
        printf("(%d,%d),",x-maxd,y-maxd);
    }*/
}

string solve(int testnr){
    int x,y,i;
    cin >> x >> y;
    string ans = "";
    x+=maxd;
    y+=maxd;
    while (x!=maxd || y!=maxd){
        i = d[x][y];
        if (x>=i && d[x-i][y]==i-1) {
            ans+='E';
            x-=i;
            continue;
        }
        if (y>=i && d[x][y-i]==i-1){
            ans+='N';
            y-=i;
            continue;
        }
        if (x+i<2*maxd && d[x+i][y]==i-1){
            ans+='W';
            x+=i;
            continue;
        }
        if (y+i<2*maxd && d[x][y+i]==i-1){
            ans+='S';
            y+=i;
        }
    }
    string a = "";
    for(int i=ans.length()-1;i>=0;i--) a+=ans[i];
    return a;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ": " << solve(i) << "\n";
    }
    
    return 0;
}
