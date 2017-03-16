#include<iostream>
using namespace std;
int n;
int num[1000][2];
int o[1000];
int ans = 0;

void dg(int p)
{
  if (p == n)
  {
    int sum = 0;
    for (int i = 0; i < p; ++i)
    {
      if (o[i] == 0) //non-origin
      {
        sum ++;
        bool flag1 = false; bool flag2 = false;
        for (int j = 0; j < p; ++j)
          if (o[j] == 1)
          {
            if (num[j][0] == num[i][0])
              flag1 = true;
            if (num[j][1] == num[i][1])
              flag2 = true;
          }
        if (flag1 == false || flag2 == false)
        {
          sum = -10000000;
          break;
        }
      }
      if (sum < 0)
        break;
    }
    if (sum > ans)
      ans = sum;
  }
  else
  {
    o[p] = 0;
    dg(p + 1);
    o[p] = 1;
    dg(p + 1);
  }
}

int main()
{
  int t;
  cin >> t;
  for (int tt = 1; tt <= t; ++tt)
  {
    ans = 0;
    cout << "Case #" << tt << ": ";
    string s1[1000], s2[1000];
    cin >> n;
    int w1 = 0;
    int w2 = 0;
    for (int i = 0; i < n; ++i)
    {
      string ss1, ss2;
      cin >> ss1 >> ss2;
      int flag = -1;
      for (int j = 0; j < w1; ++j)
        if (strcmp(s1[j].c_str(), ss1.c_str()) == 0)
        {
          flag = j;
          break;
        }
      if (flag == -1)
      {
        flag = w1;
        s1[w1] = ss1;
        w1 ++;
      }
      
      num[i][0] = flag;

      flag = -1;
      for (int j = 0; j < w2; ++j)
        if (strcmp(s2[j].c_str(), ss2.c_str()) == 0)
        {
          flag = j;
          break;
        }
      if (flag == -1)
      {
        flag = w2;
        s2[w2] = ss2;
        w2 ++;
      }
      num[i][1] = flag;
    }
    //for (int i = 0; i < n; ++i)
    //{
    //  for (int j = 0; j < 2; ++j)
    //    cout << num[i][j];
    //  cout << endl;
   // }
    dg(0);
    cout <<  ans << endl;
  }
  return 0;
}
