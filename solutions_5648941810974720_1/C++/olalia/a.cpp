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
    string s; cin>>s;
    vector<int> v(26,0);
    for (int i=0; i<s.size(); ++i)
      v[s[i]-'A']++;
    vi u(10,0);
    u[0]=v[25];
    u[2]=v['W'-'A'];
    u[3]=v['H'-'A']-v['G'-'A'];
    u[4]=v['R'-'A']-u[0]-u[3];
    u[5]=v[5]-u[4];
    u[6]=v['X'-'A'];
    u[7]=v['V'-'A']-u[5];
    u[8]=v['G'-'A'];
    u[9]=v['I'-'A']-u[8]-u[6]-u[5];
    u[1]=v['N'-'A']-2*u[9]-u[7];
    for (int i=0; i<10; ++i)
      for (int j=0; j<u[i]; ++j)
	cout<<i;
    cout<<endl;





  }



  return 0;
}
