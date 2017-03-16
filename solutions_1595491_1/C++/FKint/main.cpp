#include <cstdio>

int main(){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; ++i){
		int n,s,p;
		scanf("%d%d%d", &n, &s, &p);
		int good_amount=0;
		for(int j = 0; j < n; ++j){
			int total_score;
			scanf("%d", &total_score);
			if(total_score<p)
				continue;
			if((total_score-p)/2>=p-1)
				++good_amount;
			else if((total_score-p)/2>=p-2){
				if(s>0){
					--s;
					++good_amount;
				}
			}
		}
		printf("Case #%d: %d\n", i+1, good_amount);
	}
	return 0;
}
