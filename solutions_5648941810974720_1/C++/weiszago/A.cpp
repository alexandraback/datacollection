#include <bits/stdc++.h>
using namespace std;

int s[10];
int db[30];

void solve()
{
  string aaa;
  cin >> aaa;
  for (int i=0;i<10;i++) s[i]=0;
  for (int i=0;i<30;i++) db[i]=0;


  for (char c:aaa)
  {
    db[c-'A']++;
  }

  s[0]=db['Z'-'A'];
  s[2]=db['W'-'A'];
  s[4]=db['U'-'A'];
  s[6]=db['X'-'A'];
  s[7]=db['S'-'A']-db['X'-'A'];
  s[8]=db['G'-'A'];
  s[5]=db['V'-'A']-s[7];
  s[9]=db['I'-'A']-s[5]-s[6]-s[8];
  s[1]=db['O'-'A']-s[0]-s[2]-s[4];
  s[3]=db['H'-'A']-s[8];

  for (int i=0;i<10;i++)
  {
    for (int j=0;j<s[i];j++)
    {
      cout << i;
    }
  }
}

int main()
{
  freopen("A-large (1).in", "r", stdin);
  freopen("A-large.out", "w", stdout);
  ios_base::sync_with_stdio(false);

  int test;
  cin >> test;
  for (int t = 1;t<=test;t++) {
    cout << "Case #" << t<<": ";
    solve();
    cout << endl;
  }

  return 0;
}
