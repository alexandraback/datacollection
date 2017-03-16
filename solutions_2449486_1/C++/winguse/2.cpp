#include <cstdio>
#include <algorithm>
using namespace std;

struct P{
	int i,j,v;
};

bool operator < (const P &a, const P &b){
	return a.v<b.v;
}

int N,M,pc;
int m[110][110];
P p[12345];

bool ci(int i,int v){
	for(int j=0;j<M;j++){
		if(m[i][j]>v){
	//		printf("i %d %d %d %d\n",i,j,m[i][j],v);
			return true;
		}
	}
	return false;
}


bool cj(int j,int v){
	for(int i=0;i<N;i++){
		if(m[i][j]>v){
	//		printf("j %d %d\n",i,j);
			return true;
		}
	}
	return false;
}


bool ck(){
	for(int i=0;i<pc;i++){
		if(ci(p[i].i,p[i].v)&&cj(p[i].j,p[i].v)){
	//		printf("%d %d %d\n",p[i].i,p[i].j,p[i].v);
			return false;
		}
	//	m[p[i].i][p[i].j]=0;
	}
	return true;
}

int main(){
	int t,c;
	scanf("%d",&t);
	for(c=1;c<=t;c++){
		scanf("%d%d",&N,&M);
		pc = 0;
		for(int i=0;i<N;i++){
			for(int j=0;j<M;j++){
				scanf("%d",&m[i][j]);
				p[pc].i=i;
				p[pc].j=j;
				p[pc].v=m[i][j];
				pc++;
			}
		}
		sort(p,p+pc);
		printf("Case #%d: %s\n",c,ck()?"YES":"NO");
	}
	return 0;
}
