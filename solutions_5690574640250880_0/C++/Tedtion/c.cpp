#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
#include <cmath>
#include <cctype>
using namespace std;
#define NN 88

bool findres(int r, int c, int m, char res[][NN])
{
	int i,j;
	memset(res, '.', sizeof(char)*NN*NN);
	if (c==1) {
		for (i=0; i<m; i++) res[i][0]='*';
		res[r-1][0]='c';
		return true;
	}
	if (c==2) {
		if (r*c-m==2) return false;
		if (m%2 && r*c-m>1) return false;
		for (i=0; i<m/2; i++) res[i][0]=res[i][1]='*';
		res[r-1][1]='c';
		if (r*c-m==1) res[r-1][0]='*';
		return true;
	}
	int left = r*c-m;
	if (left==2 || left==3 || left==5 || left==7) return false;
	int n=0;
	for (j=0; j<c-3; j++) {
		for (i=0; i<r && n<m; i++) res[i][j]='*', n++;
		if (i==r-1) res[i-1][j]='.', res[0][j+1]='*';
		if (i<r) break;
	}
	if (n==m) {
		res[r-1][c-1]='c';
		return true;
	}
	m-=n;
	for (i=0; i<r; i++)
	{
		for (j=c-3; j<c && m; j++) res[i][j]='*', m--;
		if (i<r-1 && j==c-1) {
			res[i][j-1]='.';
			res[i+1][c-3]='*';
		}
		if (j<c) break;
	}
	res[r-1][c-1]='c';
	return true;
}

int main()
{
	int T;
	int r,c,m,i,j;
	char res[NN][NN];
	freopen("C-small-attempt2.in", "r", stdin);
	freopen("c.out", "w", stdout);
	scanf("%d",&T);
	for (int cas=1; cas<=T; cas++)
	{
		scanf("%d%d%d",&r,&c,&m);
		bool ok;
		if (r>c) ok=findres(r,c,m,res);
		else {
			char tmp[NN][NN];
			ok=findres(c,r,m,tmp);
			if (ok) for (i=0; i<c; i++) {
				for (j=0; j<r; j++) res[j][i]=tmp[i][j];
			}
		}
		printf("Case #%d:\n", cas);
		if (ok) {
			for (i=0; i<r; i++) {
				for (j=0; j<c; j++) printf("%c", res[i][j]);
				printf("\n");
			}
		} else printf("Impossible\n");
	}
	return 0;
}

