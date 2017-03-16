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

#define	SAFE_DELETE(ptr) if(ptr){delete ptr; ptr=NULL;}
#define	SAFE_DELETE_ARRAY(ptr) if(ptr){delete [] ptr; ptr=NULL;}

using namespace std;

int main()
{
	freopen("datain.txt", "r", stdin);
	freopen("dataout.txt", "w", stdout);

	int T; cin >> T;

	for (int i=0; i<T; i++)
	{
		double C, F, X;
		cin >> C >> F >> X;

		int N = 0;
		double delta, rst(0.0);
		do 
		{
			delta = C / (2.0 + N*F) - F*X / (4.0 + 4.0*N*F + 2.0*F + F*F*N*(N+1));
			N++;
		} while (delta < 0);
		N--;

		rst += X / (2.0+N*F);

		for (int j=0; j<=N-1; j++)
		{
			rst += C / (2.0+j*F);
		}

		cout << "Case #" << (i+1) << ": ";
		char str[300];
		sprintf(str, "%.7lf", rst);
		cout << str << endl;
	}

	fclose(stdout);
	fclose(stdin);
	return 1;
}