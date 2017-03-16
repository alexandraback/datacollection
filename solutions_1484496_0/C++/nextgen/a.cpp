#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <queue>

#define pb push_back
#define mp make_pair
#define sz size()
#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define vint vector<int>
#define forn(i,n) for (int (i)=0; (i)<(n); (i)++)

using namespace std;
const int INF=~(1<<31);
const double EPS=1e-9;
const double PI=3.141592653589793;

int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	for (int q=1; q<=t; q++) {
		int n;
		scanf("%d",&n);
		vector<int> v(n),val(1<<n,0);
		vector<set<int> >s;
		s.assign(1<<n,set<int>());
		forn(i,n) {
			scanf("%d",&v[i]);
		}
		sort(all(v));
		int g,h,k,a1,a2;
		for(int i=1; i<(1<<n); i++) {
			s[i].insert(all(s[(i-1)&i]));
			g=((i-1)&i)^i;
			s[i].insert(all(s[g]));
			g=0;
			forn(j,n) {
				if(i&(1<<j)) {
					g+=v[j];
				}
			}
			s[i].insert(g);
			val[i]=g;
		}
		forn(i,(1<<n)){
			if(s[i].size() && s[i^((1<<n)-1)].size()){
				h=i;
				g=i^((1<<n)-1);
				set<int>::iterator it1=s[h].begin(), it2=s[g].begin();
				while(it1!=s[h].end() && it2!=s[g].end()){
					if(*it1==*it2)break;
					if(*it1<*it2)it1++; else it2++;
				}
				if(it1!=s[h].end() && it2!=s[g].end()){
					k=*it1;
					break;
				}
			}
		}
		printf("Case #%d:\n",q);		
		int b=0;
		if(k==-1)puts("Impossible"); else{ 
			forn(i,(1<<n)) {
				if(val[i]==k){
					h=i^((1<<n)-1);
					for(g=h;g;g=(g-1)&h)if(val[g]==k){
						a1=i; 
						a2=g;
						b=1; 
						break;
					}
					if(b)break;
				}
			}
			forn(i,n) {
				if((1<<i)&a1) printf("%d ",v[i]);
			}
			printf("\n");
			forn(i,n) {
				if((1<<i)&a2) printf("%d ",v[i]);
			}
			printf("\n");
		}
	}	
	return 0;
}