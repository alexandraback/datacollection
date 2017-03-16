// by ¦Î
// program sky  :)

#include <stdio.h>
#include <string.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)

using namespace std;

inline int IN(){
	char c;Rin x=0;
	for(;oo<48 && c^'-' || c>57;);bool f=c=='-';if(f)oo;
	for(;c>47 && c<58;oo)x=(x<<3)+(x<<1)+c-48;if(f)x=-x;return x;
}

int n;
char s[105];

inline void hello(){
	freopen("ha.in","r",stdin);
	freopen("ha.out","w",stdout);
}

int main(){
// say hello
	hello();
	For(tc,1,IN()){
		printf("Case #%d: ",tc);
		scanf("%s",s+1);
		n=strlen(s+1);
		s[n+1]='+';
		int ans=0;
		for(int i=1;i<=n;){
			int j=i;
			for(;j<=n && s[j]==s[i];++j);
			if(s[j]==s[i])break;
			else{
				++ans;
				i=j;
			}
		}
		printf("%d\n",ans);
	}
// never say goodbye
}