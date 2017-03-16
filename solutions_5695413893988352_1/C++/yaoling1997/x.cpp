#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#define ll long long
#define ld long double
using namespace std;
const ll maxn= 20,oo= 1e9;
char s[maxn],t[maxn],cc[maxn],jj[maxn],ac[maxn],aj[maxn];
ll T,i,j,len,ans,C,J;
void dfs2(ll o,ll s,ll now){
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
		for (ll i= 0;i<10;i++){
			jj[o]= i+'0';
			dfs2(o+1,s,now*10+i);
		}
	}else {
		jj[o]= t[o];
		dfs2(o+1,s,now*10+t[o]-'0');
	}
}
void dfs(ll o,ll now){
	if (o>len){
		dfs2(1,now,0);
		return;
	}
	if (s[o]=='?'){
		for (ll i= 0;i<10;i++){
			cc[o]= i+'0';
			dfs(o+1,now*10+i);
		}
	}else {
		cc[o]= s[o];
		dfs(o+1,now*10+s[o]-'0');
	}
}
void check(ll s,ll t){
	if (abs(s-t)<ans){
		ans= abs(s-t);
		C= s;
		J= t;
		memcpy(ac,cc,sizeof(cc));
		memcpy(aj,jj,sizeof(jj));			
	}else if (abs(s-t)==ans){
		if (s<C){
			C= s;
			J= t;
			memcpy(ac,cc,sizeof(cc));
			memcpy(aj,jj,sizeof(jj));			
		}else if (s==C){
			if (t<J){
				J= t;
				memcpy(ac,cc,sizeof(cc));
				memcpy(aj,jj,sizeof(jj));	
			}
		}
	}
}
void DFS(ll o,ll ss,ll tt){
	if (o>len){
		check(ss,tt);
		return;
	}
	if (s[o]=='?'&&t[o]=='?'){
		if (ss==tt){
			cc[o]= jj[o]= '0';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');
			cc[o]= '1';
			jj[o]= '0';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');
			cc[o]= '0';
			jj[o]= '1';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');			
		}else if (ss>tt){
			cc[o]= '0';
			jj[o]= '9';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');			
		}else {
			cc[o]= '9';
			jj[o]= '0';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');						
		}
	}else if (s[o]=='?'){
		jj[o]= t[o];
		if (ss==tt){
			cc[o]= t[o];
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');
			if (t[o]+1<='9'){
				cc[o]= t[o]+1;
				DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');				
			}
			if (t[o]-1>='0'){
				cc[o]= t[o]-1;
				DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');				
			}			
		}else if (ss>tt){
			cc[o]= '0';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');			
		}else {
			cc[o]= '9';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');
		}		
	}else if (t[o]=='?'){
		cc[o]= s[o];
		if (ss==tt){
			jj[o]= s[o];
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');
			if (s[o]+1<='9'){
				jj[o]= s[o]+1;
				DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');				
			}
			if (s[o]-1>='0'){
				jj[o]= s[o]-1;
				DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');				
			}			
		}else if (ss<tt){
			jj[o]= '0';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');			
		}else {
			jj[o]= '9';
			DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');
		}				
	}else {
		cc[o]= s[o];
		jj[o]= t[o];
		DFS(o+1,ss*10+cc[o]-'0',tt*10+jj[o]-'0');
	}
}
void init(){
	ans= oo;
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	scanf("%I64d",&T);
	for (ll tt= 1;tt<=T;tt++){
		printf("Case #%I64d: ",tt);
		scanf("%s%s",s+1,t+1);
		init();
		len= strlen(s+1);
		//dfs(1,0);
		DFS(1,0,0);
		for (i= 1;i<=len;i++)
			printf("%c",ac[i]);
		printf(" ");
		for (i= 1;i<=len;i++)
			printf("%c",aj[i]);
		printf("\n");
	}return 0;
}
