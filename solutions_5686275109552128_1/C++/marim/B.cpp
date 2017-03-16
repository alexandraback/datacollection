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
		
		int d, t[1000], mn = -1;
		
		scanf("%d", &d);
		
		for(int i=0; i<d; i++){
			scanf("%d", &t[i]);		
			mn = max(mn, t[i]);
		}
		
		for(int j=1; j<=mn; j++){
			int tmp = 0;
			for(int i=0; i<d; i++){
				tmp += (t[i] - 1) / j;		
			}

			mn = min(mn, j+tmp);
		}

		printf("%d\n", mn);
	}

	return 0;
}
