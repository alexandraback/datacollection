#include <cstdio>
#include <vector>
#include <algorithm>

typedef struct tag_TestCase
{
	int id;
	int n;
	std::vector<double> naomi;
	std::vector<double> ken;
} TestCase;

bool revese_compare(double a, double b)
{
	return a > b;
}

int play_war(TestCase test_case)
{
	int result = 0;
	std::sort(test_case.naomi.begin(), test_case.naomi.end(), revese_compare);
	std::sort(test_case.ken.begin(), test_case.ken.end(), revese_compare);
	for (int i = 0; i < test_case.n; i++)
	{
		double naomi = test_case.naomi.back();
		test_case.naomi.pop_back();
		std::vector<double>::iterator ken_iterator = test_case.ken.end();
		bool ken_won = false;
		for (int j = 1; j <= test_case.ken.size(); ++j)
		{
			--ken_iterator;
			double ken = *ken_iterator;
			if (ken > naomi)
			{
				ken_won = true;
				test_case.ken.erase(ken_iterator);
				break;
			}
		}
		if (!ken_won)
		{
			test_case.ken.pop_back();
			++result;
		}
	}
	return result;
}

int play_deceitful_war(TestCase test_case)
{
	int result = 0;
	std::sort(test_case.naomi.begin(), test_case.naomi.end(), revese_compare);
	std::sort(test_case.ken.begin(), test_case.ken.end(), revese_compare);
	for (int i = 0; i < test_case.n; i++)
	{
		double naomi_min = test_case.naomi.back();
		double ken_min = test_case.ken.back();
		test_case.naomi.pop_back();
		if (naomi_min < ken_min)
			test_case.ken.erase(test_case.ken.begin());
		else
		{
			++result;
			test_case.ken.pop_back();
		}
	}
	return result;
}

void solve_test_case(TestCase test_case, FILE *output)
{
	int deceitful_war_result = play_deceitful_war(test_case);
	int war_result = play_war(test_case);
	fprintf(output, "Case #%d: %d %d\n", test_case.id, deceitful_war_result, war_result);
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
		fscanf(input, "%d", &test_case.n);
		for (int j = 0; j < test_case.n; ++j)
		{
			double value = 0.0;
			fscanf(input, "%lf", &value);
			test_case.naomi.push_back(value);
		}
		for (int j = 0; j < test_case.n; ++j)
		{
			double value = 0.0;
			fscanf(input, "%lf", &value);
			test_case.ken.push_back(value);
		}
		solve_test_case(test_case, output);
	}
	fclose(output);
	fclose(input);
}