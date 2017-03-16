#include <cstdio>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <deque>
#include <set>
#include <map>
#include <climits>

using namespace std;

void print(bool yes) {
	if (yes)
		cout<<"Yes\n";
	else
		cout<<"No\n";
}

int n;
vector< vector<int> > inherits;
vector< set<int> > ans;
vector<char> found;


bool f(int x) {
	if (found[x])
		return false;
	for (int i = 0; i < inherits[x].size(); ++i) {
		int anc=inherits[x][i];
		if (f(anc))
			return true;
		int a=ans[x].size();
		ans[x].insert(anc);
		ans[x].insert(ans[anc].begin(), ans[anc].end());
		if (a+1+ans[anc].size() != ans[x].size())
			return true;
	}
	found[x]=true;
	return false;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("cin", "r", stdin);
	freopen("cout", "w", stdout);
#endif

   int cases;
   cin>>cases;
   for (int cas = 1; cas <= cases; ++cas) {
	   cout<<"Case #"<<cas<<": ";	   
	   cin>>n;
	   inherits.clear();
	   inherits.resize(n);
	   for (int i = 0; i < n; ++i) {
		   int m;
		   cin>>m;
		   inherits[i].resize(m);
		   for (int j = 0; j < m; ++j) {
			   cin>>inherits[i][j];
			   --inherits[i][j];
		   }
	   }
	   found.clear();
	   found.resize(n);
	   ans.clear();
	   ans.resize(n);
	   bool yes=false;
	   for (int i = 0; i < n; ++i) {
		   if (f(i)) {
			   yes=true;
			   break;
		   }			   
	   }
	   print(yes);	   
   }

#ifndef ONLINE_JUDGE
    fclose(stdin);
	fclose(stdout);
    putchar('\n');
#endif
}

