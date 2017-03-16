#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include<math.h>

int main(){
int i,j,k,T,n,a,temp,count;

	scanf("%d",&T);

	for(k=0;k<T;k++){
		char s[101];int cons[100];
		scanf(" %s %d",s,&n);

		for(i=0;i<strlen(s);i++){
		if(s[i]=='a' ||s[i]=='e' ||s[i]=='i' ||s[i]=='o' ||s[i]=='u' )cons[i]=0;
		else cons[i] = 1;
		}

		temp=0;count =0;
		for(i=0;i<strlen(s)-n+1;i++){
			temp =0;
			for(j=i;j<strlen(s);j++){
				if(cons[j] == 0)temp=0;		
				if(cons[j] == 1)temp++;
				//if(i == strlen(s)-n)printf("temp = %d\n",temp);	
				if(temp==n){//printf("here\n");
				break;}
			}
		count += strlen(s)-j ;
		//printf("count =%d\n",count);
		}
	printf("Case #%d: %d\n",k+1,count);

	}

	return 0;

}
