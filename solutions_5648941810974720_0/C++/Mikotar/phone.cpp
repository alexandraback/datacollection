#include <iostream>
#include <cstdlib>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <vector>

using namespace std;

vector<int> get_counts(string str)
{
  vector<int> counts;
  for (int i = 0; i < 26; ++i)
    {
      counts.push_back(0);
    }
  
  for (int i = 0; i < str.length(); ++i)
    {
      counts[str.at(i)-65]++;
    }
  return counts;
}


vector<int> parse_str(string str)
{
  vector<int> counts = get_counts(str);
  vector<int> v;
  for (int i = 0; i < 10; ++i)
    {
      v.push_back(0);
    }
  while (counts[25] > 0) //gets zero
    {
      v[0]++;
      counts[25]--;
      counts[4]--;
      counts[17]--;
      counts[14]--;
    }
  while (counts[20] > 0) //gets four
    {
      v[4]++;
      counts[5]--;
      counts[14]--;
      counts[20]--;
      counts[17]--;
    }
  while (counts[23] > 0) //gets six
    {
      v[6]++;
      counts[18]--;
      counts[8]--;
      counts[23]--;
    }
  while (counts[6] > 0) //gets eight
    {
      v[8]++;
      counts[4]--;
      counts[8]--;
      counts[6]--;
      counts[7]--;
      counts[19]--;
    }
  while (counts[5] > 0) //gets five
    {
      v[5]++;
      counts[5]--;
      counts[8]--;
      counts[21]--;
      counts[4]--;
    }
  while (counts[8] > 0) //gets nine
    {
      v[9]++;
      counts[13]--;
      counts[13]--;
      counts[8]--;
      counts[4]--;
    }
  while (counts[22] > 0) //gets two
    {
      v[2]++;
      counts[19]--;
      counts[22]--;
      counts[14]--;
    }
  while (counts[14] > 0) //gets one
    {
      v[1]++;
      counts[14]--;
      counts[13]--;
      counts[4]--;
    }
  while (counts[19] > 0) //gets three
    {
      v[3]++;
      counts[19]--;
      counts[17]--;
      counts[7]--;
      counts[4]--;
      counts[4]--;
    }
  while (counts[21] > 0) //gets seven
    {
      v[7]++;
      counts[18]--;
      counts[4]--;
      counts[21]--;
      counts[4]--;
      counts[13]--;
    }
  return v;
}

string phone_number(string str)
{
  vector<int> nums = parse_str(str);
  stringstream ss;
  for (int i = 0; i < nums.size(); ++i)
  {
    while (nums[i] > 0)
      {
	ss << i;
	nums[i]--;
      }
  }
  return ss.str();
}

int main()
{
  int T;
  cin >> T;
  string garbage;
  getline(cin, garbage);
  for (int i = 0; i < T; ++i)
  {
    string str;
    getline(cin, str);
    cout << "Case #" << (i+1) << ": " << phone_number(str) << endl;
  }
}
