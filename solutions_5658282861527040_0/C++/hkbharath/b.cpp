#include <bits/stdc++.h>

using namespace std;

#define p_b(a,b) a.push_back(b)
#define all(a) (a.begin(),a.end())
#define m_p(a,b) make_pair(a,b)
#define sort(a) sort((all(a)))

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

void solve(){
  int a,b,k;
  cin>>a>>b>>k;
  ll sol=0;
  for(int i=0;i<a;i++)
    for(int j=0;j<b;j++){
      if((int) (i&j) < k)
	sol++;
      //cout<<(int)(i&j)<<endl;
    }
  cout<<sol<<endl;
}

int main(){
  int t,prob=1;
  cin>>t;
  while(t--){
    cout<<"Case #"<<prob++<<": ";
    solve();
  }
}
