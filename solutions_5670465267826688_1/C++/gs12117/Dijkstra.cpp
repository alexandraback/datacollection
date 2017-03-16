#include<stdio.h>
int tcn,tc;
int l;
long long int x;
char s[200100];
int main(){
	int i,j,stt;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%d%lld%s",&l,&x,s);
		printf("Case #%d: ",tc);
		stt=0;
		for(i=0;i<l;i++){
			if(s[i]=='i'){
				stt*=3;
				stt++;
				stt%=8;
			}
			else if(s[i]=='j'){
				stt+=2;
				stt%=8;
			}
			else{
				stt*=3;
				stt+=3;
				stt%=8;
			}
		}
		if(stt==0){
			printf("NO\n");
			continue;
		}
		else if(stt==4){
			if(x%2==0){
				printf("NO\n");
				continue;
			}
		}
		else{
			if(x%4!=2){
				printf("NO\n");
				continue;
			}
		}
		if(x>20)x=20;
		for(i=0;i<x;i++){
			for(j=0;j<l;j++){
				s[i*l+j]=s[j];
			}
		}
		int flag=0;
		stt=0;
		for(i=0;i<x*l;i++){
			if(s[i]=='i'){
				stt*=3;
				stt++;
				stt%=8;
			}
			else if(s[i]=='j'){
				stt+=2;
				stt%=8;
			}
			else{
				stt*=3;
				stt+=3;
				stt%=8;
			}
			if(stt==1){
				flag=1;
			}
			if(flag==1&&stt==3){
				break;
			}
		}
		if(i==x*l){
			printf("NO\n");
		}
		else{
			printf("YES\n");
		}
	}
}