#include <stdio.h>

double get_time_needed(double c, double f, double x, int n) {
	double total = 0.0, speed = 2.0;

	while (n--) {
		total += c / speed;
		speed += f;
	}
	total += x / speed;

	return total;
}

double get_answer() {
	int extra = 1;
	double c, f, x, ans, best_ans;

	scanf("%lf%lf%lf", &c, &f, &x);
	best_ans = get_time_needed(c, f, x, 0);
	for (;;) {
		ans = get_time_needed(c, f, x, extra++);
		if (ans > best_ans)
			break;
		best_ans = ans;
	}

	return best_ans;
}

int main(int argc, char* argv[]) {
	int case_no, t;

	scanf("%d", &t);
	for (case_no = 1; case_no <= t; case_no++)
		printf("Case #%d: %.7f\n", case_no, get_answer());

	return 0;
}