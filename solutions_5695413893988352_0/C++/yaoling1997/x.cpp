#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 10,oo= 1e9;
char s[maxn],t[maxn],cc[maxn],jj[maxn],ac[maxn],aj[maxn];
int T,i,j,len,ans,C,J;
void dfs2(int o,int s,int now){
	if (o>len){
		if (abs(s-now)<ans){
			ans= abs(s-now);
			C= s;
			J= now;
			memcpy(ac,cc,sizeof(cc));
			memcpy(aj,jj,sizeof(jj));			
		}else if (abs(s-now)==ans){
			if (s<C){
				C= s;
				J= now;
				memcpy(ac,cc,sizeof(cc));
				memcpy(aj,jj,sizeof(jj));			
			}else if (s==C){
				if (now<J){
					J= now;
					memcpy(ac,cc,sizeof(cc));
					memcpy(aj,jj,sizeof(jj));								
				}
			}
		}
		return;
	}
	if (t[o]=='?'){
		for (int i= 0;i<10;i++){
			jj[o]= i+'0';
			dfs2(o+1,s,now*10+i);
		}
	}else {
		jj[o]= t[o];
		dfs2(o+1,s,now*10+t[o]-'0');
	}
}
void dfs(int o,int now){
	if (o>len){
		dfs2(1,now,0);
		return;
	}
	if (s[o]=='?'){
		for (int i= 0;i<10;i++){
			cc[o]= i+'0';
			dfs(o+1,now*10+i);
		}
	}else {
		cc[o]= s[o];
		dfs(o+1,now*10+s[o]-'0');
	}
}
void init(){
	ans= oo;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%d",&T);
	for (int tt= 1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		scanf("%s%s",s+1,t+1);
		init();
		len= strlen(s+1);
		dfs(1,0);
		for (i= 1;i<=len;i++)
			printf("%c",ac[i]);
		printf(" ");
		for (i= 1;i<=len;i++)
			printf("%c",aj[i]);
		printf("\n");
	}return 0;
}
