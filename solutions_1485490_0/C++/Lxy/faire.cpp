#include<iostream>
#include<fstream>
using namespace std;
FILE *fin = fopen("C-small-attempt3.in","r");
FILE *fout =fopen("out.txt","w");
int n, m;
_int64 toy[105][2];
_int64 box[105][2];
double ans;
void init()
{
	int i;
	fscanf(fin,"%d%d",&n,&m);
	for(i=0;i<n;++i)
		fscanf(fin,"%lld%lld",&toy[i][0],&toy[i][1]);
	for(i=0;i<m;++i)
		fscanf(fin,"%lld%lld",&box[i][0],&box[i][1]);
	ans =0.0;
}
double min(double a1, double b1)
{
	return a1<b1?a1:b1;
}
void dfs(int k1, int k2,double res)
{
	if(k1==n||k2==m){
		if(ans < res)
			ans = res;
		return;
	}
	int i;
	if(toy[k1][1]==box[k2][1]){
		double temp = min((double)toy[k1][0],(double)box[k2][0]);
		toy[k1][0] -= temp;
		box[k2][0] -= temp;
		dfs(k1+1,k2,res+temp);
		dfs(k1,k2+1,res+temp);
		toy[k1][0] += temp;
		box[k2][0] += temp;
	} else {
	dfs(k1+1,k2,res);
	dfs(k1,k2+1,res);
	}
}
void work()
{
	int i, j;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			dfs(i,j,0.0);
}
int main()
{
	int ca;
	fscanf(fin,"%d",&ca);
	int k =0;
	while(ca--){
		init();
		work();
		fprintf(fout,"Case #%d: %.lf\n",++k,ans);
	}
	return 0;
}