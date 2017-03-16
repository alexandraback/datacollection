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

class RankSolver :public Solver
{
	int m_n;
	int m_cnt[3000];
	vector<int> m_solution;
	vector< vector<int> > m_list;

public:
	void init()
	{
		m_solution.clear();
		FOR(i, 3000)
			m_cnt[i] = 0;
	}

	void readInput()
	{
		fscanf(m_input, "%d", &m_n);
		FOR(i,2*m_n-1)
		{
			vector<int> l; 
			FOR(i, m_n)
			{
				int v;
				fscanf(m_input, "%d", &v);
				l.push_back(v);
				m_cnt[v]++;
			}
			m_list.push_back(l);
		}
	}

	// SOLUTION IS HERE!
	void solve()
	
	{
		/*
		sort(m_list.begin(), m_list.end());
		ITER(l, m_list)
		{
			FOR(i, l->size())
				std::cout << (*l)[i] << " ";
			std::cout << std::endl;
		}*/
		FOR(i, 3000)
			if (m_cnt[i] % 2)
				m_solution.push_back(i);
	}


	void writeOutput()
	{
		ITER(s,m_solution)
			fprintf(m_output, "%d ", *s);
		fprintf(m_output, "\n");
	}
};

int main()
{
	FILE* f = fopen("input.txt", "rt");
	FILE* fout = fopen("output.txt", "wt");

	fscanf(f, "%d", &nrTest);
	FOR(i, nrTest)
	{
		RankSolver solver;
		solver.setTest(i + 1);
		solver.setInput(f);
		solver.setOutput(fout);
		solver.readAndSolve();
	}
	fclose(f);
	fclose(fout);
}
