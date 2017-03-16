#include<iostream>

int main()
{
	std::ios::sync_with_stdio(0);
	int T; std::cin >> T;
	for(int ii = 0; ii < T; ii++)
	{
		int A, B;
		std::cin >> A >> B;
		int tens = 10, ttens = 100;
		unsigned long long count = 0;
		for(int n = A; n < B; n++)
		{
			if(n<10) continue;
			while(n >= ttens) {tens = ttens; ttens *= 10;}
			int m = n;
			while(true)
			{
				int dig = m/tens;
				m = (m-dig*tens)*10+dig;
				if(n==m) break;
				if(m>n && m <= B) count++;
			}
		}
		std::cout << "Case #" << ii+1 << ": " << count << '\n';
	}
	return 0;
}
