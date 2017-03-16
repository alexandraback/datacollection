#include<fstream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define oo 0x7fffffff
#define N 10		//0000
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define SBS(x,y) ((x)<(y)?(y-x):(x-y))

using namespace std;

int t,n,m;
double dap,p[N],accp[N];


void solve(void){
	int i,j,a;
	double x,y,z;

	//누적확율
	accp[0]=p[0];
	for(i=1;i<m;i++)
		accp[i] =accp[i-1]*p[i];

	//dap=oo;
	//걍엔터치는경우
	if(n==m){
		dap=1;
		return;
	}else{
		dap=1+n+1;
	}

	//끝까지 칠경우
	z=accp[m-1];
	x=z*(n-m+1) + (1-z)*(n-m+1+n+1);
	dap=MIN(dap,x);

	//back i번 : m-i가맞는냐..틀리냐??
	y=oo;
	for(i=1;i<=m/2;i++){
		z=accp[m-1-i];
		x=z*(n-m+i+i+1)+(1-z)*(n-m+i+i+1+n+1);
		if(x<y)
			y=x;
	//	else///
	//		y=y;
	}
	dap=MIN(dap,y);
}

int main(void){
	FILE *in,*out;
	int i,j;
	int x,y,z,k;


	in=fopen("A-small-attempt0.in","r");
	out=fopen("output.txt","w");
	fscanf(in,"%d",&t);
	
	for(i=1;i<=t;i++){
		fscanf(in,"%d %d",&m,&n);
		for(j=0;j<m;j++)
			fscanf(in,"%lf",&p[j]);
		solve();
		fprintf(out,"Case #%d: %.10lf\n",i,dap);
	}


	return 0;

}