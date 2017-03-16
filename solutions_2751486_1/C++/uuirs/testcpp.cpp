#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
#define debug(x) cout<<#x<<'='<<x<<endl;
int f[26];
char s[1000005];
int main(){
	int T,n;
	f['a'-'a']=1;
	f['e'-'a']=1;
	f['i'-'a']=1;
	f['o'-'a']=1;
	f['u'-'a']=1;
//	freopen("in","r",stdin);
//	freopen("out","w",stdout);
	scanf("%d",&T);
	int cas=1;
	while(T--){
		scanf("%s",s);
		scanf("%d",&n);
		long long ans=0,len=0,np=-1;
		for(int i=0;s[i];i++){
			if(f[s[i]-'a']){
				len=0;
			}
			else{
				len++;
			}
			if(len>=n){
				np=i-n+1;
			}
			ans+=np==-1?0:np+1;
		}
		printf("Case #%d: %lld\n",cas++,ans);
	}
}
