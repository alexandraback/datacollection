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
		int b;
		ll m;
		cin>>b>>m;
		cout<<"Case #"<<T<<": ";
		T++;
		if(b<=18 && (1<<(b-2))<m){
			cout<<"IMPOSSIBLE"<<endl;
			continue;
		}
		int ans[b][b];
		CLR(ans);
		cout<<"POSSIBLE"<<endl;
		for(int i=0;i<b-2;i++){
			for(int j=i+1;j<b-1;j++){
				ans[i][j]=1;
			}
		}
		int x = 1;
		if(m==(1<<(b-2))){
			ans[0][b-1]=1;
			m--;
		}
		while(m){
			if(m&1){
				ans[x][b-1]=1;
			}
			x++;
			m/=2;
		}
		for(int i=0;i<b;i++){
			for(int j=0;j<b;j++){
				cout<<ans[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}