#include <algorithm>
#include <numeric>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stack>
using namespace std;

pair<int, vector<int> > gr[20];
bool used[200];
int cur[200];
bool mask[1<<20];
stack<int> s;
vector<int> res;
int cnt=0;
int K,N;
bool fnd=false;

void dfs(int m) {
	if (mask[m])
		return;
	mask[m]=true;
	if (m==((1<<N)-1)) {
		fnd=true;
		while (!s.empty()) {
			res.push_back(s.top());
			s.pop();
		}
		reverse(res.begin(),res.end());
		return;
	}
	if (!fnd) {
		for (int i=0;i<N;i++) {
			if (used[i])
				continue;
			if (cur[gr[i].first]==0)
				continue;
			cur[gr[i].first]--;
			for (int j=0;j<gr[i].second.size();j++)
				cur[gr[i].second[j]]++;
			s.push(i);
			used[i]=true;
			dfs(m|(1<<i));
			if (fnd)
				continue;
			used[i]=false;
			s.pop();
			for (int j=0;j<gr[i].second.size();j++)
				cur[gr[i].second[j]]--;
			cur[gr[i].first]++;
		}
	}
}

void solveCase(int t) {
	for (int i=0;i<20;i++) {
		gr[i].first=-1;
		gr[i].second.clear();
	}
	for (int i=0;i<(1<<20);i++)
		mask[i]=false;
	for (int i=0;i<200;i++) {
		cur[i]=0;
		used[i]=false;
	}
	fnd=false;
	cnt=0;
	res.clear();
	cin>>K>>N;
	for (int i=0;i<K;i++) {
		int k;
		cin>>k;
		cur[k-1]++;
	}
	for (int i=0;i<N;i++) {
		int ti,ki;
		cin>>ti>>ki;
		gr[i].first=ti-1;
		for (int j=0;j<ki;j++) {
			int kk;
			cin>>kk;
			gr[i].second.push_back(kk-1);
		}
	}
	dfs(0);
	printf("Case #%d: ",t+1);
	if (res.empty()) {
		cout<<"IMPOSSIBLE"<<endl;
	}
	else {
		for (int i=0;i<N;i++)
			cout<<res[i]+1<<" ";
		cout<<endl;
	}
}

int main()
{
   freopen("in.in", "rt", stdin);
   freopen("out.out", "wt", stdout);
   int t;
   cin>>t;
   for (int i=0;i<t;i++)
	   solveCase(i);
   return 0;
}