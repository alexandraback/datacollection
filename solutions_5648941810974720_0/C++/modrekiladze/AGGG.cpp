#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <set>
#include <stack>
#include <iterator>
#include <queue>
#include <string>
#include <sstream>
#include <fstream>
#define pb push_back
#define fs first
#define sc second
#define mp make_pair
using namespace std;
int main() {
  ifstream cin("A-small-attempt1.in");
  ofstream cout("out2.txt");
  string s;
  int T;
  cin>>T;
  for(int t=1;t<=T;t++)
  {
  cin>>s;
  vector<int> a(26,0);
  vector<int> v;
  for(int i=0;i<s.size();i++)
      a[s[i]-'A']++;
  int k=a['Z'-'A'];
  a['Z'-'A']-=k;
  a['R'-'A']-=k;
  a['E'-'A']-=k;
  a['O'-'A']-=k;
  while(k)
  {
      v.pb(0);
      k--;
  }
  //cout<<a['F'-'A']<<endl;
  k=a['W'-'A'];
  a['W'-'A']-=k;
  a['T'-'A']-=k;
  a['O'-'A']-=k;
  while(k)
  {
      v.pb(2);
      k--;
  }
//cout<<a['F'-'A']<<endl;
  k=a['G'-'A'];
  a['G'-'A']-=k;
  a['H'-'A']-=k;
  a['T'-'A']-=k;
  a['E'-'A']-=k;
  a['I'-'A']-=k;
  while(k)
  {
      v.pb(8);
      k--;
  }
 //cout<<a['F'-'A']<<endl;
  k=a['X'-'A'];
  a['X'-'A']-=k;
  a['I'-'A']-=k;
  a['S'-'A']-=k;
  while(k)
  {
      v.pb(6);
      k--;
  }

//cout<<a['F'-'A']<<endl;
//cout<<"@@@"<<endl;
   k=a['H'-'A'];
  a['H'-'A']-=k;
  a['T'-'A']-=k;
  a['R'-'A']-=k;
  a['E'-'A']-=2*k;
  while(k)
  {
      v.pb(3);
      k--;
  }
  //cout<<a['F'-'A']<<"@@@@"<<endl;
  k=a['R'-'A'];
  a['R'-'A']-=k;
  a['F'-'A']-=k;
  a['U'-'A']-=k;
  a['O'-'A']-=k;
  while(k)
  {
      v.pb(4);
      k--;
  }
//cout<<a['F'-'A']<<endl;

   k=a['F'-'A'];
  // cout<<k<<endl;
  a['F'-'A']-=k;
  a['I'-'A']-=k;
  a['V'-'A']-=k;
  a['E'-'A']-=k;
  while(k)
  {
      v.pb(5);
      k--;
  }
//cout<<"@@@@"<<endl;
   k=a['O'-'A'];
  a['O'-'A']-=k;
  a['N'-'A']-=k;
  a['E'-'A']-=k;
  while(k)
  {
      v.pb(1);
      k--;
  }
  //cout<<"@@@@"<<endl;

  k=a['V'-'A'];
  a['S'-'A']-=k;
  a['E'-'A']-=k;
  a['E'-'A']-=k;
  a['V'-'A']-=k;
  a['N'-'A']-=k;
  while(k)
  {
      v.pb(7);
      k--;
  }

  k=a['I'-'A'];
  while(k)
  {
      v.pb(9);
      k--;
  }
  //cout<<"####"<<endl;

  sort(v.begin(),v.end());
  cout<<"Case #"<<t<<": ";
  for(int i=0;i<v.size();i++)
    cout<<v[i];
  cout<<endl;
  v.clear();
}
    return 0;
}
