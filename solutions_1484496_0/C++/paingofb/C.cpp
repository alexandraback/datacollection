#include<iostream>

using namespace std;

typedef long long int LL;
LL s[600];
LL set1[600];
LL set2[600];

int n;
bool compute(int x, LL s1, LL s2, int x1, int x2){
  if (s1 == s2 && s1 !=0){
    cout<<endl;
    for(int i=0; i<x1; ++i){
      cout<<set1[i]<<" ";
    }
    cout<<endl;
    for(int i=0; i<x2; ++i){
      cout<<set2[i]<<" ";
    }
    cout<<endl;
    return true;
  } else if (x == n) return false;

//  cerr<<x<<" "<<s1<<" "<<s2<<" "<<x1<<" "<<x2<<endl;
  LL cur = s[x];

  set1[x1] = cur;
  if (compute(x+1, s1+cur, s2, x1+1, x2)) {
    return true;
  }
  set1[x1] = 0;

  set2[x2] = cur;
  if (compute(x+1, s1, s2+cur, x1, x2+1)) return true;
  set2[x2] = 0;

  if (compute(x+1, s1, s2, x1, x2)) return true;
  return false;
}
int main(){
  int cas;
  cin>>cas;
  for(int ca=1;ca<=cas;++ca){
    cin>>n;
    for(int i=0; i<n; ++i){
      cin>>s[i];
    }
    cout<<"Case #"<<ca<<": ";
    if (!compute(0, 0, 0, 0, 0)) {
      cout<<" Impossible"<<endl;
    }
  }
}
