#include <cstdio>
using namespace std;

void solve(int caseNumber);

void solve(int caseNumber)
{
	double c, f,x;
	double ans = 0;
	double currentSpeed = 2;
	double timeElapsed = 0;

	scanf("%lf %lf %lf", &c, &f, &x);

	while(true)
	{
		double t1 = x /currentSpeed;
		double t2 = (c/currentSpeed) + (x / (currentSpeed + f));
		if (t1 <= t2)
		{
			ans = timeElapsed + t1;
			break;
		} else {
			timeElapsed += (c/currentSpeed);
			currentSpeed += f;
		}
	}

	printf("Case #%d: %0.7lf\n", caseNumber, ans);
}

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("out", "w", stdout);

	int t;
	scanf("%d", &t);

	for(int i = 1;i <= t; i++)
	{
		solve(i);
	}
}