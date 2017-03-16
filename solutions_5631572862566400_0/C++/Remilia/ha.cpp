// by ¦Î
// program sky  :)

#include <vector>
#include <stdio.h>
#include <algorithm>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)
#define pb push_back

using namespace std;

typedef vector<int> VI;

inline int IN(){
	char c;Rin x=0;
	for(;oo<48 && c^'-' || c>57;);bool f=c=='-';if(f)oo;
	for(;c>47 && c<58;oo)x=(x<<3)+(x<<1)+c-48;if(f)x=-x;return x;
}

inline void hello(){
	freopen("ha.in","r",stdin);
	freopen("ha.out","w",stdout);
}

int n,fa[1005],st[1005],vs[1005];
VI Ed[1005];

int dfs(int u){
	st[++*st]=u;
	vs[u]=1;
	if(!vs[fa[u]]){
		int res=dfs(fa[u]);
		vs[u]=0;
		--*st;
		return res;
	}
	if(fa[u]==st[1]){
		vs[u]=0;
		--*st;
		return 1+*st;
	}
	vs[u]=0;
	--*st;
	return 0;
}

inline int gao1(){
	int res=0;
	For(i,1,n)res=max(res,dfs(i));
	return res;
}

int sou(int u){
	int res=1;
	for(int v:Ed[u])if(v^fa[u]){
		res=max(sou(v)+1,res);
	}
	return res;
}

inline int lu(int u,int v){
	return sou(u)+sou(v);
}

inline int gao2(){
	For(i,1,n)Ed[fa[i]].pb(i);
	int res=0;
	For(i,1,n)if(fa[i]>i && fa[fa[i]]==i)res+=lu(i,fa[i]);
	return res;
}

int main(){
// say hello
	hello();
	For(tc,1,IN()){
		printf("Case #%d: ",tc);
		n=IN();
		For(i,1,n)fa[i]=IN(),Ed[i].resize(0);
		printf("%d\n",max(gao1(),gao2()));
	}
// never say goodbye
}