#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <algorithm>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

#define MP make_pair
#define PB push_back

int f[110][110];
int a[110];
int p,n,m;

void relax(int i,int j,int k){
	f[i][j]=max(f[i][j],k);
}
bool checkless(int i,bool f){
	if (f&&i<2) return false;
	return i<=p*3-3;
}
bool checkok(int i,bool f){
	if (f){
		return i>=max(p,2)*3-4;
	}
	else {
		return i>=p*3-2;
	}
}
int main(){
	int t,ti=0;
	for (scanf("%d",&t);t--;){
		memset(f,0,sizeof(f));
		scanf("%d%d%d",&n,&m,&p);
		for (int i=0;i<n;i++) scanf("%d",&a[i]);
		f[0][0]=1;
		for (int i=0;i<n;i++)
		for (int j=0;j<=m;j++)
		if (f[i][j]){
			if (checkless(a[i],0)) relax(i+1,j,f[i][j]);
			if (checkless(a[i],1)) relax(i+1,j+1,f[i][j]);
			if (checkok(a[i],0)) relax(i+1,j,f[i][j]+1);
			if (checkok(a[i],1)) relax(i+1,j+1,f[i][j]+1);
		}
		printf("Case #%d: %d\n",++ti,f[n][m]-1);
	}
    return 0;
}
