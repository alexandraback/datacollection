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

using namespace std;

#define all(x) ((x).begin(),(x).end())
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;


void init(){
    cout << setprecision(1)<< fixed;
}

#define mp make_pair
#define INF 1e20
#define eps 1e-3

int N,M,H;
int f[100][100];
int c[100][100];
double best[100][100];
multimap<double,pair<int,int> > q;

void gofrom(pair<int,int> from,pair<int,int> to, double time){
    if (to.first<0 || to.first>=N || to.second<0 || to.second>=M) return;
   // if (best[to.first][to.second]<time-eps) return;
    if (f[to.first][to.second]+50>c[to.first][to.second]) return; //fto,cto
    if (f[from.first][from.second]+50>c[to.first][to.second]) return; //ffrom,cto
    if (f[to.first][to.second]+50>c[from.first][from.second]) return; //fto,cfrom
    
    if (H-10*time+50>c[to.first][to.second]-eps){   //water, ceiling
        time=(50+H-c[to.first][to.second])/10.0;
    }
    
    if (H-10*time-20>f[from.first][from.second]-eps){
        if (time>eps) time+=1;
    }
    else if (time>eps) time+=10;
    
   // dbg("gofrom:",from.first,from.second,to.first,to.second,time,best[to.first][to.second]);
    
    if (time<best[to.first][to.second]-eps){
        best[to.first][to.second]=time;
        q.insert(mp(time,to));
    }
    return;
}

double solve(int testnr){
    
    cin >> H >> N >> M;
    for(int i=0;i<N;i++) for (int j=0;j<M;j++){
        cin >> c[i][j];
    }
    for(int i=0;i<N;i++) for (int j=0;j<M;j++){
        cin >> f[i][j];
    }
    
    for(int i=0;i<N;i++) for(int j=0;j<M;j++) best[i][j]=INF;
    best[0][0]=0;
    
    q.clear();
    q.insert(mp(0,mp(0,0)));
    
    while(!q.empty()){
        multimap<double,pair<int,int> >::iterator it=q.lower_bound(-1);
        q.erase(it);
      //  if (best[(*it).second.first][(*it).second.second]<(*it).first) continue;
        
        pair<int,int> p1=(*it).second,p2=p1;
        
     //   dbg(p1.first,p1.second,(*it).first);
        
        p2.first+=1;
        gofrom(p1,p2,(*it).first);
        p2.first-=2;
        gofrom(p1,p2,(*it).first);
        p2.first+=1;
        p2.second+=1;
        gofrom(p1,p2,(*it).first);
        p2.second-=2;
        gofrom(p1,p2,(*it).first);
        
    }
    
    return best[N-1][M-1];
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
