#include<stdio.h>
#include<stdlib.h>
#define OFFSET 15000
int A,N,T,t,X,Y;
int count;
long double ans;
long double p2[128]; /*p2[c]=0.5^c*/
long double foo[4096][4096];
int c;
int height;
int layer;
int tmp;
int x,y,sum;
int main(){
scanf("%d",&T);

p2[0]=1;
for(t=1;t<100;t++) p2[t]=p2[t-1]/(long double)2.0;

for(t=1;t<=T;t++){
scanf("%d",&N);
scanf("%d",&X);
scanf("%d",&Y);
if (X<0) X=-X;
layer=Y+X;
layer/=2;

tmp=0;
for(c=0;c<layer;c++) {
tmp+=c*4+1;
}

if (tmp>=N) {printf("Case #%d: 0.0\n",t);continue;}
tmp+=c*4+1;

if (tmp<=N) {printf("Case #%d: 1.0\n",t); continue;}
tmp-=c*4+1;
tmp=N-tmp;

/*printf("Want %d out of %d, max=%d\n",Y+1,tmp,layer*2);*/
for(x=0;x<=layer*2&&x<=tmp;x++)
for(y=0;y<=layer*2;y++)
foo[x][y]=0;


foo[0][0]=1;
for(sum=0;sum<=tmp;sum++)
for(x=0;x<=sum;x++){
if (x>tmp) break;
if (x>2*layer) break;
y=sum-x;
if (y>layer*2) continue;

if (x<layer*2&&y<layer*2) {foo[x+1][y]+=foo[x][y]*0.5;foo[x][y+1]+=foo[x][y]*0.5;}
if (x<layer*2&&!(y<layer*2)) {foo[x+1][y]+=foo[x][y];}
if (!(x<layer*2)&&(y<layer*2)) {foo[x][y+1]+=foo[x][y];}
}

ans=0;
for(c=Y+1;tmp-c>=0&&c<=layer*2;c++) ans+=foo[tmp-c][c];



printf("Case #%d: %.7llf\n",t, ans);

}

return 0;
}

