#include<stdio.h>
int main(){
	int z;
	int i;
	char s[1001];
	int j,k,l,r;
	char t[10001];
	for(scanf("%d ",&z),i=1;i<=z;i++){
		scanf("%s",s);
		l=r=k=1001;	
		t[k]=s[0];	
		for(j=1;s[j]!='\0';j++){
			if(t[l]<=s[j])
				k=l-1,l--;
			else
				k=r+1,r++;
			t[k]=s[j];
		}
		t[r+1]='\0';		
		printf("Case #%d: %s\n",i,(t+l));
	}
}
