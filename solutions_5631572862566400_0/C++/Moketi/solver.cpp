
#include "stdio.h"
#include <string>

#define MAX_NUM 1000

class Solver
{
	//  ID in this class is ID in the problem -1;  
	int N;
	int BFF[MAX_NUM];
	int longest[MAX_NUM]; 
public:
	int ReadProblem()
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			int bff;
			scanf("%d", &bff);
			if ((bff < 1) || (bff > MAX_NUM))
				return -1;
			BFF[i] = bff - 1;
		}
	}
	int Solve()
	{
		CalcLongest();
		int count_check[MAX_NUM];
		memset(count_check, 0, sizeof(count_check));
		int ans = 0;
		int check = 1;
		int check_at_loop_start;
		for (int i = 0; i < N; i++)
		{
			check_at_loop_start = check;
			if (count_check[i] != 0)
				continue;
			int person = i;
			int bff = BFF[person];
			count_check[person] = check++;
			while (count_check[bff] == 0)
			{
				person = bff;
				bff = BFF[person];
				count_check[person] = check++;
			}
			if (count_check[bff] >= check_at_loop_start)
			{ 
				int loop = check - count_check[bff];
				if (loop == 2)
				{
					loop += longest[person] + longest[bff];
				}
				if (loop > ans)
					ans = loop;
			}
		}
		if (check != N + 1)
			return -1;
		return ans;
	}
private:
	int CalcLongest()
	{
		memset(longest, 0, sizeof(longest));
		for (int i = 0; i < N; i++)
		{
			for (int p = 0; p < N; p++)
			{
				if (longest[p] >= i && BFF[BFF[p]] != p)
				{
					longest[BFF[p]] = i + 1;
				}
			}
		}
		return 0;
	}
};


int main(int argc, char* argv[])
{

	int num;
	scanf("%d", &num);

	for (int i = 1; i < num + 1; i++)
	{
		Solver solver;
		int answer;
		solver.ReadProblem();
		answer = solver.Solve();
		printf("Case #%d: %d\n", i, answer);
	}

	return 0;
}

