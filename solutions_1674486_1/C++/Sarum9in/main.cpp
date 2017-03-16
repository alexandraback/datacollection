#include <iostream>
#include <vector>
#include <functional>

#include <boost/assert.hpp>
#include <boost/dynamic_bitset.hpp>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::size_t tests;
	std::cin>>tests;
	for (std::size_t test = 0; test<tests; ++test)
	{
		std::size_t n;
		std::cin>>n;
		std::vector<std::vector<std::size_t>> g(n);
		for (std::size_t i = 0; i<n; ++i)
		{
			std::size_t m;
			std::cin>>m;
			g[i].resize(m);
			for (std::size_t j = 0; j<m; ++j)
			{
				std::cin>>g[i][j];
				--g[i][j];
			}
		}
		bool ret = false;
		{
			std::vector<boost::dynamic_bitset<>> inheritance(n);
			std::function<bool (std::size_t)> dfs_fill = 
				[&dfs_fill, &inheritance, &g, n](std::size_t current)
				{
					if (inheritance[current].empty())
					{
						inheritance[current].resize(n);
						for (const auto &i: g[current])
						{
							if (dfs_fill(i))
								return true;
							if ((inheritance[current] & inheritance[i]).any())
								return true;
							inheritance[current] |= inheritance[i];
						}
						BOOST_ASSERT(!inheritance[current].test(current));
						inheritance[current].set(current);
					}
					return false;
				};
			for (std::size_t i = 0; !ret && i<n; ++i)
				if (dfs_fill(i))
					ret = true;
		}
		std::cout<<"Case #"<<test+1<<": "<<(ret?"Yes":"No")<<std::endl;
	}
}

