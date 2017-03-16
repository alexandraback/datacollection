#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<iostream>
#include<queue>
#include<stack>

using namespace std;

FILE *fin;
FILE *fout;
int n,m;

set<int> edge[110];

int code[110];
bool visited[110];

char buff[110];
bool inQ[110];

string turn(int x){
	sprintf(buff,"%d",x);
	return string(buff);
}


int path[110];
string ans;



int perm[10];

bool check(){
	stack<int> st;
	st.push(perm[1]);
	for(int i = 2;i <= n;++i){
		int next = perm[i];
		bool ok = false;
		while(!st.empty()){
			int now = st.top();
			if(edge[now].find(next) == edge[now].end())
				st.pop();
			else{
				ok = true;
				break;
			}
		}
		if(!ok)
			return false;
		st.push(next);
	}
	return true;
}


string solve(){
	int minn = 0x3f3f3f3f;
	int idx = 0;
	for(int i = 1;i <= n;++i){
		if(minn > code[i]){
			minn = code[i];
			idx = i;
		}
	}
	for(int i = 1;i <= n;++i)
		perm[i] = i;
//	perm[idx] = 1;
//	perm[1] = idx;
	ans = "";
	do{
	//	for(int i = 1;i <= n;++i)
	//		printf("%d ",perm[i]);
//		printf("\n");
		bool ok = check();
	//	printf("     %d\n",ok);
		if(!ok)
			continue;
		string s = "";
		for(int i = 1;i <= n;++i)
			s += turn(code[perm[i]]);
		if(ans == "")
			ans = s;
		else
			ans = min(ans,s);
	}while(next_permutation(perm + 1,perm + 1 + n));
	return ans;
}

int main(){
	fin = fopen("C-small-attempt0.in","r");
	fout = fopen("out.txt","w");
	int T;
	fscanf(fin,"%d",&T);
	for(int cas = 1;cas <= T;++cas){//printf("case %d\n",cas);
		for(int i = 0;i < 110;++i)
			edge[i].clear();
		fscanf(fin,"%d%d",&n,&m);
		for(int i = 1;i <= n;++i)
			fscanf(fin,"%d",&code[i]);
		for(int i = 1;i <= m;++i){
			int a,b;
			fscanf(fin,"%d%d",&a,&b);
			edge[a].insert(b);
			edge[b].insert(a);
		}
		string s = solve();
		fprintf(fout,"Case #%d: %s\n",cas,s.c_str());
	}
	fclose(fin);
	fclose(fout);
	system("pause");
	return 0;
}

