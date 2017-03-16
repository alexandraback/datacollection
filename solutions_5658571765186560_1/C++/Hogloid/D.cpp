#define DEB

#include<bits/stdc++.h>
#include<unistd.h>
#define REP(i,m) for(int i=0;i<(m);++i)
#define REPN(i,m,in) for(int i=(in);i<(m);++i)
#define ALL(t) (t).begin(),(t).end()
#define CLR(a) memset((a),0,sizeof(a))
#define pb push_back
#define mp make_pair
#define fr first
#define sc second

using namespace std;


#ifdef DEB
#define dump(x)  cerr << #x << " = " << (x) << endl
#define prl cerr<<"called:"<< __LINE__<<endl
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
#else
#define dump(x) ;
#define prl ;
template<class T> void debug(T a,T b){ ;}
#endif

template<class T> void chmin(T& a,const T& b) { if(a>b) a=b; }
template<class T> void chmax(T& a,const T& b) { if(a<b) a=b; }

typedef long long int lint;
typedef pair<int,int> pi;

namespace std{
  template<class S,class T>
  ostream &operator <<(ostream& out,const pair<S,T>& a){
    out<<'('<<a.fr<<','<<a.sc<<')';
    return out;
  }
}

const int INF=5e8;

set<vector<pi> >omnio[10];;

int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
vector<pi> ever;

void fix(vector<pi>& a){
  sort(ALL(a));
  int mx1=a[0].fr,my1=a[0].sc;
  REP(i,a.size()){
    a[i].fr-=mx1;
    a[i].sc-=my1;
  }
}
void rotate(vector<pi>& a){
  REP(i,a.size()){
    a[i]=mp(-a[i].sc,a[i].fr);
  }
}

void flip(vector<pi>&a){
  REP(i,a.size()){
    a[i].fr*=-1;
  }
}


void check(int d){
  vector<pi> mini={mp(INF,INF)};
  REP(hoge2,2){
    REP(hoge,4){
      fix(ever);
      chmin(mini,ever);
      rotate(ever);
    }
    flip(ever);
  }

  omnio[d].insert(mini);
}

void dfs(int d){
  check(d);
  if(d==6) return;

  REP(i,d){
    REP(dir,4){
      int px=ever[i].fr+dx[dir],py=ever[i].sc+dy[dir];
      int fail=0;
      REP(j,d) if(mp(px,py)==ever[j]) fail=1;

      if(!fail){
        ever.pb(mp(px,py));
        dfs(d+1);
        ever.pop_back();
      }
    }
  }
}
int x,r,c;
int buf[25][25];

int dfs(int y,int x){
  buf[y][x]=1;
  int res=1;
  REP(d,4){
    int px=x+dx[d],py=y+dy[d];
    if(px<0 || py<0 || px>=c || py>=r || buf[py][px]) continue;
    res+=dfs(py,px);
  }
  return res;
}


int main(){

  ever.pb(mp(0,0));
  dfs(1);

  int t;cin>>t;
  REP(setn,t){
    scanf("%d%d%d",&x,&r,&c);



    bool res=true;
    if(x>=7) res=false;
    else for(auto om:omnio[x]){

      int suc=0;

      REP(fl_cnt,2){
        REP(rot_cnt,4){
          fix(om);
          REP(i,c) REP(j,r){
            CLR(buf);
            int fail=0;
            REP(k,om.size()){
              int px=i+om[k].fr,py=j+om[k].sc;
              if(px<0 || py<0 || px>=c || py>=r){
                fail=1;break;
              }
              buf[py][px]=1;
            }

            REP(i,r) REP(j,c) if(!buf[i][j]){
              int area=dfs(i,j);
              if(area%x) fail=1;
            }

            if(!fail){
              suc=1;
            }
          }

          rotate(om);
        }
        flip(om);

      }
      if(suc==0){
        res=false;
        break;
      }
    }
    printf("Case #%d: %s\n",setn+1,res?"GABRIEL":"RICHARD");
  }
  return 0;

}



