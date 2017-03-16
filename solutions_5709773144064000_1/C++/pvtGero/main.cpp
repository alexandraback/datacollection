#include <cstdio>
using namespace std;

int main (int argc, char *argv[])
{
	int TC;
	scanf("%d", &TC);
	
	for(int c = 1; c <= TC; c++){
		double total = 0;
		double curr = 2.0;
		double C, F, X;
		scanf("%lf %lf %lf", &C, &F, &X);
		
		bool buy = (C / curr + (X / (curr + F))) < X / curr;
		while(buy){
			total += C / curr;
			curr += F;
			buy = (C / curr + (X / (curr + F))) < X / curr;
		}
		
		printf("Case #%d: %.7f\n", c, total + (X / curr));
	}
	
	return 0;
}

