#include<bits/stdc++.h>
using namespace std;
#define MAX 1005
#define INF 1005
int n;
int t[MAX];


int solve(){
  int ans=INF;

  for(int i=1;i<MAX;i++){
    int cnt=0;
    for(int j=0;j<n;j++){
      if(t[j]<=i)continue;
      cnt+=(t[j]/i);
      if(t[j]%i==0)cnt--;
    }
    ans=min(ans,i+cnt);
  }//i
  return ans;
}

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){   
    cin>>n;
    for(int i=0;i<n;i++)cin>>t[i];
    cout<<"Case #"<<tc<<": "<<solve()<<endl;
  }
  return 0;
}
