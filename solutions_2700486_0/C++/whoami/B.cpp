#include <stdio.h>
#include <algorithm>
int n,x,y;
double print,combi[1501][1501];
double pro(){
	int m,nn,min,i,j;
	for(m=1;;m+=2){
		if(m*(m+1)>=n*2) break;
	}
	if(x+y<m-2)
		return 1.0;
	if(x+y>m)
		return 0.0;
	nn=(m*(m+1)-(m-1)*(m-2))>>1;
	min=n-(m-1)*(m-2)/2;
	if(nn==min)
		return 1.0;
	for(i=0;i<=min;i++){
		j=i;
		if(i>(nn>>1))
			j=nn>>1;
		if(min-i>=(nn>>1))
			j+=min-i-(nn>>1);
		if(j>=y+1)
			print+=combi[min][i];
	}
	return print;
}
int main(){
	int testt,test,i,j;
	combi[1][0]=0.5;
	combi[1][1]=0.5;
	for(i=2;i<=1500;i++){
		combi[i][0]=combi[i-1][0]/2;
		combi[i][i]=combi[i-1][i-1]/2;
		for(j=1;j<i;j++){
			combi[i][j]=(combi[i-1][j-1]+combi[i-1][j])/2;
		}
	}
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%d %d %d",&n,&x,&y);
		if(x<0)
			x*=-1;
		print=0;
		printf("Case #%d: %lf\n",test,pro());
	}
	return 0;
}
