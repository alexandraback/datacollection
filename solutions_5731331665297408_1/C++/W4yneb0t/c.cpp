#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
using namespace std;
typedef long long in;
in n,m;
vector<in> zip;
struct cttv{
  in loc;
  cttv(in a=0){
    loc=a;
  }
  bool operator<(const cttv cp)const{
    return zip[loc]<zip[cp.loc];
  }
};
struct stt{
  vector<in> zsf;
  vector<vector<bool> > egs;
  vector<bool> seen;
  vector<in> stck;
  vector<cttv> cvs;
  void gnv(){
    cvs.clear();
    vector<bool> pushd;
    pushd.resize(n,0);
    forv(i,stck){
      forn(j,n){
	if(!egs[stck[i]][j])
	  continue;
	if(seen[j])
	  continue;
	in ceg=j;
	if(pushd[ceg])
	  continue;
	cvs.PB(cttv(ceg));
	pushd[ceg]=1;
      }
    }
    sort(cvs.begin(),cvs.end());
  }
  void visit(in a){
    assert(sz(stck)>0);
    in act=stck[sz(stck)-1];
    bool fd=egs[act][a];
    if(!fd){
      forn(i,n){
	egs[act][i]=egs[i][act]=0;
      }
      stck.resize(sz(stck)-1);
      visit(a);
      return;
    }
    seen[a]=1;
    zsf.PB(zip[a]);
    stck.PB(a);
  }
  bool isok(){
    vector<bool> vsts;
    vsts.resize(n,0);
    queue<in> q;
    forn(i,n){
      if(seen[i]){
	q.push(i);
	vsts[i]=1;
      }
    }
    while(!q.empty()){
      in u=q.front();
      q.pop();
      forn(i,n){
	if(egs[u][i] && !vsts[i]){
	  q.push(i);
	  vsts[i]=1;
	}
      }
    }
    bool ok=1;
    forn(i,n)
      if(!vsts[i])
	ok=0;
    return ok;
  }
  void go(){
    forv(i,cvs){
      stt tp=*this;
      tp.visit(cvs[i].loc);
      if(tp.isok()){
	*this=tp;
	return;
      }
    }
    assert(0);
  }
};
vector<vector<bool> > megs;
int main(){
  in tt;
  cin>>tt;
  for(in zz=1;zz<=tt;zz++){
    cout<<"Case #"<<zz<<": ";
    cin>>n>>m;
    zip.resize(n);
    megs.clear();
    megs.resize(n,vector<bool>(n,0));
    forn(i,n)
      cin>>zip[i];
    forn(i,m){
      in ta,tb;
      cin>>ta>>tb;
      ta--;
      tb--;
      megs[ta][tb]=1;
      megs[tb][ta]=1;
    }
    stt ms;
    ms.zsf.clear();
    ms.egs=megs;
    ms.seen.clear();
    ms.seen.resize(n,0);
    in mnm=0;
    forn(i,n)
      if(zip[i]<zip[mnm])
	mnm=i;
    ms.stck.PB(mnm);
    ms.zsf.PB(zip[mnm]);
    ms.seen[mnm]=1;
    assert(ms.isok());
    while(1){
      ms.gnv();
      if(sz(ms.cvs)==0)
	break;
      ms.go();
    }
    forv(i,ms.zsf){
      cout<<ms.zsf[i];
    }
    cout<<endl;
  }
  return 0;
}

