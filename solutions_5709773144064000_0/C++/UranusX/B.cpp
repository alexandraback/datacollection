#include <cstdio>

double C, F, X;

void Work()
{
	scanf("%lf%lf%lf", &C, &F, &X);
	double CurSpd = 2;
	double Time = 0;
	double Ans = Time + X / CurSpd;
	while (1)
	{
		Time += C / CurSpd;
		CurSpd += F;
		double AnsX = Time + X / CurSpd;
		if (AnsX < Ans)
			Ans = AnsX;
		else
		{
			printf("%.7lf\n", Ans);
			break;
		}
	}
}

int main()
{
	freopen("B-small.in", "r", stdin);
	freopen("B-small.out", "w", stdout);
    int Cases;
    scanf("%d", &Cases);
    for (int Case = 1; Case <= Cases; Case ++)
    {
		printf("Case #%d: ", Case);
		Work();
    }
    return 0;
}