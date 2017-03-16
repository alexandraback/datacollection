#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bitset>

#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
const ld epsylon = 1e-9;
typedef unsigned int ui;
//inline long double get_time(){   
//	return (long double)clock()/CLOCKS_PER_SEC;
//};
//ld start_time,end_time;

unsigned long long choose(unsigned long long n, unsigned long long k) {
    if (k > n) {
        return 0;
    }
    unsigned long long r = 1;
    for (unsigned long long d = 1; d <= k; ++d) {
        r *= n--;
        r /= d;
    }
    return r;
}
#define INF 1000000000
int n, t;
int A[1024], B[1024];
bool marked[1024];
int stars;

int mn(int * a)
{
	int res = 0;
	for (int i = 1; i < n; ++i)
	{	
		if (a[i] < a[res]) res = i;
	}
	return res;
}	

int mna()
{
	int res = 0;
	for (int i = 0; i < n; ++i) 
		if (A[i] <= stars) res = i;
	for (int i = 0; i < n; ++i)
	{
		if (A[i] <= stars)
		{
			if (B[res] < B[i])
			{
				res = i;
			}
		}
	}
	return res;
}

int main()
{
	freopen("input.in","r",stdin);
	freopen("output.out","w",stdout);
	//start_time = get_time();
	//program
	
	cin >> t;
	for (int i = 1; i <= t; ++i)
	{
		cin >> n;
		memset(marked, 0, sizeof(marked));
		for (int j = 0; j < n; ++j)
			cin >> A[j] >> B[j];
		stars = 0;
		int br = 0, levels = 0;
		while (br < n)
		{
			
			int k = mn(B);
			if (B[k] <= stars)
			{
				B[k] = INF;
				if (A[k] == INF) stars++;
				else stars += 2;
				A[k] = INF;
				br++;
				marked[k] = 1;
				levels++;
			} else 
			{
				k = mna();
				if (A[k] <= stars)
				{
					A[k] = INF;
					stars++;
					levels++;
				}
				else br = -1;
			}
			if (br < 0) break;
		}
		//if (stars != 2*n) cerr << "something gone wrong";
		if (br >= 0)
			printf("Case #%d: %d\n", i, levels);
		else	printf("Case #%d: Too Bad\n", i);
	}
	//end program
	//end_time=get_time()-start_time;
	return 0;
}