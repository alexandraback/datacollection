#include<cstdio>

using namespace std;

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		static int x = 1;
		printf("Case #%d: ", x++);
		
		int N, S, p;
		scanf("%d%d%d", &N, &S, &p);
		int result = 0;
		int surprise = 0;		
		while(N--) {
			int num;
			scanf("%d", &num);
			if(num==0 && p > 0)
				continue;
			int min = num/3;
			if(min >= p || (min+1 == p && num%3!=0)) {
				result++;
				continue;
			}
			if(min+1 == p && num%3 == 0) {
				surprise++;
				continue;
			}
			if(min+2 == p && num%3 == 2) {
				surprise++;
				continue;
			}
		}
		if(surprise > S)
			surprise = S;
		printf("%d\n", result + surprise);
	}	
	return 0;
}
