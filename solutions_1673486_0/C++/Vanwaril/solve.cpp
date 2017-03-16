#include <iostream>
#include <vector>
#include <cstdio>
#include <map>

using namespace std;

float Pcorrect(vector<float> p, int len)
{
	float ret=1;
	for(int i=0; i<len; i++)
		ret *= p[i];
	return ret;
}

float Perr(vector<float> p, int len)
{
	return 1 - Pcorrect(p, len);
}

int main()
{
	int N;
	
	cin>>N;
	// Case-independent stuff?
	
	// Cases:
	for(int t=1; t<=N; t++)
	{
		// Each Case:
		float output;
		
		// random variables
		
		// input variables
		int A, B;
		
		cin>>A>>B;
		vector<float> p(A);
		for(int i=0; i<A; i++)
			cin>>p[i];
		
		// compute
		float keep_type=0, re_type=0, temp_prob;

		//Computing Keep_type
		temp_prob = Pcorrect(p, p.size());
		keep_type = output = (1-temp_prob)*(B-A+1+B+1) + temp_prob*(B-A+1);

		//Computing Re_type
		re_type = (B+2);

		if(re_type < output) output = re_type;

		// Compute backn:
		for(int i=1; i<A; i++)
		{
			// if I backspace i:
			// i keystrokes to backspace
			// B - (A-i) re-type.
			// Pcorrect(p) for first A-i things.
			temp_prob = Pcorrect(p, A-i);
			re_type = temp_prob*(i + B -A+i + 1) + (1 - temp_prob)*(i + B -A+i + 1 +B+1);
			if(re_type < output) output = re_type;
		}
		printf("Case #%d: %lf\n", t, output);
	}
	return 0;
}
