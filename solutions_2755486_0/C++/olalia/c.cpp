#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>



using namespace std;

struct attack{
  int d;
  int w, e, s;
};

bool operator<(const attack &a, const attack &b){
  return a.d<b.d;
}




int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int N; cin>>N;
    vector<attack> v;
    for (int i=0; i<N; ++i){
      int d, n, w, e, s, dd, dp, ds;
      cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
      for (int j=0; j<n; ++j){
	attack a;
	a.d=d+j*dd;
	a.w=w+j*dp;
	a.e=e+j*dp;
	a.s=s+j*ds;
	v.push_back(a);
	//cout<<a.d<<" "<<a.w<<" "<<a.e<<" "<<a.s<<endl;
      }
    }
    sort(v.begin(), v.end());
    vector<int> w1, w2;
    int dL=500;
    w1=vector<int>(2*dL, 0);
    w2=w1;
    int d=-1;
    int ans=0;
    for (int i=0; i<v.size(); ++i){
      if (v[i].d>d)
	w1=w2;
      d=v[i].d;
      //cout<<d<<endl;
      for (int j=v[i].w; j<v[i].e;++j){
	if (w1[j+dL]<v[i].s){
	  ++ans;
	  break;
	}
      }
      for (int j=v[i].w; j<v[i].e; ++j)
	w2[j+dL]=max(w2[j+dL], v[i].s);
    }



    
    cout<<"Case #"<<tc<<": "<<ans<<endl;
  }
  return 0;
}
