#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
#define eprintf(...) fprintf(stderr,__VA_ARGS__)

int n;
char s[105];

int Main(){
	scanf("%s",s);
	n=strlen(s);
	while(n&&s[n-1]=='+') n--;
	if(n==0) return 0;
	int ans=0;
	if(s[0]=='-'){
		ans++;
		reverse(s,s+n);
		for(int i=0;i<n;i++) if(s[i]=='-') s[i]='+'; else s[i]='-';
		while(n&&s[n-1]=='+') n--;
	}
	while(n){
		ans+=2;
		while(n&&s[n-1]=='-') n--;
		while(n&&s[n-1]=='+') n--;
	}
	return ans;
}

int main(){
	freopen("B-large.in","r",stdin);
	freopen("B.out","w",stdout);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		printf("Case #%d: %d\n",Case,Main());
	}
}
