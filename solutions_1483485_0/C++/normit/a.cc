#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <vector>

#define mp make_pair
#define pb push_back

#define REP(i,n) for(int i=0; i < (n); ++i)

using namespace std;

//const char *mapping = "abcdefghijklmnopqrstuvwxyz";
  const char *mapping = "yhesocvxduiglbkrztnwjpfmaq";
  

void solve()
{
	string a;
	getline(cin,a);
	REP(i, a.size()) {
		if(a[i] >= 'a' && a[i] <= 'z') {
			a[i] = mapping[a[i]-'a'];
		}
	}
	cout << a << endl;
}

int main(int argc, char *argv[])
{
  int t;
  cin >> t;
  string ee;
  getline(cin,ee);

  for(int i = 1; i <= t; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }

  return 0;
}

