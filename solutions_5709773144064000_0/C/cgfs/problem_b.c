#include <stdio.h>
#include <string.h>
#include <stdlib.h>




// return : added time
double calc_short_time_to_goal(int case_num, double c, double f, double x, double s_time, double c_candy, double c_candy_rate)
{

	double candy_need_for_goal;
	double candy_need_for_farm;
	double need_time_not_buy;
	double need_time_with_farm;
	double time_for_farm;

	//calc the required time to get to goal at next farm available

	candy_need_for_goal = x - c_candy;
	candy_need_for_farm = c - c_candy;

	// if time to goal is shorter than time for more farm, job is finished
	if (candy_need_for_goal <= candy_need_for_farm) {
		printf("Case #%d: %lf \n", case_num, candy_need_for_goal/c_candy_rate + s_time);
		return; 
	}

	// we need to check more farm or not.
	// time without more farm
	//x = c_candy_rate * need_time_not_buy + c_candy; 
	need_time_not_buy = (x - c_candy)/c_candy_rate;

	// time with one more farm
	// time for more farm 
	time_for_farm = candy_need_for_farm/c_candy_rate;
	// x = (need_time_with_farm - time_for_farm) * (c_candy_rate + c)
	need_time_with_farm = x/(c_candy_rate + f) + time_for_farm;

	if (need_time_not_buy < need_time_with_farm) {

		printf("Case #%d: %lf \n", case_num, need_time_not_buy + s_time);
		return; 
	} else {
		s_time += time_for_farm;
		c_candy = 0;
		c_candy_rate += f;
		calc_short_time_to_goal(case_num, c, f, x, s_time, c_candy, c_candy_rate);
	}

	return;

}

int main(void)
{
	int num_set;
	int case_num;
	double  c, f, x, goal_time;

	scanf("%d", &num_set);

	for (case_num = 1; case_num <= num_set; case_num++) {
		
		scanf("%lf %lf %lf", &c, &f, &x);
		//printf("%lf, %lf, %lf \n", c, f, x);
		goal_time = calc_short_time_to_goal(case_num, c, f, x, 0, 0, 2); 
	}	
}
