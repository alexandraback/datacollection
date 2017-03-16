#include <cstdio>
const int MAXL=1000002;
bool name[MAXL];
inline bool v(char c){
	if((c=='a')|(c=='e')|(c=='i')|(c=='o')|(c=='u')) return false;
	else return true;
}
int main(){
	int T;
	scanf("%d",&T);
	for(int testcase=0;testcase<T;++testcase){
		char c;
		int n,l;
		long long ans=0;
		for(scanf("%c",&c);!(('a'<=c)&&(c<='z'));scanf("%c",&c));
		l=0;name[0]=v(c);
		for(scanf("%c",&c);(('a'<=c)&&(c<='z'));scanf("%c",&c))
			name[++l]=v(c);
		name[++l]=false;
		scanf("%d",&n);
		int t=0;int last=0;
		for(int i=0;i<=l;++i){
			if(name[i]) ++t;
			else{
				if(t>=n){
					long long temp=0;
					temp=i-t-last;
					temp*=l-i+t-n+1;
					ans+=temp;
					temp=l+l-i-i+2+t-n;
					temp*=t-n+1;
					ans+=temp/2;
					last=i-n+1;
				}
				t=0;
			}
		}
		printf("Case #%d: %lld\n",testcase+1,ans);
	}
}

