#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

bool buff[35][15][2],cuff[35][15][2];
bool v[105][105];
int f[105][105];
int Test,S,P,N;
int a[105];

int main()
{
	freopen("input.txt","r",stdin);
	
	for (int i=0;i<11;++i)
	for (int j=i;j<11 && j<=i+2;++j)
	for (int k=j;k<11 && k<=i+2;++k)
		buff[i+j+k][k][k==i+2]=1;
		
	memcpy(cuff,buff,sizeof(buff));
		
	for (int i=0;i<=30;++i) {
		for (int j=9;j>=0;--j) {
			buff[i][j][0]|=buff[i][j+1][0];
			buff[i][j][1]|=buff[i][j+1][1];
		}
		for (int j=1;j<=10;++j) {
			cuff[i][j][0]|=cuff[i][j-1][0];
			cuff[i][j][1]|=cuff[i][j-1][1];
		}
	}
	
	scanf("%d",&Test);
	
	for (int t=1;t<=Test;++t){
		scanf("%d%d%d",&N,&S,&P);
		for (int i=1;i<=N;++i) scanf("%d",&a[i]);
		memset(f,0,sizeof(f));
		memset(v,0,sizeof(v));
		
		v[0][0]=1;
		for (int i=0;i<N;++i)
		for (int j=0;j<=i && j<=S;++j)
		if (v[i][j]) {
			if (buff[a[i+1]][P][0]) f[i+1][j]=max(f[i+1][j],f[i][j]+1),v[i+1][j]=1;			
			if (buff[a[i+1]][P][1]) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]+1),v[i+1][j+1]=1;
			
			if (P>0) {
				if (cuff[a[i+1]][P-1][0]) f[i+1][j]=max(f[i+1][j],f[i][j]),v[i+1][j]=1;
				if (cuff[a[i+1]][P-1][1]) f[i+1][j+1]=max(f[i+1][j+1],f[i][j]),v[i+1][j+1]=1;
			}
		}
		printf("Case #%d: %d\n",t,f[N][S]);
	}
	
	
	return 0;
}
