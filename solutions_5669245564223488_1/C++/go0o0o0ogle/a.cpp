#include <stdio.h>
#include <vector>
using namespace std;

#define INT64 __int64
#define MOD 1000000007

int N;
char str[100][105];
bool mark[100];

struct node {
	char ch;
};

vector<node> v[100];
vector<int> v2[100];

/*bool check(vector<node> &v[100])
{
	for (i = 0; i < N; i++) {
		int size = v[i].size();
		if (size > 2) {
			for (j = 1; j < size - 1; j++) {
				char ch = v[i][j].ch;
				int x, y;
				for (x = 0; x < N; x++) {
					int size = v[x].size();
					for (y = 0; y < size; y++) {
						if (x == i && y == j) {
							continue;
						}
						if (ch == v[x][y].ch) {
							return false;
						}
					}
				}
			}
		}
	}
	return true;
}*/

INT64 connect(int index)
{
	INT64 result = 1;
	for (;;) {
		int i, j;
		int hindex, tindex;
		hindex = v2[index][0];
		tindex = v2[index][v2[index].size() - 1];
		char head, tail;
		head = v[hindex][0].ch;
		tail = v[tindex][v[tindex].size() - 1].ch;
		bool find = false;
		for (i = 0; i < N; i++) {
			if (!mark[i]) {
				char h, t;
				h = v[i][0].ch;
				t = v[i][v[i].size() - 1].ch;
				if (h == t) {
					if (h == tail) {
						int mul = 1;
						for (j = v2[index].size() - 1; j >= 0; j--) {
							int idx = v2[index][j];
							char h2 = v[idx][0].ch;
							char t2 = v[idx][v[idx].size() - 1].ch;
							if (h2 == t2 && t2 == tail) {
								mul++;
							}
							else {
								break;
							}
						}
						result = result * mul % MOD;
						mark[i] = true;
						v2[index].push_back(i);
						find = true;
					}
					else if (t == head) {
						int mul = 1;
						for (j = 0; j < v2[index].size(); j++) {
							int idx = v2[index][j];
							char h2 = v[idx][0].ch;
							char t2 = v[idx][v[idx].size() - 1].ch;
							if (h2 == t2 && t2 == head) {
								mul++;
							}
							else {
								break;
							}
						}
						result = result * mul % MOD;
						mark[i] = true;
						v2[index].insert(v2[index].begin(), i);
						find = true;
					}
				}
			}
		}
		for (i = 0; i < N; i++) {
			if (!mark[i]) {
				char h, t;
				h = v[i][0].ch;
				t = v[i][v[i].size() - 1].ch;
				if (h == tail) {
					mark[i] = true;
					v2[index].push_back(i);
					find = true;
					break;
				}
				else if (t == head) {
					mark[i] = true;
					v2[index].insert(v2[index].begin(), i);
					find = true;
					break;
				}
			}
		}
		if (!find) {
			break;
		}
	}
	return result;
}

int calc()
{
	int i;
	for (i = 0; i < 100; i++) {
		v[i].clear();
		v2[i].clear();
	}
	for (i = 0; i < N; i++) {
		char ch = str[i][0];
		char *ptr = &str[i][1];
		while (*ptr) {
			char c = *ptr;
			if (c != ch) {
				node n;
				n.ch = ch;
				v[i].push_back(n);
				ch = c;
			}
			ptr++;
		}
		node n;
		n.ch = ch;
		v[i].push_back(n);
	}

	memset(mark, false, sizeof (mark));
	INT64 result = 1;
	int count = 0;
	for (i = 0; i < N; i++) {
		if (!mark[i]) {
			mark[i] = true;
			v2[count].push_back(i);
			result = result * connect(count) % MOD;
			count++;
		}
	}

	bool alpha[26];
	int j, k;
	memset(alpha, false, sizeof (alpha));
	for (i = 0; i < count; i++) {
		for (j = 0; j < v2[i].size(); j++) {
			int idx = v2[i][j];
			k = 0;
			if (j != 0) {
				k = 1;
			}
			for (; k < v[idx].size(); k++) {
				int index = v[idx][k].ch - 'a';
				if (alpha[index]) {
					return 0;
				}
				alpha[index] = true;
			}
		}
	}

	for (i = 2; i <= count; i++) {
		result = result * i % MOD;
	}

	return (int)result % MOD;
}

int main()
{
	int cs, k;
	scanf("%d", &cs);
	for (k = 0; k < cs; k++) {
		scanf("%d", &N);
		int i;
		for (i = 0; i < N; i++) {
			scanf("%s", str[i]);
		}
		printf("Case #%d: %d\n", k + 1, calc());
	}
	return 0;
}