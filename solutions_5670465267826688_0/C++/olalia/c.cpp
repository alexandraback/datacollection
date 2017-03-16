#include<iostream>

using namespace std;

typedef long long ll;

int ijk(char c){
  return c-'h';
}

int x(int a, int b){
  int c=a^b;
  if ((a%4) && (b%4))
    if(1!=(((b%4)-(a%4)+3)%3))
      c^=4;
  return c;
}

int main(){
  int T; cin>>T;
  for (int tc=1; tc<=T; ++tc){
    int L; ll X;
    cin>>L>>X;
    string s; cin>>s;
    cout<<"Case #"<<tc<<": ";
    int midt=0;
    for (int i=0; i<L; ++i)
      midt=x(midt, ijk(s[i]));
    int dua=0;
    for (int i=0; i<(X%4); ++i)
      dua=x(dua, midt);
    if (dua!=4){
      cout<<"NO\n";
      continue;
    }
    int sta=0;
    int stal=4*L;
    for (int i=0; i<L; ++i){
      sta=x(sta, ijk(s[i]));
      for (int j=0; j<4; ++j){
	if (sta==1)
	  stal=min(stal, i+1+j*L);
	sta=x(midt, sta);
      }
    }
    
    int slu=0; int slul=4*L;
    for (int i=L-1; i>-1; --i){
      slu=x(ijk(s[i]), slu);
      for (int j=0; j<4; ++j){
	if (slu==3)
	  slul=min(slul, L-i+j*L);
	slu=x(slu, midt);
      }
    }
    ll heia=slul + stal;
    ll hoi=X*L;
    if (slul<4*L && stal<4*L && heia<hoi)
      cout<<"YES\n";
    else
      cout<<"NO\n";
  }
  return 0;
}
