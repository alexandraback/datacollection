#include<iostream>
#include<fstream>
#include<cstring>
#include<vector>
using namespace std;
FILE *fin = fopen("A-small-attempt1(1).in","r");
FILE *fout = fopen("out.txt","w");
int n;
int vis[1005];
vector<int> map[1005];
void init()
{
	fscanf(fin,"%d",&n);
	int i;
	for(i =0;i<=n;++i)
		map[i].clear ();
	int m;
	int j;
	int v;
	for(i=0;i<n;++i){
		fscanf(fin,"%d",&m);
		for(j=0;j<m;++j){
			fscanf(fin,"%d",&v);
			map[i+1].push_back (v);
		}
	}
}
bool dfs(int v)
{
	int i;
	int len = map[v].size ();
	for(i=0;i<len;++i){
		if(vis[map[v][i]]==0){
			bool temp = dfs(map[v][i]);
			if(temp) return temp;
			vis[map[v][i]] ++;
		}else if(vis[map[v][i]]==1)
			return true;
	}
	return false;
}
void work()
{
	int i;
	int flag =0;
	for(i=0;i<n;++i){
		memset(vis,0,sizeof(vis));
		vis[i+1]= 1;
		if(dfs(i+1)){
			fprintf(fout,"Yes\n");
			flag =1;
			break;
		}
	}
	if(flag==0) fprintf(fout,"No\n");
}
int main()
{
	int ca;
	fscanf(fin,"%d",&ca);
	int k =0;
	while(ca--){
	fprintf(fout,"Case #%d: ",++k);
	init();
	work();
	}
	return 0;
}