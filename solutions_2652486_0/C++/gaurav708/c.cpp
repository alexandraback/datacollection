#include <cstdio>
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <functional>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector< vector<int> > vvi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<string> vs;

#define rep(i,n) for(int i=0;i<n;i++)
#define forup(i,a,b) for(int i=a;i<=b;i++)
#define fordn(i,a,b) for(int i=a;i>=b;i--)
#define drep(i,n) for(i=0;i<n;i++)
#define dforup(i,a,b) for(i=a;i<=b;i++)
#define dfordn(i,a,b) for(i=a;i>=b;i--)
#define all(x) x.begin(),x.end()
#define permute(x) next_permutation(all(x))
#define pb push_back
#define mp make_pair
#define fi first
#define sc second

int n,m,k,r;

int main() {
	int T;
	scanf("%d",&T);
	rep(t,T) {
		printf("Case #%d:",t+1);
		scanf("%d%d%d%d",&r,&n,&m,&k);
		while(r--) {
			vi prod(k);
			rep(i,k) scanf("%d",&prod[i]);
			forup(i,2,m) {
				forup(j,2,m) {
					forup(l,2,m) {
						vi trip(3);
						trip[0]=i;
						trip[1]=j;
						trip[2]=l;
						vb found(k,false);
						rep(a,(1<<n)) {
							int p=1;
							rep(b,n) {
								if(a&(1<<b)) p*=trip[b];
							}
							rep(b,k) {
								if(prod[b]==p)
									found[b]=true;
							}
						}
						bool good=true;
						rep(b,k)
							good=good and found[b];
						if(good) {
							printf("\n%d%d%d",trip[0],trip[1],trip[2]);
							goto eol;
						}
					}
				}
			}
			eol: ;
		}
	}
	return 0;
}
