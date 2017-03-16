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



class SlidesSolver :public Solver
{
	int b,m;
	int m_solution[51][51];
	bool solution;

	long long set(long long mask,int i)
	{
		mask |= 1LL<<((b-1)-i);
		return mask;
	}
	long long unset(long long mask, int i)
	{
		mask &= ~(1LL << ((b - 1) - i));
		return mask;
	}
public:
	void init()
	{
		b = 0;
		m = 0;
		solution = true;
		FOR(i, 51)
			FOR(j, 51)
			m_solution[i][j] = 0;
	}

	void readInput()
	{
		fscanf(m_input, "%d %d", &b,&m);
	}

	

	// SOLUTION IS HERE!
	void solve()
	{
		long long mask = 0;
		mask = set(mask, 2);
		mask = unset(mask, 2);
		cout << "mask:" << mask << std::endl;
		if ((1LL << (b - 2)) < m)
		{
			solution = false;
		}

		FOR(i, b - 1)
		{
			m_solution[i][i + 1] = 1;
		}
		
		
		FOR2(i,2, b)
			FOR2(j, i+1, b)
			{
				long long mask = 0;
				//FOR(k, b - 2)
					//mask += 1LL << k;
				FOR2(k, 2, b)
					mask = set(mask, k);
				std::cout << "set" << i << " and " << j << " mask: " << mask << std::endl;

				FOR2(k, i+1, j)
					mask = unset(mask, k);
				
				if (mask > ((1LL << (b-2))) - 1 - m)
					m_solution[i-1][j-1] = 1;
				std::cout << "unset" << i << " and " << j << " mask: "<< mask <<std::endl;
			}
		std::cout << "limit" << (1LL << (b - 2)) - 1 - m << std::endl;

		FOR2(i, 2, b)
		{
			long long mask = 0;
			FOR2(k, 2, i+1)
				mask = set(mask, k);
			std::cout << "unset" << i << " and " << b << " mask: " << mask << std::endl;
			if (mask > ((1LL << (b-2))) - 1 - m)
				m_solution[i-1][b-1] = 1;
			mask = 0;
			FOR2(k, i,b)
				mask = set(mask, k);
			//std::cout << "unset" << 1 << " and " << i << " mask: " << mask << std::endl;
			if (mask > (1LL << (b - 2)) - 1 - m)
			{
				//std::cout << "ok" << 0 << " and " << i-1<< std::endl;
				m_solution[0][i - 1] = 1;
			}
		}
		if (0>(1LL << (b - 2)) - 1 - m)
			m_solution[0][b-1] = 1;

	}

	void writeOutput()
	{
		if (solution)
		{
			fprintf(m_output, "POSSIBLE\n");
			FOR(i, b)
			{
				FOR(j, b)
				{
					fprintf(m_output, "%d", (m_solution[i][j]));
				}
				fprintf(m_output, "\n");
			}
		}
		else
		{
			fprintf(m_output, "IMPOSSIBLE\n");
		}
		
	}
};

int main()
{
	FILE* f = fopen("input.txt", "rt");
	FILE* fout = fopen("output.txt", "wt");

	fscanf(f, "%d", &nrTest);
	FOR(i, nrTest)
	{
		SlidesSolver solver;
		solver.setTest(i + 1);
		solver.setInput(f);
		solver.setOutput(fout);
		solver.readAndSolve();
	}
	fclose(f);
	fclose(fout);
}
