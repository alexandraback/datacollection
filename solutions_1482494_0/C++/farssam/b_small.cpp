#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#define oo 0x7fffffff
#define N 1000
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define SBS(x,y) ((x)<(y)?(y-x):(x-y))

using namespace std;

int t,n;
int chk[N];
int star[N+10][2],dap,dap1;
FILE *in,*out;


void shin(int s,int x,int c){//star, clear, play num
	int i,y,z;

	if(c>dap)
		return;

	if(x>=n){
		dap=c;
		return;
	}

	if(clock()>=30*1000){
		if(dap<oo)
			dap1=dap;
		dap=-1;

		return;
	}
	
	for(i=0;i<n;i++){
		y=chk[i];
		if(y<2 && star[i][1]<=s){
			chk[i]=2;
			shin(s+2-y,x+1,c+1);
			chk[i]=y;
		}else if(y==0 && star[i][0]<=s){
			chk[i]=1;
			shin(s+1,x,c+1);
			chk[i]=y;
		}
	}
}

int main(void){

	int i,j;

	in=fopen("B-small-attempt4.in","r");
	out=fopen("output.txt","w");
	fscanf(in,"%d",&t);
	
	for(i=1;i<=t;i++){
		fscanf(in,"%d",&n);
		for(j=0;j<n;j++)
			fscanf(in,"%d %d",&star[j][0],&star[j][1]);
		dap=dap1=oo;

		shin(0,0,0);//number of star, clear num, play num
		if(dap==-1)
			dap=dap1;

		if(dap==oo){
			fprintf(out,"Case #%d: %s\n",i,"Too Bad");
		}else{
			fprintf(out,"Case #%d: %d\n",i,dap);
		}

		for(j=0;j<n;j++)
			chk[j]=0;
	}


	return 0;

}