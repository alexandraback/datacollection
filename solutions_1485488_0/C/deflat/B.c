/**************************
*   Google Code Jam 2012  *
*        Round 1B         *
*        Problem B        *
*                         *
 *************************/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define LP(i,a,b) for(i=a;i<b;i++)
#define RANGE(a,b,c) (a<=b&&b<=c)

int h,n,m,top[MAX][MAX],bottom[MAX][MAX];
int dir[2][2]={{1,0},{0,1}};

double tide(double time){
return (double)h-time*10.0;}

double travel(int x,int y,double time){
	int x2,y2;
	double ans=0.0,temp,wait;
	int i;
	if(x==n-1&&y==m-1) return 0.0;
	else{
		LP(i,0,2){
			temp=1.0;
			x2=x+dir[i][0],y2=y+dir[i][1];
			if(RANGE(0,x2,n-1)&&RANGE(0,y2,m-1)){
				wait=(tide(time)-((double)top[x2][y2]-50.0))/10.0;
				
				if(wait>0.0) temp+=wait;
				if(tide(time+temp-1.0)-(double)bottom[x][y]<20.0) temp+=9.0;
				temp+=travel(x2,y2,time+temp);
				if(temp>ans) ans=temp;
			}
		}
	}
	return ans;
}

int main(){
	FILE *fp1,*fp2;
	char filename[50];
	int i,j,k,T,ans;
	
	scanf("%s",filename);
	fp1=fopen(filename,"r");
	fp2=fopen("output.txt","w");
	
	fscanf(fp1,"%d",&T);
	LP(i,0,T){
		fscanf(fp1,"%d %d %d",&h,&n,&m);
		LP(j,0,n){
			LP(k,0,m){
			fscanf(fp1,"%d",&top[j][k]);
		}}
		LP(j,0,n){
			LP(k,0,m){
			fscanf(fp1,"%d",&bottom[j][k]);
		}}
		fprintf(fp2,"Case #%d: %lf\n",i+1,travel(0,0,0.0));
	}
	return 0;
}