#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <memory>
#define sz size()
#define mp make_pair
#define pb push_back
#define vi vector<int>
#define fu(i,n) for(int i=0; i<(n); i++)
#define ALL(a) (a).begin(),(a).end()
#define cl(a,co) memset(a,co,sizeof a)
#define un(a) sort(ALL(a)),a.erase( unique(ALL(a)), a.end() )
typedef long long ll;
//istringstream is(s); is >> a;

using namespace std;

int ileTestow;

int main(){

	scanf("%d",&ileTestow);

	for(int q=1; q<=ileTestow; q++){
		printf("Case #%d: ",q);
		
		int n;
		vector<int> t(500);

		scanf("%d", &n);

		fu(a,n){
			scanf("%d", &t[a]);
		}

		set<int> secik;

		int res = -1, last = -1;

		fu(a,n){
			if( secik.find(t[a]) != secik.end() ){
				res = t[a];
				last = a;
				break;
			} else {
				set<int> tmp;
				tmp.insert(t[a]);
				for(set<int>::iterator it=secik.begin();it!=secik.end();it++){
					if( secik.find(t[a]+*it) != secik.end() ){
						res = t[a]+*it;
						last = a;
						break;				
					} else {
						tmp.insert(t[a]+*it);
					}
				}

				if( res == -1 )
					secik.insert(tmp.begin(), tmp.end());
				else
					break;
			}
		}

		if( res == -1 ){
			printf("Impossible\n");
			continue;
		}
		
		vector<int> r1, r2;
		
		for(int i=0; i<(1<<last); i++){
			vector<int> tmp;
			int sum = 0;
			for(int j=0; j<n; j++) if( (i&(1<<j)) > 0 ){
				sum += t[j];
				tmp.pb(t[j]);
			}

			if( sum == res ){
				r1 = tmp;
			} else if( sum + t[last] == res ){
				r2 = tmp;
			}
		}

		printf("\n");
		fu(a,r1.size()) printf("%d ", r1[a]); printf("\n");
		printf("%d ", t[last]); fu(a,r2.size()) printf("%d ", r2[a]); printf("\n");
	}

	return 0;
}
