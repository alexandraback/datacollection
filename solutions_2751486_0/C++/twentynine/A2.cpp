#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[1000005];
bool a[1000005];
int main(){
//freopen("A-small-attempt1.in","r",stdin);
//freopen("A-small-attempt1.out","w",stdout);
	long long n,i,j,tc,ii,k;
	scanf("%lld",&tc);
	for(ii=1;ii<=tc;ii++){
		scanf("\n%s %lld",s,&n);
		long long len=strlen(s),ans=0;
		
		for(i=0;i<len;i++){
			for(j=i;j<len;j++){
				long long x=0,y=0;
				for(k=i;k<=j;k++){
					if(s[k]=='a'||s[k]=='e'||s[k]=='i'||s[k]=='o'||s[k]=='u')x=0;
					else x++;
					if(x>=n)y=1;
				}
				ans+=y;
			}
		}
	
		printf("Case #%lld: %lld\n",ii,ans);
			
		
	}
	
	
	return 0;
}
	
