#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <map>
#include <deque>
#include <set>
using namespace std;

#define sz size()
#define FOR(i,a,b) for(int (i) = (a); (i) <= (b); ++(i))
#define ROF(i,a,b) for(int (i) = (a); (i) >= (b); --(i))
#define rep(i,n) for (int (i) = 0; (i) < (n); ++(i))
#define fe(i,a) for (int (i) = 0; (i) < int((a).size()); ++(i))
#define C(a) memset((a),0,sizeof(a))
#define inf 1000000000
#define pb push_back
#define ppb pop_back
#define all(c) (c).begin(), (c).end()
#define pi 2*acos(0.0)
#define sqr(a) (a)*(a)
#define mp(a,b) make_pair((a), (b))
#define X first
#define Y second

typedef vector<int> vint;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
const int INF=2000000000;   
int main() {
    freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
    //freopen("input.txt","r",stdin);
    int T,n,m,c,g,h,len; char ch;
    cin>>T;
	rep(zalupa,T){
		cin>>n;
		vector<pii> a(n);
		rep(i,n)cin>>a[i].second>>a[i].first;
		sort(all(a));
		int stars=0,ans=0;
		vint s(n);
		int it=0,b;
		while(stars<n*2){
			b=0;
			rep(i,n){
				if(a[i].first<=stars && s[i]==0){
					stars+=2;
					s[i]+=2;
					ans++;
					b=1;
				}
			}
			if(b)continue;
			rep(i,n){
				if(a[i].first<=stars && s[i]==1){
					stars+=1;
					s[i]+=1;
					ans++;
					b=1;
					break;
				}
			}
			if(b)continue;
			ROF(i,n-1,0){
				if(a[i].second<=stars && s[i]==0){
					stars+=1;
					s[i]+=1;
					ans++;
					b=1;
					break;
				}
			}
			if(b==0){it=14880000;break;}
		}
		
		if(it<14880000)
			printf("Case #%d: %d\n",zalupa+1,ans);
		else printf("Case #%d: Too Bad\n",zalupa+1);
	}
    return 0;
}