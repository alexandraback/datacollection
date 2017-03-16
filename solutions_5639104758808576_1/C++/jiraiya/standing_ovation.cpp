#include <iostream>
#include <fstream>
#include <stdlib.h>

using namespace std;

int chose_friends(int max_shyness, string line);

int main(int argc, char *argv[])
{
  istream *in;
  ifstream infile;
  if(argc > 1)
  {
    infile.open(argv[1]);
    in = &infile;
  }
  else
  {
    in = &cin;
  }
  string line;
  int noOfCase = -1;
  int case_counter = 1;
  getline(*in, line);
  noOfCase = atoi(line.c_str());
  while (noOfCase > 0)
  {
    getline(*in,line, ' ');
    int max_shyness = atoi(line.c_str());

    getline(*in, line);
    int frnd_required = chose_friends(max_shyness, line);
    cout << "Case #" << case_counter << ": " << frnd_required << endl;
    case_counter++;
    noOfCase--;
  }
  if(infile.is_open())
    infile.close();
  return 0;
}

int chose_friends(int max_shyness, string line)
{
  int friends_counter = 0;
  int current_people = 0;
  for(int i =0; i < max_shyness, current_people < max_shyness; i++)
  {
    if(i==0)
    {
      if(line[0]=='0')
      {
        friends_counter++;
        current_people++;
      }
    }
    else
    {
      if(current_people < i)
      {
        friends_counter += (i - current_people);
        current_people += (i-current_people);
      }
    }
    current_people += (line[i] -'0');
  }
  return friends_counter;
}
