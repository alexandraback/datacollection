#include <algorithm>
#include <iterator>
#include <iostream>
#include <utility>
#include <cassert>
#include <string>
#include <vector>
#include <map>

using namespace std;

bool can_get(const std::string& n, map<char, int> cnt)
{
  for(int i = 0; i < n.size(); i++)
  {
    if(cnt[n[i]] > 0)
      cnt[n[i]]--;
    else
      return false;
  }

  return true;
}

int get_num(const string& n, map<char, int>& cnt)
{
  int used_cnt = 0;
  for(size_t j = 0; j < n.size(); j++) {
    assert(cnt[n[j]] > 0);
    cnt[n[j]]--;
    used_cnt++;
  }

  return used_cnt;
}

int extract(char ch, const string& s, int num, map<char, int>& cnt, std::string& out)
{
  int used_cnt = 0;
  while(cnt[ch] > 0) {
    used_cnt += get_num(s, cnt);
    out += ('0' + num);
  }
  return used_cnt;
}

string solve(const string& s)
{
  const vector<string> nums = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", 
                               "SIX", "SEVEN", "EIGHT", "NINE"};

  map<char, int> cnt;
  for(size_t i = 0; i < s.size(); i++)
    cnt[s[i]]++;

  std::string out;
  int used_cnt = 0;

  used_cnt += extract('Z', nums[0], 0, cnt, out);
  used_cnt += extract('W', nums[2], 2, cnt, out);
  used_cnt += extract('U', nums[4], 4, cnt, out);
  used_cnt += extract('X', nums[6], 6, cnt, out);
  used_cnt += extract('G', nums[8], 8, cnt, out);

  for(size_t i = 0; i < nums.size(); i++) {
    while(can_get(nums[i], cnt)) {
      out += ('0' + i);
      used_cnt += get_num(nums[i], cnt);
    }
  }

  assert(used_cnt == s.size());
  sort(out.begin(), out.end());
  return out;
}

int main()
{
  int t;
  cin >> t;

  for(int test = 1; test <= t; test++) {  
    string s;
    cin >> s;
    cout << "Case #" << test << ": " << solve(s) << std::endl;
  }

	return 0;
}
