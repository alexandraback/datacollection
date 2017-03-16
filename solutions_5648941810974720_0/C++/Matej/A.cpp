#include <iostream>
#include <string>
using namespace std;

string S;

string numbers[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
char seq_c[] = {'Z', 'W', 'U', 'X', 'G', 'F', 'V', 'R', 'O', 'E'};
int seq_d[] = {0, 2, 4, 6, 8, 5, 7, 3, 1, 9};

int main()
{
  int T;
  cin >> T;
  getline(cin, S);
  for (int Ti = 1; Ti <= T; Ti++)
  {
    // input
    getline(cin, S);
    int N = S.length();
    
    // letter counts
    int counts[50];
    for (char a = 'A'; a <= 'Z'; a++)
      counts[a - 'A'] = 0;
    for (int n = 0; n < N; ++n)
      counts[S[n] - 'A']++;
    
    // number counts
    int num_counts[15];
    for (int d = 0; d < 10; ++d)
      num_counts[d] = 0;
    
    for (int d = 0; d < 10; ++d) {
      num_counts[seq_d[d]] = counts[seq_c[d] - 'A'];
      //for (int i = 0; i < count; ++i)
      //cout << seq_d[d];
      for (int i = 0; i < numbers[seq_d[d]].length(); ++i)
	counts[numbers[seq_d[d]][i] - 'A'] -= num_counts[seq_d[d]];
      
      //for (char a = 'A'; a <= 'Z'; a++)
      //  cout << a << ": " << counts[a - 'A'] << endl;
    }
    
    // produce output
    cout << "Case #" << Ti << ": ";
    for (int d = 0; d < 10; ++d)
      for (int i = 0; i < num_counts[d]; ++i)
	cout << d;
    cout << endl;
  }
  return 0;
}
