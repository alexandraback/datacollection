#include<iostream>
#include<cstdio>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<iomanip>
#include<algorithm>
#include<cmath>
#include<string>





using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<vi> wi;





using namespace std;


struct p{
  ll c;
  ll j;
};

bool operator<(const p &a, const p &b){
  if (abs(a.c-a.j)<abs(b.c-b.j))
    return 1;
  if (abs(a.c-a.j)>abs(b.c-b.j))
    return 0;
  if (a.c<b.c)
    return 1;
  if (a.c>b.c)
    return 0;
  return a.j<b.j;
}


ll big(string s, int k){
  ll r=0;
  for (int i=k; i<s.size(); ++i){
    ll x;
    if (s[i]=='?')
      x=9;
    else
      x=s[i]-'0';
    r+=x*pow(10,s.size()-i-1);
  }
  return r;
}

ll sma(string s, int k){
  ll r=0;
  for (int i=k; i<s.size(); ++i){
    ll x;
    if (s[i]=='?')
      x=0;
    else
      x=s[i]-'0';
    r+=x*pow(10,s.size()-i-1);
  }
  return r;
}


void printit(ll a, int n){
  ll ti=10;
  for (int i=0; i<n; ++i){
    ll b=a/pow(10,n-1-i);
    cout<<(b%ti);
  }
  return;
}


int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    cout<<"Case #"<<tc<<": ";
    string C, J;
    cin>>C>>J;
    ll c=0; ll j=0;
    p pi;
    p bes;
    bes.c=1000000000000000001;
    bes.j=0;
    int n=C.size();
    bool ja=1;
    ll ti=10;
    for (int i=0; i<C.size(); ++i){
      if ((C[i]=='?') && (J[i]=='?')){
	pi.c=c+big(C, i+1); pi.j=j+sma(J, i+1)+pow(ti, n-1-i);
	if (pi<bes)
	  bes=pi;
	pi.c=c+sma(C,i+1)+pow(ti,n-1-i); pi.j=j+big(J,i+1);
	if (pi<bes)
	  bes=pi;
	continue;
      }
      if (C[i]=='?'){
	if (J[i]!='9'){
	  pi.c=c+(1+J[i]-'0')*pow(ti, n-1-i)+sma(C, i+1);
	  pi.j=j+big(J,i);
	  if (pi<bes)
	    bes=pi;
	}
	if (J[i]!='0'){
	  pi.c=c+(-1+J[i]-'0')*pow(ti,n-1-i)+big(C,i+1);
	  pi.j=j+sma(J,i);
	  if (pi<bes)
	    bes=pi;
	}
	c+=pow(ti,n-1-i)*(J[i]-'0');
	j=c;
	continue;
      }
      if (J[i]=='?'){
	if (C[i]!='9'){
	  pi.j=j+(1+C[i]-'0')*pow(ti,n-1-i)+sma(J, i+1);
	  pi.c=c+big(C,i);
	  if (pi<bes)
	    bes=pi;
	}
	if (C[i]!='0'){
	  pi.j=j+(-1+C[i]-'0')*pow(ti,n-1-i)+big(J,i+1);
	  pi.c=c+sma(C,i);
	  if (pi<bes)
	    bes=pi;
	}
	c+=pow(ti,n-1-i)*(C[i]-'0');
	j=c;
	continue;
      }
      if (J[i]==C[i]){
	c+=pow(10,n-1-i)*(C[i]-'0');
	j=c;
	continue;
      }
      pi.c=c+sma(C,i);
      pi.j=j+big(J,i);
      //cout<<c<<" "<<sma(C,i)<<endl;
      if (pi<bes)
	bes=pi;
      pi.c=c+big(C,i);
      pi.j=j+sma(J,i);
      if (pi<bes)
	bes=pi;
      ja=0;
      break;
    }
    pi.c=c;
    pi.j=j;
    if (ja && pi<bes)
      bes=pi;
    printit(bes.c,n);
    cout<<" ";
    printit(bes.j,n);
    cout<<endl;
    //cout<<" "<<C<<" "<<J<<" "<<bes.j<<" "<<bes.c<<endl;





  }



  return 0;
}
