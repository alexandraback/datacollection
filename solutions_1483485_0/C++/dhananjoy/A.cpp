

#include <iostream>
#include <vector>
#include <cstring>
#include <cstdio>
#include <string>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <queue>
#include <deque>
#include <fstream>
#include <limits>


#define Long unsigned long long
#define pi pair <int, int>
#define Point pair <double, double>
#define vi vector < int >
#define vvi vector < vi >
#define vpi vector < pi >
#define X first
#define Y second
#define all(v) (v).begin(), (v).end()
#define forall(i,n) for( int i = 0; i < n; ++i )
#define Forall(i,a,b) for( int i = a; i < b; ++i )
#define pb push_back
#define mp make_pair

using namespace std;


ofstream out ("A.out");
ifstream in ("A.in");


int main (int argc, char const* argv[])
{
	char map[300];
	string A = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
	string B = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
	for (int i = 0; i < A.size(); i += 1)
	{
		map[A[i]] = B[i];
	}
	map['z'] = 'q';
	map['q'] = 'z';
	
	int T;
	in >> T;
	getline(in,A);
	for (int t = 1; t <= T; t += 1)
	{
		getline(in,A);
		out << "Case #" << t << ": ";
		for (int i = 0; i < A.size(); i += 1)
		{
			out << map[A[i]];
		}
		out << '\n';
	}
	return 0;
}


