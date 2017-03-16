#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
#include <vector>

#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

struct attack {
  int d,w,e,s;
};

bool cmp(attack a,attack b){
  return a.d<b.d;
}


int cs,tbcnt,d,n,w,e,s,dd,dp,ds,h[420];

int main(){

  cin>>cs;
  rep(ii,cs){
    vector<attack> vec;
    fill(h,h+420,0);

    cin>>tbcnt;
    rep(i,tbcnt){
      cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
      w+=200;e+=200;e--;
      rep(j,n){
	attack nat;
	nat.d = d+dd*j;
	nat.s = s+ds*j;
	nat.w = max(w+dp*j,0);
	nat.e = min(e+dp*j,400);
	vec.push_back(nat);
      }
    }
    sort(vec.begin(),vec.end(),cmp);
    //rep(i,vec.size()){
    //cout<<"day : "<<vec[i].d<<" "<<vec[i].w<<" "<<vec[i].e<<" "<<vec[i].s<<endl;
    //}
    
    int cday = 0;
    int ret  = 0;
    int sz = vec.size();
    int p  = 0;

    while(p<sz){
      cday = vec[p].d;
      int pe = p;
      while(pe<sz && vec[pe].d==cday)pe++;
      for(int i=p;i<pe;i++){
	int cw = vec[i].w;
	int ce = vec[i].e;
	int ca = vec[i].s;
	for(int j=cw;j<=ce;j++){
	  if(h[j]<ca){
	    ret++;
	    //cout<<i<<" "<<j<<" "<<h[j]<<" "<<ca<<endl;
	    break;}
	}
      }
      for(int i=p;i<pe;i++){
	int cw = vec[i].w;
	int ce = vec[i].e;
	int ca = vec[i].s;
	for(int j=cw;j<=ce;j++)h[j]=max(h[j],ca);
      }
      p=pe;
    }
    cout<<"Case #"<<ii+1<<": "<<ret<<endl;
  }


}
