#include <cstdio>
#include <vector>

using namespace std;

struct el {
	int p;
	int c; 
	
	el(int _p, int _c): p(_p), c(_c) {}
	el(){}
	
	int time() {
		return (p-1)/c + 1;
	}
};

int main() {
	
	int T;
	scanf("%d", &T);
	
	for(int t = 1; t <= T; t++) {
		printf("Case #%d: ", t);
		
		int D;
		scanf("%d", &D);
		
		vector<el> vec(D);
		for(int i = 0; i < D; i++) {
			int a;
			scanf("%d", &a);
			vec[i] = el(a,1);
		}
		
		int sol = 1000;
		
		for(int i = 1000; i >= 1; i--) {
			int count = 0;
			for(int j = 0; j < D; j++) {
				while(vec[j].time() > i) vec[j].c++;
				count += vec[j].c-1;
			}
			if(sol > i+count) sol = i+count;
		}
		
		printf("%d\n", sol);
	}
	
	return 0;
}
