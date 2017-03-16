#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
using namespace std;

#include <algorithm>
#include <complex>
#include <exception>
#include <list>
#include <stack>
#include <bitset>
#include <csetjmp>
#include <fstream>
#include <locale>
#include <stdexcept>
#include <cassert>
#include <csignal>
#include <functional>
#include <map>
#include <cctype>
#include <cstdarg>
#include <iomanip>
#include <memory>
#include <streambuf>
#include <cerrno>
#include <cstddef>
#include <ios>
#include <new>
#include <string>
#include <cfloat>
#include <cstdio>
#include <iosfwd>
#include <numeric>
#include <typeinfo>
#include <ciso646>
#include <cstdlib>
#include <iostream>
#include <ostream>
#include <utility>
#include <climits>
#include <cstring>
#include <istream>
#include <queue>
#include <valarray>
#include <clocale>
#include <ctime>
#include <iterator>
#include <set>
#include <vector>
#include <cmath>
#include <deque>
#include <limits>
#include <sstream>

#define pb push_back
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
#define sz size()
#define FOR(i,m) for(int i=0;i<(int)(m);i++)
#define FOR2(i,n,m) for(int i=n;i<(int)(m);i++)
#define ITER(it,c) for(auto it=c.begin();it!=c.end();++it)
#define RITER(it,c) for(auto it=c.rbegin();it!=c.rend();++it)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
#define X real()
#define Y imag()
#define length(V) (hypot((V).X,(V).Y))
#define vect(a,b) ((b)-(a))
#define cross(a,b) ((conj(a)*(b)).imag())
#define normalize(v) ((v)/length(v))
#define rotate(p,about,theta) ((p-about)*exp(point(0,theta))+about)
#define pointEqu(a,b) (comp(a.X,b.X)==0 && comp(a.Y,b.Y)==0)

int nrTest;

class Solver{
	int m_test;
protected:
	FILE* m_input;
	FILE* m_output;
public:

	Solver() :m_input(stdin), m_output(stdout)
	{
	}

	void setInput(FILE* in)
	{
		m_input = in;
	}

	void setOutput(FILE* out)
	{
		m_output = out;
	}

	void setTest(int test)
	{
		m_test = test;
	}

	void readAndSolve()
	{
		init();
		readInput();
		solve();
		fprintf(m_output, "Case #%d: ", m_test);
		writeOutput();
	}

	virtual void readInput() = 0;
	virtual void solve() = 0;


	virtual void writeOutput() = 0;


	virtual void init() = 0;
};

class CustomSolver :public Solver
{
	int m_n;
	vector<int> m_BFF;
	vector<int> m_fromBFF[3000];
	bool m_partofchain[3000];
	int m_solution;
public:
	void init()
	{
		m_solution = 0;
		m_BFF.clear();
		FOR(i, m_n)
			m_fromBFF[i].clear();
	}

	void readInput()
	{
		fscanf(m_input, "%d", &m_n);
		FOR(i, m_n)
		{
			int a;
			fscanf(m_input, "%d", &a);
			m_BFF.push_back(a-1);
			m_fromBFF[a - 1].push_back(i);
		}
	}

	// SOLUTION IS HERE!
	void solve()
	{
		int visited_at[3000];
		m_solution = 0;


		vector<int> chain;
		FOR(i, m_n)
		{
			FOR(i, 3000)
			{
				visited_at[i] = 0;
				m_partofchain[i] = false;
			}
			chain.clear();

			int crt = i;
			int cnt = 0;
			int last = i;

			while (visited_at[crt] == 0)
			{
				visited_at[crt] = ++cnt;				
				chain.push_back(crt);
				if ((cnt > 1) && (m_BFF[crt]==last))
				{
					ITER(ng,m_fromBFF[crt])
					{
						if (visited_at[*ng] == 0)
						{
							chain.push_back(*ng);
							m_solution = max(m_solution, cnt + 1);
							break;
						}
					}
					m_solution = max(m_solution, cnt);
					ITER(c, chain)
					{
						m_partofchain[*c] = true;
					}
				}
				
				last = crt;
				crt = m_BFF[crt];
			}
			m_solution = max(m_solution, cnt - visited_at[crt] + 1);

		}
		int chainl = 0;
		FOR(i, 3000)
			chainl += m_partofchain[i];
		m_solution = max(m_solution, chainl);

	}

	void writeOutput()
	{
		fprintf(m_output, "%d\n", m_solution);
	}
};

int main()
{
	FILE* f = fopen("input.txt", "rt");
	FILE* fout = fopen("output.txt", "wt");

	fscanf(f, "%d", &nrTest);
	FOR(i, nrTest)
	{
		CustomSolver solver;
		solver.setTest(i + 1);
		solver.setInput(f);
		solver.setOutput(fout);
		solver.readAndSolve();
	}
	fclose(f);
	fclose(fout);
}
