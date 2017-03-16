#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

 
vector<string> gen_all(vector<string> v, string s)
{
  //cout << "gen_all: " << v.size() << endl;
  if (s.length() == 0)
    return v;
  vector<string> result;
  if (s.find('?') == string::npos)
    {
      for (int i = 0; i < v.size(); ++i)
	result.push_back(v[i]+s);
      return result;
    }
  int c = s.find('?');
  for (int i = 0; i < v.size(); ++i)
    {
      result.push_back(v[i]+s.substr(0, c) + string("0"));
      result.push_back(v[i]+s.substr(0, c) + string("1"));
      result.push_back(v[i]+s.substr(0, c) + string("2"));
      result.push_back(v[i]+s.substr(0, c) + string("3"));
      result.push_back(v[i]+s.substr(0, c) + string("4"));
      result.push_back(v[i]+s.substr(0, c) + string("5"));
      result.push_back(v[i]+s.substr(0, c) + string("6"));
      result.push_back(v[i]+s.substr(0, c) + string("7"));
      result.push_back(v[i]+s.substr(0, c) + string("8"));
      result.push_back(v[i]+s.substr(0, c) + string("9"));
    }
  return gen_all(result, s.substr(c+1));
}

string close(string l, string r)
{
  //cout << "close" << endl;
  vector<string> v;
  v.push_back("");
  vector<string> left =  gen_all(v, l);
  vector<string> right = gen_all(v, r);

  int i = 0, j = 0;
  int mini = 0, minj = 0;
  int mindist = abs(atoi(right[0].c_str())-atoi(left[0].c_str()));
  //cout << "entering while loop" << endl;
  //cout << left.size() << " " << right.size() << endl;
  while ( i < left.size() && j < right.size())
    {
      //cout << i << " " << j << endl;
      if (atoi(left[i].c_str()) == atoi(right[j].c_str()))
	{
	  stringstream ss;
	  ss << left[i] << " " << right[j];
	  return ss.str();
	}
      if (abs(atoi(left[i].c_str()) - atoi(right[j].c_str())) < mindist)
	{
	  mindist = abs(atoi(left[i].c_str()) - atoi(right[j].c_str()));
	  mini = i;
	  minj = j;
	}
      (atoi(left[i].c_str()) < atoi(right[j].c_str())) ? ++i : ++j;
    }
  stringstream ss;
  ss << left[mini] << " " << right[minj];
  return ss.str();
}

int main()
{
  int T;
  cin >> T;
  string garbage;
  getline(cin, garbage);
  for (int t = 1; t <= T; ++t)
  {
    string line;
    getline(cin, line);
    istringstream iss(line);
    string l, r;
    iss >> l >> r;
    cout << "Case #" << t << ": " << close(l, r) << endl;
  }
}
