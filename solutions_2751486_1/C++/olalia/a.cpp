#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<set>


using namespace std;

typedef long long ll;

int main(){
  int T; cin>>T;
  set<char> wow;
  wow.insert('a');
  wow.insert('e');
  wow.insert('i');
  wow.insert('o');
  wow.insert('u');
  for (int tc=1; tc<=T; ++tc){
    string s; int n; cin>>s>>n;//scanf("%s %d", &s, &n);
    vector<int> v;
    int c=0;
    int L=s.size();
    for (int i=0; i<L; ++i){
      if (wow.find(s[i])==wow.end())
	++c;
      else
	c=0;
      if (c>=n)
	v.push_back(i);
    }
    vector<int> w(L,-1);
    c=0;
    for (int i=0; i<L; ++i){
      while (c<v.size() && v[c]-i<n-1)
	++c;
      if (c==v.size())
	break;
      w[i]=v[c];
    }
    ll ans=0;
    for (int i=0; i<L; ++i){
      if (w[i]!=-1)
	ans+=L-w[i];
    }



    
    cout<<"Case #"<<tc<<": "<<ans<<endl;
  }
  return 0;
}
