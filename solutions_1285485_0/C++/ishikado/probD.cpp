#include <iostream>
#include <vector>
#include <algorithm>
#include <complex>
#include <set>
#include <cmath>

using namespace std;

const double EPS=(1e-9);
typedef complex<double> P;

// 内積
double dot(P a, P b) {
  return (a.real() * b.real() + a.imag() * b.imag());
}
// 外積
double cross(P a, P b) {
  return (a.real() * b.imag() - a.imag() * b.real());
}
// 点a,bを端点とする線分と点cとの距離
double distance_ls_p(P a, P b, P c) {
  if ( dot(b-a, c-a) < EPS ) return abs(c-a);
  if ( dot(a-b, c-b) < EPS ) return abs(c-b);
  return abs(cross(b-a, c-a)) / abs(b-a);
}

//typedef pair<int,int> pii;
typedef pair<double,double> pdd;
class Vec{
public:
  double val[2];
  bool operator<(const Vec &vec)const{
    if(abs(val[0]-vec.val[0])<EPS
       &&abs(val[1]-vec.val[1])<EPS)return false;
    else if(abs(val[0]-vec.val[0])<EPS){
      if(vec.val[1]<this->val[1])return true;
      else if(vec.val[1]>this->val[1])return false;
    }
    else if(vec.val[0]<this->val[0])return true;
    else return false;
    //else if(vec.val[0]>this->val[0])return false;
  }
};

int main(){
  int t;
  cin>>t;
  for(int l=0;l<t;l++){
    int h,w,d;
    cin>>h>>w>>d;
    char ch;
    double px,py;
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cin>>ch;
	if(ch=='X'){
	  px=(j-0.5);
	  py=(i-0.5);
	}
      }
    }
    //P cp=P(px,py);
    w-=2;h-=2;
    int res=0;
    vector<pdd> ps;
    const int lim=100;
    for(int i=-lim;i<=lim;i++){
      for(int j=-lim;j<=lim;j++){
	if(i==j&&i==0)continue;
	// 指定マスの座標との距離を調べる
	double ox,oy;
	if(abs(j)%2==0){
	  if(j<0)ox=px-(px+(w-px))*abs(j);
	  else ox=px+(px+(w-px))*j;
	}
	else if(j<0)ox=px-(2*px*(1+abs(j)/2)+2*(w-px)*(abs(j)/2));
	else ox=px+(2*px*(j/2)+2*(w-px)*(1+j/2));
	if(abs(i)%2==0){
	  if(i<0)oy=py-(py+(h-py))*abs(i);
	  else oy=py+(py+(h-py))*i;
	}
	else if(i<0)oy=py-(2*py*(1+abs(i)/2)+2*(h-py)*(abs(i)/2));
	else oy=py+(2*py*(i/2)+2*(h-py)*(1+i/2));
	double dist=sqrt((ox-px)*(ox-px)+(oy-py)*(oy-py));
	if(abs(dist-d)<EPS||dist<d)
	  ps.push_back(pdd(oy,ox));
      }
    }
    set<Vec> spd;
    P p2=P(px,py);
    for(int i=0;i<ps.size();i++){
      P p1=P(ps[i].second,ps[i].first);
      P e=(p1-p2)/abs(p1-p2);
      pdd tmp=pdd(e.real(),e.imag());
      Vec v;
      v.val[0]=e.real();
      v.val[1]=e.imag();
      // // まだ存在しない向きの場合
      if(spd.count(v)==0){
       	spd.insert(v);
       	res++;
      }
    }
    cout<<"Case #"<<l+1<<": "<<res<<endl;
  }

  return 0;
}

