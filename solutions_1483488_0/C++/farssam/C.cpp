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

int t,n,a,b;
int dap,cnt;
int data[20];

int jari(int x){
	int i,y=1;

	for(i=1;;i++){
		y*=10;
		if(x<y)
			return i;
	}
}

int is_new(int x){
	int i;
	for(i=0;i<cnt;i++){
		if(data[i]==x)
			return 0;
	}
	data[cnt++]=x;
	return 1;
}

int main(void){
	FILE *in,*out;
	int i,j,k,x,y,z,l,p;
	int su[11]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};

	in=fopen("C-small-attempt0.in","r");
	out=fopen("output.txt","w");


	fscanf(in,"%d",&t);

	for(i=1;i<=t;i++){
		fscanf(in,"%d %d",&a,&b);
		dap=0;

		for(j=a;j<=b;j++){
			if(j==123){
				j=j;
			}
			l=jari(j);

			x=1;
			p=0;

			cnt=0;
			while(1){
				x*=10;
				p++;
				if(x>b)
					break;
				y=j/x;
				z=j%x;
				if(z<(x/10))
					continue;
				y=z*su[l-p]+y;

				if(y>j && y<=b && is_new(y)==1){
					dap++;
				}
			}

		}

		fprintf(out,"Case #%d: %d\n",i,dap);		
	}


	return 0;

}