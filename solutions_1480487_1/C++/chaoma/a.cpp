#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cassert>
#include <cmath>

using namespace std;
typedef long long int ll;
const int inf = INT_MAX;
const int max_con = 200;
int n_con;
int con[max_con];
int tot;

void input(void)
{
	int i, j, k;
	scanf("%d", &n_con);
	for (i = 0; i < n_con; i++)
		scanf("%d", con + i);
	// for (i = 0; i < n_con; i++)
	// 	printf("%d ", con[i]);
	// printf("\n");
}

void output(int icase)
{
	int i, j, k;
	printf("Case #%d:", icase + 1);
	int nt = tot;
	int n = 0;
	for (i = 0; i < n_con; i++) {
		if (tot / n_con - con[i] < 0) {
			nt -= con[i];
			n++;
		}
	}
	for (i = 0; i < n_con; i++)
		if (tot / n_con - con[i] < 0)
			printf(" %lf", 0.0);
		else
			printf(" %lf", ((double)nt / (n_con - n) - con[i]) / (tot / 2) * 100);
	printf("\n");
}

void solve(void)
{
	int i, j, k;
	tot = 0;
	for (i = 0; i < n_con; i++)
		tot += con[i];
	tot *= 2;
}

int main()
{
	int n_case;
	scanf("%d", &n_case);
	for (int i = 0; i < n_case; i++) {
		input();
		solve();
		output(i);
	}
	return 0;
}
