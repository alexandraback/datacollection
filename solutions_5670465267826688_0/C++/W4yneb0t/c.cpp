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
string tp;
pair<in,in> mult(in sgn, in val, in val2){
  in osg=1-2*sgn;
  if(val>0 && val2>0){
    if((val2-val+3)%3!=1)
      osg*=-1;
  }
  sgn=(1-osg)/2;
  if(val>val2)
    swap(val,val2);
  if(val==0)
    return MP(sgn,val2);
  if(val==val2)
    return MP(sgn,0);
  for(in i=1;i<=3;i++)
    if(i!=val && i!=val2)return MP(sgn,i);
  assert(0);
  return MP(0,0);
}
vector<VVI> upd(vector<VVI> pos, in nu){
  vector<VVI> ret(3,VVI(2,VI(4,0)));
  pair<in,in> tp;
  forn(pdn,3){
    forn(sgn,2){
      forn(val,4){
	if(!pos[pdn][sgn][val])continue;
	if(pdn<2 && sgn==0 && val==pdn+1)
	  ret[pdn+1][0][nu]=1;
	tp=mult(sgn,val,nu);
	ret[pdn][tp.first][tp.second]=1;
      }
    }
  }
  return ret;
}
vector<VVI> pos;
int main(){
  in T;
  cin>>T;
  in l,x;
  for(in zz=1;zz<=T;zz++){
    pos.clear();
    pos.resize(3,VVI(2,VI(4,0)));
    pos[0][0][0]=1;
    cin>>l>>x;
    cin>>tp;
    cout<<"Case #"<<zz<<": ";
    if(x>=15){
      x-=15;
      x%=4;
      x+=15;
    }
    forn(i,x){
      forv(j,tp){
	pos=upd(pos,tp[j]-'h');
      }
    }
    if(pos[2][0][3])
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
  }
  return 0;
}
