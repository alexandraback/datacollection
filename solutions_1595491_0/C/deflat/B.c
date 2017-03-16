#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp1,*fp2;
	char filename[50];
	int i,t,n,s,p,j,input,ans,surprise;
	
	scanf("%s",filename);
	fp1=fopen(filename,"r");
	fp2=fopen("output.txt","w");
	
	fscanf(fp1,"%d",&t);
	for(i=0;i<t;i++){
		ans=0,surprise=0;
		fscanf(fp1,"%d %d %d",&n,&s,&p);
		for(j=0;j<n;j++){
			fscanf(fp1,"%d",&input);
			if(input>=3*p-2){
				ans++;
			}else if(input>=3*p-4&&input!=0){
				surprise++;
			}
		}
		if(surprise>=s){
			ans+=s;
		}else{
			ans+=surprise;
		}
		fprintf(fp2,"Case #%d: %d\n",i+1,ans);
	}
	return 0;
}