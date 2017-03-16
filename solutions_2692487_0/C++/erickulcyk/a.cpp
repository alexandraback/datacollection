#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>
#include <utility>
#include <functional>
#include <iterator>
#include <complex>
#include <valarray>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>

using namespace std;

#define f(i,n) for(int i=0; i <n;i++)
#define fi(i,s,n) for(int i=s; i<n;i++)
typedef long long ll;

vector<int> vals;
map<int,int> sol[102];

int maxVal = 101;

int solve(int ind, int val){
	//printf("ind %d %d %d\n",ind,val, ind<vals.size()?vals[ind]:-1);
	if(ind>=vals.size() || val>=maxVal)
		return 0;
	else if (sol[ind].find(val) !=sol[ind].end()){
		//printf("found sol %d\n",sol[ind][val]);
		return sol[ind][val];
	}
	else if (vals[ind]<val){
		sol[ind][val]=solve(ind+1,val+vals[ind]);
		//printf("returning %d\n",sol[ind][val]);
		return sol[ind][val];
	}
	else{
		int add = -1;
		int numNeeded = -1;
		if((val-1)!=0){
			int numNeeded =0;
			int nVal = val;
			while(nVal<=vals[ind]){
				numNeeded++;
				nVal+=nVal-1;
			}
			int tot = nVal+vals[ind];

			add = numNeeded+solve(ind+1,tot);
		}
		int remove = solve(ind+1,val);
		if(add<0 || (remove+1<=add))
			sol[ind][val] = remove+1;
		else
			sol[ind][val] = add;
		//printf("here ind %d %d %d\n",ind,val, ind<vals.size()?vals[ind]:-1);
		//printf("add %d %d\n",add+numNeeded,remove+1);
		return sol[ind][val];
	}
}

int main(){
	int tc;
	scanf("%d",&tc);
	f(i,tc){
		printf("Case #%d: ",i+1);
		int n,a;
		scanf("%d %d",&n,&a);
		vals.clear();
		f(j,a){
			int t;
			scanf("%d",&t);
			vals.push_back(t);
		}

		sort(vals.begin(),vals.end());
		printf("%d\n",solve(0,n));
		f(j,a)
			sol[j].clear();
	}
	return 0;
}
