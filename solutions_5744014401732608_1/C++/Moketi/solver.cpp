
#include <stdio.h>


struct Problem
{
	int num_buildings;
	unsigned long long way;
	void Load()
	{
		scanf("%d %llu", &num_buildings, &way);
	}
};


class Solver
{
public:
	void SolveAndAnswer(const Problem* p)
	{
		unsigned long long max_way = 1ull << (p->num_buildings - 2); // connect x -> y if building id x is smaller than id y
		if (p->way > max_way)
		{
			printf("IMPOSSIBLE\n");
			return;
		}
		printf("POSSIBLE\n");
		// connect x -> y if building id x is smaller than id y , and y is not B 
		// connect x -> B to control the count of way is jyust M , the way is 1, 1, 2, 4, ......

		printf("0");
		for (int j = 0; j < p->num_buildings - 1; j++)
		{
			printf("1");
		}
		printf("\n");
		unsigned long long connect = p->way - 1;
		for (int i = 1; i < p->num_buildings; i++)
		{
			for (int j = 0; j < p->num_buildings - 1; j++)
			{
				printf("%c", i < j ? '1' : '0');
			}
			printf("%c\n", (connect &1) ? '1' : '0');
			connect >>= 1;
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
		Problem p;
		p.Load();
		printf("Case #%d: ", i);
		solver.SolveAndAnswer(&p);
	}

	return 0;
}

