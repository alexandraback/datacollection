
#include <stdio.h>
#include <string>

#define LENGTH  1024

struct Problem
{
	char S[LENGTH]; 
};

class Solver
{
public:
	std::string solve(const Problem* p)
	{
		int len = strlen(p->S);
		std::string ans = p->S[0] + std::string();
		for (int i = 1; i < len; i++)
		{
			std::string s1, s2;
			s1 = p->S[i] + ans;
			s2 = ans + p->S[i];
			if (s1 < s2)
				ans = s2;
			else
				ans = s1;
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
		std::string answer;
		scanf("%s", &p.S);
		answer = solver.solve(&p);
		printf("Case #%d: %s\n", i, answer.c_str());
	}

	return 0;
}

