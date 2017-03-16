#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

int n;
char s[100000];
char a[100000],b[100000];

int main(){
	freopen("A-small-attempt1.in","r",stdin);
	freopen("A.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		scanf("%s",s);
		n=strlen(s);
		a[0]=0;
		b[0]=0;
		for(int i=0;i<n;i++){
			b[0]=s[i];
			strcpy(b+1,a);
			a[i]=s[i];
			a[i+1]=0;
			if(strcmp(b,a)>0){
				strcpy(a,b);
			}
		}
		printf("Case #%d: %s\n",Case,a);
	}
}
