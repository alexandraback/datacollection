#include <cstdio>

using namespace std;

int main(int argc, const char *argv[])
{
	int cases, casen=0;
	int N, s[256], sum, n;
	double threshold, ans;
	bool flag;
	int i;

	scanf("%d", &cases);
	while(casen<cases){
		scanf("%d", &N);
		sum = 0;
		for(i = 0; i < N; i++){
			scanf("%d", &s[i]);
			sum += s[i];
		}
		threshold = (double)sum*2/N;
		n = N;
		flag = true;
		while(flag){
			flag = false;
			for(i = 0; i < N; i++){
				if(s[i] > threshold){
					--n;
					threshold -= (s[i]-threshold)/n;
					s[i] = -1;
					flag = true;
				}
			}
		}

		++casen;
		printf("Case #%d:", casen);
		for(i = 0; i < N; i++){
			ans = 100*(threshold-s[i])/sum;
			printf(" %lf", s[i]!=-1?ans:0);
		}
		printf("\n");
	}
	return 0;
}
