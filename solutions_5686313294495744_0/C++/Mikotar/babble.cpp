#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int num_fake(vector<string> left,
	     vector<string> right)
{
  int count = 0;
  vector<string> ul, ur;
  for (int i = 0; i < left.size(); ++i)
    {
      vector<string>::iterator ln = left.begin() + i;
      vector<string>::iterator rn = right.begin() + i;
      if ((find(ln+1, left.end(), left[i]) != left.end() ||
	   find(ul.begin(), ul.end(), left[i]) != ul.end())&&
	  (find(rn+1, right.end(), right[i]) != right.end() ||
	   find(ur.begin(), ur.end(), right[i]) != ur.end()))
	{
	  count++;
	}
      else
	{
	  ul.push_back(left[i]);
	  ur.push_back(right[i]);
	}
    }
  return count;
}

int main()
{
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t)
  {
    int num;
    cin >> num;
    string garbage;
    getline(cin, garbage);
    vector<pair<string, string> > words;
    vector<string> left, right;
    for (int i = 0; i < num; ++i)
      {
	string str;
	getline(cin, str);
	istringstream iss(str);
	string s1, s2;
	iss >> s1;
	iss >> s2;
	left.push_back(s1);
	right.push_back(s2);
	words.push_back(make_pair(s1, s2));
      }
    cout << "Case #" << t << ": " << num_fake(left, right) << endl;
  }
}
