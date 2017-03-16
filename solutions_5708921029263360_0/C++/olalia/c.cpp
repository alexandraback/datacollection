#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>





using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> wi;

int J,P,S,K;

int nu(vector<int> v){
  return v[0]*P*S+v[1]*S+v[2];
}

using namespace std;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    cin>>J>>P>>S>>K;
    int n=J*P*S;
    wi u(J*P*S, vi(3,0));
    for (int i=0; i<n; ++i){
      u[i][0]=i/P/S;
      u[i][1]=(i/S)%P;
      u[i][2]=i%S;
    }
    vi x(P*S,0), y(J*S,0), z(J*P,0);
    set<int> s=set<int>();

    vector<int> tal(3,J);
    tal[1]=P;
    tal[2]=S;

    vector<int> abc(3,0);
    int ans=0;
    for (int i=0; i<n; ++i){
      for (int j=0; j<3; ++j){
	abc[j]+=1;
	abc[j]%=tal[j];
	if (s.find(nu(abc))!=s.end() || x[abc[1]*S+abc[2]]==K || y[abc[0]*S+abc[2]]==K || z[abc[0]*P+abc[1]]==K)
	  continue;
	x[abc[1]*S+abc[2]]++;
	y[abc[0]*S+abc[2]]++;
	z[abc[0]*P+abc[1]]++;
	s.insert(nu(abc));
	u[ans]=abc;
	++ans;
      }
    }
    cout<<ans<<endl;
    for (int i=0; i<ans; ++i){
      for (int j=0; j<3; ++j){
	cout<<u[i][j]+1<<" ";
      }
      cout<<endl;
    }





  }



  return 0;
}
