//by jackyliuxx
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;
map<int,string> mp;
vector<int> e[100];

bool hs[100];

bool es(int x,int y){
	return mp[x]<mp[y];
}
/*
string dfs(int x){
	hs[x]=1;
	int i;
	for(i=0;i<n;i++
*/
string ep(int *x,int *y){
	if(x==y)
		return string("");
	else
		return mp[*x]+ep(x+1,y);
}

bool ac(int *x,int *y){
	vector<int> st;
	memset(hs,0,sizeof(hs));
	st.clear();
	st.push_back(*x);
	hs[*x]=1;
	int i;
	x++;
	while(st.size() && x!=y){
		int p=st.back();
		for(i=0;i<e[p].size();i++){
			if(e[p][i]==*x){
				st.push_back(*x);
				x++;
				break;
			}
		}
		if(i==e[p].size())
			st.pop_back();
	}
	if(x==y)
		return true;
	else
		return false;
}


int main () {
	int t,ct=1;
	cin>>t;
	while(t--){
		int n,m;
		mp.clear();
		scanf("%d%d",&n,&m);
		int i;
		string s;
		for(i=1;i<=n;i++){
			cin>>s;
			mp[i]=s;
			e[i].clear();
		}
		int x,y;
		for(i=0;i<m;i++){
			cin>>x>>y;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for(i=1;i<=n;i++)
			sort( e[i].begin(),e[i].end(),es);
		s="-1";
		int ans[50];
		for(i=1;i<=n;i++)
			ans[i-1]=i;
		do{
			if(ac(ans,ans+n)){
				if(s=="-1")
					s=ep(ans,ans+n);
				else if(ep(ans,ans+n)<s)
					s=ep(ans,ans+n);
			}
		}while(next_permutation(ans,ans+n));
		/*
		string s2;
		for(i=1;i<=n;i++){
			memset(hs,0,sizeof(hs));
			s2=dfs(i);
			if(s=="-1" || s2<s)
				s=s2;
		}
		*/
		cout<<"Case #"<<ct++<<": "<<s<<endl;
	}
}
