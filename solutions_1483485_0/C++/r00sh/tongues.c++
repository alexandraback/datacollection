#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char master[26] = {
  'y',
  'h',
  'e',
  's',
  'o',
  'c',
  'v',
  'x',
  'd',
  'u',
  'i',
  'g',
  'l',
  'b',
  'k',
  'r',
  'z',
  't',
  'n',
  'w',
  'j',
  'p',
  'f',
  'm',
  'a',
  'q',
};
		   
int main(void)
{
  ifstream fin;
  ofstream fout;

  int n;
  string str;
  char c;

  fin.open("tongues1.in");
  fout.open("tongues1.out");

  fin >> n;
  getline(fin, str);
  
  for (int i = 0; i < n; i++)
    {
      fout << "Case #" << (i + 1) << ": ";
      getline(fin, str);
      for (int j = 0; j < str.size(); j++)
	{
	  if (str[j] == ' ')
	    fout << ' ';
	  else
	    fout << master[(int) (str[j] - 97)];
	}
      fout << endl;      
    }

  fin.close();
  fout.close();

  return 0;
}
