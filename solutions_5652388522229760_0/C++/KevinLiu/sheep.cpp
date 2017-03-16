#include <stdio.h>

int visit[10];

bool allVisited()
{
	for (int i=0;i<10;i++) {
		if (visit[i]==0) return false;
	}
	return true;
}

void visitX(int X)
{
	//printf("visit: %d\n", X);
	while(X>0) {
		visit[X%10]=1;
		X/=10;
	}
}

int countsheep(const int N)
{
	if (N==0) {
		return 0;
	}

	int i;
	for (i=0;i<10;i++) visit[i]=0;

	for (i=1; true; i++) {
		visitX(N*i);
		if (allVisited()) break;
	}
	return N*i;
}

int main()
{
	int T,N;
	scanf("%d", &T);
	for (int i=0;i<T;i++) {
		scanf("%d", &N);
		printf("Case #%d: ", i+1);
		int x=countsheep(N);
		if (x<=0) {
			printf("INSOMNIA\n");
		} else {
			printf("%d\n", x);
		}
	}
	return 0;
}
