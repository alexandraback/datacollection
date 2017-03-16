#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

string  answer[6][6][40];
int r,c;
char s[55][55];
int b[5][5];
bool mark[5][5];

void make(int x,int y,int z) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			b[i + x][j + y] += z;
		}
	}
}

void print(string s) {
        if (s == "") {
                return;
        }
        for (int i = 0,k = 0; i < r; ++i) {
                for (int j = 0; j < c; ++j) {
                        putchar(((i == 1) && (j == 1))?'c':s[k]);
			++k;
                }
                puts("");
        }
}

int dfs(int x,int y) {
	if ((x < 0) || (x >= r) || (y < 0) || (y >= c) || (mark[x][y]) || (b[x][y] <= 0)) {
		return 0;
	}
	mark[x][y] = true;
	int r = 1 + dfs(x - 1, y);
	r += dfs(x + 1, y);
	r += dfs(x, y - 1);
	r += dfs(x, y + 1);
	return r;
}
	

void init(int x,int y) {
	if (y >= c) {
		init(x + 1, 0);
		return;
	}
	if (x >= r) {
		string temp = "";
		memset(mark,0,sizeof(mark));
		int num = 0,cp = r * c - dfs(0, 0);
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < c; ++j) {
				if (b[i][j]) {
					temp += '.';
				}
				else {
					++num;
						
					temp += '*';
				}
			}
		}
		if (cp == num) {
			answer[r][c][num] = temp;
		}
		return;
	}
	if (x || y) {
		init(x, y + 1);
	}
	if ((x + 3 <= r) && (y + 3 <= c)) {
		make(x,y,1);
		init(x, y + 1);
		make(x,y,-1);
	}
}

void give(char ch) {
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			putchar((i == 0) && (j == 0)?'c':ch);
		}
		puts("");
	}
}
	
int main() {
	for (r = 3; r <= 5; ++r) {
		for (c = 3; c <= 5; ++c) {
			
			init(0,0);
			
		}
	
	}
	int z,zz;
	scanf("%d",&zz);
	for (int z = 1; z <= zz; ++z) {
		int m;
		scanf("%d%d%d",&r,&c,&m);
		printf("Case #%d:\n",z);
		if (m == 0) {
			give('.');
			continue;
		}
		int n = r * c;
		if (n - 1 == m) {
			give('*');
			continue;
		}
		if (r == 1) {
			for (int i = 0; i < m; ++i) {
				putchar('*');
			}
			for (int i = m; i + 1 < c; ++i) {
				putchar('.');
			}
			puts("c");
			continue;
		}
		if (c == 1) {
			for (int i = 0; i < m; ++i) {
				puts("*");
			}
			for (int i = m; i + 1 < r; ++i) {
				puts(".");
			}
			puts("c");
			continue;
		}
		// r >= 2 c >= 2
		if (r == 2) {
			if ((m <= (c - 2) * 2) && (m % 2 == 0)) {
				putchar('c');
				for (int i = c - m / 2 - 1; i > 0; --i) {
					putchar('.');
				}
				for (int i = m / 2; i > 0; --i) {
					putchar('*');
				}
				puts("");
				for (int i = c - m / 2; i > 0; --i) {
					putchar('.');
				}
				for (int i = m / 2; i > 0; --i) {
					putchar('*');
				}
				puts("");
			}
			else {
				puts("Impossible");
			}
			continue;
		}
		if (c == 2) {
			if ((m <= (r - 2) * 2) && (m % 2 == 0)){
				puts("c.");
				for (int i = r - m / 2 - 1; i > 0; --i) {
					puts("..");
				}
				for (int i = m / 2; i > 0; --i) {
					puts("**");
				}
			
			}
			else {
                                puts("Impossible");
                        }
			continue;
		}
		if (m + 9 > n) {
			puts("Impossible");
			continue;
		}
		if (answer[r][c][m] == "") {
			puts("Impossible");
                        continue;
		}
		print(answer[r][c][m]);
	}
	return 0;
}	
