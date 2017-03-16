#include <iostream>
using namespace std;

int path[1001][11];
int n;
bool flagfind;
int from,to;
int counts;

void init(){
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>path[i][0];
		for (int j=1;j<=path[i][0];j++)
			cin>>path[i][j];
	}
	flagfind=false;
}

void dfs(int i){
	if (counts==2) return ;
	if (i==to){counts++; if (counts==2) flagfind=true; return;}
	int num=path[i][0];
	if (num==0) return ;
	for (int j=1;j<=num;j++){
		dfs(path[i][j]);
	}
}

void test(int f,int t){
	from=f;to=t;
	counts=0;
	dfs(from);
}

void solve(){
	for (int i=1;i<=n;i++)
		for (int j=1;j<=n;j++)
			if (i!=j){
				//path i to j
				test(i,j);
				if (flagfind) goto end;
			}
end: ;
}

int main (){
	freopen("A-small-attempt0.in","r",stdin);
	freopen("3A.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;++t){
		init();
		printf("Case #%d: ",t);
		solve();
		if (flagfind) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}