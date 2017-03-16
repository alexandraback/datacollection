#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <vector>  
#include <queue>  
#include <set>  
#include <map>  
#include <cstdio>  
#include <cstdlib>  
#include <cctype>  
#include <cmath>  
#include <list> 

using namespace std;

typedef map<char,char> dict;
typedef vector<int> VI;
typedef long long LL;
#define VLL vector<long long>
#define SZ(v) ((int)(v).size())  
#define FOR(i,a,b) for(int i=(a);i<(b);++i)  
#define REP(i,n) FOR(i,0,n)  
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)  
#define REPE(i,n) FORE(i,0,n)  
#define FORSZ(i,a,v) FOR(i,a,SZ(v))  
#define REPSZ(i,v) REP(i,SZ(v))  


char buf[1024];

int ni(){
	int i;
	scanf("%d", &i);
	return i;
}

char nc(){
	char c;
	scanf("%c", &c);
	return c;
}

double nd(){
	double i;
	scanf("%f", &i);
	return i;
}

string ns() { 
	scanf( "%s", buf ); return buf; 
}

string nl() {
	scanf("%[a-z ]\n", buf); return buf;
}

class Less {
public:
	bool operator()(const pair<int,int>& l, const pair<int,int>& r) const{
		if (l.first == r.first) return r.second < l.second;
		return l.first < r.first;
	}
};


int main(void){
	int T = ni();
	for (int c = 0; c < T; c++) {
		int N = ni();

		int star = 0;
		int cost = 0;
		int m;
		VI used(N, 0);
		vector<pair<int,int> > tower(N, make_pair(0,0));
		FOR(i,0,N) {
			tower[i].second = ni(); tower[i].first = ni();
		}
		sort(tower.begin(), tower.end(), Less());

		for(m = 0; m < N; m++){
			if (tower[m].first > star) {
				bool bupdate = false;
				
				do {
					bupdate = false;
					for(int i = N-1; i >= 0; i--) {
						if (used[i]) continue;
						if (tower[i].second <= star) {
							used[i] = 1;
							cost++;
							star++;
							bupdate = true;
							break;
						}
					}
				} while (bupdate == true && star < tower[m].first);

				if (star < tower[m].first) {
					break;
				}
			}
			if (used[m]) star++;
			else star += 2;

			used[m] = 1;
			cost++;
		}

		if (m == N)       printf("Case #%d: %d\n", c+1, cost);
		else              printf("Case #%d: Too Bad\n", c+1);
	}
}