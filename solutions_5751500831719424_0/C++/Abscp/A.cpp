#include<cstdio>
#include<cstring>
#include<algorithm>
#include<string>
using namespace std;
int n,a[110],b[110],len[110];
char s[110][110];
bool check(){
	int l=strlen(s[1]);
	string t1,t2;
	t1=s[1][0];
	for(int i=1;i<l;++i){
		if(s[1][i]==s[1][i-1])continue;
		t1+=s[1][i];
	}
	for(int i=2;i<=n;++i){
		t2=s[i][0];
		l=strlen(s[i]);
		for(int j=1;j<l;++j){
			if(s[i][j]==s[i][j-1])continue;
			t2+=s[i][j];
		}
		if(t1!=t2)return 0;
	}
	return 1;
}
void solve(int cas){
	printf("Case #%d: ",cas);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%s",s[i]);
	if(!check()){
		printf("Fegla Won\n");
		return;
	}
	for(int i=1;i<=n;++i){
		b[i]=0;
		len[i]=strlen(s[i]);
	}
	int ans=0;
	while(1){
		for(int i=1;i<=n;++i){
			a[i]=0;
			while(b[i]+1<len[i]&&s[i][b[i]]==s[i][b[i]+1]){
				++b[i];
				++a[i];
			}
			++b[i];
		}
		sort(a+1,a+n+1);
		for(int i=1;i<=n;++i)ans+=abs(a[i]-a[(n+1)/2]);
		if(b[1]==len[1])break;
	}
	printf("%d\n",ans);
}
int main(){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("A-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int i=1;i<=T;++i)solve(i);
	return 0;
} 
