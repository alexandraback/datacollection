#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;

long long int diff = -1;
string str1, str2;
string now1, now2;
string ans1, ans2;
int flag;

int dg(int p)
{
  //cout << p << "," << now1 << "," << now2 << endl;
  //cout << p << endl;
  if (p == str1.size())
  {
    //cout << now1 << " " << now2;
    long long int s1, s2;
    s1 = 0; s2 = 0;
    for (int i = 0; i < str1.size(); ++i)
    {
      s1 = s1 * 10 + (int)now1[i] - (int)('0');
      s2 = s2 * 10 + (int)now2[i] - (int)('0');
    }
    long long int nowdiff = abs(s1 - s2);
    //cout << nowdiff << endl;
    if (diff < 0 || nowdiff < diff)
    {
      diff = nowdiff;
      ans1 = now1; ans2 = now2;
    }
    if (nowdiff == diff && (strcmp(now1.c_str(), ans1.c_str()) < 0 || (strcmp(now1.c_str(), ans1.c_str()) == 0 && strcmp(now2.c_str(), ans2.c_str()) < 0)))
    {
      ans1 = now1; ans2 = now2;
    }
  }
  else
  {
    int i = p;
    string tmp1, tmp2;
    tmp1 = now1; tmp2 = now2;
    if (flag == 1)
    {
      if (str1[i] == '?')
        now1[i] = '0';
      if (str2[i] == '?')
        now2[i] = '9';
      dg(p + 1);
      now1 = tmp1;
      now2 = tmp2;
    }
    else if (flag == -1)
    {
      if (str1[i] == '?')
        now1[i] = '9';
      if (str2[i] == '?')
        now2[i] = '0';
      dg(p + 1);
      now1 = tmp1;
      now2 = tmp2;
    }
    else
    {
      if (str1[i] != '?' && str2[i] != '?')
      {
        if (str1[i] < str2[i])
        {
          flag = -1;
          dg(p + 1);
        }
        else if (str1[i] > str2[i])
        {
          flag = 1;
          dg(p + 1);
        }
        else
          dg(p + 1);
      }
      else if (str1[i] == '?' && str2[i] == '?')
      {
        //cout << "1234" << endl;
        int prevflag = flag;
        // flag = 0
        now1[i] = '0'; now2[i] = '0';
        dg(p + 1);
        now1 = tmp1; now2 = tmp2;
        flag = prevflag;
        // flag = 1
        now1[i] = '1'; now2[i] = '0';
        flag = 1;
        dg(p + 1);
        flag = prevflag;
        now1 = tmp1; now2 = tmp2;
        // flag = -1
        now1[i] = '0'; now2[i] = '1';
        flag = -1;
        dg(p + 1);
        flag = prevflag;
        now1 = tmp1; now2 = tmp2;
      }
      else if (str1[i] == '?')
      {
        int prevflag = flag;
        // flag = 0;
        now1[i] = str2[i];
        dg(p + 1);
        now1 = tmp1; now2 = tmp2;
        flag = prevflag;
        // flag = 1
        if (str2[i] < '9')
        {
          now1[i] = (char)((int)str2[i] + 1);
          flag = 1;
          dg(p + 1);
          now1 = tmp1; now2 = tmp2;
          flag = prevflag;
        }
        // flag = -1
        if (str2[i] > '0')
        {
          now1[i] = (char)((int)str2[i] - 1);
          flag = -1;
          dg(p + 1);
          now1 = tmp1; now2 = tmp2;
          flag = prevflag;
        }
      }
      else
      {
        int prevflag = flag;
        // flag = 0;
        now2[i] = str1[i];
        dg(p + 1);
        now1 = tmp1; now2 = tmp2;
        flag = prevflag;
        // flag = 1;
        if (str1[i] > '0')
        {
          now2[i] = (char)((int)str1[i] - 1);
          flag = 1;
          dg(p + 1);
          now1 = tmp1; now2 = tmp2;
          flag = prevflag;
        }
        // flag = -1;
        if (str1[i] < '9')
        {
          now2[i] = (char)((int)str1[i] + 1);
          flag = -1;
          dg(p + 1);
          now1 = tmp1; now2 = tmp2;
          flag = prevflag;
        }
      }
    }
  }
}

int main()
{
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt)
  {
    flag = 0;
    diff = -1;
    cout << "Case #" << tt << ": ";
    cin >> str1 >> str2;
    now1 = str1; now2 = str2;
    dg(0);
    cout << ans1 << " " << ans2 << endl;
  }
  return 0;
}
