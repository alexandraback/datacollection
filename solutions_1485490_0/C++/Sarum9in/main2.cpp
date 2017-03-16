#include <iostream>
#include <vector>
#include <algorithm>

#include <cstdint>

struct prod
{
	std::uint64_t count;
	std::size_t type;
};

struct state
{
	std::uint64_t used, a, b;
};

int main()
{
	std::size_t tests;
	std::cin>>tests;
	for (std::size_t test = 0; test<tests; ++test)
	{
		std::size_t n, m;
		std::cin>>n>>m;
		std::vector<prod> a(n), b(m);
		for (prod &i: a)
			std::cin>>i.count>>i.type;
		for (prod &i: b)
			std::cin>>i.count>>i.type;
		std::uint64_t ret;
		{
			std::vector<std::vector<state>> d(n+1, std::vector<state>(m+1));
			std::fill(d[0].begin(), d[0].end(), state{0, 0, 0});
			for (std::size_t i = 1; i<=n; ++i)
			{
				d[i][0] = state{0, 0, 0};
				for (std::size_t j = 1; j<=m; ++j)
				{
					d[i][j].a = d[i][j].b = 0;
					d[i][j].used = std::max(d[i-1][j].used, d[i][j-1].used);
					if (a[i-1].type==b[j-1].type)
					{
						const std::uint64_t cur = std::min(a[i-1].count, b[j-1].count);
						if (cur+d[i-1][j-1].used>d[i][j].used)
						{
							d[i][j].used = cur+d[i-1][j-1].used;
							d[i][j].a = a[i-1].count-cur;
							d[i][j].b = b[i-1].count-cur;
						}
					}
					for (std::size_t k = 1; k<i; ++k)
					{
						if (a[i-1].type==a[k-1].type)
						{
							state nxt = d[k][j];
							nxt.a += a[i-1].count;
							const std::uint64_t cur = std::min(nxt.a, nxt.b);
							nxt.used += cur;
							nxt.a -= cur;
							nxt.b -= cur;
							if (nxt.used>d[i][j].used)
								d[i][j] = nxt;
						}
					}
					for (std::size_t k = 1; k<j; ++k)
					{
						if (b[j-1].type==b[k-1].type)
						{
							state nxt = d[i][k];
							nxt.b += b[j-1].count;
							const std::uint64_t cur = std::min(nxt.a, nxt.b);
							nxt.used += cur;
							nxt.a -= cur;
							nxt.b -= cur;
							if (nxt.used>d[i][j].used)
								d[i][j] = nxt;
						}
					}
				}
			}
			ret = d.back().back().used;
		}
		std::cout<<"Case #"<<test+1<<": "<<ret<<std::endl;
	}
}

