#include <iostream>
#include <set>

using namespace std;

int min_cost, cost, next_cost, num_mo, rest;
int curr;

long a;

multiset<int> motes;


int getcost(long mote)
{
  int ret = 0;
  while (a <= mote)
  {
    a += a-1;
    ret++;
  }
  return ret;
}

void printVars(int mote)
{
  cout << "min_cost: " << min_cost << endl;
  cout << "cost: " << cost << endl;
  cout << "rest: " << rest << endl;
  cout << "a: " << a << endl;
  cout << "next mote: " << mote << endl;
  cout << "rest: " << rest << endl;
  cout << "===========================" << endl;
}


int solve()
{
  if (a == 1)
  {
    return num_mo;
  }
  curr = 0;
  cost = 0;
  rest = num_mo;
  min_cost = num_mo;
  multiset<int>::iterator it = motes.begin();
  while (it != motes.end())
  {
    if (cost + rest < min_cost)
      min_cost = cost + rest;
    next_cost = getcost(*it);
    //printVars(*it);
    if (cost + next_cost >= min_cost)
      return min_cost;
    cost += next_cost;
    a += *it;
    it++;
    rest--;
  }
  return cost;
}


int main()
{
  int no;
  std::cin >>  no;
  for (int i=0; i < no; i++)
  {
    motes.clear();
    cin >> a;
    cin >> num_mo;
    for (int j =0; j < num_mo; j++)
    {
      int temp;
      cin >> temp;
      motes.insert(temp);
    }
    std::cout<< "Case #" << i+1 << ": " << solve() << endl;
  }
}
