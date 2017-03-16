#include <cstdio>
#include <cstdlib>

using namespace std;

int compare_double(const void * d1, const void * d2)
{
	if (*(double *)d1 < *(double *)d2)
		return -1;
	else if (*(double *)d1 == *(double *)d2)
		return 0;
	else
		return 1;
}

int compute_deceitful_war(double * a, double * b, int len)
{
	qsort(a, len, sizeof(double), compare_double);
	qsort(b, len, sizeof(double), compare_double);
	int a_lower, a_upper;
	int b_lower, b_upper;
	int a_score;
	a_lower = b_lower = a_score = 0;
	a_upper = b_upper = len - 1;
	while (
			(a_lower <= a_upper) &&
			(b_lower <= b_upper))
	{
		if (a[a_upper] < b[b_upper]) // use smaller a to crash larger b
		{
			a_lower++;
			b_upper--;
			continue;
		}
		if (a[a_upper] > b[b_upper]) // alreay larger, yay
		{
			a_upper--;
			b_upper--;
			a_score++;
		}

	}
	return a_score;
}

int compute_war(double * a, double * b, int len)
{
	qsort(a, len, sizeof(double), compare_double);
	qsort(b, len, sizeof(double), compare_double);
	int a_lower, a_upper;
	int b_lower, b_upper;
	int b_score;
	a_lower = b_lower = b_score = 0;
	a_upper = b_upper = len - 1;
	while (
			(a_lower <= a_upper) &&
			(b_lower <= b_upper))
	{
		if (a[a_lower] < b[b_lower]) // b: yay
		{
			a_lower++;
			b_lower++;
			b_score++;
			continue;
		}
		if (a[a_lower] > b[b_lower]) // b: i will get the next one
		{
			b_lower++;
		}
	}
	return len - b_score;
}

int main (int argc, const char * argv[])
{
	freopen(argv[1], "r", stdin);
	if (argc == 3)
		freopen(argv[2], "w", stdout);

	int num_tc;
	scanf("%d\n", &num_tc);
	for (int i = 0; i < num_tc; i++)
	{
		int len;
		scanf("%d\n", &len);
		double * a = new double[len];
		double * b = new double[len];
		for (int j = 0; j < len - 1; j++)
			scanf("%lf ", &a[j]);
		scanf("%lf\n", &a[len - 1]);
		for (int j = 0; j < len - 1; j++)
			scanf("%lf ", &b[j]);
		scanf("%lf\n", &b[len - 1]);

		int dw_score = compute_deceitful_war(a, b, len);
		int w_score = compute_war(a, b, len);
		printf("Case #%d: %d %d\n", i + 1, dw_score, w_score);

		delete[] a;
		delete[] b;
	}

	fclose(stdin);
	if (argc == 3)
		fclose(stdout);
}
