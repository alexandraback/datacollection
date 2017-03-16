#include <string>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main()
{
  ifstream myInput;
  myInput.open("C-small-attempt1.in");
  ofstream myOutput;
  myOutput.open("solution.out");

  int t;
  myInput >> t;
  for(int i = 0; i < t; i++)
  {
    int n;
    myInput >> n;
    int size = 0;
    int array[n + 1];
    for(int j = 1; j <= n; j++)
    {
      int input;
      myInput >> input;
      array[j] = input;
    }

    for(int j = 1; j <= n; j++)
    {
      vector<int> vec;
      vec.push_back(j);
      bool cont = 1;
      while(cont)
      {
        for(int k = 0; k < vec.size(); k++)
          if(array[vec.back()] == vec[k])
            cont = 0;
        if(cont)
          vec.push_back(array[vec.back()]);
      }
      if(array[vec.back()] == vec.front() || array[vec.back()] == vec[vec.size() - 2])
      {
        for(int k = 1; k <= n; k++)
        {
          bool notUsed = 1;
          for(int m = 0; m < vec.size(); m++)
            if(k == vec[m])
              notUsed = 0;
          if(notUsed && array[k] == vec.back() && array[vec.back()] != vec.front())
            vec.push_back(k);
        }
        if(vec.size() > size)
          size = vec.size();
        if(size > n)
          size = n;
      }
    }

    myOutput << "Case #" << i + 1 << ": " << size << endl;
  }
}
