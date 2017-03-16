
#include <iostream>
#include <string>
#include <map>

using namespace std;

#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

int main(){
  string before;
  int N;
  map<char,char> m;

  m[' '] = ' ';
  m['y'] = 'a';
  m['n'] = 'b';
  m['f'] = 'c';
  m['i'] = 'd';
  m['c'] = 'e';
  m['w'] = 'f';
  m['l'] = 'g';
  m['b'] = 'h';
  m['k'] = 'i';
  m['u'] = 'j';
  m['o'] = 'k';
  m['m'] = 'l';
  m['x'] = 'm';
  m['s'] = 'n';
  m['e'] = 'o';
  m['v'] = 'p';
  m['q'] = 'z';
  m['p'] = 'r';
  m['d'] = 's';
  m['r'] = 't';
  m['j'] = 'u';
  m['g'] = 'v';
  m['t'] = 'w';
  m['h'] = 'x';
  m['a'] = 'y';
  m['z'] = 'q';


  cin >> N;
  getline(cin,before);  

  for(int i = 1; i <= N; i++){
    getline(cin,before);
    cout << "Case #" << i << ": ";
    for(int j = 0; j < before.size(); j++){
      char c = m[ before[j] ];
	cout << m[ before[j] ];
    }
    cout << endl;
  }

  return 0;
}
