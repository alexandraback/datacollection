#include <stdio.h>
#include <string.h>
#include <algorithm>
using std::next_permutation;

bool check(char *s){
	bool show[26];
	memset(show,0,sizeof(show));
	while( *s ){
		if( show[*s-'a'] ) return 0;
		show[*s-'a'] = 1;
		++s;
		while( *s && *s == *(s-1) )
			++s;
	}
	return 1;
}

char alls[100000];
char in[200][200];

void build(int *p, int n){
	int aptr = 0;
	for(int i=0;i<n;++i){
		char *t = in[p[i]];
		int ptr = 0;
		while( t[ptr] ){
			alls[aptr++] = t[ptr++];
		}
	}
	alls[aptr] = 0;
}


int main(){
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t){
		int n;
		scanf("%d",&n);
		for(int i=0;i<n;++i)
			scanf("%s", in[i]);
		int p[10];
		for(int i=0;i<n;++i)
			p[i] = i;	
		int ans = 0;
		do{
			build(p,n);
			if( check(alls) )
				++ans;
		}while(next_permutation(p,p+n));
		printf("Case %d: %d\n",t, ans);
	}
	return 0;	
}
