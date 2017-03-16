#include<fstream>
#include<cstdlib>
#include<cstring>
#define N 1002
using namespace std;
FILE *in,*out;
int n,tt,dg[N],grp[N][N],q,st,chk[N];
int solve();
void dfs(int x);
int main()
{
	in=fopen("input.txt","r");
	out=fopen("output.txt","w");
	int zz;
	fscanf(in,"%d",&tt);
	for(zz=1;zz<=tt;zz++){
		fprintf(out,"Case #%d: ",zz);
		if(solve()) fprintf(out,"Yes\n");
		else fprintf(out,"No\n");
	}
	return 0;
}

int solve()
{
	int i,a,j,b;

	fscanf(in,"%d",&n);
	memset(dg,0,sizeof(dg));
	for(i=0;i<n;i++){
		fscanf(in,"%d",&a);
		for(j=0;j<a;j++){
			fscanf(in,"%d",&b);
			b--;
			grp[i][dg[i]++]=b;
		}
	}

	for(i=0;i<n;i++){
		q=0; st=i;
		memset(chk,0,sizeof(chk));
		dfs(i);
		if(q>1) return 1;
	}
	return 0;
}

void dfs(int x)
{
	int i,j;

	if(q==2) return ;
	chk[x]++;
	if(chk[x]>=2){
		q=2;
		return ;
	}
	for(i=0;i<dg[x];i++){
		j=grp[x][i];
		dfs(j);
	}
}