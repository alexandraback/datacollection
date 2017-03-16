#include<bits/stdc++.h>
using namespace std;
string a,b;
int n,m,r;

bool check();
double solve();

int main(){
  int Tc;
  cin>>Tc;
  for(int tc=1;tc<=Tc;tc++){
    cin>>n>>m>>r;
    cin>>a>>b;
    cout<<"Case #"<<tc<<": ";
    printf("%.8f\n",solve());
  }
  return 0;
}


bool check(){
  for(int i=0;i<m;i++){
    int flg=false;
    for(int j=0;j<n;j++)
      if(b[i]==a[j])flg=true;
    if(!flg)return true;
  }
  return false;
}

double solve(){
  if(check() || r<m) return 0;

  int maxm=0,id=0;
  char t[200];
  for(int i=0;i<200;i++)t[i]='.';

  for(int i=0;i+m<=r;i++){
    bool flg=true;
    for(int j=0;j<m;j++)
      if(t[i+j]!='.'&&t[i+j]!=b[j])
	flg=false;
    if(!flg)continue;
    maxm++;
    for(int j=0;j<m;j++)t[i+j]=b[j];
  }
  /*
  for(int i=0;i<r;i++){
    cout<<t[i];
  }
  cout<<endl;
  */
  int cnt[26]={};
  double p[26];
  for(int i=0;i<n;i++)cnt[a[i]-'A']++;
  for(int i=0;i<26;i++)
    p[i]=(double)cnt[i]/(double)n;
  double P= r-m+1;
  for(int i=0;i<m;i++)
    P*=p[ b[i]-'A' ];

  return maxm-P;
}
