#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <direct.h>
#include <assert.h>
#include <time.h>

#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <queue>
#include <set>
#include <bitset>
#include <exception>
#include <memory>
#include <numeric>
#include <limits>
#include <functional>
#include <stack>
#include <iterator>
#include <random>
#include <unordered_map>
#include <unordered_set>

#include <cctype>
#include <cstddef>
#include <cstring>
#include <ctime>

#define NOMINMAX
#include <windows.h>

#define	SAFE_DELETE(ptr) if(ptr){delete ptr; ptr=NULL;}
#define	SAFE_DELETE_ARRAY(ptr) if(ptr){delete [] ptr; ptr=NULL;}

using namespace std;

typedef long long INT64;
INT64 foo(INT64 a,INT64 b);
void run(INT64 P, INT64 Q, INT64 RST=0);

int main()
{
	freopen("datain.txt","r",stdin);
	freopen("dataout.txt","w",stdout);
	
	int T; cin >> T;
	INT64 P,Q;
	for (int i = 1; i <= T; ++i)
	{
		scanf("%I64d/%I64d",&P, &Q);
		printf("Case #%d: ",i);
		run(Q, P);
	}
	return 0;
}

INT64 foo(INT64 a,INT64 b)
{
	if ( b==0 )
		return a;
	else
		return foo(b, a%b);
}

void run(INT64 Q, INT64 P, INT64 RST)
{
	RST++;
	INT64 x = foo(P, Q);

	P = P/x; Q = Q/x;
	INT64 temp_val = Q;
	while (temp_val %2 == 0)
	{
		temp_val >>= 1;
	}

	if (temp_val != 1)
	{
		cout << "impossible" << endl;
		return;
	}

	INT64 var_num = 0;
	temp_val = Q;
	while (temp_val > P)
	{
		temp_val >>= 1;
		var_num++;
	}

	if (RST = 10)
		RST = 0;

	printf("%I64d\n",var_num);
}