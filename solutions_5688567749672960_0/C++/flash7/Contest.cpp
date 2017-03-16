//============================================================================
// Name        : Contest.cpp
// Author      : Tarango Khan
// Team        : Byteheads
//============================================================================

#include <bits/stdc++.h>
using namespace std;

string int2str(int a) {
	stringstream ss;
	ss << a;
	string str = ss.str();
	return str;
}

int str2int(string s) {
	stringstream ss(s);
	int i;
	ss >> i;
	return i;
}

string char2str(char c) {
	stringstream ss;
	string s;
	ss << c;
	ss >> s;
	return s;
}
map<int, int> Map, Block;

struct Val {
	int num;
	int cnt;
	Val(int a, int b) {
		num = a;
		cnt = b;
	}
};

int reverseStr(int num) {
	if (num < 10)
		return num;
	string s = int2str(num);
	string t = "";
	int i = s.length() - 1;
	while (i >= 0 && s[i] == '0')
		i--;
	for (; i >= 0; i--) {
		t = t.append(char2str(s[i]));
	}
	return str2int(t);
}

int main() {
	int nCase, N, v;
	Map[1] = 1;
	int res = 1;
	queue<Val> Q;
	Q.push(Val(1, 1));
	while (Q.empty() == false) {
		Val cur = Q.front();
		Q.pop();
		Block[cur.num] = cur.cnt;
		if (cur.num > 1000000) {
			continue;
		}
		v = cur.num + 1;
		if (Map[v] != 1) {
			Map[v] = 1;
			Q.push(Val(v, cur.cnt + 1));
		}
		v = reverseStr(cur.num);
		if (Map[v] != 1) {
			Map[v] = 1;
			Q.push(Val(v, cur.cnt + 1));
		}
	}
	scanf("%d", &nCase);
	for (int cs = 1; cs <= nCase; cs++) {
		scanf("%d", &N);
		printf("Case #%d: %d\n", cs, Block[N]);
	}
	return 0;
}
