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
	
int N;

In >> N;

vector<int> onestar(N, 0), twostar(N, 0);

for(int i=0; i<N; i++)
	In >> onestar[i] >> twostar[i];

int ret = 0, curstar = 0;
int flag = true;
while(flag)
{
	flag = false;
	for(int i=0; i<N; i++)
		if(curstar >= twostar[i] && twostar[i] > -1)
		{	curstar++;
			twostar[i]=-1000;
			if(onestar[i] > -1)
			{	curstar++;
				onestar[i] = -1000;
			}
			ret++;
			flag = true;
			break;
		}
	if(flag) continue;
	int bi = -1;
	for(int i=0; i<N; i++)
		if(curstar >= onestar[i] && onestar[i] > -1)
		{	
			if(bi==-1)
				bi = i;
			else if(twostar[bi] < twostar[i])
				bi = i;
		}
	if(bi > -1)
	{
			curstar++;
			onestar[bi]=-1000;
			flag = true;
			ret++;
	}

}

flag = true;
for(int i=0; i<N; i++)
	if(twostar[i] > -1)
		flag = false;


if(flag)
Out << "Case #" << h+1 << ": " << ret << endl;
else
Out << "Case #" << h+1 << ": Too Bad" << endl;

}

In.close();

Out.close();

return 0;

}
 
