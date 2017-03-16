#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define pb push_back
#define F first
#define S second
int main(){int t; cin>>t; rep(tc,t){string st; cin>>st; string cstr="a"; cstr[0]=st[0]; rep(i,st.size()){if(i!=0){if(st[i]>=cstr[0]){cstr=st[i]+cstr; } else{cstr=cstr+st[i]; } } } cout<<"Case #"<<tc+1<<": "; cout<<cstr<<"\n"; } return 0; }