#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <utility>
#include <functional>
using namespace std;

#define MP(x, y) make_pair(x, y)
#define SET(p) memset(p, -1, sizeof(p))
#define CLR(p) memset(p, 0, sizeof(p))
#define MEM(p, v) memset(p, v, sizeof(p))
#define CPY(d, s) memcpy(d, s, sizeof(s))
#define SZ(c) (int)c.size()
#define PB(x) push_back(x)
#define ff first
#define ss second
#define ll long long
#define ld long double
#define mod 1000000007
#define inf 1061109567LL
#define pii pair< int, int >
#define pll pair< ll, ll >
#define psi pair< string, int >
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	int T = 1;
	while(t--){
		int j,p,s,k;
		cin>>j>>p>>s>>k;
		int a = j*p*min(s,k);
		int b = j*min(p,k)*s;
		int c = min(j,k)*p*s;
		int ans = min(a,min(b,c));
		cout<<"Case #"<<T<<": ";
		T++;
		cout<<ans<<endl;
		if(ans==a){
			for(int i=1;i<=j;i++){
				for(int x=1;x<=p;x++){
					for(int y=1;y<=min(s,k);y++){
						cout<<i<<" "<<x<<" "<<y<<endl;
					}
				}
			}
		}
		else if(ans==b){
			for(int i=1;i<=j;i++){
				for(int x=1;x<=min(p,k);x++){
					for(int y=1;y<=s;y++){
						cout<<i<<" "<<x<<" "<<y<<endl;
					}
				}
			}
		}
		else{
			for(int i=1;i<=min(j,k);i++){
				for(int x=1;x<=p;x++){
					for(int y=1;y<=s;y++){
						cout<<i<<" "<<x<<" "<<y<<endl;
					}
				}
			}
		}
		
	}
	return 0;
}