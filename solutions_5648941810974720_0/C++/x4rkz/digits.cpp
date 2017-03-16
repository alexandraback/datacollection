#include <iostream>
#include <vector>
#include <map>

using namespace std;

int main()
{
  int N;
  cin >> N;
  for(int i = 1; i <= N; ++i) {
    map<char, int> m;

    for(int j = 'A'; j <= 'Z'; ++j)
      m[j] = 0;
    
    string s;
    cin >> s;

    for(int j = 0; j < s.size(); ++j) {
      m[s[j]] ++;
    }
    
    int nb[10] = {};

    nb[0] = m['Z'];
    nb[2] = m['W'];
    nb[6] = m['X'];
    nb[8] = m['G'];

    nb[7] = m['S'] - nb[6];
    nb[3] = m['H'] - nb[8];

    nb[4] = m['R'] - nb[0] - nb[3];
    nb[5] = m['V'] - nb[7];

    nb[9] = m['I'] - nb[5] - nb[8] - nb[6];
    nb[1] = m['O'] - nb[0] - nb[2] - nb[4];

    cout << "Case #" << i << ": ";
    for(int j = 0; j < 10; ++j)
      for(int k = 0; k < nb[j]; ++k)
	cout << j;
    cout << endl;
  }
}
