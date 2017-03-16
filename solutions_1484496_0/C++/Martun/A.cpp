#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>

using namespace std;

struct indexes
{
	short ind[501];
	long long sum;
	int count;

	bool operator<(const indexes& other) const
	{
		return sum < other.sum;
	}
};

long long s[502];
int n;
const long long p = 8677;
bool m[501][p + 1];

std::set<indexes> d;

indexes current;

short current_set[501];
bool FIN_FLAG;
void print_solution(const indexes& p1, const indexes& p2)
{
	bool used1[502];
	bool used2[502];

	memset(used1, false, sizeof(used1));
	memset(used2, false, sizeof(used2));
	int i;
	for (i = 0; i < p1.count; ++i)
	{
		used1[p1.ind[i]] = true;
	}
	for (i = 0; i < p2.count; ++i)
	{
		used2[p2.ind[i]] = true;
	}
	
	bool first_time = true;
	for (i = 1; i <= n; ++i)
	{
		if (used1[i] && !used2[i])
		{
			if (!first_time)
			{
				std::cout << ' ';
			}
			std::cout << s[i];
			first_time = false;
		}
	}
	std::cout << "\n";
	
	first_time = true;
	for (i = 1; i <= n; ++i)
	{
		if (used2[i] && !used1[i])
		{
			if (!first_time)
			{
				std::cout << ' ';
			}
			std::cout << s[i];
			first_time = false;
		}
	}
	std::cout << "\n";
}

void read()
{
	int i;
	cin >> n;
	for (i = 1; i <= n; ++i)
	{
		cin >> s[i];
	}
}
void add_all_sets(int i1, int j1)
{
	if (FIN_FLAG)
	{
		return;
	}
	if ((j1 == 0) && (i1 == 0))
	{
		if (d.find( current) == d.end())
		{
			d.insert(current);
		}
		else
		{
			print_solution(current, *d.find( current));
			FIN_FLAG = true;
			return;
		}

		return ;
	}
	if (m[i1 - 1][j1])
	{
		add_all_sets(i1 - 1, j1);
		if (FIN_FLAG)
		{
			return;
		}
	}
	if (m[i1 - 1][(p + j1 - (s[i1] % p)) % p])
	{
		current.ind[current.count] = i1;
		++current.count;
		current.sum += s[i1];

		add_all_sets(i1 - 1, (p + j1 - (s[i1] % p)) % p);
		if (FIN_FLAG)
		{
			return;
		}
		--current.count;
		current.sum -= s[i1];
	}
}
bool start_long_check(int i1, int j1)
{
	d.clear();
	current.count = 0;

	add_all_sets(i1, j1);

	return FIN_FLAG;
}
void solve()
{
	FIN_FLAG = false;
	int i,j;
	memset(m, false, sizeof(m));
	for (i = 0; i <= n; ++i)
	{
		m[i][0] = true;
	}
	for (i = 1; i <= n; ++i)
	{
		for (j = 0; j < p; ++j)
		{
			if (m[i - 1][(p + j - (s[i] % p)) % p])
			{
				m[i][j] = true;
			}
			if (m[i - 1][j])
			{
				if (!m[i][j])
				{
					m[i][j] = true;
				}
				else
				{
					/// If solution found, just return
					if (start_long_check(i,j))
						return ;
				}
			}
		}
	}
	std::cout << "Impossible\n";
} 
int main()
{
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	int t;
	cin >> t;
	int i;
	for (i = 1; i <= t; ++i)
	{
		read();
		std::cout << "Case #" << i << ":\n";
		solve();
	}
}