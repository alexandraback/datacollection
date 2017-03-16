#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
const int N = 110000;
//#define LOCAL
ll c[20],j[20];
char sc[20],sj[20];
int n;
char tc[20],tj[20];
string aa,bb;
ll ansa,ansb;
ll ans;
inline ll string_to_num(char *s){
	ll a=0;
	for(int i=0;s[i];i++)
		a=a*10+s[i]-'0';
	return a;
}

void pd(){
	ll tmpa,tmpb;
	tmpa = string_to_num(tc);
	tmpb = string_to_num(tj);
	ll tmp = abs(tmpa-tmpb);
	if (ans==-1 || ans>tmp){
		ans = tmp;
		ansa = tmpa;
		ansb = tmpb;
		aa = tc;
		bb = tj;
		return;
	}

	if (tmp==ans && ansa>tmpa){
		ansa = tmpa; ansb = tmpb; aa = tc; bb = tj; return;
	}
	if (tmp==ans && ansa==tmpa && ansb>tmpb){
		ansa = tmpa; ansb = tmpb; aa = tc; bb = tj; return;
	}
}
void dfs(int a){
	if (a==2*n){
		pd();
		return;
	}
	if (a>=n){
		if (sj[a-n]=='?'){
			for(char c='0';c<='9';c++){
				tj[a-n] = c;
				dfs(a+1);
			}
		}else dfs(a+1);
	}else{
		if (sc[a]=='?'){
			for(char c='0';c<='9';c++){
				tc[a] = c;
				dfs(a+1);
			}
		}else dfs(a+1);
	}
}

int main(){
	#ifdef LOCAL
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	#endif
	
	int T;
	scanf("%d",&T);
	for(int times=1;times<=T;times++){
		scanf(" %s %s",sc,sj);
		n = strlen(sc);
		for(int i=0;i<=n;i++) tc[i]=sc[i],tj[i]=sj[i];
		ans = -1;
		dfs(0);

		printf("Case #%d: ",times);
		cout << aa << " " << bb << endl;
	}
	return 0;
}