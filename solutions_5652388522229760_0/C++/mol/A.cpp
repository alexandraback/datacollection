#include <stdio.h>

int main(){
	int T;
	scanf("%d",&T);
	for(int i=0; i<T; i++){
		int N;
		scanf("%d",&N);
        if(N == 0){
            printf("Case #%d: INSOMNIA\n",i+1);
            continue;
        }
        char flg[10];
        for(int j=0; j<10; j++)
            flg[j] = 0;
        int ans;
        for(int k=1; ; k++){
            ans = k*N;
            int tmp=k*N;
            while(tmp>0){
                flg[tmp%10] = 1;
                tmp /= 10;
            }
            int awake = 0;
            for(int j=0; j<10; j++)
                if(flg[j] == 0)
                    awake = 1;
            if(awake == 0)
                break;
        }
		printf("Case #%d: %d\n",i+1,ans);
	}
	return 0;
}
