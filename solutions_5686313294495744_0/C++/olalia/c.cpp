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





using namespace std;


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    int n; cin>>n;
    map<string, int> ma=map<string, int>(), mb=ma;
    vector<string> a(n,"");
    vector<string> b=a;
    for (int i=0; i<n; ++i){
      cin>>a[i]>>b[i];
      ma[a[i]]+=1;
      mb[b[i]]+=1;
    }
    vector<bool> u(n,0);
    map<string, int> m1=map<string,int>(), m2=m1;
    for (int i=0; i<n; ++i){
      if ((ma[a[i]]==1) || (mb[b[i]]==1)){
	m1[a[i]]+=1;
	m2[b[i]]+=1;
	u[i]=1;
      }
    }
    int ans=0;
    for (int i=0; i<n; ++i){
      if (u[i])
	continue;
      if (m1[a[i]]>0 && m2[b[i]]>0)
	++ans;
      m1[a[i]]+=1;
      m2[b[i]]+=1;
    }
    cout<<ans<<endl;



  }



  return 0;
}
