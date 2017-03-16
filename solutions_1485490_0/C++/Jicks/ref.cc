#include <iostream>
#include <vector>
#include <map>

typedef std::map<long long int, long long int> s;

std::vector<std::vector<std::pair<s, s>>> state;
std::vector<long long int> typeN;
std::vector<long long int> numberN;
std::vector<long long int> typeM;
std::vector<long long int> numberM;

long long int compute(int i, int j, long long int ni, long long int nj)
{

  /*auto itn = state[i][j].first.find(ni);
  auto itm = state[i][j].second.find(nj);
  if (itn != state[i][j].first.end())
    return itn->second + (typeN[i] == typeM[j]) ? std::min(ni, nj) : 0;
  else if (itm != state[i][j].second.end())
    return itm->second + (typeN[i] == typeM[j]) ? std::min(ni, nj) : 0;
*/
  if (typeN[i] == typeM[j])
  {
    long long int max = 0;
    long long int min = 0;
    if (ni > nj)
    {
      max = (j + 1 < typeM.size()) ? compute(i, j + 1, ni - nj, numberM[j + 1]) : 0;
      min = nj;
      //state[i][j].first.insert(std::make_pair(ni - nj, max));
    }
    else if (ni < nj)
    {
      max = (i + 1 < typeN.size()) ? compute(i + 1, j, numberN[i + 1], nj - ni) : 0;
      min = ni;
      //state[i][j].second.insert(std::make_pair(nj - ni, max));
    }
    else
    {
      if (i + 1 >= typeN.size() || j + 1 >= typeM.size()) return ni;
      max = compute(i + 1, j + 1, numberN[i + 1], numberM[j + 1]);
      min = ni;
    }
    //state[i][j].first.insert(std::make_pair(ni, max));
    //state[i][j].second.insert(std::make_pair(nj, max));
    return max + min;
  }
  else
  {
    long long int n = (i + 1 < typeN.size()) ? compute(i + 1, j, numberN[i + 1], nj) : 0;
    long long int m = (j + 1 < typeM.size()) ? compute(i, j + 1, ni, numberM[j + 1]) : 0;
    long long int max = std::max(n, m);
    //state[i][j].first.insert(std::make_pair(ni, max));
    //state[i][j].second.insert(std::make_pair(nj, max));
    return max;
  }
}


int main()
{
  int T; std::cin >> T; std::cin.ignore();

  for (int i = 1; i <= T; ++i)
  {
    int N, M; std::cin >> N; std::cin >> M; std::cin.ignore();
    typeN.clear(); numberN.clear(); typeM.clear(); numberM.clear();

    for (int j = 0; j < N; ++j)
    {
      long long int tmp;
      std::cin >> tmp; numberN.push_back(tmp);
      std::cin >> tmp; typeN.push_back(tmp);
    }
    std::cin.ignore();
    for (int j = 0; j < M; ++j)
    {
      long long int tmp;
      std::cin >> tmp; numberM.push_back(tmp);
      std::cin >> tmp; typeM.push_back(tmp);
    }
    std::cin.ignore();
    state = std::vector<std::vector<std::pair<s, s>>>(typeN.size(),
        std::vector<std::pair<s, s>>(typeM.size(), std::make_pair(s(), s())));
    std::cout << "Case #" << i << ": " << compute(0, 0, numberN[0], numberM[0]) << std::endl;
  }
}
