// by ¦Î
// program sky  :)

#include <vector>
#include <stdio.h>
#include <string>
#include <string.h>
#include <algorithm>
#include <iostream>

#define Rin register int
#define oo (c=getchar())
#define For(i,l,r) for(int _r=r,i=l;i<=_r;++i)
#define rep(i,l,r) for(int _r=r,i=l;i<_r;++i)
#define dto(i,r,l) for(int _l=l,i=r;i>=_l;--i)
#define ALL(V) V.begin(),V.end()
#define pb push_back
#define x first
#define y second

using namespace std;

inline int IN(){
	char c;Rin x=0;
	for(;oo<48 && c^'-' || c>57;);bool f=c=='-';if(f)oo;
	for(;c>47 && c<58;oo)x=(x<<3)+(x<<1)+c-48;if(f)x=-x;return x;
}

int n;

char s[10000];

string ss;

inline void hello(){
	freopen("ha.in","r",stdin);
	freopen("ha.out","w",stdout);
}

int main(){
// say hello
	hello();
	For(tc,1,IN()){
		scanf("%s",s+1);
		n=strlen(s+1);
		ss="";
		For(i,1,n){
			if(ss+s[i]<s[i]+ss)ss=s[i]+ss;
			else ss=ss+s[i];
		}
		printf("Case #%d: ",tc);
		cout<<ss<<endl;
	}
// never say goodbye
}