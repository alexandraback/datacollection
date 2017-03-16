#include<stdio.h>
#include<string.h>
#define MAX_NUM_LEN 100
char fStr[40000][MAX_NUM_LEN+1];
int fn;

int bSearch(char *str,int isLow);
int cmp(char *aStr,char *bStr);
void init(void);
void get_fStr(int n,int len,int val);
void square(int n,int len);

void main(void){
	int t,tcase;
	char aStr[MAX_NUM_LEN+1];
	char bStr[MAX_NUM_LEN+1];
	int lfn,hfn;
	FILE *fin,*fout;
	init();
	fin = fopen("C-large-1.in","rw");
	fout = fopen("out.txt","ww");
	fscanf(fin,"%d",&tcase);
	for(t=1;t<=tcase;t++){
		fscanf(fin,"%s%s",aStr,bStr);
		hfn=bSearch(bStr,0);
		lfn=bSearch(aStr,1);
		fprintf(fout,"Case #%d: %d\n",t,hfn-lfn);
	}
	fclose(fin);
	fclose(fout);
}
int bSearch(char *str,int isLow){
	int low=0,high=fn,mid=(low+high)/2;
	while(low<high){
		int cmpV=cmp(str,fStr[mid]);
		if(cmpV==0){
			break;
		}else if(cmpV<0){
			high=mid-1;
			mid=(low+high)/2;
		}else{
			low = mid+1;
			mid=(low+high)/2;
		}
	}
	low = cmp(str,fStr[mid]);
	if(low==0){
		if(!isLow) mid++; 
	}else if(low>0){
		mid++;
	}
	return mid+1;
}
int cmp(char *aStr,char *bStr){
	if(strlen(aStr)==strlen(bStr))
		return strcmp(aStr,bStr);
	return strlen(aStr)-strlen(bStr);
}
void init(void){
	int i;
	fn=0;
	for(i=1;i<50;i++){
		get_fStr(0,i,0);
	}
	fStr[0][0]='0';
	fStr[0][1]='\0';
}
void get_fStr(int n,int len,int val){
	if(n>(len-1)/2){
		int k;
		fn++;
		for(k=0;k<=(len-1)/2;k++){
			fStr[fn][k]=fStr[0][k];
			fStr[fn][len-1-k]=fStr[0][k];
		}
		square(fn,len);
	}
	else{
		int i;
		if(n==0) i=1;
		else i=0;
		while(i<=3){
			int nval;
			if(len%2==1&&n==len/2){
				nval=val+i*i;
			}else{
				nval=val+2*i*i;
			}
			if(nval<10){
				fStr[0][n]=(char)i;
				get_fStr(n+1,len,nval);
				fStr[0][n]=0;
			}else{
				break;
			}
			i++;
		}
	}
}

void square(int n,int len){
	int i,j;
	int sum[MAX_NUM_LEN+1];
	for(i=0;i<=MAX_NUM_LEN;i++) sum[i]=0;
	for(i=0;i<len;i++){
		for(j=0;j<len;j++){
			sum[i+j]+=fStr[n][i]*fStr[n][j];
		}
	}
	len = len*2-1;
	for(i=0;i<len;i++){
		fStr[n][i]='0'+sum[len-1-i];
	}
	fStr[n][len]='\0';
}