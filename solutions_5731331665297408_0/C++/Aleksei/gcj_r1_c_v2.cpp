#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <vector>
#include <string>
#include <cassert>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;

const int SZ = 10;

int n;
bool possible;
string zip[SZ];
int g[SZ][SZ];
vector<int> p;
string min_rez;

void dfs(int poz, vector<int> stack){
	if(poz==n-1){
		possible = true;
		return;
	}else{
		stack.push_back(p[poz]);
		int next = p[poz+1];
		while(true){
			int v = stack.back();
			if(g[v][next]){
				dfs(poz+1, stack);
				if(possible) return;
			}
			if(stack.size()>1){
				stack.pop_back();
			}else{
				break;
			}
		}
	}
}

string conc(const vector<int>& p){
	string rez="";
	for(int i=0; i<p.size(); i++) rez+=zip[p[i]];
	return rez;
}

int main(){
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin>>ntests;
	for(int testnum=0; testnum<ntests; testnum++){
		int m;
		cin>>n>>m;
		for(int i=0; i<n; i++) cin>>zip[i];
		memset(g,false,sizeof(g));
		for(int i=0; i<m; i++){
			int x, y;
			cin>>x>>y;
			x--; y--;
			g[x][y] = g[y][x] = true;
		}
		min_rez = "99999999999999999999999999999999999999999999999999999999999999999999999999999";
		p.resize(n);
		for(int i=0; i<n; i++) p[i] = i;
		do{
//			for(int i=0; i<n; i++) cout<<p[i]<<' ';
//			cout<<endl;
			possible = false;
			string sss = conc(p);
			if(sss<min_rez){
				vector<int> stack(0);
				dfs(0,stack);
				if(possible) min_rez=sss;
			}

		}while(next_permutation(p.begin(),p.end()));
		cout<<"Case #"<<testnum+1<<": "<<min_rez<<endl;
	}
	return 0;
}
