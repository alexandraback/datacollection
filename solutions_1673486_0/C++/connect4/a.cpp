#include <string.h>       
#include <vector>       
#include <set>       
#include <map>       
#include <algorithm>       
#include <math.h>       
#include <sstream>       
#include <ctype.h>       
#include <queue>       
#include <stack>       
#include <iostream> 
#include <gmp.h>	// if GMP is not allowed, I apologize
#include <fstream>
#include <iomanip>
using namespace std;


int main()
{
fstream In("a-small.in", ios::in);
fstream Out("a-small.out", ios::out);

int tests;

In >> tests;
for(int h=0; h<tests; h++)
{
	
long double ret = 1e9;

int A, B;

In >> A >> B;

vector<long double> probs(A, 0);

for(int i=0; i<A; i++)
	In >> probs[i];
ret = B + 2;
cout << "0:  " << B+2 << endl;
long double p = 1.0;
for(int i=0; i< A; i++)
{
	p *= probs[i];
	int m = A-i-1; // number of characters to erase/type
	long double d = (2*m + (B-A) + 1) + (1-p) * (B+1) ;
	cout << i+1 << ": " <<  d << endl;
	ret = min(ret, d);
}

Out << "Case #" << h+1 << ": " << setprecision(10) << ret << endl;

}

In.close();

Out.close();

return 0;

}
 
