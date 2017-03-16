#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
using namespace std;

unsigned int iter_factorial(unsigned int n)
{
    unsigned int ret = 1;
    for(unsigned int i = 1; i <= n; ++i)
        ret *= i;
    return ret;
}


unsigned int comb_cal(unsigned int n, unsigned int k)
{
	unsigned int ret;
	ret = iter_factorial(n) / iter_factorial(k);
	ret = ret / iter_factorial(n-k);
	return ret;
}
int main(int argc, char * argv[])
{
double half = 0.5;
	ifstream fin("input.txt"); 
	ofstream fout("output.txt");
	
	if(!fin.good())
	{
		cout << "opps" << endl;
	}
	string str;
	getline(fin, str);
	
	const int T = atoi(str.c_str());

	for( int aaa = 0; aaa < T ; aaa++)
	{
		//	Load everything!!
		getline(fin, str);
		istringstream iss(str);

		//	 Data
		int N, X, Y;
		iss >> N >> X >> Y;

		double prob(1000);

if( X < 0 || Y < 0)
{	prob = 0;
}
		//	Done
		else if ((X==0) && (Y==0))
		{
			prob = 1;
		}
		//	Done
		else if(Y==0)
		{
			//	Done
			if((X==-2) || (X==2))
			{
				if (N == 1)
				{
					prob = 0;
				}
				else if (N == 2)
				{	prob = half;}
				else if (N==3)
				{	prob = 1 - pow(half,2); }

				/*else if((N <=3) && (N > 1))
				{
					prob = 1 - pow(half, N-1);
				}
				*/
				else if (N >= 4)
				{
					prob = 1;
				}
			}

			//	Done
			else if((X==-4) || (X==4))
			{
				if(N <= 6)
				{
					prob = 0;
				}
				else if (N <= 10)
				{
					prob = 1 - pow(half, N-6);
				}
				else
				{
					prob = 1;
				}
			}

			else if((X== -6 ) || (X==6))
			{
				if (N < 15) 
				{
					prob = 0;
				}
				else if( N < 21)
				{
					prob = 1 - pow(half, N - 15);
				}
			}
			else {prob = 0;}
		}

		// Done
		else if(Y==1)
		{
			//	Done
			if((X==1)  || (X==-1))
			{
				if(N <=2)
				{	
					prob = 0;
				}
				else if(N == 3)
				{
					prob = pow(half,2);
				}
				else if (N == 4)
				{
					prob = half;
				}
				else if (N >=5)
				{	
					prob = 1;
				}
			}

			//	Done
			else if((X==3)  || (X==-3))
			{
				if(N <=7)
				{	
					prob = 0;
				}
				else if(N == 8)
				{
					prob = pow(half,2);
				}
				else if (N == 9)
				{
					prob = pow(half,3)*(1 + comb_cal(3,2) );
				}
				else if (N == 10)
				{
					prob = pow(half,4)*(comb_cal(4,2) + comb_cal(4,3) + comb_cal(4,4));
				}
				else if (N == 11)
				{
					prob = 1 - pow(half,3);
				}
				else if (N >= 12)
				{	 prob = 1; }
			}


			// Done
	else 		if((X==5)  || (X==-5))
			{
				if(N <= 16)
				{	
					prob = 0;
				}
				if ( N == 17)
				{
					prob = pow(half,2);
				}
				else if (N == 18)
				{
					prob = half;
				}
				else if (N == 19)
				{
					prob = pow(half,4)*(1+comb_cal(4,2) + comb_cal(4,3));
				}
				else if(N==20)
				{
					prob = pow(half,5)*(1+comb_cal(5,2) + comb_cal(5,3) + comb_cal(5,4));
				}
			}
			else {prob = 0;}
		}


		else if(Y==2)
		{
			if(X == 0)
			{
				if(N <= 5)
				{
					prob =0;
				}
				else 
				{	
					prob = 1;
				}
			}

			// Prollyjjj
			else if((X == 2) || (X==-2))
			{
				if(N<=8)
				{	
					prob = 0;
				}
				else if (N == 9)
				{
					prob = pow(half, 3);
				}
				else if (N == 10)
				{
					prob = pow(half,4) *(1 + comb_cal(4, 3));
				}
				else if (N == 11)
				{
					prob = half;
				}
				else if (N == 12)
				{
					prob = 1 - pow(half,2);
				}
				else if (N>= 13)
				{
					prob = 1;
				}
			}


			//	Done
	else 		if((X == 4) || (X==-4))
			{
				if (N <= 17)
				{	prob = 0;}
				else if (N == 18)
				{ 	prob = pow(half,3);	}
				else if (N == 19)
				{	prob = pow(half,4) * (1 + comb_cal(4,3));}
				else if(N == 20)
				{	prob = pow(half,5)*(1+comb_cal(5,4)+comb_cal(5,3));}
			}
			else {prob = 0;}
		}



		// Done
		else if(Y==3)
		{
			//	Done
			if( (X== -1) || (X==1))
			{
				if(N<= 9)
				{	prob =0;}
				else if (N == 10)
				{
					prob = pow(half,4);
				}
				else if (N == 11)
				{	
					prob = pow(half,3);
				}
				else if( N == 12)
				{
					prob = pow(half,2);
				}
				else if(N==13)
				{
					prob = half;
				}
				else if (N >= 14)
				{	
					prob = 1;
				}
			}
			else if ((X == -3 ) || (X == 3))
			{
				if (N <19)
				{prob = 0;}
				if (N == 19)
				{	prob = pow(half,4); }
				if (N == 20) 
				{ prob = pow(half,5) *( 1+ comb_cal(5,4));}
			}
			else {prob = 0;}
		}



		else if(Y==4)
		{
			if (X== 0)
			{	
				if (N >= 15)
				{
					prob = 1;
				}
				else
				{	prob = 0; }
				}
			else if ((X== -2) || (X==2))
			{
				if (N == 20)
				{
					prob = pow(half , 5);
				}
				else {prob = 0;}
			}
			else {prob = 0;}
		}
		else { prob = 0;}

if (prob < 0){prob = 0;}

		//fout << "Case #" << aaa+1 << ": " << prob << endl;
		fout << fixed << setprecision(10) << "Case #" << aaa+1 << ": " << setprecision(10) << static_cast<double>(prob)<< setprecision(10) <<  endl;

	}	

	fin.close(); fout.close();
	return 0;
}
