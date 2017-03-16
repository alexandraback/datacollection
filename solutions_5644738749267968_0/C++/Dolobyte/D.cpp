#include<cstdio>
#include<algorithm>
using namespace std;

int T, N;
double a[2000], b[2000];

int War(){
	int l1=0, l2=0;
	while(l1<N){
		while(l2<N && b[l2] < a[l1]) l2++;
		if (l2 == N){
			return N-l1;
		}
		l1++; l2++;
	}
}

int War1(){
	int l1=0, l2=0, r2=N-1, ret=0;
	while(l1<N){
		if (a[l1] < b[l2]) r2--;
		if (a[l1] > b[l2]){
			ret++; l2++;
		}
		l1++;
	}
	return ret;
}

int main()
{
	freopen("D.in", "r", stdin);

	scanf("%d", &T);
	for(int o=0; o<T; o++){
		scanf("%d", &N);
		for(int i=0; i<N; i++)
			scanf("%lf", &a[i]);
		for(int i=0; i<N; i++)
			scanf("%lf", &b[i]);
		sort(a, a+N);
		sort(b, b+N);
//		for(int i=0; i<N; i++)
//			printf("%lf %lf\n", a[i], b[i]);
		
		int ans1 = War1(), ans2 = War();
		printf("Case #%d: %d %d\n", o+1, ans1, ans2);
	}
	return 0;
}
