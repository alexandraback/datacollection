#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<memory.h>
#include<assert.h>
using namespace std;
typedef long long ll;
typedef long double ld;

#include <unistd.h>
#include <wait.h>
bool __multithreading = true;
const int __limitofthreads = 8;
vector<pid_t> __ids;
char __str[128];
int __tests, __testsdone, __id;
void __inctests(){
	++__testsdone;
	sprintf(__str, "\033[1;1Htests %d/%d done.%c",__testsdone,__tests,10);
	cerr<<__str;
}

set<int> g[1111];
int p[1111];

int dfs(int v){
	int ans = 0;
	for(int i : g[v]){
		ans = max(ans, 1+dfs(i));
	}
	return ans;
}

void solve(int test){
	///+++start read ALL data+++
	
	int n;
	cin>>n;
	for(int i=0;i<n;++i) g[i].clear();
	for(int i=0;i<n;++i){
		int j;
		cin>>j;
		--j;
		g[j].insert(i);
		p[i] = j;
	}
	
	///---end read data---
	if(__multithreading){
		if(__ids.size()>=__limitofthreads && wait(0)!=-1) __inctests();
		__id = fork();
		if(__id>0){
			__ids.push_back(__id);
			return ;
		}
		sprintf(__str, "thread%d.out", test);
		freopen(__str, "w", stdout);
	}
	///start solution and write output
	cout<<"Case #"<<test<<": ";
	
	int ans = 0;
	for(int i=0;i<n;++i){
		for(int k=0,j=i;k<=n;++k,j=p[j]){
			if(k && j==i){
				ans = max(ans, k);
				break;
			}
		}
	}
	
	int sum = 0;
	for(int i=0;i<n;++i) if(i==p[p[i]]){
		int j = p[i];
		if(i>j) continue;
		g[i].erase(j);
		g[j].erase(i);
		sum+=2 + dfs(i) + dfs(j);
		g[i].insert(j);
		g[j].insert(i);
	}
	ans = max(ans, sum);
	cout<<ans<<endl;
	
}

int main(){
	freopen("input.txt","r",stdin); freopen("output.txt","w",stdout);
	
	cin>>__tests;
	for(int i=1;i<=__tests;++i){
		solve(i);
		if(__multithreading&&__id==0) return 0;
	}
	
	///combining outputs
	if(__multithreading){
		for(pid_t __id : __ids) if(waitpid(__id,0,0)!=-1) __inctests();
		int __bufsize = 1<<16;
		char *__buf = new char[__bufsize];
		for(int i=1;i<=__tests;++i){
			sprintf(__str, "thread%d.out", i);
			FILE *f = fopen(__str, "r");
			while(fgets(__buf, __bufsize, f)) printf("%s",__buf);
			fclose(f);
			remove(__str);
		}
		delete [] __buf;
	}
	
	return 0;
}
