#include <cstdio>

const int MAXN = 1200;
char str[MAXN];
int N;

void run(int test){
	scanf("%d",&N);
	scanf("%s",str);

	int now = 0, need = 0;
	for(int i=0;str[i];i++){
		int val = str[i] - '0';

		if(now >= i){
			now += val;
			continue;
		}else{
			int add = i-now;
			now += add;
			need += add;

			now += val;
		}
	}
	printf("Case #%d: %d\n",test,need);
}

int main(){
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);

	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);
	return 0;
}