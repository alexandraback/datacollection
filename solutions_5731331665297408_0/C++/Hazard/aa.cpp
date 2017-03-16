#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N,M;
pair<string,int> zip[10];
char temp[10];
int a,b;
int map[10][10];
string ans;
int order[10];
int ck[10];
bool EP;
void dfs(int x,int cnt){
	if(cnt==N){
		string temp="";
		for(int i=0;i<N;i++){
			temp += zip[order[i]].first;
		}
		ans = temp;
		EP = true;
		return;
	}
	for(int i=1;i<=N;i++){
		if(!ck[i] && map[x][i]){
			ck[i]=1;
			order[cnt] = i;
			dfs(i,cnt+1);
			order[cnt] = 0;
			if(EP) return;
			ck[i]=0;
		}
		
		if(ck[i]>0 && ck[i]<4 && map[x][i]){
			ck[i]++;
			dfs(i,cnt);
			if(EP) return;
			ck[i]--;
		}
	}
}
bool compare(pair<string,int> a,pair<string,int> b){
	if(strcmp(a.first.c_str(),b.first.c_str()) < 0) return true;
	return false;
}
int main()
{
	FILE *in =fopen ("input.txt","r");
	FILE *out =fopen ("output.txt","w");
	int T;
	fscanf(in,"%d",&T);
	for(int t=1;t<=T;t++){
		if(t==35)
			t=t;
		memset(map,0,sizeof(map));
		memset(ck,0,sizeof(ck));
		ans = "";
		fscanf(in,"%d%d",&N,&M);
		for(int i=1;i<=N;i++) {
			fscanf(in,"%s",temp);
			zip[i].first = temp;
			zip[i].second = i;
		}
		sort(zip+1,zip+N+1,compare);
		for(int i=0;i<M;i++){
			fscanf(in,"%d%d",&a,&b);
			int ra,rb;
			for(int i=1;i<=N;i++){
				if(zip[i].second == a) ra = i;
				if(zip[i].second == b) rb = i;
			}
			map[ra][rb]=1;
			map[rb][ra]=1;
		}
		EP = false;
		order[0] = 1;
		ck[1] = 1;
		dfs(1,1);
		fprintf(out,"Case #%d: %s\n",t,ans.c_str());
	}
	return 0;
}