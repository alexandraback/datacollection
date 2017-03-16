#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int isCons(char a){
	if(a!='a'&&a!='e'&&a!='i'&&a!='o'&&a!='u')
		return 1;
	return 0;

}

int main(){
    FILE *pt = fopen("outCOns.txt","w");
	int i,j,k,t,total,m,len,n,count,last;
	char a[1000001];
	
	scanf("%d",&t);
	for(i=1;i<=t;i++){
		scanf("%s %d",a,&n);
		len = strlen(a);
		m=0;
		total=0;
		count = 0;
		last = 0;
		for(j=0;j<len;j++){
			if(isCons(a[j])){
				m++;
				printf("m=%d\n",m);
				if(m==n){	
					//total += len-n+1;
					k=j+1-n ;
					printf("pos=%d j+1-n=%d len-j-1=%d\n",j,j+1-n,len-j-1);
					/*if(last>0){
					total += k+ (k+1)*(len-j-1-last+n) + 1;
					}*/
					//else{
					total += k+ (k+1)*(len-j-1) + 1;
					
					//}
					last = j;
					count++;	
				m=1;
				}
				
			}	
			else{
				m=0;
			}		
		}
		printf("count = %d total = %d\n",count,total);
		if(last !=0)
		printf("%d\n",total-count+1-len+last+1);
	
		else
		printf("0\n");
		
		if(last !=0)
		fprintf(pt,"Case #%d: %d\n",i,total-count+1-len+last+1);
	
		else
		fprintf(pt,"Case #%d: 0\n",i);
	}    
    fclose(pt);
}
