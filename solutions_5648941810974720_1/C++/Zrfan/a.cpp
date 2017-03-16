#include<iostream>
#include<cstring>
using namespace std;
int num[26];

int getnum(char ch)
{
  return (int)ch - (int)'A';
}

int deleten(string p)
{
  for (int i = 0; i < p.size(); ++i)
  {
    num[getnum(p[i])] --;
  }
}

int main()
{
  int t;
  cin >> t;
  for (int tt = 1; tt <=t; ++tt)
  {
    cout << "Case #" << tt << ": ";
    string str;
    cin >> str;
    memset(num, 0, sizeof(num));
    for (int i = 0; i < str.size(); ++i)
    {
      num[getnum(str[i])] ++;
    }
    
    int ans[10];
    memset(ans, 0, sizeof(ans));
    while (num[getnum('Z')])
    {
      ans[0] ++;
      deleten("ZERO");
    }
    while (num[getnum('G')])
    {
      ans[8] ++;
      deleten("EIGHT"); 
    }
    while (num[getnum('W')])
    {
      ans[2] ++;
      deleten("TWO");
    }
    while (num[getnum('X')])
    {
      ans[6] ++;
      deleten("SIX");
    }
    while (num[getnum('S')])
    {
      ans[7] ++;
      deleten("SEVEN");
    }
    while (num[getnum('U')])
    {
      ans[4] ++;
      deleten("FOUR");
    }
    while (num[getnum('R')])
    {
      ans[3] ++;
      deleten("THREE");
    }
    while (num[getnum('O')])
    {
      ans[1] ++;
      deleten("ONE");
    }
    while (num[getnum('F')])
    {
      ans[5] ++;
      deleten("FIVE");
    }
    while (num[getnum('E')])
    {
      ans[9] ++;
      deleten("NINE");
    }
    for (int i = 0; i < 10; ++i)
    {
      for (int j = 0; j < ans[i]; ++j)
        cout << i;
    }
    cout << endl;

  }
  return 0;
}
