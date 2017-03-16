#include <iostream>
using namespace std;

int n;
int num[20];
bool ans[20],ans2[20];
bool f[20],flag;
int ac,ac2;
int sum,small;
int counts;
int now,ii;

void init(){
	cin>>n;
	sum=0;
	small=num[0];
	for (int i=0;i<n;i++){
		cin>>num[i];
		if (num[i]<small) small=num[i];
		sum+=num[i];
	}
	return ;
}

void dfs(int i){
	if (counts==2 || i==20) return ;
	if (now==ii){
		counts++;
		if (counts==1) for (int j=0;j<n;j++) ans[j]=f[j];
		if (counts==2) for (int j=0;j<n;j++) ans2[j]=f[j];
		return ;
	}
	if (now+num[i]<=ii) {
		now=now+num[i];
		f[i]=true;
		dfs(i+1);
		f[i]=false;
		now=now-num[i];
	}
	dfs(i+1);
}
	

void solve(){
	flag=false;

	for (ii=small+1;ii<sum;ii++){	
		counts=0;
		ac=0;
		now=0;
		memset(f,false,sizeof(f));
		dfs(0);
		if (counts==2){
			bool tmpf=false;
			for (int i=0;i<n;i++) if (ans[i]){if (tmpf) cout<<' ';tmpf=true;cout<<num[i];}
			cout<<endl;
			tmpf=false;
			for (int i=0;i<n;i++) if (ans2[i]){if (tmpf) cout<<' ';tmpf=true;cout<<num[i];}
			cout<<endl;
			flag=true;
			break;
		}
	}
	if (!flag) cout<<"Impossible"<<endl;
	return ;
}

int main (){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("2C.out","w",stdout);
	int T;
	cin>>T;
	for (int t=1;t<=T;++t){
		init();
		printf("Case #%d: \n",t);
		solve();
	}
	return 0;
}