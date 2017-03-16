#include<cstdio>
long long p[11][16];
int main(){
	int i,j;
	for(i=2;i<11;i++){
            p[i][0]=1;
            for(j=1;j<16;j++)p[i][j]=p[i][j-1]*i;
        }
        char bits[20];
	bits[0]=bits[15]='1';
	bits[16]=0;
	const int mm=1<<14;
	long long num;
        freopen("output.txt","w",stdout);
        puts("Case #1:");
        int cnt=0,k;
	for(i=0;i<mm;i++){
		for(j=0;j<14;j++)
                    if(i>>j&1)bits[14-j]='1';
                    else bits[14-j]='0';
                printf("%s%s",bits,bits);
                for(j=2;j<11;j++){
                    num=p[j][0]+p[j][15];
                    for(k=0;k<14;k++)if(i>>k&1)num+=p[j][k+1];
                    printf(" %lld",num);
                }
                cnt++;
                printf("\n");
                if(cnt==500)break;
	}
	return 0;
}
