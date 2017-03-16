#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

int min(int a, int b)
{
	if(a<b) return a;
	return b;
}

// returns the layer that block x,y is on
int layer(int x, int y)
{
	if(x<0) return ((y-x)/2)+1;
	return ((y+x)/2)+1;
}

// Returns N choose k
int binom(int N, int k)
{
	if (k==0) return 1;
	if(k==N) return 1;
	return binom(N-1, k-1) + binom(N-1, k);
}



double phi(double x)
{
	// Magic(!) cumulative normal distribution
	// Taken from John Cook www.johndcook.com
    // constants
    double a1 =  0.254829592;
    double a2 = -0.284496736;
    double a3 =  1.421413741;
    double a4 = -1.453152027;
    double a5 =  1.061405429;
    double p  =  0.3275911;

    // Save the sign of x
    int sign = 1;
    if (x < 0)
        sign = -1;
    x = fabs(x)/sqrt(2.0);

    // A&S formula 7.1.26
    double t = 1.0/(1.0 + p*x);
    double y = 1.0 - (((((a5*t + a4)*t) + a3)*t + a2)*t + a1)*t*exp(-x*x);

	return 0.5*(1.0 + sign*y);
}

double big_b_or_fewer(int b, int N)
{
	double mean = ((double)N)/2;
	double sigma = sqrt(((double)N)/4);

	return phi((((double)b)-mean)/sigma);

}

// returns the probability that b or fewer balls go in one direction, out of N
double b_or_fewer(int b, int N)
{

	if(N>40) return big_b_or_fewer(b, N);


	int tot=0;
	for(int i = 0; i<=b;i++)
	{
		tot+=binom(N, i);
		//cout << i << " tot= : " << tot << endl;
	}
	int power = pow(2, (double)N);
	double retval = ((double)tot)/((double)power);
	//cout << "tot power retval " << tot <<" "<< power <<" "<<retval<<endl;
	return retval;
}

// Return probability that we get to height y on row r with N diamonds
// nb Need y+1 to go right
double prob(int r, int y, int N)
{
	//cout << "Calling prob r y N " << r << y << N <<endl;
	// Deal with top diamond case first
	if(N>=(4*r - 3)) return 1;

	// if left side fills and we make it, return 1
	if(N-(2*(r-1))>=y+1) return 1;

	if(y==2*(r-1))
	{
		if(N>=(4*r)-3)
		{
			return 1;
		} else {
			return 0;
		}
	}
	//cout << " Not top" << endl;
	double p=0;

	// And if not enough, return 0
	if(N<(y+1)) return 0;

	//cout << "Enough to make it." << endl;
	// Add (probability left side has N - (y+1) or fewer)
	p+=b_or_fewer(N-(y+1), N); 
	//cout << "p= " << p<<endl;
	// Add probabiity left side fills
	//if((N-(2*r))>=y+1)
	//{
		//p+= 1.0 - b_or_fewer((2*r)-1, N); //chance left side fills
		//cout << "then p= " << p<<endl;
	//}

	// We return (chance other side fills)
	return p;
}

int main(int argc, char ** argv)
{
	int T;
	scanf("%d", &T);

	deque<int> sizes;
	for(int t = 1; t<=T;t++)
	{
		printf("Case #%d: ", t);
		// Read data
		int N,x,y;
		scanf(" %d %d %d,", &N, &x, &y);
		
		//determine layer that x,y is on
		int l = layer(x,y);

		// number of diamonds in lower layers
		N -= ((l*(l-1))*2) - (3*(l-1));

		// Stop if we don't get there
		if(N<=0)
		{
			printf("0\n");
			continue;
		}

		double p;
		p = prob(l, y, N);
		printf("%f\n", p);
	}
	return 0;
}