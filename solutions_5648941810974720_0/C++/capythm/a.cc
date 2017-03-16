#include <iostream>
#include <string>
using namespace std;
int main( void )
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for( int testcase=1; testcase<=T; testcase++ ){
    string S;
    cin >> S;
    int a[256];
    int ret[10];
    for( int i='A'; i<='Z'; i++ ) a[i] = 0;
    for( int i=0; i<S.size(); i++ ){
      a[S[i]]++;
    }
    for( int i=0; i<10; i++ ) ret[i] = 0;

    ret[0] = a['Z'];
    a['E'] -= a['Z'];
    a['R'] -= a['Z'];
    a['O'] -= a['Z'];
    a['Z'] -= a['Z'];

    ret[2] = a['W'];
    a['T'] -= a['W'];
    a['O'] -= a['W'];
    a['W'] -= a['W'];

    ret[6] = a['X'];
    a['S'] -= a['X'];
    a['I'] -= a['X'];
    a['X'] -= a['X'];

    ret[8] = a['G'];
    a['E'] -= a['G'];
    a['I'] -= a['G'];
    a['H'] -= a['G'];
    a['T'] -= a['G'];
    a['G'] -= a['G'];

    ret[7] = a['S'];
    a['E'] -= a['S'];
    a['V'] -= a['S'];
    a['E'] -= a['S'];
    a['N'] -= a['S'];
    a['S'] -= a['S'];

    ret[5] = a['V'];
    a['F'] -= a['V'];
    a['I'] -= a['V'];
    a['E'] -= a['V'];
    a['V'] -= a['V'];

    ret[4] = a['F'];
    a['O'] -= a['F'];
    a['U'] -= a['F'];
    a['R'] -= a['F'];
    a['F'] -= a['F'];

    ret[3] = a['T'];
    a['H'] -= a['T'];
    a['R'] -= a['T'];
    a['E'] -= a['T'];
    a['E'] -= a['T'];
    a['T'] -= a['T'];

    ret[9] = a['I'];
    a['N'] -= a['I'];
    a['E'] -= a['I'];
    a['N'] -= a['I'];
    a['I'] -= a['I'];

    ret[1] = a['O'];

    cout << "Case #" << testcase << ": ";
    for( int i=0; i<10; i++ ){
      for( int j=0; j<ret[i]; j++ ) cout << i;
    }
    cout << endl;
  }
}
