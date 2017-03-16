#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <list>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <set>
#include <utility>
#include <stack>

#define rep(i,n) for(int i = 0; i < (n); i++)

using namespace std;

void solve();
void runCase();

int go(vector<int> ds, int v) {
	vector<int> vs(v+1),y;
	vs[0] = 1; y = vs;
	rep(i,ds.size()) {
		y = vs;
		rep(j,v) if(vs[j] && j+ds[i]<=v) {
			y[j+ds[i]] = 1;
		}
		vs = y;
	}
	int r = 0;
	rep(i,v+1) if(vs[i]) r++;
	return r-1;
}

void runCase()
{
	int c,d,v;
	scanf("%d%d%d",&c,&d,&v);
	vector<int> ds(d);
	rep(i,d) scanf("%d",&ds[i]);
	sort(ds.begin(),ds.end());
	
	int best_num = go(ds,v);
	// printf("%d\n",best_num);
	
	if(best_num==v) {
		printf("0\n");
		return;
	}
	
	
	set<int> s;
	rep(i,d) s.insert(ds[i]);
	
	int r = 0;
	for(;;) {
		int best_x = -1,best_num=0;
		for(int i = 1; i <= v; i++) if(s.count(i)==0) {
			vector<int> vvs = ds;
			vvs.push_back(i);
			int num = go(vvs,v);
			if(best_num < num) {
				best_num = num;
				best_x = i;
			}
		}
		
		ds.push_back(best_x);
		s.insert(best_x);
		r++;
		// printf("%d\n",best_num);
		if(best_num==v) break;
	}
	
	printf("%d\n",r);
}

void runSample() {
	string input;

	char buf[501] = {0};
	cin.getline(buf,501);

	input = buf;


	printf("%s\n",input.c_str());
}

void solve()
{
	int n;
	scanf("%d",&n);
	getchar();

	for(int i = 0; i < n; i++) {
		printf("Case #%d: ",i+1);
		runCase();
		//runSample();
	}
}

int main()
{
	solve();
	return 0;
}
