#include<stdio.h>
#include<stdlib.h>

int main(){
	FILE *fp1,*fp2;
	char filename[50],input[105],translator[26],output[105];
	int i,t,j;
	char sample[3][105]= {"ejp mysljylc kd kxveddknmc re jsicpdrysi" , "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" , "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
	char sample2[3][105]={"our language is impossible to understand" , "there are twenty six factorial possibilities" , "so it is okay if you want to just give up"};
	for(i=0;i<26;i++){
		translator[i]=NULL;
	}
	for(i=0;i<3;i++){
		j=0;
		while(sample2[i][j]!='\0'){
			if(sample2[i][j]!=' '){
				translator[sample[i][j]-'a']=sample2[i][j];
			}
			j++;
		}
	}
	translator['q'-'a']='z';
	while(i<26){
		if(translator[i]==NULL){
			translator[i]='q';
			break;
		}
		i++;
	}
	
	scanf("%s",filename);
	fp1=fopen(filename,"r");
	fp2=fopen("output.txt","w");
	

	fscanf(fp1,"%d ",&t);	
	for(i=0;i<t;i++){
		fflush(stdin);
		fgets(input,sizeof(input),fp1);
		j=0;
		while(input[j]!='\0'){
			if(input[j]!=' '){
				input[j]=translator[input[j]-'a'];
			}
			j++;
		}
		fprintf(fp2,"Case #%d: %s\n",i+1,input);
	}
	return 0;
}