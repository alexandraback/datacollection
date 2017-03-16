#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

typedef struct A{
	int h,px,py;
}AA;
AA a[10005];
int s[105][105],N,M,use[105][105];
int op[4][2]={{-1,0},{0,-1},{0,1},{1,0}};

int com(const void *aa,const void *bb){
	AA c,d;
	c = *(AA*)(aa);
	d = *(AA*)(bb);
	return c.h>d.h ? -1 : 1;
}

bool ok(int tx,int ty,int hh){
	int i,j,nx,ny,c,re,ret = false;
	for(i=0,j=3;i<2;i++,j--){
		c = 0;
		nx = tx+op[i][0];
		ny = ty+op[i][1];
		re = 1;
		while(nx>=0 && nx<N && ny>=0 && ny<M && re==1){
			if(use[nx][ny]==1 && hh<s[nx][ny])
				re = 0;
			nx += op[i][0];
			ny += op[i][1];
		}
		if(re==1) c += 1;
		///////////////////////////////
		nx = tx+op[j][0];
		ny = ty+op[j][1];
		re = 1;
		while(nx>=0 && nx<N && ny>=0 && ny<M && re==1){
			if(use[nx][ny]==1 && hh<s[nx][ny])
				re = 0;
			nx += op[j][0];
			ny += op[j][1];
		}
		if(re==1) c += 2;
		if(c==3){
			ret = true;
			s[tx][ty] = hh;
			nx = tx+op[i][0];
			ny = ty+op[i][1];
			while(nx>=0 && nx<N && ny>=0 && ny<M){
				s[nx][ny] = hh;
				nx += op[i][0];
				ny += op[i][1];
			}
			nx = tx+op[j][0];
			ny = ty+op[j][1];
			while(nx>=0 && nx<N && ny>=0 && ny<M){
				s[nx][ny] = hh;
				nx += op[j][0];
				ny += op[j][1];
			}
		}
	}
	return ret;
}

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("out.txt","w",stdout);
    
    int T,t,n,m,i,j,all;
	scanf(" %d",&T);
	for(t=1;t<=T;t++){
		scanf(" %d %d",&N,&M);
		all = 0;
		for(n=0;n<N;n++){
			for(m=0;m<M;m++){
				scanf(" %d",&a[all].h);
				a[all].px = n;
				a[all].py = m;
				all++;
			}
		}
		qsort(a,all,sizeof(a[0]),com);
		for(n=0;n<=N;n++)
			for(m=0;m<=M;m++)
				s[n][m] = 105;
		int re = 1,x,y,hh;
		memset(use,0,sizeof(use));
		for(i=0;i<all && re==1;i++){
			x = a[i].px;
			y = a[i].py;
			hh = a[i].h;
			use[x][y] = 1;
			if(hh==s[x][y])	continue;
			else if(hh>s[x][y])	re = 0;
			else{
				if(!ok(x,y,hh))	re = 0;
			}
		}
		if(re==0)	printf("Case #%d: NO\n",t);
		else	printf("Case #%d: YES\n",t);
		/*for(n=0;n<N;n++){
			for(m=0;m<M;m++){
				if(m==0)	printf("%d",s[n][m]);
				else	printf(" %d",s[n][m]);
			}
			printf("\n");
		}*/
	}
    
    return 0;
}