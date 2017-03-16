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

string fsmall = "C-small-attempt0.in";
string flarge = "A-large.in";

ofstream fout;
ifstream fin;
const int max_len = 1<<20;
long buf[max_len];
int func()
{
	int n;
	int i,j;
	int len;
	int data[50];
	fin>>n;
	len = 1 << n;
	for (i = 0; i < n ; i++)
	{
		fin>>data[i];
	}
	memset(buf, 0, sizeof(buf));
	for (i = 0; i < len ; i++)
	{
		for (j = 0 ; j < n ; j++)
		{
			if (i & (1 << j))
				buf[i] += data[j];
		}
	}
	for (i = 1; i < len ; i++)
	{
		for (j = i+1; j < len ; j++)
		{
			if (buf[i] == buf[j])
				break;
		}
		if (j < len)
		{
			break;
		}
	}
	if (buf[i] != 0 && buf[j] != 0)
	{
		fout<<endl;
		for (int k = 0 ; k < n ; k++)
		{
			if (i & (1 << k))
				fout<<" "<<data[k];
			fout.flush();
		}
		fout<<endl;
		for (int k = 0 ; k < n ; k++)
		{
			if (j & (1 << k))
				fout<<" "<<data[k];
			fout.flush();
		}
	} 
	else
	{
		fout<<endl;
		fout<<"Impossible";
	}
	//fout<<buf[i]<<buf[j];
	return 0;
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