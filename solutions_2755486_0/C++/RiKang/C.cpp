#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<algorithm>
#include<vector>

using namespace::std;

__int64 ca,la;
__int64 n,n1,m;

__int64 at[105][5];
__int64 mo[2005];

void input(){
	__int64 i,d,w,e,s,d1,p1,s1,j,te;
	scanf("%I64d",&n);
	n1=0;
	m=0;
	for(i=1;i<=n;i++){
		scanf("%I64d %I64d %I64d %I64d %I64d %I64d %I64d %I64d",&d,&n1,&w,&e,&s,&d1,&p1,&s1);
		w+=1000;
		e+=1000;
		for(j=0;j<n1;++j){
			at[++m][0]=d;
			at[m][1]=w;
			at[m][2]=e;
			at[m][3]=s;
			d+=d1;
			w+=p1;
			e+=p1;
			s+=s1;
		}
	}
	for(i=1;i<=m;i++)
		for(j=i+1;j<=m;j++)
			if(at[i][0]>at[j][0]){
				te=at[i][0],at[i][0]=at[j][0],at[j][0]=te;
				te=at[i][1],at[i][1]=at[j][1],at[j][1]=te;
				te=at[i][2],at[i][2]=at[j][2],at[j][2]=te;
				te=at[i][3],at[i][3]=at[j][3],at[j][3]=te;
			}
}

void process(){
	__int64 i,j,p=at[1][0],j1=1,k;
	bool posi;
	at[m+1][0]=2140000000;
	for(i=0;i<2000;i++)
		mo[i]=0;
	for(i=2;i<=m+1;i++){
		if(at[i][0]!=p){
			for(j=j1;j<i;++j){
				posi=false;
				for(k=at[j][1];k<at[j][2];++k)
					if(mo[k]<at[j][3])
						posi=true;
				if(posi)
					++la;
			}
			for(j=j1;j<i;++j){
				for(k=at[j][1];k<at[j][2];++k)
					if(mo[k]<at[j][3])
						mo[k]=at[j][3];
			}

			p=at[i][0];
			j1=i;
		}
	}
}

void output(){
	printf("Case #%I64d: %I64d\n",ca,la);
}

int main(){
	int i,t;
	freopen("C-small-attempt1.in","rt",stdin);
	freopen("C-small-attempt1.out","wt", stdout);
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