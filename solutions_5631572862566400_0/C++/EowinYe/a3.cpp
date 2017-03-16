#include <iostream>
#include <string>
#include <math.h>
#include <fstream>

using namespace std;

int len[1010];
int num[1010];
int next[1010];
int visited[1010];
int flag[1010];
int is2[1010];
int root[1010];
int getans[1010];
int n;

int dfs1(int x,int dep){
	num[x]=dep;
	flag[x]=true;
	visited[x]=true;
	root[next[x]]=0;
	if (flag[next[x]]){
		flag[x]=false;
		return (num[x]-num[next[x]]+1);
	}
	if (visited[next[x]]){
		flag[x]=false;
		return 0;
	}
	int ret = dfs1(next[x],dep+1);
	flag[x]=false;
	return ret;
}

void dfs2(int x,int tot){
	flag[x]=true;
	if (is2[next[x]]){
		len[next[x]]=max(len[next[x]],tot);
		flag[x]=false;
		return;
	}
	if (flag[next[x]]){
		flag[x]=false;
		return;
	}
	dfs2(next[x],tot+1);
	flag[x]=false;
}

int main(){
	int Test,cnt;
	ifstream in("C-small-attempt0.in");
	ofstream out("C-small-attempt0.out");
	in>>Test;
	for (cnt=1;cnt<=Test;cnt++){
		in>>n;
		int ans1=0;
		for (int i=1;i<=n;i++){
			visited[i]=0;
			len[i]=0;
			root[i]=1;
			is2[i]=0;
			getans[i]=0;
			in>>next[i];
		}
		for (int i=1;i<=n;i++){
			ans1=max(ans1,dfs1(i,0));
			if (next[next[i]]==i){
				is2[i]=1;
			}
		}
		for (int i=1;i<=n;i++){
			if (root[i] && !is2[i]){
				dfs2(i,1);
			}
		}
		int ans2=0;
		int ans3=0;
		for (int i=1;i<=n;i++){
			if (is2[i] && !getans[i]){
				ans2=max(ans2,len[i]+len[next[i]]+2);
				ans3=ans3+max(len[i],len[next[i]])+2;
				getans[i]=1;
				getans[next[i]]=1;
			}
		}
		int ans=max(ans1,ans2);
		ans=max(ans,ans3);
		out<<"Case #"<<cnt<<": "<<ans<<endl;
	}
	in.close();
	out.close();
}
