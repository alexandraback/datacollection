#include <iostream>

using namespace std;

int main ()
{
  int lines, n, s, p, max;
  cin >> lines;
  string str;
  getline(cin, str);
  int NOTSURcnt = 0;
  int SURcnt = 0;
  int SURmin;
  for (int i=0; i<lines; i++) {
    cin >>n>>s>>p;
    if (p>1) {
      SURmin = 3*p-4;
    } else {
      SURmin = 3*p-2;
    }
    for (int j=0; j<n; j++) {
      int x;
      cin >> x;
      if (x>=3*p-2) {
        NOTSURcnt++;
      } else if (SURmin<=x && x<3*p-2) {
        SURcnt++;
      }
    }
    getline(cin, str);
    int SURcntReal = SURcnt > s? s : SURcnt;
    max = NOTSURcnt + SURcntReal;
    cout << "Case #"<<i+1<<": "<<max<<endl;
    NOTSURcnt = 0;
    SURcnt = 0;
  }
  return 0;
}
