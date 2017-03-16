
#include <stdio.h>
#include <algorithm>
#include <vector>

struct Problem
{
	int J;
	int P;
	int S;
	int K;
	void Load()
	{
		scanf("%d %d %d %d", &J, &P, &S, &K);
	}
};

struct Answer
{
	struct A{ int ans[3]; };
	std::vector<A> ans;
	void Print(int id)
	{
		printf("Case #%d: %d\n", id, ans.size());
		for (auto i = ans.begin(); i < ans.end(); i++)
		{
			printf("%d %d %d\n", i->ans[0] + 1, i->ans[1] + 1, i->ans[2] + 1);
		}
	}
};

class Solver
{
public:
	Answer solve(const Problem* prob)
	{
		Answer ans;
		int j, p, s;
		int count = 0;
		int offset = 0;


		for (int i = 0; i < std::min(prob->K, prob->S); i++)
		{
			j = p = s= offset = 0;
			for (int b = 0; b < prob->J*prob->P; b++)
			{
				Answer::A a = { j, (p + offset) % prob->P, 0 };
				ans.ans.push_back(a);
				j++; if (j >= prob->J)j = 0;
				p++; if (p >= prob->P)p = 0;
				if ((j == 0) && (p == 0))
					offset++;
			}
		}
		bool count_up_cond_00 = prob->K > prob->S;
		for (auto i = ans.ans.begin(); i < ans.ans.end(); i++)
		{
			if (count_up_cond_00 && i->ans[0] == 0 && i->ans[1] == 0)
				s++;
			if ((!count_up_cond_00) && i->ans[0] == 0)
			{
				count++;
				if (count >= prob->K)
				{
					count = 0;
					s++;
				}
			}
			i->ans[2] = s;
		}
		return ans;
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
		Answer a;
		p.Load();
		a = solver.solve(&p);
		a.Print(i);
	}

	return 0;
}

