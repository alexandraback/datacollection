#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define _ ios::sync_with_stdio(false);
//#define mem(x,x) memset(x,(x),(int)(sizeof(x)))
#define pii pair<int,int>
#define fr(i,x,n) for(int i=(x);i<=(n);i++)
#define frd(i,x,n) for(int i=(x);i>=(n);i--)
#define nl cout<<endl
#define sp cout<<" "
#define pb push_back
#define mp make_pair 
#define F first 
#define S second
#define V vector
#define si size()
ll mod=1e9+7;
map<string, int> mapb, mapa;
string x[20],y[20];
int main(){_
  int t;
  cin >> t;
  fr(Z,1,t){
    int n;cin >> n;
    mapa.clear();
    mapb.clear();
    fr(i,0,n-1)
      cin>>x[i]>>y[i];
    //../and
    int res = 0;
    for(int i = 0; i < (1 << n); i++){
      mapa.clear(), mapb.clear();
      int cans = 0;
		
		      for(int j = 0; j < n; j++){
		        if(not (i & (1 << j))){
		          mapa[x[j]] ++;
		          mapb[y[j]] ++;
		        }
      }
	for(int j = 0; j < n; j++){
	   
	  if((i & (1 << j)) and mapa[x[j]] > 0 and mapb[y[j]] > 0){
	  cans++;
	}
}
     
      if(cans == __builtin_popcount(i)){
        res = max(res, cans);
      }
    }
    cout<<"Case #"<<Z<<": ";
    cout<<res<<endl;
  }
  return 0;
}