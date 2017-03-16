#include <stdio.h>
#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <set>
#include <map>
#include <queue>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back

typedef long long li;
typedef double ld;
typedef pair <int, int> pi;
int timer=1;
void solve();
int main ()
{
	freopen ("in.txt", "r", stdin);
	freopen ("out.txt", "w", stdout);
	int t;
	cin>>t;
	while (t--)
		solve(), timer++;
	return 0;
}
//#define int li
double a, b;
double p[100500];
double pr[100500];
void solve()
{
	scanf ("%lf%lf", &a, &b);
	for (int i=0; i<a; i++)
		scanf ("%lf", &p[i]);
	pr[0]=p[0];
	for (int i=1; i<a; i++)
		pr[i]=pr[i-1]*p[i];
	double ans=b+2;

	for (int i=0; i<=a; i++)
	{
		double ii=(double)i;
		double cur=(b-ii+a-ii+1);
		double now=((i>0)?pr[i-1]:1.0);
		cur+=(1.0-now)*(b+1);
		ans=min(ans, cur);
	}

	cout<<"Case #"<<timer<<": ";
	printf ("%.9lf", ans);
	cout<<endl;
}
