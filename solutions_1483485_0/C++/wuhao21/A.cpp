#include <cstdio>
#include <algorithm>
using namespace std;
const char change[26]={'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
int T;
char s[1111];
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	scanf("%d",&T);getchar();
	for (int t=1;t<=T;t++){
		gets(s);
		int l=strlen(s);
		for (int i=0;i<l;i++) if (s[i]>='a' && s[i]<='z') s[i]=change[s[i]-'a'];
		printf("Case #%d: ",t);
		puts(s);
	}
	return 0;
}
