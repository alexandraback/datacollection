#include<bits/stdc++.h>
#define ft first
#define sd second
#define pb push_back
using namespace std;

typedef long long ll;

const int N = 1100000;

int main(){
  ios_base::sync_with_stdio(0);
  int t;
  cin >> t;
  for(int tt = 1; tt <= t; tt++){
    ll n, m;
    cin >> n >> m;
    cout<<"Case #"<<tt<<": ";
    ll pot = (1<<(n-2));
    if(pot < m){
      cout<<"IMPOSSIBLE\n";
      continue;
    }
    cout<<"POSSIBLE\n";
    if(m == pot){
      cout<<"0";
      for(int i = 1; i < n; i++) cout<<"1";
      cout<<"\n";
    }
    else{
      string s = "0";
      for(int i = 1; i < n - 1; i++){
	s += char('0' + m%2);
	m /= 2;
      }
      s += '0';
      for(int j = n - 1; j >= 0; j--) cout<<s[j];
      cout<<"\n";
    }
    for(int i = 1; i < n; i++){
      for(int j = 0; j <= i; j++) cout<<"0";
      for(int j = i + 1; j < n; j++) cout<<"1";
      cout<<"\n";
    }
  }
}