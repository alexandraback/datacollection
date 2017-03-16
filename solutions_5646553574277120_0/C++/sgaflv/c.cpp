


#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <iostream>

#include <algorithm>
#include <map>
#include <vector>
#include <set>

using namespace std;

#define EPS 0.000000001
#define INF 1000000000

#define N 1000000
#define ll 100000000000001LL

bool used[31];
bool solved[70];

int c,d,v;
int extra=10;


void fill(int num) {
	for (int i=30;i>=num;i--) {
		if (solved[i-num]) {
			solved[i]=true;
		}
	}
	
}


int solve() {
	solved[0]=true;
	
	for (int i=1;i<=v;i++) {
		if (used[i]) fill(i);
	}
	
	for (int i=1;i<=v;i++) {
		if (!solved[i]) {
			extra++;
			used[i]=true;
			fill(i);
		}
	}
}

int main() {
	
	int T;
	cin>>T;
	int caseNum=0;
	
	while (T-->0)
	{
		cin>>c>>d>>v;
		
		memset(used, 0, sizeof(used));
		memset(solved, 0, sizeof(solved));
		extra=0;
	
		for (int i=0;i<d;i++) {
			int a;
			cin>>a;
			used[a]=true;
		}
		
		solve();
		
		cout<<"Case #"<<++caseNum<<": "<<extra<<endl;
	}
	
	return 0;
}

