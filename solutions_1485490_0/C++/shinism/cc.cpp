#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<vector>
#define N 1000
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define CHA(x,y) ((x)>(y)?((x)-(y)):((y)-(x)))

using namespace std;

struct emp {
	__int64 x,__int64 y;
};

emp my[N];
__int64 n,m,dap,su[N][2],su1[N][2];
FILE *in,*out;

void shin(__int64 pack1,__int64 pack_qnt,__int64 toy,__int64 toy_qnt,__int64 qnt){
	


	if(pack1==1 && toy==1){
		dap=dap;
	}

	if(su[pack1][0]==su1[toy][0]){
		if(pack_qnt<toy_qnt){
			qnt+=pack_qnt;
			toy_qnt-=pack_qnt;
			pack_qnt=0;
		}else{
			qnt+=toy_qnt;
			pack_qnt-=toy_qnt;
			toy_qnt=0;
		}		
	}
	dap=MAX(dap,qnt);

	if(pack1==n-1 && pack_qnt==0)
		return;
	if(toy==m-1 && toy_qnt==0)
		return;

	if(pack1>=n && toy>=m)
		return;


	if(pack_qnt==0 && pack1<n-1){
		if(toy_qnt==0 && toy<m-1){
			shin(pack1+1,su[pack1+1][1],toy+1,su1[toy+1][1],qnt);
		}else{
			shin(pack1+1,su[pack1+1][1],toy,toy_qnt,qnt);
		}
		shin(pack1+1,su[pack1+1][1],toy+1,su1[toy+1][1],qnt);

	}else if(toy_qnt==0 && toy<m-1){
		shin(pack1,pack_qnt,toy+1,su1[toy+1][1],qnt);
		shin(pack1+1,su[pack1+1][1],toy+1,su1[toy+1][1],qnt);
	}else{
		if(pack1<n-1)
			shin(pack1+1,su[pack1+1][1],toy,toy_qnt,qnt);
		if(toy<m-1)
			shin(pack1,pack_qnt,toy+1,su1[toy+1][1],qnt);
	}
}

void solve(void){
	__int64 i,j,x,y;

	fscanf(in,"%I64d %I64d",&n,&m);
	for(i=0;i<n;i++){
		fscanf(in,"%I64d %I64d",&su[i][1],&su[i][0]);
	}
	for(i=0;i<m;i++){
		fscanf(in,"%I64d %I64d",&su1[i][1],&su1[i][0]);
	}
	shin(0,su[0][1],0,su1[0][1],0);
}

__int64 main(){

	__int64 i,x,y,ttt;

	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	fscanf(in,"%I64d",&ttt);
	for(i=1;i<=ttt;i++){
		dap=0;
		solve();
		fprintf(out,"Case #%I64d: %I64d\n",i,dap);
	}
	return 0;
}
