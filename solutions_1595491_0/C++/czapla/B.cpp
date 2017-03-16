#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cstdlib>
using namespace std;

int N, surprising, minwyn, wyn, s;

int main(){
	int testy;
	scanf("%d", &testy);
	for(int t = 1; t <= testy; t++){
		printf("Case #%d: ", t);
		scanf("%d %d %d", &N, &surprising, &minwyn);
		wyn = 0;
		for(int i = 0; i < N; i++){
			scanf("%d", &s);
			if((s+2)/3 >= minwyn)
				wyn++;
			else if(surprising>0 && s>=2 && (s+4)/3 >= minwyn){
				surprising--;
				wyn++;
			}
		}
		printf("%d\n", wyn);
	}
	return 0;
}
