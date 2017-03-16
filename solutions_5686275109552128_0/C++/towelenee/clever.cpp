#include<cassert>
#include<queue>
#include<cstring>
#include<cstdio>
#include<vector>
#include<string>
#include<set>
#include<map>
#include<cmath>
#include<iostream>
#include<algorithm>

typedef long long ll;
typedef std::vector<int> container;

int calcAnswer(container set, std::map<container, int>& ans)
{
  sort(set.begin(), set.end(), std::greater<int>());
  if (ans.count(set))
    return ans[set];
  int& ansRef = ans[set];
  ansRef = *set.cbegin();
  for (size_t i = 0; i < set.size(); ++i)
  {
    if (set[i] != 1)
    {
      for (int one = 1; one < set[i]; one++)
      {
	container nw;
	nw.push_back(one);
	nw.push_back(set[i] - one);
	for (size_t j = 0; j < set.size(); j++)
	  if (i != j)
	    nw.push_back(set[j]);
	ansRef = std::min(ansRef, calcAnswer(nw, ans) + 1);
      }
    }
  }
  return ansRef;
}
int main()         
{
  int test_n;
  scanf("%d",&test_n);
  std::map<std::vector<int>, int> answer;
  for(int test_id = 0; test_id < test_n; test_id++)
  {
    printf("Case #%d: ",test_id + 1);
    int n;
    std::cin >> n;
    container set;
    for (int i = 0; i < n; ++i)
    {
      int k;
      std::cin >> k;
      set.push_back(k);
    }
    std::cout << calcAnswer(set, answer) << std::endl;
    std::cerr << answer.size() << std::endl;
  }
  return 0;
}

