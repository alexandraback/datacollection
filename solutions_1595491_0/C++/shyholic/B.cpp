#include<stdio.h>

int main(void){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,T;
	scanf("%d",&T);
	for(t=1;t<=T;t++){
		int ans=0;
		int N,S,p;
		int tp[100];
		int q[100], r[100];
		scanf("%d %d %d",&N,&S,&p);
		for(int i=0;i<N;i++){
			scanf("%d",&tp[i]);
			q[i] = tp[i] / 3;
			r[i] = tp[i] % 3;
		}

		for(int i=0;i<N;i++){
			for(int j=0;j<i;j++){
				if(q[i] < q[j]){
					int tmp;
					tmp = q[i];
					q[i] = q[j];
					q[j] = tmp;
					
					tmp = r[i];
					r[i] = r[j];
					r[j] = tmp;
				}
			}
		}

		int chk = 0;
		for(int i=0;i<N;i++){
			if(q[i] >= p) ans++;
			else if(q[i] == p-1 && r[i] != 0) ans++;
			else{
				if(chk < S){
					if(r[i] == 0 && q[i] + 1 >= p && q[i] != 0){
						chk++;
						ans++;
					}
					else if(r[i] == 2 && q[i] + 2 >= p){
						chk++;
						ans++;
					}
				}
			}
		}
		printf("Case #%d: %d\n",t, ans);
	}
}