#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
	freopen("output.txt", "w", stdout);

	int tc;
	scanf("%d", &tc);

	int c;
	for(c = 1; c<=tc; c++){
		printf("Case #%d: ", c);

		double data[2][1020];

		int n;
		scanf("%d", &n);
		
		int i, j;
		for(i = 0; i<2; i++){
			for(j = 0; j<n; j++){
				scanf("%lf", &data[i][j]);
			}
		}

		sort(data[0], data[0]+n);
		sort(data[1], data[1]+n);

		int warAns = 0, war2Ans = 0;

		int rear = n-1;
		for(i = n-1; i>=0; i--){
			if(data[0][i] > data[1][rear]) warAns++;
			else rear--;
		}

		int used;
		for(used = 0; used < n; used++){
			int rear = n-1, t = 0;
			for(i = n-1-used; i>=0; i--){
				if(data[1][i] < data[0][rear]){
					t++;
					rear--;
				}
			}
			war2Ans = max(t, war2Ans);
		}

		printf("%d %d\n", war2Ans, warAns);
	}

	return 0;
}