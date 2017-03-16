#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char s[211];
int tests,ans,i,j,k,n,m,a[211],tc;
int main(){
	for (scanf("%d",&tests),tc=1;tests--;tc++){
		fprintf(stderr,"%d\n",tc);
		scanf("%s",s);n=strlen(s);
		for (i=1;i<=n;i++) a[i]=(s[i-1]=='+')?1:0;
		for (ans=0;;){
			while (a[n]) n--;
			if (!n) break;
			for (i=0;i<n&&a[i+1];i++);
			if (i==n) break;
			if (i){
				ans++;
				for (j=1;j<=i;j++) a[j]^=1;
			}
			for (i=0;i<n&&!a[i+1];i++);
			for (i++;i<=n&&a[i];i++);
			if (i>n){
				ans++;break;
			}else{
				ans++;
				for (j=1;j<=n/2;j++) swap(a[j],a[n-j+1]);
				for (j=1;j<=n;j++) a[j]^=1;
			}
		}
		printf("Case #%d: %d\n",tc,ans);
	}
	return 0;
}
