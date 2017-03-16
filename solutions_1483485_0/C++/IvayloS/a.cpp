#define _CRT_SECURE_NO_DEPRECATE
#include <iostream> 
#include <string>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <math.h>
#include <stack>
#include <deque>
#include <numeric>
#define all(x) x.begin(),x.end()
#define mpair make_pair
using namespace std;
typedef long long ll;
typedef long double ld;
const ld epsylon = 1e-9;
int main()
{

  //freopen("ivo.in","r",stdin);
  //freopen("code.out","w",stdout);
  //map<char, char> m;
  //int nt;
  //cin >> nt;
  //string a,b;
  //getline(cin, a);
  //for (int it=0;it<nt;++it){
  //  getline(cin,a);
  //  getline(cin,b);

  //  for (int  i =0 ;i<(int)a.size();++i){
  //    if (isalpha(a[i])) {
  //      m[a[i]] = b[i];
  //    }
  //  }
  //}
  //cerr << m.size() << endl;
  //int used[256];
  //memset(used, -1, sizeof(used));
  //for (map<char, char>::iterator it = m.begin();it!=m.end();++it){
  //  used[it->second] = 1;
  //}
  //for (char c='a'; c <= 'z'; ++c) {
  //  if (used[c] == -1) {
  //    m['z'] = c;
  //    break;
  //  }
  //}
  //cout << "char code[256];\n";

  //for (char c = 'a'; c <= 'z'; ++c) {
  //  printf("c[\'%c\'] = \'%c\';\n", c, m[c]);
  //}
  //return 0;

  freopen("google.in","r",stdin);
  freopen("google.out","w",stdout);
  char c[256];
  c['a'] = 'y';
  c['b'] = 'h';
  c['c'] = 'e';
  c['d'] = 's';
  c['e'] = 'o';
  c['f'] = 'c';
  c['g'] = 'v';
  c['h'] = 'x';
  c['i'] = 'd';
  c['j'] = 'u';
  c['k'] = 'i';
  c['l'] = 'g';
  c['m'] = 'l';
  c['n'] = 'b';
  c['o'] = 'k';
  c['p'] = 'r';
  c['q'] = 'z';
  c['r'] = 't';
  c['s'] = 'n';
  c['t'] = 'w';
  c['u'] = 'j';
  c['v'] = 'p';
  c['w'] = 'f';
  c['x'] = 'm';
  c['y'] = 'a';
  c['z'] = 'q';
  int nt;
  cin>>nt;
  string temp;
  getline(cin, temp);
  for(int it=1;it<=nt;it++)
  {
    getline(cin, temp);
    for (int i = 0; i< (int)temp.size();++i){
      if (isalpha(temp[i])) {
        temp[i] = c[temp[i]];
      }
    }
    cout<<"Case #"<<it<<": " << temp <<endl;
  }
  return 0;
}
