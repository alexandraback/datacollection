#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<vector>
#include<cmath>
#include<string>
#define ll long long
#define ld long double
using namespace std;
const int maxn= 2e5;
char s[maxn];
string d[100];
int b[100],vis[100],c[100],a[100][100],e[100][100];
int i,j,k,x,bl,len;
int idx(char c){
	return c-'A';
}
int main()
{
	//freopen("1.in","r",stdin);
	//freopen("1.out","w",stdout);
	d[0]= "ZERO";
	d[1]= "ONE";
	d[2]= "TWO";
	d[3]= "THREE";
	d[4]= "FOUR";
	d[5]= "FIVE";
	d[6]= "SIX";
	d[7]= "SEVEN";
	d[8]= "EIGHT";
	d[9]= "NINE";
	for (i= 0;i<10;i++){
		int len= d[i].size();
		for (j= 0;j<len;j++){
			x= idx(d[i][j]);
			e[i][x]++;
			a[x][i]= 1;
		}
	}
	int ooo;
	scanf("%d",&ooo);
	int T= 0;
	while (scanf("%s",s+1)>0){
		T++;
		printf("Case #%d: ",T);
		memset(c,0,sizeof(c));
		memset(vis,0,sizeof(vis));
		len= strlen(s+1);
		for (i= 1;i<=len;i++)
			b[idx(s[i])]++;
		for (;;){
			bl= 1;
			for (i= idx('A');i<=idx('Z');i++){
				int j,cnt= 0;
				for (j= 0;j<10;j++){
					if (!a[i][j]) continue;
					if (vis[j]) continue;
					cnt++;
					x= j;
				}
				if (cnt==1){
					c[x]+= b[i]/e[x][i];
					vis[x]= 1;
					int L= d[x].size();
					for (j= 0;j<L;j++){
						int id= idx(d[x][j]);
						b[id]-= c[x];
					}
					bl= 0;
					break;
				}
			}
			if (bl) break;
		}
		for (i= 0;i<10;i++)
			for (j= 1;j<=c[i];j++)
				printf("%d",i);
		printf("\n");
	}return 0;
}
