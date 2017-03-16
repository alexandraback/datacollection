#include <stdio.h>
#include <math.h>

int main() {
	int t;
	double c,f,x;
	scanf("%u\n", &t);
	double a = 0;
	double a_new;
	int nfarms = 0;
	double tfarm;
	double rate;

	int i;
	
	for(i=1; i<=t; i++) {
		scanf("%lf %lf %lf\n", &c, &f, &x);

		//c is number for a farm, f is increased rate of a farm, x is number to win.
		//Algorithm: calculate initial time to win with no farms:
		a_new = x/2.0;
		// Now, for a given farm, if we're going to buy it at all, we should do so as early as possible.
		// If a farm makes sense, the time to win will be shorter if we buy the farm than if we don't.  Once times start getting longer, we stop because buying more farms can't help
		rate = 2.0;
		nfarms = 0;
		tfarm = 0;
		do {
			a = a_new;
			tfarm += c/rate;
			nfarms++; rate += f;
			a_new = tfarm + x/rate;
		} while (a_new < a);

		printf("Case #%u: %0.7lf\n",i,a);
	}
	return 0;
}
