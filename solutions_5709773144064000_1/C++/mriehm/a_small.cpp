#include <cstdio>

using namespace std;

int main(void)
{
	unsigned int number_of_tests;
	scanf("%u\n", &number_of_tests);
	for (unsigned int test = 0; test < number_of_tests; ++test)
	{
		double farm_cost;
		double farm_cookie_bonus;
		double cookie_goal;
		scanf("%lf %lf %lf\n", &farm_cost, &farm_cookie_bonus, &cookie_goal);

		double current_seconds = 0;
		double cookies_per_second = 2;
		while(1)
		{
			double seconds_to_farm = farm_cost / cookies_per_second;
			double seconds_to_win = cookie_goal / cookies_per_second;
			double seconds_to_win_with_farm = seconds_to_farm + cookie_goal / (cookies_per_second + farm_cookie_bonus);
			if (seconds_to_win > seconds_to_win_with_farm)
			{
				cookies_per_second += farm_cookie_bonus;
				current_seconds += seconds_to_farm;
			}
			else
			{
				current_seconds += seconds_to_win;
				break;
			}
		}

		printf("Case #%u: %.7lf\n", test + 1, current_seconds);
	}
}
