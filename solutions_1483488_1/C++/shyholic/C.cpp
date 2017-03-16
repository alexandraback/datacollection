#include<stdio.h>

bool chk[3000][3000];
int store[10];

int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int t,T;
	scanf("%d",&T);
	for(t=0;t<T;t++){
		int cnt = 0, A, B;
		scanf("%d %d",&A,&B);
		for(int i=A;i<=B;i++){
			int p = 10, mp;
			while(p<=i) p = p * 10;
			mp = p;
			p = p / 10;
			int ccnt = 0;
			while(p>1){
				int pre = i / p;
				int suf = i % p;

				if(suf != 0 && i < pre + suf * (mp / p) && pre + suf * (mp / p) <= B){
					int j;
					for(j=0;j<ccnt;j++){
						if(store[j] == pre + suf * (mp / p)){
							break;
						}
					}
					if(j == ccnt){
						cnt++;
						store[ccnt++] = pre + suf * (mp / p);
					}
				}
				p = p / 10;
			}
		}
		printf("Case #%d: %d\n",t+1,cnt);
	}
	return 0;
}