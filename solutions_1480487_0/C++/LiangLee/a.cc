#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

#define FOR(i,a,b) for(int i = (a) ; i < (b) ; i ++)
#define REP(i,n) FOR(i, 0, n)
#define ALL(a) (a).begin(),(a).end()
#define SZ(a) ((int)(a).size())
#define pb push_back

string fsmall = "A-small-attempt0.in";
string flarge = "A-large-practice.in";
ofstream fout;
ifstream fin;

void func()
{
	int score[201];
	int sum = 0;
	double total = 0;
	double per[201];
	int n;
	int count;
	double avg;
	fin>>n;
	REP(i,n)
	{
		fin>>score[i];
		sum += score[i];
		per[i] = 100;
	}

	total = sum * 2;
	avg = total/n;
	count = n;
	REP(i,n)
	{
		if (score[i] >= avg)
		{
			per[i] = 0;
			total -= score[i];
			count--;
		}
	}
	avg = total/count;
	REP(i,n)
	{
		if (per[i] > 0)
		{
			per[i] = (avg - score[i])/sum;
		}
	}

	REP(i,n)
	{

		fout<<" "<<setprecision(6)<<per[i]*100;
		//printf(" %.6lf", per[i]);
	}

}

int main()
{
	int n;
	fin.open(fsmall.c_str());
	fout.open("out.txt");
	fin>>n;
	REP(i,n)
	{
		fout<<"Case #"<<i+1<<":";

		func();

		fout<<endl;
	}
	fin.close();
	fout.close();
	return 0;

}