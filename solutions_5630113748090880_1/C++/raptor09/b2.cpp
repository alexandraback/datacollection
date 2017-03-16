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

  int tc, n, x, k = 1;
  int H[2500+10];
  cin>>tc;
  while(tc--){
	  cout<<"Case #"<<(k++)<<":";
	  Set(H,0);
	  cin>>n;
	  int r = (2*n-1)*n;
	  while(r--){
		  cin>>x;
		  H[x]++;
	  }
	  int sw = 1;
	  rep(i,1,2501){
		  if(H[i]&1){
			  cout<<" "<<i;
		  }
	  }
	  cout<<"\n";
  }
  
  return 0;
}
