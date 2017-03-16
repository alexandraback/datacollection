#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

struct TestCase
{
  int smax;
  std::vector<int> guests;
	int solution;

  TestCase(FILE* input)
  {
		char buffer[1001];
    fscanf(input, "%d", &smax);
		guests.reserve(smax + 1);
		int idx = 0;
		while (idx <= smax)
		{
			char c;
			fscanf(input, "%c", &c);
			if (std::isspace(c))
				continue;
			guests.push_back(c - '0');
			++idx;
		}
  }

  void Solve()
  {
		int result = 0;
		int prevLevelGuests = guests[0];
		for (int i = 1; i < guests.size(); ++i)
		{
			if (i > prevLevelGuests)
			{
				int d = i - prevLevelGuests;
				result += d;
				prevLevelGuests += d;
			}
			prevLevelGuests += guests[i];
		}
		solution = result;
  }

	bool Check()
	{
		return true;
	}
};

void main()
{
  std::srand(std::time(0));
  FILE* input = fopen("io/input.txt", "rt");
  int t;
  fscanf(input, "%d\n", &t);
  std::vector<TestCase> testCases;
  testCases.reserve(t);
  for (int i = 0; i < t; ++i)
    testCases.push_back(TestCase(input));
  fclose(input);
  FILE* output = fopen("io/output.txt", "wt");
  for (int i = 0; i < t; ++i)
  {
    testCases[i].Solve();
    if (testCases[i].Check())
    {
      fprintf(output, "Case #%d: ", i + 1);
      fprintf(output, "%d", testCases[i].solution);
      fprintf(output, "\n");
    }
    else
    {
      fprintf(output, "Error!");
      break;
    }
  }
  fclose(output);
}