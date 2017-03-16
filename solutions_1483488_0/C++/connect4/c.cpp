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

int table[2000005];

int main()
{
fstream In("c-small.in", ios::in);
fstream Out("c-small.out", ios::out);

int tests;

In >> tests;

for(int h=0; h<tests; h++)
{
memset(table, 0, sizeof(table));
int A, B;
In >> A >> B;
int a = A, q = 0, d = 1;

do
{
	a /= 10;
	q++;
	d *= 10;
}while(a);
d/=10;
long long ret = 0;
for(int i=A; i<=B; i++)
{	
	if(table[i]) continue;
	int c = 0, num=i;
	for(int j=0; j<q; j++)
	{
		if(!table[num])
		{	table[num]= 1;
			if(num >= A && num <=B)
				c++;
		}
		num = (num/10) + (num%10)*d;
	}
	ret += c * (c-1) / 2;
}	
	

Out << "Case #" << h+1 << ": " << ret << endl;

}

In.close();

Out.close();

return 0;

}
 
