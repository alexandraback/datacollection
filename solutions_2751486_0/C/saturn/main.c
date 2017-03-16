#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLENGTH 1000000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
static char name[MAXLENGTH];
void exchange(int* arr,int p,int r){
	int temp = arr[p];
	arr[p] = arr[r];
	arr[r] = temp;
}
 
int partition(int* arr,int p,int r){
	int x = arr[r];
	int i=p-1;
	int j=0;
	for(j=p;j<r;j++){
		if(arr[j]<=x){
			i++;
			exchange(arr,i,j);
		}
	}
	exchange(arr,i+1,r);
	return i+1;
}
 
void quickSort(int* arr,int p,int r){
	int q =0;
	if(p<r){
		q = partition(arr,p,r);
		quickSort(arr,p,q-1);
		quickSort(arr,q+1,r);
	}
}

int isVowel(char c){
	if(c == 'a' || c == 'e' || c == 'i'||c=='o' || c== 'u'){
		return 1;
	}
	return 0;
}

int hasNCons(char* s,int len,int n){
	int i =0,j;
	int res = 0;
	for(i=0;i<=len-n;i++){
		if(isVowel( s[i]) == 0){
			res = 1;
			for(j = i+1;j<=i+n-1;j++){
				if(isVowel(s[j])== 1){
					res = 0;
					break;
				}
			}
			if(res ==1) return 1;
		}
	}
	return 0;
}

int getNValue(char *s,int n){
	int len = strlen(s);
	int tempLen = 0;
	int start = 0;
	int res = 0;
	for(tempLen = n;tempLen <= len;tempLen++){
		for(start =0;start+tempLen <= len;start++){
			if(hasNCons(s+start,tempLen,n)==1) res++;
		}
	}
	return res;
}


void putzero(void){
	int i =0;
	for(i=0;i<MAXLENGTH;i++){
		name[i] = 0;
	}
}
int main(void) {
	FILE* inp = fopen("inp.txt","r");
	FILE* out = fopen("out.txt","w");

	int test = 0,i,caseCount;
	int n,l;
	

	int ans = 0;
	fscanf(inp,"%d",&test);
	for(caseCount =1;caseCount<=test;caseCount++){
		putzero();
		fscanf(inp,"%s",name);
		fscanf(inp,"%d",&n);
		
		ans = getNValue(name,n);
		print:
		fprintf(out,"Case #%d: %d\n",caseCount,ans);
	}
	
	return 0;
}
