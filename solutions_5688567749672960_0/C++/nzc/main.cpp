#include <algorithm>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <deque>
#include <fstream>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <iomanip>
#include <climits>
#include <bitset>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef long long ll;
typedef unsigned long long ull;

#define INF 1e9
#define EPS 1e-9
#define PI acos(-1.0)
#define MOD 1234567

int caseNo = 1, T, N;

int invert(int x) {
	int rev = 0;
	while(x) {
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return rev;
}

int main() {		
	// open files
	//freopen("homework.txt","r",stdin);
    //freopen("output.txt","w",stdout);	

	ofstream fout ("A_out.txt");
    ifstream fin ("A-small-attempt0 (2).in");
	fin >> T;
	while(T--) {
		fin >> N;
		vi d(N + 1, INF); d[1] = 1;
		queue<int> q; q.push(1);

		while(!q.empty()) {
			int u = q.front(); q.pop();
			int v = u + 1;			
			if(v <= N && d[v] == INF) {
				d[v] = d[u] + 1;
				q.push(v);
			}
			v = invert(u);			
			if(v <= N && d[v] == INF) {
				d[v] = d[u] + 1;
				q.push(v);
			}
		}
		fout << "Case #" << (caseNo++) << ": " << d[N] << endl;
	}
	
	system ("pause");
	return 0;	
}