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

ifstream fin("B.in");
ofstream fout("B.out");

int cnt[2505];

int main() {
  fin >> T;
  for (int tt = 1; tt <= T; tt++) {
    cout << "Working on Case #" << tt << "\n";
    fin >> N;
    for (int i = 1; i <= 2500; i++) cnt[i] = 0;
    for (int i = 0; i < 2*N-1; i++) {
    	for (int j = 0; j < N; j++) {
    		int a;
    		fin >> a;
    		cnt[a]++;
    	}
    }
    fout << "Case #" << tt << ":";
    for (int i = 1; i <= 2500; i++) {
    	if (cnt[i]%2 == 1) fout << " " << i;
    }
    fout << "\n";
  }
  return 0;
}