#include <algorithm>
#include <cassert>
#include <iostream>
#include <iterator>
#include <sstream>
#include <string>
#include <vector>

/*std::vector<int> F(const std::vector<int> &k, int N, int M)
{
	std::sort(v.begin(), v.end());
	if (v.back() > M)
	{
		for (auto iter(v.begin()); iter != v.end() - 1; ++iter)
			if (!(v.back() % *iter))
			{
				auto v2 = v;
				v2.back() /= *iter;
				auto r = F(v2);
			}
	}
}*/

int main()
{
	int T;
	{
		std::string s;
		std::getline(std::cin, s);
		std::istringstream ss(s);
		ss >> T;
	}

	int R, N, M, K;
	{
		std::string s;
		std::getline(std::cin, s);
		std::istringstream ss(s);
		ss >> R >> N >> M >> K;
	}

	std::cout << "Case #1:" << std::endl;

	for (int i = 0; i < R; ++i)
	{
		static int k[12];
		{
			std::string s;
			std::getline(std::cin, s);
			std::istringstream ss(s);
			std::copy_n(std::istream_iterator<int>(ss), K, k);
		}
		
		int K2 = std::remove(k, k + K, 1) - k;
		std::sort(k, k + K2);
		K2 = std::unique(k, k + K2) - k;
		std::reverse(k, k + K2);
		
		// debug
		//std::copy_n(k, K2, std::ostream_iterator<int>(std::cout, " "));
		//std::cout << "= ";
		
		int V = K2;
		static int v[24];
		std::copy_n(k, K2, v);
		
		for (;;)
		{
			int h = v[0]; // highest number
			int VV = V;
			for (int i = 1; i < VV; ++i)
			{
				if (!(h % v[i]))
				{
					v[V++] = h / v[i];
					v[0] = 0;
				}
			}
			if (!v[0])
			{
				std::copy_n(v + 1, --V, v);
				std::sort(v, v + V);
				V = std::unique(v, v + V) - v;
				std::reverse(v, v + V);
			}
			else break; // give up
		}
		
		assert(V <= N);
		
		if (V < N)
		{
			do_retry:
			bool retry = false;
			for (int i = 0; i < K2; ++i)
			{
				int x = k[i];
				for (int j = 0; j < V; ++j)
				{
					if (!(x % v[j]))
						x /= v[j];
				}
				if (x != 1)
				{
					if (x > M)
					{
						retry = true;
						continue;
					}
						
					v[V++] = x;
				}
			}
			if (retry) goto do_retry;
		}
		
		for (int i = 0; i < V; ++i)
		{
			if (v[i] > M)
			{
				std::fill_n(v, N, 2);
				break;
			}
		}

		/*std::vector<int> v;
		std::copy_n(k, K, std::back_inserter(v));
		
		v = F(v);
		std::fill_n(v, N - v.size(), 2);*/
		
		/*int N = 0;
		if (K)
		{
			// iterate back from the last number, which is the highest number
			for (;;)
			{
				if (K < N)
				{
					for (int i = 0; i < K; ++i)
					{
						if (k[i] % 2)
						{
							k[i] /= 2;
							k[K++] = 2;
							std::sort(k, k + K);
							continue;
						}
					}
				}
				
				if (K == N)
				{
					for (int i = 0; i < K; ++i)
					{
						if (k[i] > M)
						{
							break;
						}
					}
					break; // solved!
				}
				
				// is the largest k divisible by any of the others?
				retry:
				for (int i = 0; i < K - 1; ++i)
					if (k[K - 1] % k[i])
					{
						k[K - 1] /= k[i];
						if (k[K - 1] > M) 
							goto retry;
					}
			}
		
			// 2 <= n <= M

			int largest_k = 0, smallest_k = M;
			for (int i = 0; i < K; ++i)
			{
				largest_k = std::max(largest_k, k[i]);
				smallest_k = std::min(smallest_k, k[i]);
			}
		}
		else std::fill_n(n, N = NN, 2);*/

		std::copy_n(v, N, std::ostream_iterator<int>(std::cout));
		std::cout << std::endl;
	}
}
