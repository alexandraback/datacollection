#include <iostream>
#include <vector>
#include <stdio.h>
#include <set>
#include <stdlib.h>
using namespace std;

vector<long long> p;
set<long long> ps;

int isnotprime(long long n)
{
	if (ps.find(n) != ps.end())
		return 0;
	for(int i=0; i<p.size(); i++)
		if (n%p[i] == 0)
			return p[i];
	return 0;
}

long long ston(string s, int base)
{
	long long r = 0;
	for(int i=0; i<s.size(); i++)
	{
		r*=base;
		if (s[i] == '1')
			r += 1;
	}
//	printf("%s %d %d %lld\n", s.c_str(), base, s.size(), r);
	return r;
}

int main()
{
	srand(time(NULL));
	int i,j,k;
	p.push_back(2);
	p.push_back(3);
	for(long long n=5; n<65537; n+=2)
	{
		for(i=0; i<p.size(); i++)
		{
			if (n%p[i] == 0)
				break;
			if (p[i]*p[i] > n) break;
		}
		if (p[i]*p[i] > n)
			p.push_back(n);
	}
	for(i=0; i<p.size(); i++)
		ps.insert(p[i]);

	int cc,ca;
	cin >> ca;
	for(cc=1; cc<=ca; cc++)
	{
		int N,J;
		cin >> N >> J;
		set<string> visited;
		string s = "";
		for(int i=0; i<N; i++)
			s.push_back('0');
		s[0] = s[N-1] = '1';
		printf("Case #%d:\n", cc);
		while(J > 0)
		{
			for(i=1; i<N-1; i++)
				s[i] = rand()%2 + '0';
			if (visited.find(s) != visited.end())
				continue;
			visited.insert(s.c_str());

			vector<long long> r;
			for(i=2; i<=10; i++)
			{
				long long nb = ston(s, i);
				long long tr = isnotprime(nb);
//				printf("%lld %lld\n", nb, tr);
				if (tr == 0)
					break;
				else
				{
					r.push_back(tr);
				}
			}
			if (r.size() == 9)
			{
				printf("%s", s.c_str());
				for(i=0; i<9; i++)
					printf(" %lld", r[i]);
				printf("\n");
				J--;
			}
		}
	}
}
