#include<stdio.h>
#include<string.h>

int stars[1000][2];
int status[1000];
void solve() {
	int N;
	scanf("%d", &N);
	for(int i=0;i<N;i++) {
		scanf("%d%d", &stars[i][0], &stars[i][1]);
	}
	int s=0, c=0;
	memset(status, 0, sizeof(status));
	while(s<N*2) {
		int mna=-1, mnb=-1, mxa=-1;
		for(int j=0;j<N;j++) {
			if(status[j]<1&&stars[j][0]<=s&&stars[j][1]>mxa) {
				mna=j;
				mxa=stars[j][1];
			}
			if(status[j]<2&&stars[j][1]<=s) mnb=j;
		}
		if(mnb!=-1) {
			s+=2-status[mnb];
			status[mnb]=2;
			c++;
		} else if(mna!=-1) {
			s+=1-status[mna];
			status[mna]=1;
			c++;
		} else {
			puts("Too Bad");
			return;
		}
	}
	printf("%d\n", c);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int c=1;c<=T;c++) {
		printf("Case #%d: ", c);
		solve();
	}
}