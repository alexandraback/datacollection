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
		
		int N;
		vector< pair<int,int> > t;

		scanf("%d", &N);

		for(int i=0; i<N; i++){
			int a, b;
			scanf("%d%d", &a, &b);
			t.push_back(make_pair(b,a));
		}

		sort(ALL(t));

		int curLevel = 0, bonus=0;
		bool ok = true;

		for(int i=0; i<t.size(); i++){
			if( curLevel >= t[i].first ){
				curLevel+=2;		
				if( t[i].second == -1 ) curLevel--;
			} else {
				bool sthChanged = true;
				while( sthChanged && curLevel < t[i].first ){
					sthChanged = false;

					for(int j=t.size()-1; j>=i; j--) if( t[j].second != -1 ){
						if( curLevel >= t[j].second ){
							curLevel++;
							bonus++;
							t[j].second = -1;

							sthChanged = true;
							break;
						} 
					}
				}

//cerr << "i: " << i << " curLevel: " << curLevel << " bonus: " << bonus << endl;					
				if( curLevel >= t[i].first ){
					curLevel += 2;
					if( t[i].second == -1 ) curLevel--;
				} else {
					ok = false;
					break;
				}
			}
//cerr << "### i: " << i << " curLevel: " << curLevel << " bonus: " << bonus << endl;					
			 /* else {
				while( bonus < i && curLevel < t[i].first ){
					curLevel += 3;	
					bonus++;
				}
				if( curLevel >= t[i].first ){
					curLevel += 2;
				} else if( curLevel >= t[i].second && curLevel+1 >= t[i].first ){
					curLevel += 4;
					bonus++;
				} else {
					ok = false;
					break;
				}
			} */
		}

		if( !ok ){
			printf("Too Bad\n");
		} else {
			printf("%d\n", N+bonus);
		}
	}

	return 0;
}
