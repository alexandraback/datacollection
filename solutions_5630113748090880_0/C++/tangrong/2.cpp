#include<stdio.h>

const int N=100;
int tmp[N][N];
int map[N][N];

int set[65535];

int main()
{
	int T, n;

	scanf("%d", &T);

	for(int t=1; t<=T; ++t) {
        scanf("%d", &n);
        for(int tt=0; tt<65535; tt++) set[tt] = 0;

		for (int ti=0; ti<2*n-1; ti++)
			for (int tj=0; tj<n; tj++) {
				scanf("%d", &tmp[ti][tj]);
                set[tmp[ti][tj]]++;
            }
		//for (int ti=0; ti<2*n-1; ti++) {
		//	for (int tj=0; tj<n; tj++) {
        //        printf(" %d", tmp[ti][tj]);
        //    }
        //    puts("");
        //}
        //for (int index=0; index<20; ++index) {
        //    printf(" %d:%d", index,set[index]);
        //}

        printf("Case #%d:", t);
        for (int index=0; index<65535; ++index) {
            if (1 == set[index]%2) {
                printf(" %d", index);
            }
        }
        printf("\n");

        //int cur = 0;
        //for (int index=0; index<65535; ++index) {
        //    if (set[index] !=0 ) {
        //        for (int tindex=0; tindex<2*n-1; tindex++) {
        //            if (set[index] == tmp[tindex][cur]) {
        //                
        //            }
        //        
        //        }
        //    } 
        //
       //}
	}



}
