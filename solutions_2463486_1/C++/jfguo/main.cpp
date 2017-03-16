#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
#include <queue>
#include <map>
#include <sstream>
using namespace std;

typedef long long LL;
typedef unsigned int UINT32;

LL nums[] = {
  1LL,
  4LL,
  9LL,
  121LL,
  484LL,
  10201LL,
  12321LL,
  14641LL,
  40804LL,
  44944LL,
  1002001LL,
  1234321LL,
  4008004LL,
  100020001LL,
  102030201LL,
  104060401LL,
  121242121LL,
  123454321LL,
  125686521LL,
  400080004LL,
  404090404LL,
  10000200001LL,
  10221412201LL,
  12102420121LL,
  12345654321LL,
  40000800004LL,
  1000002000001LL,
  1002003002001LL,
  1004006004001LL,
  1020304030201LL,
  1022325232201LL,
  1024348434201LL,
  1210024200121LL,
  1212225222121LL,
  1214428244121LL,
  1232346432321LL,
  1234567654321LL,
  4000008000004LL,
  4004009004004LL,
  100000020000001LL,
  100220141022001LL,
  102012040210201LL,
  102234363432201LL,
  121000242000121LL,
  121242363242121LL,
  123212464212321LL,
  123456787654321LL,
  400000080000004LL
};

int str2int(const string &s) {
  stringstream ss(s);
  int a;
  ss >> a;
  return a;
}

string int2str(int a) {
  stringstream ss;
  ss << a;
  return ss.str();
}

// vector<LL> nums;

string calc()
{
  LL A, B;
  cin >> A >> B;
  int ans = 0;
  int size = sizeof(nums)/sizeof(nums[0]);
  // cerr << size << endl;

  for (int i = 0; i < size; ++i) {
    if (nums[i]>=A && nums[i]<=B) {
      ++ans;
    }
  }

  return int2str(ans);
}

bool isp(LL i) {
  stringstream ss;
  ss << i;
  string s = ss.str();
  for (int i = s.length() - 1, j=0; j < i; --i, ++j) {
    if (s[i] != s[j]) return false;
  }
  return true;
}

int main(void)
{
  /*
  int size = sizeof(nums)/sizeof(nums[0]);
  for (int i = 0; i < size; ++i) {
    cout << nums[i] << endl;
  }
  return 0;
  */
  /*
  for (LL i = 1; i <= 100000000; ++i) {
    if (isp(i) && isp(i*i)) {
      // nums.push_back(i*i);
      cout << i*i << "LL," << endl;
    }
  }
  return 0;
  */

  // NOTE: if using getline() to read the input, the following two lines should be
  // added to read the line sepeartor in the first line. 
  string line;
  getline(cin, line);
	int N = str2int(line);

	for (int i=1; i<=N; ++i) {
		cout << "Case #" << i << ": " << calc() << endl;
	}

	return 0;
}
