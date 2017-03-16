#include<cstdio>
#include<cmath>
long long stk[12];
inline bool get(long long num,int bs){
	long long lmt=sqrt(num)+10;
	if(lmt>=num)lmt=num-1;
	for(long long i=2;i<=lmt;i++){
		if(num%i==0){
			stk[bs]=i;
			return true;
		}
	}
	return false;
}
long long p[12][32];
int main(){
	freopen("output.txt","w",stdout);
	const int mm=1<<14;
	int cnt=0,i,j,k;
	for(i=2;i<11;i++){
		p[i][0]=1;
		for(j=1;j<32;j++)p[i][j]=p[i][j-1]*i;
	}
	long long num;
	puts("Case #1:");
	char bit[40];bit[16]=0;
	for(i=0;i<mm;i++){
		bool flg=true;
		for(j=2;j<11;j++){
			num=p[j][0]+p[j][15];
			for(k=0;k<14;k++)if(i>>k&1)num+=p[j][k+1];
			flg&=get(num,j);
			if(!flg)break;
		}
		if(!flg)continue;
		bit[0]=bit[15]='1';
		for(j=0;j<14;j++)
			if(i>>j&1)bit[14-j]='1';
			else bit[14-j]='0';
		printf("%s",bit);
		for(j=2;j<11;j++)printf(" %lld",stk[j]);
		cnt++;
		printf("\n");	
		if(cnt==50)break;
	}
	return 0;
}
