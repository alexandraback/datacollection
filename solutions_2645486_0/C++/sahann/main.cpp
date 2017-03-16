#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;
int ve[20000];
ifstream cin("B-small-attempt0.in");
ofstream cout("B-small.out");
//don't forget overflow and the bounds;

bool feasible(int n, int E, int R){
	int curE = E;
	bool ret = true;
	for(int i=0;i<n;i++){
		curE -=ve[i];
		if(curE<0) {ret = false;break;}
		curE+=R;
		if(curE>E) curE = E;
	}
	return ret;
}


int main(){
	long long T;
	cin >> T;
	for(int t=0;t<T;t++){
		int E,R,N;
		cin >> E >> R >> N;
		vector <pair <int,int> > vpi;
		vector <int> vi;
		for(int i=0;i<N;i++){
			pair <int,int> pi;
			cin >> pi.first;
			pi.second = i;
			vpi.push_back(pi);
			vi.push_back(pi.first);
		}
		sort(vpi.begin(),vpi.end());
		reverse(vpi.begin(),vpi.end());
		for(int i=0;i<N;i++){
			ve[i] = 0;
		}
		for(int i=0;i<N;i++){
			int lb = 0;
			int ub = 100*1000*1000;
			ve[vpi[i].second] = ub;
			while(ub-lb>1){
				int mid = (lb+ub)/2;
				ve[vpi[i].second] = mid;
				if(feasible(N,E,R)) lb = mid;
				else ub = mid;
			}
			ve[vpi[i].second] = lb;			 
		}
		int ret =0;
		for(int i=0;i<N;i++){
			ret+=ve[i]*vi[i];
		}
		cout << "Case #" << t+1 << ": " << ret << endl;

		

	}
	
	return 0;
}