#include <iostream>
#include <iomanip>		// setprecision
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>			// map, unordered_map
#include <set>			// set, unordered_set
#include <algorithm>	// sort, stable_sort
#include <cstdlib>		// atoi, atof, etc.
using namespace std;

#define INT_MAX       2147483647

int GCD(int a, int b)
{
	return b==0 ? a : GCD(b, a%b);
}



typedef unsigned long long ull_int;

struct T
{
	int d;		// initial day
	int n;		// #attacks
	int w;	// west of initial attack
	int e;		// east of initial attack
	int s;		// strength of initial attack
	int delta_d;	// delta of days
	int delta_p;	// delta of eastward
	int delta_s;		// delta of strength
	T() 
	{	d=0;
		n=0;
		w=0;
		e=0;
		s=0;
		delta_d=0;
		delta_p=0;
		delta_s=0;
	}
	// bool operator<(const T &b) const  { return y<b.y; }
};

bool check(int *wall, int w, int e, int s)
{	// true if attack succeeds
	for (int i=w+200; i<e+200; i++)
		if (wall[i]<s)	return true;
	return false;
}
bool finished(vector<int> &done, vector<T> &tribes)
{	// false if any one tribe hasn't finished all attacks
	for (int i=0; i<tribes.size(); i++)
		if ( done[i]<tribes[i].n )
			return false;
	return true;
}
void update_wall(int *wall, int w, int e, int s)
{	// update wall[] in between [w, e] at strength s
	for (int i=w+200; i<e+200; i++)
		wall[i] = max(wall[i], s);
}

int solve(vector<T> &tribes)
{
	int wall[401] = {0}, result=0, i, j;		// notice wall[i] represents the height of wall[i,i+1]
	int N=tribes.size();		// #tribes
	vector<int> done(N,0);	// #attacks finished by each tribe
	while ( !finished(done, tribes) )
	{
		int cur=INT_MAX;
		for (i=0; i<N; i++)		// search for the nearest attack date
			if (done[i]<tribes[i].n)
				cur = min(cur, tribes[i].d+done[i]*tribes[i].delta_d);
		for (i=0; i<N; i++)		// there may be multiple attacks on the same day "cur"
		{
			if (done[i]<tribes[i].n && cur==tribes[i].d+done[i]*tribes[i].delta_d)	// tribes[i] has attack
			{
				if (check(wall, tribes[i].w+done[i]*tribes[i].delta_p, tribes[i].e+done[i]*tribes[i].delta_p, tribes[i].s+done[i]*tribes[i].delta_s) )
					result++;				
			}
		}
		for (i=0; i<N; i++)		// there may be multiple attacks on the same day "cur"
		{
			if (done[i]<tribes[i].n && cur==tribes[i].d+done[i]*tribes[i].delta_d)	// tribes[i] has attack
			{
				if (check(wall, tribes[i].w+done[i]*tribes[i].delta_p, tribes[i].e+done[i]*tribes[i].delta_p, tribes[i].s+done[i]*tribes[i].delta_s) )
					update_wall(wall, tribes[i].w+done[i]*tribes[i].delta_p, tribes[i].e+done[i]*tribes[i].delta_p, tribes[i].s+done[i]*tribes[i].delta_s);
				done[i]++;
			}
		}
	}
	return result;
}

int main()
{
	ifstream infile;
	infile.open("C-small-attempt0.in");
	ofstream outfile;
	outfile.open("small.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		int n;
		infile >> n;
		infile.ignore(10,'\n');
		vector<T> tribes(n,T());
		for (int i=0; i<n; i++)
		{
			infile >> tribes[i].d >> tribes[i].n >> tribes[i].w >> tribes[i].e >> tribes[i].s >> tribes[i].delta_d >> tribes[i].delta_p >> tribes[i].delta_s;
			infile.ignore(10,'\n');
		}
		int result = solve(tribes);
		outfile << "Case #" << t << ": " << result << endl;
		cout << "Case #" << t << " solved!\n";
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}