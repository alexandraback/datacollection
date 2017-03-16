//Bartosz Prusak
#include<iostream>

int counter[31];

int main()
{
	std::ios::sync_with_stdio(0);
	int T; std::cin >> T;
	for(int ii = 0; ii < T; ii++)
	{
		for(int i = 0; i < 31; i++)
			counter[i] = 0;
		int N, S, p, t, y = 0;
		std::cin >> N >> S >> p;
		for(int i = 0; i < N; i++)
		{
			std::cin >> t; counter[t]++;
		}
		int i;
		for(i = 30; i/3+bool(i%3) >= p; i--)
			y += counter[i];
		if(i > 0)
		{
			if(counter[i] >= S)
				y += S;
			else
				if(counter[i]+counter[i-1] >= S)
					y += S;
				else
					y += counter[i]+counter[i-1];
		}
		std::cout << "Case #" << ii+1 << ": " << y << '\n';
	}
	return 0;
}
