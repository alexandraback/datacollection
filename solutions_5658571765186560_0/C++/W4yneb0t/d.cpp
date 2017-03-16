#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
bool cbf(VVI bd, in x){
  in ct=0;
  forv(i,bd){
    forv(j,bd[i])
      ct+=bd[i][j];
  }
  if(ct==x)return 1;
  if(ct+x==sz(bd)*sz(bd[0]))return 1;
  return 1;//lol i dunno
}
in x;
VVI rot(VVI a){
  VVI rt(sz(a[0]),VI(sz(a)));
  forv(i,a){
    forv(j,a[0])
      rt[j][sz(a)-i-1]=a[i][j];
  }
  return rt;
}
VVI flip(VVI a){
  VVI rt=a;
  forv(i,a){
    forv(j,a[0]){
      rt[sz(a)-i-1][j]=a[i][j];
    }
  }
  return rt;
}
struct bord{
  VVI cd;
  void opt()const{
    forv(i,cd){
      forv(j,cd[0]){
	if(cd[i][j])cout<<'#'<<" ";
	else cout<<'.'<<" ";
      }
      cout<<endl;
    }
  }
  void norm(){
    in xmx=0;
    in xmn=20;
    in ymx=0;
    in ymn=20;
    forv(i,cd){
      forv(j,cd[i]){
	if(cd[i][j]){
	  if(i>xmx)xmx=i;
	  if(i<xmn)xmn=i;
	  if(j>ymx)ymx=j;
	  if(j<ymn)ymn=j;
	}
      }
    }
    VVI tcd=cd;
    cd.clear();
    cd.resize(xmx-xmn+1,VI(ymx-ymn+1));
    for(in i=xmn;i<=xmx;i++){
      for(in j=ymn;j<=ymx;j++){
	cd[i-xmn][j-ymn]=tcd[i][j];
      }
    }
    vector<VVI> trs;
    trs.PB(cd);
    forn(i,3)
      trs.PB(rot(trs.back()));
    trs.PB(flip(trs.back()));
    forn(i,3)
      trs.PB(rot(trs.back()));
    sort(all(trs));
    cd=trs[0];
  }
  bord(VVI a=VVI(0)){cd=a;norm();}
  bool operator<(const bord cp)const{
    return cd<cp.cd;
  }
};
set<bord> doms;
VVI cd;
in d[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
void dfs(in tg){
  if(tg==0){
    doms.insert(cd);
    return;
  }
  bool hnb;
  in nx,ny;
  forv(i,cd){
    forv(j,cd[i]){
      if(cd[i][j])continue;
      hnb=0;
      forn(k,4){
	nx=i+d[k][0];
	ny=j+d[k][1];
	if(nx<0 || ny<0 || nx>=sz(cd) || ny>=sz(cd))
	  continue;
	hnb|=cd[nx][ny];
      }
      if(!hnb)continue;
      cd[i][j]=1;
      dfs(tg-1);
      cd[i][j]=0;
    }
  }
}
void gendom(){
  doms.clear();
  cd=VVI(x*2-1,VI(x*2-1,0));
  cd[x-1][x-1]=1;
  dfs(x-1);
}
void imp(){
  cout<<"RICHARD"<<endl;
}
void pos(){
  cout<<"GABRIEL"<<endl;
}
in r,c;
bool isgp(VVI bd, in a, in b){
  VVI stt(r,VI(c,0));
  forv(i,bd){
    forv(j,bd[i]){
      if(bd[i][j])
	stt[a+i][b+j]=1;
    }
  }
  forn(i,r){
    forn(j,c){
      if(stt[i][j])continue;
      queue<in> qx,qy;
      VVI ccp(r,VI(c,0));
      in ct=0;
      qx.push(i);
      qy.push(j);
      stt[i][j]=1;
      while(!qx.empty()){
	in x=qx.front();
	in y=qy.front();
	ccp[x][y]=1;
	ct++;
	qx.pop();
	qy.pop();
	in nx,ny;
	forn(k,4){
	  nx=x+d[k][0];
	  ny=y+d[k][1];
	  if(nx<0 || ny<0 || nx>=r || ny>=c)continue;
	  if(stt[nx][ny])continue;
	  stt[nx][ny]=1;
	  qx.push(nx);
	  qy.push(ny);
	}
      }
      if(ct%x)return 0;
      if(!cbf(ccp,x))return 0;
    }
  }
  return 1;
}
bool cbp(VVI bd){
  for(in i=0;i+sz(bd)<=r;i++){
    for(in j=0;j+sz(bd[0])<=c;j++){
      if(isgp(bd,i,j))
	return 1;
    }
  }
  return 0;
}
bool beats(VVI bd){
  if(cbp(bd))return 0;
  if(cbp(rot(bd)))return 0;
  return 1;
}
void docase(){
  cin>>x>>r>>c;
  if(r>c)swap(r,c);
  if((r*c)%x){
    imp();
    return;
  }
  if(x>c){
    imp();
    return;
  }
  if(x>=2*(r+1)){
    imp();
    return;
  }
  if(x>=7){
    imp();
    return;
  }
  /*if(r>=4 && c>=7){
    pos();
    return;
  }
  if(r<=3 && x==6){
    imp();
    return;
    }*/ //sounds right but not sure
  gendom();
  fors(i,doms){
    if(beats(i->cd)){
      imp();
      return;
    }
  }
  pos();
}
int main(){
  in T;
  cin>>T;
  for(in zz=1;zz<=T;zz++){
    cout<<"Case #"<<zz<<": ";
    docase();
  }
  return 0;
}
