#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstdlib>
#include<queue>
#include<cmath>

using namespace std;

typedef long long ll;

ll P;
vector<ll> fac;



int main(){
  int T; cin>>T;
  P=1000000007;
  fac=vector<ll>(200, 1);
  for (int i=1; i<200; ++i){
    fac[i]=i*fac[i-1];
    fac[i]%=P;
  }
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    int n; cin>>n;
    vector<string> v(n,"");
    for (int i=0; i<n; ++i)
      cin>>v[i];
    vector<int> first(26, -1);
    vector<int> second(26, -1);
    vector<int> free(26,0);
    bool ja=1;
    ll ans;
    for (int i=0; ja && i<n; ++i)
      for (int j=1; ja && j<v[i].size(); ++j)
	if (v[i][j]!=v[i][j-1]){
	  if (first[v[i][j]-'a']!=-1 || second[v[i][j-1]-'a']!=-1){
	    ja=0;
	    //cout<<"hei"<<endl;
	  }
	  first[v[i][j]-'a']=i;
	  second[v[i][j-1]-'a']=i;
	}
    for (int i=0; i<n; ++i){
      if (v[i].size()==1){
	free[v[i][0]-'a']++;
	//cout<<v[i][0]<<endl;
      }
      for (int j=1; j<v[i].size(); ++j){
	if (v[i][j]!=v[i][j-1])
	  break;
	if (j+1==v[i].size())
	  free[v[i][j]-'a']++;
      }
    }
    for (int i=0; 0 && i<26; ++i)
      cout<<first[i]<<" "<<second[i]<<" "<<free[i]<<char('a'+i)<<endl;
    for (int i=0; i<26; ++i){
      if (first[i]!=-1 && first[i]==second[i] && free[i]!=0){
	ja=0;
	//cout<<"halla"<<endl;
      }
      if (first[i]!=-1 && first[i]==second[i] && v[first[i]][0]==v[first[i]][v[first[i]].size()-1])
	ja=0;
    }
    
    if (!ja){
      cout<<0<<endl;
      continue;
    }

    //cout<<"hei"<<endl;
    vector<int> u(26,0);
    int chains=0;
    for (int i=0; i<26; ++i){
      if (first[i]!=-1 && first[i]!=second[i] && first[v[first[i]][0]-'a']==-1){
	chains++;
	int j=i;
	while(1){
	  u[j]=1;
	  if (second[j]==-1)
	    break;
	  j=v[second[j]][v[second[j]].size()-1]-'a';
	}
      }
    }
    for (int i=0; i<26; ++i)
      if (u[i]==0 && first[i]!=-1 && second[i]!=-1 && first[i]!=second[i])
	ja=0;
    if (!ja){
      cout<<0<<endl;
      continue;
    }
    for (int i=0; i<26; ++i)
      if (u[i]==0 && free[i]!=0)
	++chains;
    
    ans=fac[chains];
    for (int i=0; i<26; ++i){
      ans*=fac[free[i]];
      ans%=P;
    }
    cout<<ans<<endl;
    //cout<<chains<<endl;
    
  }
  return 0;
}
