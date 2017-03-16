#include <iostream>
#include <cassert>
using namespace std;


int main() {
  int T;
  std::ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> T;
  for(int cn = 1; cn <= T; ++cn) {
cerr << cn << " of " << T << '\n';

	char s[2005];
	cin >> s;

    int freq[256] = {0};
	int nums[10] = {0};

    for(int i = 0; s[i] != '\0'; ++i) {
	  freq[s[i]]++;
	}

    nums[0] = freq['Z'];
	freq['Z'] -= nums[0];
	freq['E'] -= nums[0];
	freq['R'] -= nums[0];
	freq['O'] -= nums[0];
    nums[6] = freq['X'];
	freq['S'] -= nums[6];
	freq['I'] -= nums[6];
	freq['X'] -= nums[6];
    nums[2] = freq['W'];
	freq['T'] -= nums[2];
	freq['W'] -= nums[2];
	freq['O'] -= nums[2];
    nums[4] = freq['U'];
	freq['F'] -= nums[4];
	freq['O'] -= nums[4];
	freq['U'] -= nums[4];
	freq['R'] -= nums[4];
    nums[8] = freq['G'];
	freq['E'] -= nums[8];
	freq['I'] -= nums[8];
	freq['G'] -= nums[8];
	freq['H'] -= nums[8];
	freq['T'] -= nums[8];

    nums[1] = freq['O'];
	freq['O'] -= nums[1];
	freq['N'] -= nums[1];
	freq['E'] -= nums[1];
    nums[3] = freq['H'];
	freq['T'] -= nums[3];
	freq['H'] -= nums[3];
	freq['R'] -= nums[3];
	freq['E'] -= 2 * nums[3];
    nums[5] = freq['F'];
	freq['F'] -= nums[5];
	freq['I'] -= nums[5];
	freq['V'] -= nums[5];
	freq['E'] -= nums[5];
    nums[7] = freq['S'];
	freq['S'] -= nums[7];
	freq['E'] -= nums[7];
	freq['V'] -= nums[7];
	freq['E'] -= nums[7];
	freq['N'] -= nums[7];
	nums[9] = freq['N'] / 2;
	freq['N'] -= 2 * nums[9];
	freq['I'] -= nums[9];
	freq['E'] -= nums[9];
	for(int i= 'A'; i <= 'Z'; ++i) assert(freq[i] == 0);
	cout << "Case #" << cn << ": ";
	for(int i = 0; i < 10; ++i) {
	  while(nums[i]--) cout << i;
	}
	cout << '\n';
  }
}

