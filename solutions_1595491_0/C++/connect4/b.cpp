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
using namespace std;


int main()
{
fstream In("b-small.in", ios::in);
fstream Out("b-small.out", ios::out);

int tests;

In >> tests;

for(int h=0; h<tests; h++)
{
int ret = 0;

int N, S, P;

In >> N >> S >> P;

for(int i=0; i<N; i++)
{
	int n;
	In >> n;
	if(3*P-2 <= n)
		ret++;
	else if(3*P-4 <= n && n > 1 && S)
	{	ret++; S--;
	}
}

Out << "Case #" << h+1 << ": " << ret << endl;

}

In.close();

Out.close();

return 0;

}
 
