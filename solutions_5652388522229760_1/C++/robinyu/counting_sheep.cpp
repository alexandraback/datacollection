#include <fstream>

bool found[10];

void count(long long int x)
{
	int r;
	while (x > 0)
	{
		r = x%10;
		found[r] = x;
		x /= 10;
	}
}

int main()
{
	std::ifstream fin ("A-large.in");
	std::ofstream fout("A-large.out");
	int tc;
	long long int n;
	
	fin >> tc;
	for (int t = 0; t < tc; t++)
	{
		fout << "Case #" << t+1 << ": ";
		fin >> n;
		if (n == 0) fout << "INSOMNIA\n";
		else
		{
			for (int i = 0; i < 10; i++) found[i] = false;
			for (int i = 1; ; i++)
			{
				count(i*n);
				bool allclear = true;
				for (int j = 0; j < 10; j++)
				{
					allclear = (allclear && found[j]);
				}
				if (allclear)
				{
					fout << i*n << '\n';
					break;
				}
			}
		}
	}
}
