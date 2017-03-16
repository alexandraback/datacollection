#include<algorithm>
#include<cstdio>

const int LEN = 1005;

using namespace std;

int N,M;
long long ans;

long long num1[LEN], num2[LEN];
long long type1[LEN], type2[LEN];
long long  remain2[LEN][LEN];
long long value[LEN][LEN];

void print() {
	return ;
	for(int i=0;i<N;i++, puts("")) {
		for(int j=0;j<M;j++)
			printf("%2lld ", value[i][j]);
	}
	puts("\n");
}

int main() {

	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;t++) {

		scanf("%d %d",&N,&M);
		for(int i=0;i<N;i++) 
			scanf("%lld %lld",&num1[i],&type1[i]);

		for(int i=0;i<M;i++) 
			scanf("%lld %lld",&num2[i],&type2[i]);

		for(int i=0;i<N;i++) {

			int remain = num1[i];
			int done = 0;

			for(int j=0;j<M;j++) {
				if(type2[j] == type1[i]) {

					if( remain > num2[j] ) {
						done+=num2[j];
						remain -= num2[j];
						remain2[i][j] = 0;
					}
					else {
						done+=remain;
						remain=0;
						remain2[i][j] = num2[j] - remain;
					}
				} else {
					remain2[i][j] = num2[j];
				}
				value[i][j] = done;	
			}
		}

		print();

		for(int i=1;i<N;i++) {
			for(int j=0;j<i;j++) {
				for(int p=0;p<M;p++) {

					long long pre = value[j][p];
					long long done = 0;
					long long quota = num1[i];

					if(type2[p] == type1[i]) {
						if(remain2[j][p]!=0) {
							if(quota > remain2[j][p]) {
								done = remain2[j][p];
								quota -= remain2[j][p];
							} else {
								done = quota;	
								quota = 0;
							}
						}	
					}

					for(int k=p+1;k<M;k++) {
						if(type1[i]==type2[k]) {
							if(quota > num2[k]) {
								quota-= num2[k];
								done += num2[k];
								remain2[i][k] = 0;
							}
							else {
								done += quota;
								remain2[i][k] = num2[k] - quota;
								quota = 0;
							}
						} else {
							remain2[i][k] = num2[k];
						}
						value[i][k] = max(value[i][k], done+pre);
					}		
				}
			}
		}

		print();

		ans = 0;

		for(int i=0;i<N;i++)
			for(int j=0;j<M;j++)
				ans = max(ans, value[i][j]);


		printf("Case #%d: %lld\n",t,ans);
	}
}
