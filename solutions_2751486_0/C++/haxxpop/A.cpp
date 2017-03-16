#include<stdio.h>
#include<string.h>
char s[2000000];
int gap[2000000];
long long ans = 0;
int iscon(char c){
	if( c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' )
		return 0;
	return 1;
}
int main(){
	int t;
	scanf("%d",&t);
	for(int e = 0 ; e < t ; e++ ){
		int n,len ;
		scanf("%s %d",s,&n);
		len = strlen(s);
		int ct = 0;
		gap[len] = 0;
		ans = 0;
		for(int i = 0 ;i < len ;i++ ){
			if( iscon(s[i]) ) ct++;
			else ct = 0;
			if( ct == n ){
				gap[i] = 1;
				ct = n-1;
			}
			else gap[i] = 0;
		}
		/*if( e == 1 ){
			for(int i = 0 ;i < len ; i++ ) printf("%d ",gap[i]);
			printf("\n");
		}*/

		ct = 0;
		for(int i = len-1 ; i >=0 ; i-- ){
			if( gap[i] == 1 ) ct =0;
			else ct++;
			gap[i] = ct;
		}
		ct = 0;
		for(int i = 0 ; i < len ; i++ ){
			if( iscon(s[i]) ) ct++;
			else ct = 0;
			if( ct == n ){
				ans += (i-ct+2)*((long long) gap[i+1]+1);
				ct = n-1;
				//if( e == 1) printf("%d %lld\n",i,ans);
			}
		}
		printf("Case #%d: %lld\n",e+1,ans);
	}
}


				 
		


