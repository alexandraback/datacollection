#include<cstdio>
#include<string>
#include<cstring>
#include<string>
using namespace std;

const int maxn=2010;

const string num[10]={"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

char s[maxn];
int n;

int a[300];
int ans[maxn];int ansN;

void change(char c,int x){
	int z=a[c];
	for(int i=0;i<z;++i){
		ans[ansN++]=x;
		for(int j=0;j<num[x].size();++j)--a[num[x][j]];
	}
}

void solve(){
	scanf("%s",s);n=strlen(s);
	for(int i=0;i<n;++i)a[s[i]]++;
	ansN=0;
	change('Z',0);
	change('W',2);
	change('U',4);
	change('F',5);
	change('X',6);
	change('V',7);
	change('G',8);
	change('T',3);
	change('O',1);
	change('I',9);
	for(char c='A';c<='Z';++c)assert(a[c]==0);
	sort(ans,ans+ansN);
	for(int i=0;i<ansN;++i)printf("%d",ans[i]);putchar('\n');
}

int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	memset(a,0,sizeof a);
	int kase,i=0;scanf("%d",&kase);
	for(int i=1;i<=kase;++i){
		printf("Case #%d: ",i);
		solve();
	}
	return 0;
}
