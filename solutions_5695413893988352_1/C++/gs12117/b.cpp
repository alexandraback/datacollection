#include<stdio.h>
#include<string.h>
int tcn,tc;
int n;
char cod[30];
char jam[30];//codejam!
long long int ansd,ansa,ansb;
void printd(long long int x,int len){
	if(len==0)return;
	printd(x/10,len-1);
	int r=x%10;
	printf("%d",r);
}
void findans(long long int a,long long int b,int dep){
	if(dep==n){
		long long int diff;
		if(a>b){
			diff=a-b;
		}
		else{
			diff=b-a;
		}
		if(diff<ansd||(diff==ansd&&(a<ansa||(a==ansa&&b<ansb)))){
			ansd=diff;
			ansa=a;
			ansb=b;
		}
	}
	else{
		int i,ta,tb;
		if(a<b){
			if(cod[dep]=='?'){
				ta=9;
			}
			else{
				ta=cod[dep]-'0';
			}
			if(jam[dep]=='?'){
				tb=0;
			}
			else{
				tb=jam[dep]-'0';
			}
			findans(a*10+ta,b*10+tb,dep+1);
		}
		else if(a>b){
			if(cod[dep]=='?'){
				ta=0;
			}
			else{
				ta=cod[dep]-'0';
			}
			if(jam[dep]=='?'){
				tb=9;
			}
			else{
				tb=jam[dep]-'0';
			}
			findans(a*10+ta,b*10+tb,dep+1);
		}
		else{
			a*=10;
			b*=10;
			if(cod[dep]!='?')a+=cod[dep]-'0';
			if(jam[dep]!='?')b+=jam[dep]-'0';
			if(cod[dep]=='?'){
				if(jam[dep]=='?'){
					findans(a,b,dep+1);
					for(i=1;i<10;i++){
						findans(a+i,b,dep+1);
						findans(a,b+i,dep+1);
					}
				}
				else{
					for(i=0;i<10;i++){
						findans(a+i,b,dep+1);
					}
				}
			}
			else{
				if(jam[dep]=='?'){
					for(i=0;i<10;i++){
						findans(a,b+i,dep+1);
					}
				}
				else{
					findans(a,b,dep+1);
				}
			}
		}
	}
}
int main(){
	int i,j;
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&tcn);
	for(tc=1;tc<=tcn;tc++){
		scanf("%s",&cod);
		scanf("%s",&jam);
		n=strlen(cod);
		ansd=2e18;
		findans(0,0,0);
		printf("Case #%d: ",tc);
		printd(ansa,n);
		printf(" ");
		printd(ansb,n);
		printf("\n");
	}
	return 0;
}