#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B)	for(int I = (A); I < (B); ++I)
#define REP(I,N)	FOR(I,0,N)
#define ALL(A)		(A).begin(), (A).end()

using namespace std;
char vowels[] = {'a','e','i','o','u'};
char name[1111111];

bool isv(char x)
{
	bool vow = false;
	REP(k, 5) if(x == vowels[k]) vow = true;
	return vow;
}

int main()
{
	int currTest,T;
	scanf("%d", &T);
	REP(currTest, T) {
		int n;
		scanf("%s %d", name, &n);
		int len = strlen(name);
		int cnt = 0;
		for(int i = n-1; i >= 0; i--) {
			if(isv(name[i])) break;
			cnt++;
		}
		long long ans = 0;
		vector<int> pos;
		for(long long start = 0; start < len-n+1; start++) {
			if(cnt == n) {
//				ans += len-n-start+1;//(start+1)*(len-n);
				pos.push_back(start);
				if(!isv(name[start])) cnt--;
			}	
			if(start == len-n) break;
			if(isv(name[start+n])) {
				cnt = 0;
			}
			else cnt++;
		}
		if(pos.size() > 0) {
			int x = 0;
			for(int s = 0; s < len-n+1; s++) {
				while(x < pos.size() && s > pos[x]) {
					x++;
				}
				if(x < pos.size()) { //printf("subs start %d are %d\n ", s, len-(pos[x]+n)+1); 
					ans += len-(pos[x]+n)+1; 
				}
			}
		}
		printf("Case #%d: %lld\n", currTest+1, ans);
	}
	return 0;
}
