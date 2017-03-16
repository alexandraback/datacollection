//be naame khodaa

#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <string>
#include <cstdio>
#include <algorithm>
#include <set>
#include <cassert>
#include <iomanip>
typedef long long ll;

using namespace std;
typedef pair <int, int> pii;

string digs[10] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int cnt[1005], rep[105]; 

void add(int x){
	for (int i = 0; i < digs[x].length(); i++)
		cnt[digs[x][i]]--;
	rep[x]++;
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	string s;
	cin >> t;
	for (int it = 1; it <= t; it++){
		cin >> s;
		for (int i = 0; i < s.length(); i++)
			cnt[s[i]]++;

		while (cnt['Z']) add(0);
		while (cnt['X']) add(6);
		while (cnt['W']) add(2);
		while (cnt['G']) add(8);
		while (cnt['S']) add(7);
		while (cnt['V']) add(5);
		while (cnt['F']) add(4);
		while (cnt['T']) add(3);
		while (cnt['O']) add(1);
		while (cnt['N']) add(9);

		cout << "Case #" << it << ": ";
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < rep[i]; j++)
				cout << i;
			rep[i] = 0;
		}
		cout << endl;
	}
	return 0;
}
