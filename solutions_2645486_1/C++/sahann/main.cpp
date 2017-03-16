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
ifstream cin("B-Large.in");
ofstream cout("B-Large.out");
//don't forget overflow and the bounds;

bool feasible(long long n, long long E, long long R){
	long long curE = E;
	bool ret = true;
	for(long long i=0;i<n;i++){
		curE -=ve[i];
		if(curE<0) {ret = false;break;}
		curE+=R;
		if(curE>E) curE = E;
	}
	return ret;
}/*
long long  feasible2(long long n, long long E, long long R,long long j){
	long long curE = E;
	long long ret = 0;
	long long mx1 = 0;
	long long mn = E;
	for(long long i=0;i<n;i++){
		if(i==j) {
			mx1 =curE;
			mn = 0;
			for(int k=i+1;k<n;k++){
				mn = max(ve[k]-(k-i)*R,mn); 
			}
			ret = mx1 - mn;
			break;
		}else{
			curE -=ve[i];
			if(curE<0) {ret = false;break;}
			curE+=R;
			if(curE>E) curE = E;
		}
	}
	return max(ret,0LL);
}*/


int main(){
	long long T;
	cin >> T;
	for(long long t=0;t<T;t++){
		long long E,R,N;
		cin >> E >> R >> N;
		vector <pair <long long,long long> > vpi;
		vector <long long> vi;
		for(long long i=0;i<N;i++){
			pair <long long,long long> pi;
			cin >> pi.first;
			pi.second = i;
			vpi.push_back(pi);
			vi.push_back(pi.first);
		}
		sort(vpi.begin(),vpi.end());
		reverse(vpi.begin(),vpi.end());
		for(long long i=0;i<N;i++){
			ve[i] = 0;
		}
		for(long long i=0;i<N;i++){
			long long lb = 0;
			long long ub = 12*1000*1000;
			ve[vpi[i].second] = ub;
			
			while(ub-lb>1){
				long long mid = (lb+ub)/2;
				ve[vpi[i].second] = mid;
				if(feasible(N,E,R)) lb = mid;
				else ub = mid;
			}
			//lb = feasible2(N,E,R,vpi[i].second);
			ve[vpi[i].second] = lb;			 
		}
		long long ret =0;
		for(long long i=0;i<N;i++){
			ret+=ve[i]*vi[i];
		}
		cout << "Case #" << t+1 << ": " << ret << endl;

		

	}
	
	return 0;
}