#include <cstdio>
#include <algorithm>
using namespace std;

const int N=10005;
int tab[8][8]={
	{0|0,0|1,0|2,0|3},
	{0|1,4|0,0|3,4|2},
	{0|2,4|3,4|0,0|1},
	{0|3,0|2,4|1,4|0}
};

int l;
long long x;
char s[N];
bool opt[24][24],ans[24][24],tmp[24][24];
bool f[N][24];

void mul(bool c[24][24],bool a[24][24],bool b[24][24]){
	for(int i=0;i<24;i++)
		for(int j=0;j<24;j++){
			tmp[i][j]=false;
			for(int k=0;k<24;k++) if(a[i][k]&&b[k][j]){
				tmp[i][j]=true;
				break;
			}
		}
	for(int i=0;i<24;i++)
		for(int j=0;j<24;j++)
			c[i][j]=tmp[i][j];
}

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen(".out","w",stdout);
	for(int i=0;i<8;i++)
		for(int j=0;j<8;j++)
			tab[i][j]=tab[i&3][j&3]^(i&4)^(j&4);
	int T; scanf("%d",&T);
	for(int Case=1;Case<=T;Case++){
		scanf("%d%lld",&l,&x);
		scanf("%s",s+1);
		for(int i=1;i<=l;i++) s[i]=s[i]-'i'+1;
	//	for(int i=l+1;i<=l*x;i++) s[i]=s[i-l];
	//	l*=x;
		for(int left=0;left<24;left++){
			for(int i=0;i<=l;i++)
				for(int j=0;j<24;j++)
					f[i][j]=false;
			f[0][left]=true;
			for(int i=1;i<=l;i++){
				for(int j=0;j<3;j++)
					for(int k=0;k<8;k++){
						int x=j*8+k;
						if(!f[i-1][x]) continue;
						int jj=j,kk=tab[k][s[i]];
						int y=jj*8+kk;
						f[i][y]=true;
						if(j<2&&kk==j+1){
							jj=j+1,kk=0;
							y=jj*8+kk;
							f[i][y]=true;
						}
					}
			}
			for(int right=0;right<24;right++)
				opt[left][right]=f[l][right];
		}
	//	printf("Case #%d: %s\n",Case,f[l][2*8+3]?"YES":"NO");
		/*
		for(int i=0;i<24;i++,puts(""))
			for(int j=0;j<24;j++) printf(" %d",opt[i][j]);
		puts("");
		*/
		
		for(int i=0;i<24;i++)
			for(int j=0;j<24;j++)
				ans[i][j]=(i==j);
		for(;x;x>>=1){
			if(x&1)
				mul(ans,ans,opt);
			mul(opt,opt,opt);
		}
		printf("Case #%d: %s\n",Case,ans[0][2*8+3]?"YES":"NO");
	}
	scanf("\n");
}
