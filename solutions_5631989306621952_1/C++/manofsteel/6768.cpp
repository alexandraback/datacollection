#include<stdio.h>
#include<string.h>

void addleft(char a[],int n,char c){
	char temp[10001];
	int i;
	for(i=0;i<n;i++){
		temp[i]=a[i];
	}
	temp[0]=c;
	
		for(i=0;i<n;i++){
		temp[i+1]=a[i];
	}
	for(i=0;i<=n;i++){
		a[i]=temp[i];
	}
	
}



int main(){
	int t;
	scanf("%d",&t);
	int n=t;
	while(t--){
		printf("Case #%d: ",n-t);
		char a[1001],b[1001];
		scanf("%s",a);
		int i;
		int n=strlen(a);
		b[0]=a[0];
		for(i=1;i<n;i++){
			if(a[i]>=b[0]){
				addleft(b,i,a[i]);
			}
			else{
				b[i]=a[i];
			}
		}
		for(i=0;i<n;i++){
			printf("%c",b[i]);
		}
		printf("\n");
		
	}
}
