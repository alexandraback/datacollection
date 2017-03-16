#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

int ca,la;
int x,x1,ya,y,m;
int xy;
int po[1000005];
int xx[1000005];

void input(){
	scanf("%d %d",&x,&y);
	if(x>0)
		xy=x,x1=x;
	else
		xy=-x,x1=-x;
	if(y>0)
		xy+=y,ya=y;
	else
		xy-=y,ya=-y;
}

void process(){
	int i,m1,px=-1;
	m=1;
	while(!(m*(m+1)/2>=xy && (m*(m+1)/2)%2==xy%2))
		++m;
	m1=m*(m+1)/2-xy;
	for(i=m;i>=1;--i)
		po[i]=1,xx[i]=-1;
	for(i=m;i>=1;--i){
		if(m1/2<=i){
			po[m1/2]=-1;
			break;
		}
		m1-=2*i;
		po[i]=-1;
	}
	px=-1;
	if(x1!=0){
	for(i=m;i>=1;--i){
		if(po[i]==1){
			if(x1>i){
				x1-=i;
				xx[i]=1;
				px=i;
			}
			else if(x1==i){
				x1-=i;
				xx[i]=1;
				break;
			}
			else{
				if(po[x1]==1){
					xx[x1]=1;
				}
				else if(x1>=3){
					xx[1]=1;
					xx[x1-1]=1;
				}
				else if(x1==1){
					//if(px==-1)
						xx[1]=xx[2]=1;
					//else
					//	xx[2]=-1,xx[px-1]=1;
				}
				else if(x1==2){
					xx[1]=xx[2]=xx[3]=1;
				}
				break;
			}
		}
	}
	}
}

void output(){
	int i,chx=0,chy=0;
	printf("Case #%d: ",ca);
	for(i=1;i<=m;i++){
		if(xx[i]==1){
			if(x*po[i]>0 || (x==0 && po[i]>0)){
				chx+=i;
				printf("E");
			}
			else{
				chx-=i;
				printf("W");
			}
		}
		else{
			if(y*po[i]>0 || (y==0 && po[i]>0)){
				chy+=i;
				printf("N");
			}
			else{
				chy-=i;
				printf("S");
			}
		}
	}
//	if(chx!=x || chy!=y)
	//	printf(" check!!  %d %d :: %d %d",x,y,chx,chy);
	printf("\n");
}

int main(){
	int i,t;
	freopen("B-large.in","rt",stdin);
	freopen("B-large.out","wt", stdout);
	scanf("%d",&t);
	while(t--){
		la=0;
		ca++;
		input();
		process();
		output();
	}
	return 0;
}