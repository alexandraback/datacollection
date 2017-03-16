#include<stdio.h>
#include<string.h>
int main(){
	int tc;
	int l=1;
	scanf("%d",&tc);
	while(tc--){
		char s[1000];
		int n;
		scanf("%s",s);
		scanf("%d",&n);
		int i=0;
		int j=i+n;
		int count=0;
		int k;
		int num=0;
		int y;
		while(s[i]!='\0'){
			j=i+n;
			while(j <= strlen(s)){
			/*for(y=i;y<j;y++){
			printf("%c",s[y]);
			}
			printf("\n");
			*/
				num=0;
				for(k=i;k<j;k++){
				//printf("num=%d\n",num);
					//if(s[k]!='a' && s[k]!='e' && s[k]!='i' && s[k]!='o'  && s[k]!='u'){
					if(s[k]=='a' || s[k]=='e' || s[k]=='i' || s[k]=='o' ||  s[k]=='u'){
						num=0;
					}
					else{
						num++;
					}
					if(num>=n){
						count++;
						break;
					}
				}
				j++;
			}
			i++;
		}
		printf("Case #%d: %d\n",l,count);
		l++;
	}
	return 0;
}









