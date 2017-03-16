#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1000005];
bool a[1000005];
int main(){
//freopen("A-large.in","r",stdin);
//freopen("A-large.out","w",stdout);
	long long n,i,j,tc,ii;
	scanf("%lld",&tc);
	for(ii=1;ii<=tc;ii++){
		scanf("\n%s %lld",s,&n);
		long long len=strlen(s);
		long long x=0;
		long long ans=0;
		long long y=-1;
		for(j=0;j<len;j++){
			if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u')x=0;
			else x++;
				
			
			if(x>=n){
				ans+=j+1-n+1;
			}
			else if(y!=-1){
					ans+=y+1;
			}
			if(x>=n){
					y=j-n+1;
			}	
		}
		printf("Case #%lld: %lld\n",ii,ans);
			
		
	}
	
	
	return 0;
}
	
