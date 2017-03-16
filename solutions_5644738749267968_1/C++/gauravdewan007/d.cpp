#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>

#include <cmath>
#include <cstring>
using namespace std;


#if 0
#include "generic.h"
#define cin fin
#define cout fout
#endif

int play(double* k, double* na, int n)
{
	double* lb=k;
	double* ub=k+n;
	int p = 0;
	for(;p<n && lb!=ub;p++)
	{
		lb = lower_bound(lb, ub, na[p]);
		if(lb == ub)
			break;
		lb++;
	}
	return p;
}
#define N 1002
double ken[N], naomi[N];
int main()
{
	int t,c;
	cin>>t;
	for(c=1;c<=t;c++)
	{
		int n,i;
		cin>>n;
		for(i=0;i<n;i++)
			cin>>naomi[i];
		for(i=0;i<n;i++)
			cin>>ken[i];
		sort(&ken[0], &ken[n]);
		sort(&naomi[0], &naomi[n]);
		int op = play(&ken[0], &naomi[0], n); //return kens points in optimal play
		int dp = play(&naomi[0], &ken[0], n); //return naomis points in deceitful play
		
		cout<<"Case #"<<c<<": ";
		cout<<dp<<" "<<n-op;
		
		cout<<endl;
	}
	return 0;
}