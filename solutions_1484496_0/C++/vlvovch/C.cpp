#include <cstdio>
#include <iostream>
#include <fstream>
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
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int T;
int N;
vector<int> nmbs;
vector<int> sol1;
vector<int> sol2;
vector<int> wrk1;
vector<int> wrk2;
bool fsol = 0;

void go1(int n);
void go2(int n);

void go1(int n)
{
	if (fsol) return;
	if (n==N) 
	{
		go2(0);
		return;
	}
	wrk1[n] = 0;
	go1(n+1);
	if (fsol) return;
	wrk1[n] = 1;
	go1(n+1);
	return;
}

void go2(int n)
{
	if (fsol) return;
	if (n==N)
	{
		int sum1 = 0, sum2 = 0;
		rep(i,N) if (wrk1[i]) sum1 += nmbs[i];
		rep(i,N) if (wrk2[i]) sum2 += nmbs[i];
		if (sum1==sum2 && sum1>0)
		{
			sol1 = wrk1;
			sol2 = wrk2;
			fsol = 1;
			return;
		}
		return;
	}
	wrk2[n] = 0;
	go2(n+1);
	if (fsol) return;
	if (wrk1[n]==0)
	{
		wrk2[n] = 1;
		go2(n+1);
	}
	return;
}


int main()
{
    fstream fin("C-small-attempt0.in",ifstream::in);
    fstream fout("C-small-attempt0.out",ofstream::out);
    fin >> T;
    for(int j=1;j<=T;j++)
    {
		fin >> N;
		nmbs.resize(N);
		rep(i,N) fin >> nmbs[i];
		fsol = 0;
		wrk1.resize(N);
		rep(i,N) wrk1[i] = 0;
		wrk2 = sol1 = sol2 = wrk1;
		go1(0);
		int sum1 = 0;
		rep(i, N) if (sol1[i]) sum1 += nmbs[i];
		if (sum1==0) fout << "Case #" << j << ":\nImpossible\n";
		else
		{
			fout << "Case #" << j << ":\n";
			rep(i,N) if (sol1[i]) fout << nmbs[i] << " ";
			fout << "\n";
			rep(i,N) if (sol2[i]) fout << nmbs[i] << " ";
			fout << "\n";
		}
    }
    fin.close();
    fout.close();
    cout << "running time=" << clock()/(double)CLOCKS_PER_SEC;
    system("PAUSE");
    return 0;
}
