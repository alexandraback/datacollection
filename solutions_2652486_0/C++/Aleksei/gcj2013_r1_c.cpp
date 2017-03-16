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
#include <cstdlib>
#include <numeric>
#include <sstream>
#include <fstream>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <cassert>
using namespace std;


int a[15];
int num[15];
int use[15];
int n, m, k;
bool found;

bool can(){
	int mask = 1<<n;
	memset(use,0,sizeof(use));
	for(int c=0; c<mask; c++){
		int prod = 1;
		for(int i=0; i<n; i++){
			if(c & (1<<i)){
				prod*=num[i];
			}
		}
		for(int i=0; i<k; i++){
			if(a[i]==prod) use[i]++;
		}
	}
	int nused = 0;
	for(int i=0; i<k; i++){
		if(use[i]>0) nused++;
	}
	return nused==k;
}

void go(int v){
	if(v>=n){
		if(can()){
			found = true;
		}
		return;
	}
	for(int i=2; i<=m; i++){
		num[v] = i;
		go(v+1);
		if(found) return;
	}
}

int main() {
	ifstream cin("input.txt");
	ofstream cout("output.txt");
	int ntests;
	cin >> ntests;
	for (int testnum = 0; testnum < ntests; testnum++) {
		cout << "Case #" << testnum + 1 << ":"<< endl;
		int r;
		cin>>r>>n>>m>>k;
		for(int rr=0; rr<r; rr++){
			for(int i=0; i<k; i++) cin>>a[i];
			found = false;
			go(0);
			assert(found);
			for(int i=0; i<n; i++) cout<<num[i];
			cout<<endl;
		}
	}
	return 0;
}
