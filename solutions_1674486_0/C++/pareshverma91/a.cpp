
/*Paresh Verma*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>		//max heap implementation
#include <limits.h>

#define pub push_back
#define pob pop_back
#define fi first
#define se second
#define debug(a) { for( typeof(a.begin()) it = a.begin() ; it != a.end() ; it++ ) cout << *it << " "; cout << endl; }

using namespace std;

//class comparators for queue and others
class classcomp{
	public:
		bool operator() (const int& l, const int& r)const{
			return l<r;
		}
};

vector< vector<int> > ed;
vector<int> emp;
int vis[1200];

bool dfs(int in){
	if(vis[in]==1)
		return true;
	vis[in]=1;
	int i,j;
	for(i=0;i<ed[in].size();i++){
		if(dfs(ed[in][i]))
			return true;
	}
	return false;
}


int main(){
	int T,i,j,k,l,m,n;
	scanf("%d",&T);
	for(int p=1;p<=T;p++){
		printf("Case #%d: ",p);
		bool ff=false;
		ed.clear();

		scanf("%d",&n);
		ed.pub(emp);
		for(i=1;i<=n;i++){
			ed.pub(emp);
			scanf("%d",&m);
			for(j=0;j<m;j++){
				scanf("%d",&l);
				ed[i].pub(l);
			}
		}
		for(i=1;i<=n;i++){
			memset(vis,0,sizeof(vis));
			ff=dfs(i);
			if(ff)
				break;
		}
		if(ff){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
