#include <cstdio>
#include <cmath>
#include <ctime>
#include <cctype>
#include <limits>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

struct TestCase
{
	std::vector<int> init_dishes;
	int solution;

  TestCase(FILE* input)
  {
		int d = 0;
		fscanf(input, "%d\n", &d);
		init_dishes.reserve(d);
		for (int i = 0; i < d; ++i)
		{
			int p = 0;
			fscanf(input, "%d", &p);
			init_dishes.push_back(p);
		}
  }

  void InternalSolve(std::vector<int>& dishes, std::vector<int>& distinct, int special_time, int& best_time)
  {
    std::vector<int>::iterator max_dish_it = std::max_element(dishes.begin(), dishes.end());
    if (special_time + *max_dish_it < best_time)
      best_time = special_time + *max_dish_it;
    if (*max_dish_it == 1)
      return;
    int max_dish = *max_dish_it;
    int max_dish_idx = max_dish_it - dishes.begin();
    for (auto it = distinct.rbegin(); it != distinct.rend(); ++it)
    {
      if (*it >= max_dish)
        continue;
      std::vector<int> new_dishes = dishes;
      new_dishes[max_dish_idx] = *it;
      new_dishes.push_back(max_dish - *it);
      InternalSolve(new_dishes, distinct, special_time + 1, best_time);
    }
    std::vector<int> new_dishes = dishes;
    new_dishes[max_dish_idx] = max_dish / 2;
    new_dishes.push_back(max_dish - max_dish / 2);
    InternalSolve(new_dishes, distinct, special_time + 1, best_time);
  }

  void Solve()
  {
		int best_time = std::numeric_limits<int>::max();
    std::unordered_set<int> distinct_set;
    distinct_set.insert(init_dishes.begin(), init_dishes.end());
    std::vector<int> distinct;
    distinct.insert(distinct.end(), distinct_set.begin(), distinct_set.end());
    std::sort(distinct.begin(), distinct.end());
    std::vector<int> new_dishes = init_dishes;
    InternalSolve(new_dishes, distinct, 0, best_time);
    solution = best_time;
  }

	bool Check()
	{
		if (*std::max_element(init_dishes.begin(), init_dishes.end()) < solution)
			return false;
		return true;
	}
};

void PrintDishes(std::vector<int>& dishes)
{
  printf("(");
  for (int i = 0; i < dishes.size(); ++i)
    printf(" %d", dishes[i]);
  printf(" )");
}

void main()
{
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
     printf("%d: ", i + 1);
//     PrintDishes(testCases[i].init_dishes);
     printf("\n");
    testCases[i].Solve();
		fprintf(output, "Case #%d: ", i + 1);
    if (testCases[i].Check())
    {
      fprintf(output, "%d", testCases[i].solution);
      fprintf(output, "\n");
    }
    else
    {
      fprintf(output, "Error!\n");
      testCases[i].Check();
      throw std::exception();
      break;
    }
  }
  fclose(output);
}