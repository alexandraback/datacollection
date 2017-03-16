
//Problem B. 

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <memory.h>
#include <cmath>

using namespace std;

#define MAXINT 1000000

int h,n,m;
int c[100][100];
int f[100][100];
double t[100][100];

int x,y;
double v1,v2;

double caltime(int x1, int y1, int x2, int y2, double starttime){
	if (x1<0 || x1>=n || x1<0 || x2>=n || y1<0 || y1>=m || y2<0 || y2>=m) return MAXINT;
	if (c[x1][y1]-f[x2][y2]<50) return MAXINT;
	if (c[x2][y2]-f[x1][y1]<50) return MAXINT;
	if (c[x2][y2]-f[x2][y2]<50) return MAXINT;
	//if (c[x1][y1]-f[x1][y1]<50) return MAXINT; //redundant

	double movetime=starttime;
	double waterlevel=h-starttime*10;
	//if (f[x1][y1]<waterlevel && c[x2][y2]-waterlevel<50) movetime+=(50-(c[x2][y2]-waterlevel))/10.0;
	if (c[x2][y2]-waterlevel<50) movetime+=(50-(c[x2][y2]-waterlevel))/10.0;
	
	waterlevel=h-movetime*10;
	if (movetime==0) return 0;
	if (waterlevel-f[x1][y1]>=20) movetime+=1;
	else movetime+=10;
	return movetime;	
}

void compute(){
	v1=caltime(x,y,x+1,y,t[x][y]);
	if (t[x+1][y]>v1) {
		t[x+1][y]=v1;
		x=x+1;
		compute();
		x=x-1;
	}
	v1=caltime(x,y,x-1,y,t[x][y]);
	if (t[x-1][y]>v1) {
		t[x-1][y]=v1;
		x=x-1;
		compute();
		x=x+1;
	}
	v1=caltime(x,y,x,y+1,t[x][y]);
	if (t[x][y+1]>v1) {
		t[x][y+1]=v1;
		y=y+1;
		compute();
		y=y-1;
	}
	v1=caltime(x,y,x,y-1,t[x][y]);
	if (t[x][y-1]>v1) {
		t[x][y-1]=v1;
		y=y-1;
		compute();
		y=y+1;
	}
}

int main(){
	int te;
	int i,j,k;

	cin>>te;
	for (i=0;i<te;i++){
		cin>>h>>n>>m;
		for (j=0;j<n;j++) {
			for (k=0;k<m;k++) cin>>c[j][k];
		}
		for (j=0;j<n;j++) {
			for (k=0;k<m;k++) cin>>f[j][k];
		}
		//memset(t,0,100*100*sizeof(int));
		for (j=0;j<n;j++) {
			for (k=0;k<m;k++) t[j][k]=MAXINT;
		}
		t[0][0]=0;
		x=0; y=0;

		compute();
		cout<<"Case #"<<(i+1)<<": ";
		printf("%.8f",t[n-1][m-1]);
		cout<<endl;
		//for (j=0;j<n;j++) cout<<rpi[j]<<endl;
		//for (j=0;j<n;j++) printf("%f %f %f %.10f\n",wp[j],owp[j],oowp[j],rpi[j]);
	}
}
