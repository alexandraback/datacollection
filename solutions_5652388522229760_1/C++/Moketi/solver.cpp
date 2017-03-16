
#include "stdio.h"

class Solver
{
	bool is_used[10];
public:
	int Solve(int N)
	{
		if (N < 0)
			N = -N;
		if (N == 0)
			return -1;
		Initialize();
		int num = N;

		AddNumber(num);
		while (!IsEnd()){
			num += N;
			AddNumber(num);
		};
		return num;
	}
private:
	void Initialize()
	{
		for (int i = 0; i < 10; i++)
			is_used[i] = false;
	}
	bool IsEnd()
	{
		for (int i = 0; i < 10; i++)
			if (!is_used[i])
				return false;
		return true;
	}
	void AddNumber(int num)
	{
		if (num < 0)
			return;
		is_used[num % 10] = true;
		while (num >= 10)
		{
			num /= 10;
			is_used[num % 10] = true;
		}
	}
};

int main(int argc, char* argv[])
{

	int num;
	scanf("%d", &num);

	for (int i = 1; i < num + 1; i++)
	{
		Solver solver;
		int  answer;
		int N;
		scanf("%d", &N);
		answer = solver.Solve(N);
		if (answer < 0)
			printf("Case #%d: INSOMNIA\n", i);
		else
			printf("Case #%d: %d\n", i, answer);
	}

	return 0;
}

