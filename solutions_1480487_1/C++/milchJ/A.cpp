#include <cstdio>
#include <algorithm>

using namespace std;

typedef pair<int, int> PII;

PII arr[200];
double erg[200];
double min(double a, double b) {
	return a<b?a:b;
}
int main() {

	int T;
	scanf("%d", &T);
	for(int t=0; t<T; ++t) {
		int N, s;
		scanf("%d", &N);
		int sum=0;
		for(int i=0; i<N; ++i) {
			scanf("%d", &s);
			arr[i] = PII(s, i);
			sum += s;
		}
		sort(arr, arr+N);
		
		for(int i=0; i<N; ++i) {
		//printf("lauf%d\n", i);
			double ges = sum+arr[i].first;
			int num=1;
			for(int j=0; j<N; ++j) {
				if(i!=j) {
					if( (double)arr[j].first <= ges / num ) {
						ges += arr[j].first;
						num++;
					//printf("ges %lf num %d\n", ges, num);
					} 
				}
			}	
			erg[arr[i].second] = max(100.0* ( ges / (double)num - arr[i].first) / (double) sum, 0.0);
		}
	
		printf("Case #%d:", t+1);
		for(int i=0; i<N; ++i) {
			printf(" %lf", erg[i]);
		}
		printf("\n");
	}
	return 0;
}
