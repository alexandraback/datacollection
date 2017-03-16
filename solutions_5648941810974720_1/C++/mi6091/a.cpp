#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[26];
int cnt[10][26];
int br[10];

string nums[] =
{
  "ZERO",
  "ONE",
  "TWO",
  "THREE",
  "FOUR",
  "FIVE",
  "SIX",
  "SEVEN",
  "EIGHT",
  "NINE"
};

int order[] = {0, 2, 4, 5, 6, 7, 8, 9, 1, 3};
char letter[] = {'Z', 'O', 'W', 'T', 'U', 'F', 'X', 'V', 'G', 'I'};
string s;

void precompute()
{
  for(int i = 0; i < 10; i++)
  {
    for(int j = 0; j < nums[i].size(); j ++)
    {
        cnt[i][nums[i][j] - 'A'] ++;
    }
  }
}
void solve ()
{
  memset(a, 0, sizeof(a));
  memset(br, 0, sizeof(br));
  cin >> s;

  for(int i = 0; i < s.size(); i++)
  {
    a[s[i] - 'A'] ++;
  }

  for(int i = 0; i < 10; i++)
  {
    char next = letter[order[i]];
    int count = a[next - 'A'];

    br[order[i]] = count;

    for(int j = 0; j < 26; j++)
    {
      a[j] -= count * cnt[order[i]][j];
    }
  }

  for(int i = 0; i < 10; i++)
  {
    //cout << br[i] << " " << endl;
    while(br[i]--)
    {
      cout << i;
    }
  }

  cout << endl;

}
int main ()
{
  precompute();
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++)
  {
    printf("Case #%d: ", i);
    solve();
  }

  return 0;
}
