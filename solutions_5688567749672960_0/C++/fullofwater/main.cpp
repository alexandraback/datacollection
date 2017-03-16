#include <cstdio>
#include <cstring>
#include <algorithm>
#include <unistd.h>
#include <string>

using namespace std;

int step[1000005];
int N=sizeof(step)/sizeof(int)-3;

int test(int u) {
	string a=to_string(u), b=a;
	reverse(a.begin(),a.end());
	//printf("[%s %s]\n", a.c_str(), b.c_str());
	return atoi(a.c_str());
}

void dfs(int i) {
	//printf("%d\n", i);
	if (i+1<N) {
		if (step[i+1]>step[i]+1)
			step[i+1]=step[i]+1, dfs(i+1);
	}
	int jj=test(i);
	if (jj<N && jj>i && step[jj]>step[i]+1)
		step[jj]=step[i]+1, dfs(jj);
}

int main() {
	int T;
	long long n;
	for (int i=1;i<N;i++) {
		step[i]=0x3fffffff;
	}
	step[1]=1;
	for (int i=1;i<N;i++) {
		if (i+1<N) {
			step[i+1]=min(step[i+1], step[i]+1);
		}
		int jj=test(i);
		if (jj<N && jj>i)
			step[jj]=min(step[jj], step[i]+1);
	}
	scanf("%d", &T);
	for (int C=1;C<=T;C++) {
		scanf("%lld", &n);
		printf("Case #%d: %d\n", C, step[n]);
	}
}

