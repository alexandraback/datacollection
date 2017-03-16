#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <set>
#include <map>

using namespace std;

#define ll long long
#define pii pair<int,int>

int N,T;

ifstream fin("C.in");
ofstream fout("C.out");

int next[1005];
int loc[1005];
int maxval[1005];

int main() {
  fin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Working on Case #" << tt << "\n";
    fin >> N;
    for (int i = 0; i < N; i++) {
    	fin >> next[i];
    	next[i]--;
    }
    for (int i = 0; i < N; i++) {
    	maxval[i] = -1;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
    	for (int j = 0; j < N; j++) loc[j] = -1;
    	int ind = i;
    	loc[i] = 0;
    	while (loc[next[ind]] == -1) {
    		loc[next[ind]] = loc[ind]+1;
    		ind = next[ind];
    	}
    	ans = max(ans,loc[ind]-loc[next[ind]]+1);
    	if (loc[ind]-loc[next[ind]] == 1) {
    		//cout << "SPECIAL FOUND\n";
    		maxval[next[ind]] = max(maxval[next[ind]],loc[ind]);
    	}
    }
    int ans2 = 0;
    for (int i = 0; i < N; i++) {
    	if (next[next[i]] == i) ans2 += maxval[i]+maxval[next[i]];
    }
    ans2/=2;
    ans = max(ans,ans2);
    fout << "Case #" << tt << ": " << ans << "\n";
  }
  return 0;
}