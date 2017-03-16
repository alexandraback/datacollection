#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream myInput;
  myInput.open("B-large.in");
  ofstream myOutput;
  myOutput.open("solution.out");

  int t;
  myInput >> t;
  for(int i = 0; i < t; i++)
  {
    int n;
    myInput >> n;

    int array[n];
    bool index[2501];
    for(int j = 0; j < 2500; j++)
    {
      index[j] = 0;
    }

    int input;

    for(int j = 0; j < (n * ((2 * n) - 1)); j++)
    {
      myInput >> input;
      index[input] = !index[input];
    }
    int current = 0;
    for(int k = 1; k < 2501; k++)
    {
      if(index[k])
      {
        array[current] = k;
        current++;
      }
    }
    myOutput << "Case #" << i + 1 << ":";
    for(int m = 0; m < n; m++)
    {
      myOutput << " " << array[m];
    }
    myOutput << endl;
  }
}
