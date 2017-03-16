#include <cstdio>
#include <map>

const double initial_rate = 2.0;

typedef struct tag_TestCase
{
	int id;
	double farm_price;
	double farm_rate;
	double goal;
	//std::map<int, double> farm_building_prices;
} TestCase;


void solve_test_case(TestCase test_case, FILE *output)
{
	int max_n = 2 * (int)(1.0 + test_case.goal / test_case.farm_price - initial_rate / test_case.farm_rate);
	double best_time = test_case.goal / initial_rate;
	double farm_building_price = 0.0;
	double divisor = initial_rate;
	for (int n = 1; n <= max_n; ++n)
	{
		farm_building_price += test_case.farm_price / divisor;
		divisor += test_case.farm_rate;
		double time = test_case.goal / divisor + farm_building_price;
		if (time < best_time)
			best_time = time;
	}
	fprintf(output, "Case #%d: %.7f\n", test_case.id, best_time);
}

void main()
{
	FILE *input = fopen("IO/input.txt", "rt");
	FILE *output = fopen("IO/output.txt", "wt");
	int t = 0;
	fscanf(input, "%d", &t);
	for (int i = 1; i <= t; ++i)
	{
		TestCase test_case;
		test_case.id = i;
		fscanf(input, "%lf %lf %lf", &test_case.farm_price, &test_case.farm_rate, &test_case.goal);
		solve_test_case(test_case, output);
	}
	fclose(output);
	fclose(input);
}