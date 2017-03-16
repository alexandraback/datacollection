#include <iostream>
#include <string>
using namespace std;

#define FOR(i, a, b) for(int i(a);i<=(int)(b);i++)
#define REP(i,n) FOR(i,0,n-1)


void Prepare() {

}

void Work(int casenum) {
    string s;
    cin >> s;
    string t;
    REP(i, s.length()) {
        string e;
        e.push_back(s[i]);
        if (t + e <= e + t)
            t = e + t;
        else
            t = t + e;
    }
    cout << "Case #" << casenum << ": " << t << endl;
}

int main() {
  Prepare();
  int n;
  cin >> n;
  FOR(i, 1, n) Work(i);

}
