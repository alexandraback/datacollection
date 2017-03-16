#include <stdio.h>
#include <memory.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int R,C,M,F;
bool g[50][50];
int main()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int t;
	bool f;
	scanf("%d",&t);
	for(int k=1;k<=t;++k){
		printf("Case #%d:\n",k);
		scanf("%d%d%d",&R,&C,&M);
		F=R*C-M;
		memset(g,true,sizeof(g));
		f=false;
		if(M==R*C-1){
			f=true;
			g[0][0]=false;
		}else if(R==1 || C==1 || M==0){
			f=true;
			memset(g,false,sizeof(g));
			for(int i=0;i<M;++i)
				if(R==1)
					g[0][C-i-1]=true;
				else
					g[R-i-1][0]=true;
		}else{
			for(int r=2;!f && r<=R && r<=F;++r)
				for(int c=2;!f && c<=C && r*c<=F;++c)
					if(F-r*c<=r+c-2){
						if(r==R){
							int rem=F-r*c;
							if(rem/r>=1)
								continue;
							if(rem==1)
								continue;
							f=true;
							for(int i=0;i<r;++i)
								for(int j=0;j<c;++j)
									g[i][j]=false;
							for(int i=0;i<rem;++i)
								g[i][c]=false;
						}else if(c==C){
							int rem=F-r*c;
							if(rem/c>=1)
								continue;
							if(rem==1)
								continue;
							f=true;
							for(int i=0;i<r;++i)
								for(int j=0;j<c;++j)
									g[i][j]=false;
							for(int i=0;i<rem;++i)
								g[r][i]=false;
						}else{
							int rem=F-r*c;
							int a=min(rem,max(r,c)-1);
							int b=rem-a;
							if(b==1){
								++b;
								--a;
							}
							if(a<0 || a==1 || b>min(r,c))
								continue;
							f=true;
							for(int i=0;i<r;++i)
								for(int j=0;j<c;++j)
									g[i][j]=false;
							if(r>c){
								for(int i=0;i<a;++i)
									g[i][c]=false;
								for(int i=0;i<b;++i)
									g[r][i]=false;
							}else{
								for(int i=0;i<a;++i)
									g[r][i]=false;
								for(int i=0;i<b;++i)
									g[i][c]=false;
							}
						}
					}
		}
		if(!f)
			puts("Impossible");
		else
			for(int i=0;i<R;++i,puts(""))
				for(int j=0;j<C;++j)
					if(!i && !j)
						putchar('c');
					else if(g[i][j]==false)
						putchar('.');
					else
						putchar('*');
	}
	return 0;
}