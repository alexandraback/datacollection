#include<cstdio>
#include<algorithm>

using namespace std;

int number_of_cases, testcase, Smax;
char P[1005];
int S, sum, sol;

int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	scanf("%d", &number_of_cases);

	for (testcase = 1; testcase <= number_of_cases; testcase++) {
		scanf("%d", &Smax);
		scanf("%s", P);

		sum = P[0] - '0';
		sol = 0;

		for (S = 1; S <= Smax; S++) {
			sol += max(0, S - sum);
			sum += max(0, S - sum);
			sum += P[S] - '0';
		}

		printf("Case #%d: %d\n", testcase, sol);
	}

	return 0;
}