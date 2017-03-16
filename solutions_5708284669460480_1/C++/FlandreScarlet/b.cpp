#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
template<class T> T sqr(T x) {return x*x;}
#define pi acos(-1)
#define INF 100000000
#define debug(x) cerr<<#x"="<<(x)<<"\n";
#define foreach(it,v) for (__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)

int fail[110];
int a[26];
int go[110][26];
int f[110][110];
double g[110][110];
char s[110];

int main() {
	int tt;
	scanf("%d",&tt);
	for (int te=1;te<=tt;te++) {
		int K,L,S;
		scanf("%d%d%d",&K,&L,&S);
		scanf("%s",s);
		memset(a,0,sizeof(a));
		for (int i=0;i<K;i++) a[s[i]-'A']++;
		scanf("%s",s+1);
		memset(go,0,sizeof(go));
		memset(fail,0,sizeof(fail));
		for (int i=0;i<=L;i++) {
			if (i>1) {
				int x=fail[i-1];
				while (x && s[x+1]!=s[i]) x=fail[x];
				if (s[x+1]==s[i]) fail[i]=x+1;
			}
			for (int j=0;j<26;j++)
				if (i+1<=L && s[i+1]=='A'+j) go[i][j]=i+1;
				else go[i][j]=go[fail[i]][j];
		}
		for (int i=0;i<=S;i++)
			for (int j=0;j<=L;j++) {
				f[i][j]=-INF;
				g[i][j]=0;
			}
		f[0][0]=0;
		for (int i=0;i<S;i++)
			for (int j=0;j<=L;j++)
				for (int k=0;k<26;k++)
					if (a[k]) {
						int t=f[i][j];
						if (go[j][k]==L) t++;
						f[i+1][go[j][k]]=max(f[i+1][go[j][k]],t);		
					}
		g[0][L]=1;
		for (int i=1;i<=S;i++)
			for (int j=0;j<=L;j++) {
				for (int k=0;k<26;k++)
					if (a[k]) {
						g[i][j]+=g[i-1][go[j][k]]*a[k]/K;
					}
				if (j==L) g[i][j]+=1;
			}
		int a1=0;
		double a2=g[S][0];
		for (int j=0;j<=L;j++) 
			a1=max(a1,f[S][j]);
		printf("Case #%d: %.10lf\n",te,a1-a2);
	}
}
