/*
*/

//#pragma comment(linker, "/STACK:16777216")
#define _CRT_SECURE_NO_WARNINGS

#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define norm asdfasdgasdgsd

#define eps 1e-9
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

const int INF = 1e9;

const int N = 1000;

int tests;
int st;
int tes;
long long best_dif, best_score1, best_score2;
int ts;
string best_st1, best_st2;

string greedy_max(string st, int start)
{
	for (int i = start; i < st.size(); i++)
	{
		if (st[i] == '?')
			st[i] = '9';
	}
	return st;
}

string greedy_min(string st, int start)
{
	for (int i = start; i < st.size(); i++)
	{
		if (st[i] == '?')
			st[i] = '0';
	}
	return st;
}

long long eval(string st)
{
	long long res = 0;
	for (int i = 0; i < st.size(); i++)
		res = res * 10 + st[i] - 48;
	return res;
}

bool best(long long a, long long b)
{
	long long here = abs(a - b);
	if (here != best_dif)
		return (here < best_dif);
	if (a != best_score1)
		return (a < best_score1);
	if (b != best_score2)
		return b < best_score2;
	return false;
}

void run_eval(string st1, string st2)
{
	long long val1 = eval(st1);
	long long val2 = eval(st2);
	if (best(val1, val2))
	{
		best_dif = abs(val1 - val2);
		best_score1 = val1;
		best_score2 = val2;
		best_st1 = st1;
		best_st2 = st2;
	}
}
void solve(string st1, string st2, int start)
{
	if (start == st1.size())
		run_eval(st1, st2);
	
	//if (ts == 7)
		//cout << "!" << st1 << " " << st2 << "%" << start << endl;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == j)
				continue;
			if (st1[start] != '?'&&st1[start] != i + 48)
				continue;
			if (st2[start] != '?'&&st2[start] != j + 48)
				continue;

			string memo1 = st1;
			string memo2 = st2;

			st1[start] = i + '0';
			st2[start] = j + '0';
			string temp1, temp2;
			if (i < j)
			{
				temp1 = greedy_max(st1,start+1);
				temp2 = greedy_min(st2, start + 1);
			}
			else
			{
				temp1 = greedy_min(st1, start + 1);
				temp2 = greedy_max(st2, start + 1);
			}
			//if (ts == 7)
			//	cout<<start<<" "<<i<<" "<<j<<" "<< temp1 << "  " << temp2 << " "<<st1<<" "<<st2<<endl;

			run_eval(temp1, temp2);
			st1 = memo1;
			st2 = memo2;
		}
	}
}

int main(){
	//freopen("fabro.in","r",stdin);
	//freopen("fabro.out","w",stdout);
	freopen("F:/in.txt", "r", stdin);
	freopen("F:/out.txt", "w", stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);

	cin >> tests;
	for (; tests; --tests)
	{
		++ts;
		string st1, st2;
		cin >> st1 >> st2;
		best_dif = 3e18;
		best_score1 = 3e18;
		best_score2 = 3e18;
		
		for (int com_pref = 0; com_pref <= st1.size(); com_pref++)
		{
			string temp1 = st1;
			string temp2 = st2;
			bool shit = 0;

			for (int i = 0; i < com_pref; i++)
			{
				if (temp1[i] != '?'&&temp2[i] != '?'&&temp1[i] != temp2[i])
					shit = 1;
				if (temp1[i] != '?')
					temp2[i] = temp1[i];
				if (temp2[i] != '?')
					temp1[i] = temp2[i];
			}
			if (shit)
				continue;
			for (int i = 0; i < com_pref; i++)
			{
				if (temp1[i] == '?')
					temp1[i] = '0';
				if (temp2[i] == '?')
					temp2[i] = '0';
			}

			//if (ts == 7)
				//cout << "@" << temp1 << " " << temp2 << " " << com_pref << endl;
			solve(temp1, temp2, com_pref);
		}
		cout << "Case #" << ts << ": " << best_st1 << " " << best_st2 << endl;

	}

	cin.get(); cin.get();
	return 0;
}