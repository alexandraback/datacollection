#include <iostream>
#include <vector>
#include<algorithm>
#define pb push_back
using namespace std;
int a[10000];
int visit[10000];
int cyc;
vector <int> p1, p2, pa[1019];

vector <int> chains;
int level[10000];
void dfs(int ind) {
	int cur = ind;
	while(visit[a[cur]] == 0) {
		visit[a[cur]] = visit[cur] + 1;
		cur = a[cur];
	}
	cyc = max(visit[cur] + 1 - visit[a[cur]], cyc);
	return;
}

int dir_cyc(int n) {
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=n;j++) visit[j] = 0;
		visit[i] = 1;
		dfs(i);
	}
	return cyc;
}

void find_pairs(int n) {
	p1.clear();
	p2.clear();
	for(int i=1;i<=n;i++) 
		for(int j=i+1;j<=n;j++) {
			if(a[i] == j && a[j] == i) {
				p1.pb(i);
				p2.pb(j);
			}
		}
	return;
}

int longest_chain(int n, int ind, int no) {
	int k = pa[ind].size();
	int x = 0;
	for(int i=0;i<k;i++) {
		if(pa[ind][i] == no) continue;
		level[pa[ind][i]] = level[ind] + 1;
		x = max(x, longest_chain(n, pa[ind][i], no));
	}
	return x + 1;
}

int main() {
	freopen("A.in","r",stdin);
	freopen("B.txt","w",stdout);
	int t,n,ans;
	cin >> t;
	for(int ii=0;ii<t;ii++) {
		cin >> n;
		for(int i=1;i<=n;i++) pa[i].clear();
		for(int i=1;i<=n;i++) visit[i] = 0;
		cyc = 0;
		for(int i=1;i<=n;i++) {
			scanf("%d",&a[i]); 
			pa[a[i]].pb(i);
		}
		ans = dir_cyc(n);
		
//		cout << "Directed cycle : " << ans << endl;
//		for(int i=1;i<=n;i++) cout << visit[i] << " " ; cout << endl;
		
		find_pairs(n);
//		
//		cout << "Pairs : " ;
//		for(int i=0;i<p1.size() ;i++) cout << p1[i] << " " << p2[i] << endl;
//		cout << endl;
		
		int k = p1.size();
		
		chains.clear();
		
		int tmp;
		
		for(int i=0;i<k;i++) {
			for(int j=1;j<=n;j++) level[j] = 0;
			level[p1[i]] =1;
			tmp = longest_chain(n, p1[i], p2[i]);
			
			for(int j=1;j<=n;j++) level[j] = 0;
			level[p2[i]] =1;
			tmp += longest_chain(n, p2[i], p1[i]);
			
			chains.pb(tmp);
		}
		
		sort(chains.begin(), chains.end());
		
//		cout << "Chains : " ;
//		for(int i=0;i<chains.size() ;i++) cout << chains[i] << " " ;
//		cout << endl;
		
		int temp, l = chains.size();
		
		if(l >= 2) {
			temp = chains[l-1] + chains[l-2];
			for(int i=0;i<l-2;i++) if(chains[i] == 2) temp += 2;
		} else if(l == 1) {
			temp = chains[0];
		} else temp = 0;
		
		ans = max (ans, temp);
		
		cout << "Case #" << ii+1 << ": " << ans << endl;
		
		
	}
	
}



/*
10

6
2 1 4 3 6 5

8
2 1 4 3 6 5 8 7

9
2 1 1 3 2 5 8 7 8

7
2 1 1 3 2 5 1

9
2 1 1 3 2 5 1 7 8

10
2 3 1 10 3 5 6 7 8 9

*/