#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cstdlib>
using namespace std;
int i,j,k,l,n,m,len,next[1150000][26],f[2][1150000][5],ans,t,bo[1150000],
	T,tim,v,x;
char c[120];
void add(){
	int i,j,l=strlen(c+1),p=1;
	for(i=1;i<=l;++i){
		j=c[i]-97;
		if(!next[p][j])next[p][j]=++len;
		p=next[p][j];
	}
	bo[p]=1;
}
void renew(int y,int z,int v){
	if(z>=5)z=4;
	f[t^1][y][z]=min(f[t^1][y][z],v);
}
int main(){
	freopen("C_dict.txt","r",stdin);
	freopen("C.out","w",stdout);
	len=1;
	while(scanf("%s",c+1)!=EOF)
		add();
	freopen("C.in","r",stdin);
	for(scanf("%d",&T),tim=1;tim<=T;++tim){
		scanf("%s",c+1);
		l=strlen(c+1);
		memset(f,3,sizeof(f));
		f[0][1][4]=0;
		t=0;
		for(i=1;i<=l;++i){
			for(j=1;j<=len;++j)
				for(k=0;k<5;++k)if((v=f[t][j][k])<100000){
					if(next[j][c[i]-97])renew(next[j][c[i]-97],k+1,v);
					if(k==4){
						for(x=0;x<26;++x)if(next[j][x])
							renew(next[j][x],0,v+1);
					}
					if(bo[j]){
						if(next[1][c[i]-97])renew(next[1][c[i]-97],k+1,v);
						if(k==4){
							for(x=0;x<26;++x)if(next[1][x])
								renew(next[1][x],0,v+1);
						}
					}
					f[t][j][k]=100000000;
				}
			t^=1;
		}
		ans=100000000;
		for(i=1;i<=len;++i)if(bo[i])
			for(j=0;j<5;++j)ans=min(ans,f[t][i][j]);
		printf("Case #%d: %d\n",tim,ans);
	}
}
			
