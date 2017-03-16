#include<bits/stdc++.h>
using namespace std;
int Tc;
int n,t[2000];
string s;

void solve(){
  int ans=0,cnt=t[0];
  for(int i=1;i<=n;i++){
    if(t[i]==0)continue;

    if(cnt<i){
      ans+=(i-cnt);
      cnt=i;
    }
    cnt+=t[i];
  }
  cout<<ans<<endl;
}

int main(){
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cout<<"Case #"<<tc<<": ";
    cin>>n>>s;
    for(int i=0;i<=n;i++)t[i]=s[i]-'0';
    solve();
  }
  return 0;

}
