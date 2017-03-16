#include <iostream>
#include <iomanip>
using namespace std;

long double toGoal(const long double &inc, const long double& goal)
{
  return (goal/inc);
}

int main(int, char**)
{
  cout << fixed << setprecision(7);

  int test_cases;
  cin >> test_cases;
  for(int id = 1; id <= test_cases; ++id)
  {
    long double cost, farm, goal;
    cin >> cost >> farm >> goal;
    long double gain = 2;
    long double mtime = 0;

    while(true)
    {
      long double to_goal = toGoal(gain, goal);
      long double to_farm = toGoal(gain, cost);
      long double to_goal2 = toGoal(gain+farm, goal);
      //long double to_farm2 = toGoal(gain+farm, cost);

      //long double diff = to_goal2 - to_farm;
      long double sum = to_farm+to_goal2;
      
      //Chega ao objetivo
      if(sum >= to_goal)
      {
        mtime += to_goal;
        break;
      } else
      //Compra nova fazenda
      {
        mtime += to_farm;
        gain += farm;
      }
      
    }

    cout << "Case #"<< id << ": " << mtime << endl;
    


  }
  return 0;
}