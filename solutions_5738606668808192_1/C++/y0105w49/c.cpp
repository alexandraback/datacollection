#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin>>t; for(int zz=1;zz<=t;zz++) {
    printf("Case #%d:\n",zz);
    int n,j;
    cin>>n>>j;
    n/=2;
    for(int i=0;i<j;i++) {
      int d=1<<(n-2);
      string s="1";
      for(;d/=2;) s+=(d&i)?'1':'0';
      s+='1';
      cout<<s<<s;
      for(int p=2;p<=10;p++) {
        long long q=1; for(int r=0;r<n;r++) q*=p;
        ++q;
        cout<<" "<<q;
      }
      cout<<endl;
    }
  }
}
