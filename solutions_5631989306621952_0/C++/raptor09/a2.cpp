#include <bits/stdc++.h>

#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define INF 2147483647
#define pi acos(-1.0)
#define EPS 1e-9
#define INF_LONG 9223372036854775807LL
#define Set(a, s) memset (a, s, sizeof (a))
#define trace(s,v) printf("%s => %d\n",s,v)
#define SSTR( x ) dynamic_cast< std::ostringstream & > (( std::ostringstream() << std::dec << x )).str()
#define debug(t,n) cout<<">"<<(t)<<"="<<(n)<<"\n";
#define b(x) cout<<(x)<<endl;

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

int main() {
  ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

  int tc,k = 1;
  string s;
  cin>>tc;
  while(tc--){
	  cin>>s;
	  string nc = SSTR(s[0]);
	  rep(i,1,s.length()){
		  if(s[i] >= nc[0]){
			  nc = s[i]+nc;
		  }else{
			  nc+=s[i];
		  }
	  }
	  cout<<"Case #"<<(k++)<<": "<<nc<<"\n";
  }
  
  return 0;
}
