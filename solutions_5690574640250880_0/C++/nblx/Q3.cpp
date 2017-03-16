#include <iostream>
#include <iomanip>		// setprecision
#include <string>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <algorithm>		// sort, stable_sort
#include <cstdlib>			// atoi, atof, etc.
#include <cmath>			// floor
using namespace std;
typedef unsigned long long ull_int;

bool solve(int R, int C, int M, vector<string> &res)
{	// res: always return axb, where a<=b
	int t = R*C-M, a=min(R,C), b=max(R,C);
	if (a==1)		// 1xb:  line graph
	{	string tmp("c");
		tmp.append(t-1, '.');
		tmp.append(M, '*');
		res.push_back(tmp);
		return true;
	}
	if (t==1)
	{	string tmp("c");
		tmp.append(b-1, '*');
		res.push_back(tmp);
		for (int i=0; i<a-1; i++)		res.push_back(string(b, '*'));
		return true;
	}
	if (t==2 || t==3 || t==5 || t==7)	return false;
	if (a==2)
	{	if (t&0x1)	// t is odd
			return false;
		else	// t is even
		{	string tmp(t/2, '.');
			tmp.append(b-t/2, '*');
			res.push_back(tmp);
			res.push_back(tmp);
			res[0][0] = 'c';
			return true;
		}
	}
	// a>=3
	int q=t/a, r=t%a;
	int aa, bb, rr, dd;
	if (q<=1)
	{	bb = 2;
		dd = 0;
		if (t&0x1)	// t%2==1
		{	rr = 3;
			aa = (t-3)/2;
		} else		// t%2==0
		{	rr = 0;
			aa = t/2;
		}
	} else		// q>=2
	{	bb = q;
		if (r==1)
		{	if (q==2)
			{	dd = 0;
				rr = 3;
				aa = a-1;
			} else	// q>=3
			{	rr=2;
				aa = a-1;
				dd = q-1;
			}
		} else	// r==0  or  r>=2
		{	rr = r;
			aa = a;
			dd = 0;
		}
	}
	// draw block:  aa x bb  plus a last column containing  rr  '.'  plus a last row containing dd '.'
	string tmp;
	if (bb<b)
	{
		tmp.append(bb+1, '.');
		tmp.append(b-bb-1, '*');
	} else	// bb==b;  in this case   aa==a, t==R*C, M=0
		tmp.append(b, '.');
	for (int i=0; i<rr; i++)		res.push_back(tmp);
	if (bb<b)		tmp[bb] = '*';
	for (int i=0; i<aa-rr; i++)	res.push_back(tmp);
	if (dd>0)
	{	aa++;
		string temp(dd, '.');
		temp.append(b-dd, '*');
		res.push_back(temp);
	}
	for (int i=0; i<a-aa; i++)	res.push_back(string(b, '*'));
	res[0][0] = 'c';
	return true;
}


int main()
{
	ifstream infile;
	infile.open("C-small-attempt1.in");
	ofstream outfile;
	outfile.open("small.out");
	int nCases;
	infile >> nCases;
	infile.ignore(10,'\n');
	for (int t=1; t<=nCases; t++)
	{
		int R, C, M;
		infile >> R >> C >> M;
		infile.ignore(10,'\n');		
		
		outfile << "Case #" << t << ":" << endl;
		vector<string> res;
		bool succ = solve(R, C, M, res);
		if (succ)		// succeed
		{	
			if (R<=C)
			{
				for (int i=0; i<R; i++)
					outfile << res[i] << endl;				
			} else	// C<R: transpose the result
			{	for (int i=0; i<R; i++)
				{
					for (int j=0; j<C; j++)		
						outfile << res[j][i];
					outfile << endl;
				}
			}
		} else
			outfile << "Impossible" << endl;

		// cout << "Case #" << t << ":" << fixed  << res << endl;
	}
	infile.close();
	outfile.close();
	char c;
	cin >> c;
	return 0;
}