#include <cstdio>

int T;

int main(){
	freopen("A-small-attempt1.in", "r", stdin);
	freopen("A-small-attempt1.out", "w", stdout);
	scanf("%d", &T);
	for(int t = 1; t <= T; t++){
		int N;
		scanf("%d", &N);
		int val[201], org[201], sum = 0;
		double ans[201];
		for(int i = 0; i < N; i++){
			scanf("%d", &val[i]);
			sum += val[i];
			org[i] = val[i];
			ans[i] = 0.0;
		}
		double tsum = sum;
		for(int i = 0; i < N; i++){
			int pos = -1, cnt = 0;
			int Min = 10000, Sec = 30000;
			for(int j = 0; j < N; j++)
				if(val[j] < Min) Min = val[j], cnt = 1;
				else if(val[j] == Min) ++cnt;
			for(int j = 0; j < N; j++)
				if(val[j] > Min && Sec > val[j]) Sec = val[j], pos = j;
			int dif = cnt * (Sec - Min);
			if(dif > sum) {
				for(int j = 0; j < N; j++)
					if(val[j] == Min)
						ans[j] = (double(sum * 100) / cnt + (val[j] - org[j]) * 100) / tsum;
					else ans[j] = 0.0;
				break;
			}else{
				sum -= dif;
				for(int j = 0; j < N; j++)
					if(val[j] == Min) val[j] = Sec;
			}
		}
		printf("Case #%d:", t);
		for(int i = 0; i < N; i++)
			printf(" %lf", ans[i]);
		putchar('\n');
	}
}
