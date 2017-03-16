#include<stdio.h>
#include<string.h>
char c[1000001];
int main()
{
	FILE *fi=fopen("A-small-attempt2.in","r");
	FILE *fo=fopen("A-small-attempt2.out","w");
	int t,i,l,n,j,cnt=0,temp;
	__int64 sum=0;

	fscanf(fi,"%d",&t);
	for(i=0;i<t;i++){
		fscanf(fi,"%s %d",c,&n);
		l=strlen(c);
		temp = sum = cnt = 0;
		for(j=0;j<l;j++){
			if(c[j] != 'a' && c[j] != 'e' && c[j] != 'i' && c[j] != 'o' && c[j] != 'u')
				cnt++;
			if((c[j] == 'a' || c[j] == 'e' || c[j] == 'i' || c[j] == 'o' || c[j] == 'u') || (j==l-1)){
				if(j==l-1 && c[j] != 'a' && c[j] != 'e' && c[j] != 'i' && c[j] != 'o' && c[j] != 'u') j=l;
				if(cnt>=n){
					sum+= (__int64)( (j-cnt-temp+1)*(l-j+1) +  (cnt-n-1) * (cnt-n) / 2 + (j-cnt-temp+1)*(cnt-n) + (l-j+1)*(cnt-n) );
					temp = j-n+1;
				}
				cnt=0;
			}
		}
		fprintf(fo,"Case #%d: %I64d\n",i+1,sum);
	}
}