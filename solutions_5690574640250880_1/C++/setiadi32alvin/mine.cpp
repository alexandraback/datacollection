#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<utility>
#include<vector>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<stack>
#include<queue>

#define inf 2123123123
#define LL long long
#define MP make_pair
#define ii pair<int,int>
using namespace std;
void OPEN(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
}
int i,j,t,r,c,x,m;
char S[55][55];
void print(){
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)
			printf("%c",S[i][j]);
		printf("\n");
	}
}
int main(){
	OPEN();
	scanf("%d",&t);
	for(int z=1;z<=t;z++){
		scanf("%d%d%d",&r,&c,&x);
		printf("Case #%d:\n",z);
		m=r*c-x;
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				S[i][j]='*';
		if(m==1){
			S[0][0]='c';
			print();
			continue;
		}
		if(c==1 || r==1){
			for(i=0;i<r;i++)
				for(j=0;j<c;j++)
					if(m>0){
						S[i][j]='.';
						m--;
					}
			S[0][0]='c';
			print();
			continue;
		}
		if(c==2 || r==2){
			if(m==2 || m%2==1){
				printf("Impossible\n");
				continue;
			}
			if(c==2){
				for(i=0;i<r;i++)
					for(j=0;j<c;j++)
						if(m>0){
							S[i][j]='.';
							m--;
						}
			}			
			else if(r==2){
				for(i=0;i<c;i++)
					for(j=0;j<r;j++)
						if(m>0){
							S[j][i]='.';
							m--;
						}
			}
			S[0][0]='c';
			print();
			continue;
		}
		if(m==2 || m==3 || m==5 || m==7){
			printf("Impossible\n");
			continue;
		}
		S[0][0]=S[0][1]=S[1][0]=S[1][1]='.';
		m-=4;
		for(i=2;i<max(r,c);i++){
			if(m>=2 && i<r){
				S[i][0]=S[i][1]='.';
				m-=2;
			}
			if(m>=2 && i<c){
				S[0][i]=S[1][i]='.';
				m-=2;
			}
		}
		if(m%2==1){
			S[2][2]='.';
			m--;
		}
		for(i=0;i<r;i++)
			for(j=0;j<c;j++)
				if(m>0 && S[i][j]=='*'){
					S[i][j]='.';
					m--;
				}
		S[0][0]='c';
		print();
	}
	return 0;
}