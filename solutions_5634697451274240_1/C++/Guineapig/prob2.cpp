#include <iostream>
#include <string>

using namespace std;



int solve(bool *stack, int size, bool final_state)
{
  // Skipping the bottom part of the stack that is already right
  int i = size - 1;
  while (i >= 0 && stack[i] == final_state)
    i--;
  if (i < 0)
    return 0;

  // Counting the number of reversed items at the bottom of the active stack
  int j = i;
  while (j >= 0 && stack[j] != final_state)
    j--;
  if (j < 0)
    return 1;

  return 1 + solve(stack, j+1, !final_state);
}


int main(int, char**)
{
  int T;
  cin >> T;

  for (int i_t=0 ; i_t < T ; i_t++)
  {
    string str_stack;
    cin >> str_stack;
    int size = str_stack.size();
    // cout << str_stack << endl;
    bool stack[256];
    for (int i=0 ; i < str_stack.size() ; i++)
      stack[i] = str_stack[i] == '+';

    int res = solve(stack, size, true);

    cout << "Case #" << (i_t + 1) << ": " << res << endl;
  }
}