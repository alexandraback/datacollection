/**************************************************
 * Author	 : xiaohao Z
 * Blog	 : http://www.cnblogs.com/shu-xiaohao/
 * Last modified : 2016-04-30 23:44
 * Filename	 : A.cpp
 * Description	 : 
 * ************************************************/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <set>
#include <map>
#define MP(a, b) make_pair(a, b)
#define PB(a) push_back(a)

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<unsigned int,unsigned int> puu;
typedef pair<int, double> pid;
typedef pair<ll, int> pli;
typedef pair<int, ll> pil;

const int INF = 0x3f3f3f3f;
const double eps = 1E-6;
const int LEN = 30;
int num[LEN], ans[LEN];
string tab[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};

void push(int x, int N) {
	for(int i=0; i<tab[x].size(); i++) {
		num[tab[x][i] - 'A'] -= N;
	}
}

int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T, kase = 1;
	string str;
	cin >> T;
	while(T --) {
		memset(num, 0, sizeof num);
		memset(ans, 0, sizeof ans);
		cin >> str;
		for(int i=0; i<str.size(); i++) num[str[i] - 'A'] ++;
		ans[0] = num['Z' - 'A'];
		push(0, ans[0]);
		ans[2] = num['W' - 'A'];
		push(2, ans[2]);
		ans[4] = num['U' - 'A'];
		push(4, ans[4]);
		ans[6] = num['X' - 'A'];
		push(6, ans[6]);
		ans[8] = num['G' - 'A'];
		push(8, ans[8]);
		ans[1] = num['O' - 'A'];
		push(1, ans[1]);
		ans[3] = num['R' - 'A'];
		push(3, ans[3]);
		ans[5] = num['F' - 'A'];
		push(5, ans[5]);
		ans[7] = num['V' - 'A'];
		push(7, ans[7]);
		ans[9] = num['E' - 'A'];
		push(9, ans[9]);
		cout << "Case #" << kase ++ << ": ";
		for(int i=0; i<10; i++)
			for(int j=0; j<ans[i]; j++)
				cout << i;
		cout << endl;
	}
	return 0;
}

