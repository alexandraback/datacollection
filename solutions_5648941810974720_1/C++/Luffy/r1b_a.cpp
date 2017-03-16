#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

typedef pair<int, int> P;

int main(){
	freopen("output.txt","w",stdout);
	freopen("input.in","r",stdin);
	int T;
	cin >> T;
	string s;
	map<char, int> counter;
	char ans[1000];
	int idx;
	for (int t=1; t<=T; t++) {
		cin >> s;
		counter.clear();
		for (int i=0; i<s.length(); i++) {
			counter[s[i]]++;
		}
		idx = 0;
		while (counter['Z'] > 0) {
			ans[idx++] = 0;
			counter['Z']--;
			counter['E']--;
			counter['R']--;
			counter['O']--;
		}
		while (counter['W'] > 0) {
			ans[idx++] = 2;
			counter['W']--;
			counter['T']--;
			counter['O']--;
		}
		while (counter['X'] > 0) {
			ans[idx++] = 6;
			counter['S']--;
			counter['I']--;
			counter['X']--;
		}
		while (counter['U'] > 0) {
			ans[idx++] = 4;
			counter['F']--;
			counter['O']--;
			counter['U']--;
			counter['R']--;
		}
		while (counter['G'] > 0) {
			ans[idx++] = 8;
			counter['E']--;
			counter['I']--;
			counter['G']--;
			counter['H']--;
			counter['T']--;
		}
		while (counter['H'] > 0) {
			ans[idx++] = 3;
			counter['T']--;
			counter['H']--;
			counter['R']--;
			counter['E']-=2;
		}
		while (counter['F'] > 0) {
			ans[idx++] = 5;
			counter['F']--;
			counter['I']--;
			counter['V']--;
			counter['E']--;
		}
		while (counter['Z'] > 0) {
			ans[idx++] = 5;
			counter['Z']--;
			counter['E']--;
			counter['R']--;
			counter['O']--;
		}
		while (counter['S'] > 0) {
			ans[idx++] = 7;
			counter['S']--;
			counter['E']-=2;
			counter['V']--;
			counter['N']--;
		}
		while (counter['I'] > 0) {
			ans[idx++] = 9;
			counter['I']--;
			counter['N']-=2;
			counter['E']--;
		}
		while (counter['O'] > 0) {
			ans[idx++] = 1;
			counter['O']--;
			counter['N']--;
			counter['E']--;
		}
		sort(ans, ans+idx);
		printf("Case #%d: ", t);
		for (int i=0; i<idx; i++) {
			printf("%d", ans[i]);
		}
		printf("\n");
	}
	return 0;
}