#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

int s[600];

vector<int> SA;
vector<int> SB;

int rest[600];
int N;
bool test(int sa, int sb, int n) {
	if(n==N) return ((sa == sb) and sa!=0);
	if(abs(sa-sb)>rest[n]) return false;
	if(test(sa + s[n], sb, n+1)) {
		SA.push_back(s[n]);
		return true;
	}
	if(test(sa, sb + s[n], n+1)) {
		SB.push_back(s[n]);
		return true;		
	}
	
	return test(sa, sb, n+1);
}
int main() {
	//freopen("C.in", "r", stdin);
	int T;
	scanf("%d\n", &T);
	for(int t=1; t<=T; t++) {
		SA.clear(); SB.clear();
		scanf("%d", &N);
		for(int i=0; i<N; i++) {
			scanf("%d", &s[i]);
		}
		sort(s, s+N);
		reverse(s, s+N);
		s[N] = 0;
		rest[N] = 0;
		for(int i=N; i>=0; i--) {
			rest[i] = s[i]+ rest[i+1];
		//	printf("%d\n", rest[i]);
		}
		
		printf("Case #%d:\n", t);
		if(test(0,0,0)) {
			printf("%d", SA[0]);
			for(unsigned int i=1; i<SA.size(); i++) {
				printf(" %d", SA[i]);
			}
			printf("\n");
			printf("%d", SB[0]);
			for(unsigned int i=1; i<SB.size(); i++) {
				printf(" %d", SB[i]);
			}
			printf("\n");
			
		} else {
			printf("Impossible\n");
		}
		
		
		
	}
}
