#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <cmath>
#include <set>
using namespace std;
const int maxn = 105; 
int type['Z'+5]; 
char str[maxn]; 
const double EPS = 1E-9; 

int findLenth()
{
	int i, j, n = strlen(str); 
	for (i=1; i<n; i++)
	{
		for (j=0; i+j < n; j++)
		{
			//if (i + j == n) return i; 
			if (str[i+j] != str[j]) break; 
		}
		if (i+j == n) return i; 
	}
	return n; 
}
double findFactor(int val, int k)
{
	int i, j, n = strlen(str); 
	double ans = val; 
	for (i=0; i<n; i++)
	{
		//cout << type[str[i]] << endl; 
		ans *= (double)type[str[i]] / k; 
	}
	return ans; 
}
bool checkInpossible()
{
	int i, j, n = strlen(str); 
	for (i=0; i<n; i++)
	{
		if (type[str[i]] == 0) return true; 
	}
	return false; 
}

int main()
{
	int T, I=0, k, l, s, x, i; 
	double ans, fac; 
	scanf ("%d", &T); 
	while (I++ < T)
	{
		scanf ("%d%d%d", &k, &l, &s); 

		scanf ("%s", str); 
		memset (type, 0, sizeof (type)); 
		for (i=0; str[i]; i++) type[str[i]]++; 

		scanf ("%s", str); 
		if (checkInpossible())
			printf ("Case #%d: %.7lf\n", I, 0.0);
		else{

			fac = findFactor(s - l + 1, k); 
			x = findLenth(); 

			//cout << x << " " << fac << endl; 
			//cout << (s - l) / x + 1 << endl; 

			ans = (s - l) / x + 1 - fac; 

			printf ("Case #%d: %.7lf\n", I, ans+EPS); 
		}
	}
}