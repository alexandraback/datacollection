#include <iostream>
#include <string>
#include <vector>

using namespace std;
typedef long long int int64;

bool consonant[256];

int main()
{
  for (int i = 0; i < 256; ++i)
    consonant[i] = true;
  consonant['a'] = false;
  consonant['e'] = false;
  consonant['i'] = false;
  consonant['o'] = false;
  consonant['u'] = false;

  int T;
  cin >> T;
  for (int case_num = 1; case_num <= T; ++case_num)
  {
    string name;
    int n;
    cin >> name >> n;
    int L = name.length();

    int64 count = 0;
    for (int start = 0; start < L; ++start)
    {
      int end;
      int num_cons = 0;
      for (end = start; end < L; ++end)
      {
	if (consonant[name[end]])
	  ++num_cons;
	else
	  num_cons = 0;
	if (num_cons >= n)
	  break;
      }
#if 0
      for (int k = end; k < L; ++k)
	cerr << name.substr(start, k - start + 1) << endl;
#endif
      count += (L - end);
    }

    cout << "Case #" << case_num << ": " << count << endl;
  }
  return 0;
}

