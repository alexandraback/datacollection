#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
const int mm=1000000007;
char ch[111];
int tests,i,j,k,cc,n,m,w[111][111],ans,p[111],cot[31],len[111];
bool check(){
	int k,i,j,pre,tt;
	for (k=1,pre=tt=0;k<=n;k++){
		i=p[k];
		for (j=1;j<=len[i];j++){
			if (w[i][j]!=pre){
				if (pre){
					if (tt!=cot[pre]) return 0;
				}
				pre=w[i][j];tt=0;
			}
			tt++;
		}
	}
	return 1;
}
int main(){
	scanf("%d",&tests);cc=0;
	while (tests--){
		scanf("%d",&n);cc++;memset(cot,0,sizeof(cot));
		for (i=1;i<=n;i++){
			scanf("%s",ch);len[i]=strlen(ch);
			for (j=0;j<len[i];j++) w[i][j+1]=ch[j]-'a'+1,cot[w[i][j+1]]++;
		}
		ans=0;
		for (i=1;i<=n;i++) p[i]=i;
		while (1){
			if (check()) ans++;
			if (!next_permutation(p+1,p+1+n)) break;
		}
		printf("Case #%d: %d\n",cc,ans);
	}
	return 0;
}
