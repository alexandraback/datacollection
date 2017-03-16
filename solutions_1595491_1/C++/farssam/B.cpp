#include<fstream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#define oo 0x7fffffff
#define N 101
#define MAX(x,y) ((x)>(y)?(x):(y))
#define MIN(x,y) ((x)<(y)?(x):(y))
#define SBS(x,y) ((x)<(y)?(y-x):(x-y))

using namespace std;

int t,n,p,s,su[N];
int dap;

int make_dap(void){
	int i,x=0,z;
	int y=0;

	sort(su,su+n);
	for(i=n-1;i>=0;i--){
		if(su[i]%3==0){
			x=su[i]/3;
			if(x>=p)
				y++;
			else if(s>0 && x+1>=p){
				y++;
				s--;
			}
		}else if(su[i]%3==1){
			x=su[i]/3+1;
			if(x>=p)
				y++;
		}else{
			x=su[i]/3+1;
			if(x>=p)
				y++;
			else if(s>0 && x+1>=p){
				y++;
				s--;
			}
		}
	}

	return y;
}

int main(void){
	FILE *in,*out;
	int i,j,x,y,z;

	in=fopen("B-large.in","r");
	out=fopen("output.txt","w");


	fscanf(in,"%d",&t);
	y=0;
	for(i=1;i<=t;i++){
		fscanf(in,"%d %d %d",&n,&s,&p);
		dap=0;
		y=0;
		for(j=0;j<n;j++){
			fscanf(in,"%d",&x);
			if(x<2){
				if(x>=p)
					dap++;
			}else
				su[y++]=x;
		}
		n=y;

		dap+=make_dap();

		fprintf(out,"Case #%d: %d\n",i,dap);		
	}


	return 0;

}