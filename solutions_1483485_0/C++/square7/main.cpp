#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
char mappingTo[26];

void map(istream& is, ifstream& os, char* to)
{
  int totLine;
  is >> totLine;
  string Istr;
  string Ostr;
  getline(is, Istr);
  for (int i = 0; i < totLine; ++i)
    {
      getline(is, Istr);
      getline(os, Ostr);
      if(Istr.size() != Ostr.size())
	{cout << "Error in String" << endl;}
      for(int j = 0; j < Istr.size(); ++j)
	{
	  if(isalpha(Istr[j]))
	    {
	      int index = Istr[j] - 'a';
	      to[index] = Ostr[j];
	    }
	}
    }
  to[25] = 'q';
  char left;
  for(int i = 0; i < 26; ++i)
    {
      char curr = 'a' + i;
      bool isThis = 0;
      for(int j = 0; j < 26; ++j)
	{
	  if(curr == to[j])
	    {isThis = 1;}
	}
      if(isThis == 0)
	{
	  to['q'-'a'] = curr;
	  break;
	}
    }
  // for(int i = 0; i < 26; ++i)
  // {
  //   cout << char('a' + i) << ' ';
  //   cout << to[i] << endl;
  // }
}


int main(int argc, char* argv[])
{
  if(argc != 5)
    {
      cout << "Error" << endl;
      return -1;
    }
  ifstream samplein(argv[1]);
  ifstream sampleout(argv[2]);
  ifstream input(argv[3]);
  ofstream output(argv[4]);
  map(samplein, sampleout, mappingTo);
  int totLine;
  input >> totLine;
  string str;
  getline(input, str);
  for(int i = 0; i < totLine; ++i)
    {
      getline(input, str);
      output << "Case #" << (i+1) << ": ";
      for(int j = 0; j < str.size(); ++j)
	{
	  char trans = ' ';
	  if(isalpha(str[j]))
	    {
	      trans = mappingTo[str[j]-'a'];
	    }
	    output << trans;
	}
	  output << endl;
    }
}
