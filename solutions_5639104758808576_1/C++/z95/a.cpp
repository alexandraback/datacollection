#include <cstdlib>
#include <cstring>
#include <cstdio>
#define FOR(i,n) for(int i=0;i<n;++i)

using namespace std;

  
int main(void) {
	int n;
	char s[5000];
	scanf("%d",&n);
	FOR(k,n) {
		int smax;
		scanf("%d %s\n",&smax,s);
		long long ppl = 0;
		int ans=0;
		for(int i=0;i<=smax;++i) {
			if(ppl<i) {
				ans+=i-ppl;
				ppl=i;
			}
			ppl+=s[i]-'0';
		}
		char x='#';
		printf("Case %c%d: %d\n",x,k+1,ans);
	}
	
	
   
}