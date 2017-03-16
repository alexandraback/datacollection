#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <fstream>
#include <math.h>
#include <map>
#include <string>
#include <deque>
#define LL long long int
#define double long double
using namespace std;

void solve(int t)
{
	int a,b,i,j,kol=0,k;
	cin>>a>>b>>k;
	for (i=0; i<a; i++)
		for (j=0; j<b; j++)
			if ((i&j) < k)
			{
				//cout<<i<<" "<< j<<endl;
				kol++;
			}
	cout << "Case #" << t << ": ";
	cout<<kol<<endl;
}

int main()
{
	freopen("B-small-attempt0.in", "r", stdin); freopen("output.txt", "w", stdout);
	int i,t;
	cin>>t;
	for (i=1; i<=t; i++)
		solve(i);
	return 0;
}