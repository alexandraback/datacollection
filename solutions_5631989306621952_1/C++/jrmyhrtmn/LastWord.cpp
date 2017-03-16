#include <string>
#include <iostream>
#include <fstream>
using namespace std;

int main()
{
  ifstream myInput;
  myInput.open("A-large.in");
  ofstream myOutput;
  myOutput.open("solution.out");

  int t;
  myInput >> t;
  for(int i = 0; i < t; i++)
  {
    string word;
    string lastWord;

    myInput >> word;

    lastWord.push_back(word[0]);

    for(int j = 1; j < word.length(); j++)
    {
      char add = word[j];
      if(add >= lastWord[0])
        lastWord.insert(0, 1, add);
      else
        lastWord.push_back(add);
    }

    myOutput << "Case #" << i + 1 << ": " << lastWord << endl;
  }
}
