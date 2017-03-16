#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int countdigit(int i){
	int count=0;
	while(i!=0){
		i=i/10;
		count++;
	}
	return count;
}

int main(){
	FILE *fp1,*fp2;
	char filename[50];
	int t,a,b,i,j,k,l,l2,ans,target,temp,digit,overlap[6],minus;
	
	scanf("%s",filename);
	fp1=fopen(filename,"r");
	fp2=fopen("output.txt","w");
	
	fscanf(fp1,"%d",&t);
	for(i=0;i<t;i++){
		ans=0;
		fscanf(fp1,"%d %d",&a,&b);
		for(j=a;j<b;j++){
			l2=0;
			digit=countdigit(j);
			target=j;
			for(k=0;k<digit-1;k++){
				minus=0;
				temp=target%10;
				target=(target-temp)/10+temp*pow(10,digit-1);
				if(j<target&&target<=b){
					for(l=0;l<l2;l++){
						if(target==overlap[l]) minus=1;
					}
					ans+=1-minus;
					overlap[l2]=target;
					l2++;
				}
			}
		}
		fprintf(fp2,"Case #%d: %d\n",i+1,ans);
	}
	return 0;
}