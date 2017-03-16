#include <cstdio>
#include <cstring>
#include <string>
#include <memory.h>
int T,Ti;
char ch[1000010];
int l;
int n,cn;
struct consc {
	int s,e;
};
consc c[600000];
int vow[100];
int vowel(char x) {
	return (x!='a' && x!='e' && x!='i' && x!='o' && x!='u');
}
int main() {
	freopen("input.txt","rt",stdin);
	freopen("output.txt","wt",stdout);
	scanf("%d",&T);
	for(Ti=1;Ti<=T;Ti++) {
		memset(vow,0,sizeof(vow));
		memset(c,0,sizeof(c));
		cn=0;
		strset(ch,0);
		scanf("%s",ch);
		scanf("%d",&l);
		n=strlen(ch);
		int i;
		int cons=0;
		int s,e;
		s=-1;
		e=-1;
		vow[0]=vowel(ch[0]);
		for(i=1;i<n;i++) {
			if(vowel(ch[i])==1) {
				if(vow[i-1]!=0) vow[i]+=vow[i-1];
				vow[i]++;
			}
		}
		for(i=0;i<n;i++) {
			if(vow[i]>0) {
				if(s==-1) s=i;
			}
			if(vow[i]==0) {
				if(s!=-1) e=i-1;
				if(e-s+1>=l) {
					c[cn].s=s;
					c[cn].e=e;
					cn++;
				}
				s=-1;
				e=-1;
			}
		}
		if(s!=-1 && n-s+1>=l) {
			c[cn].s=s;
			c[cn].e=n-1;
			cn++;
		}
		__int64 ans=0;
		if(cn!=0) {
			int cur=0;
			for(i=0;i<n;i++) {
				if(i<c[cur].s) {
					ans+=n-c[cur].s-l+1;
				}
				else if(c[cur].s<=i && i<=c[cur].e-l+1) {
					ans+=n-i-l+1;
				} else {
					cur++;
					i--;
				}
				if(cur==cn) break;
			}
		}
		printf("Case #%d: %I64d\n",Ti,ans);
	}
	return 0;
}
