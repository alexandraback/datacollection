#include <iostream>
#include <string>
#include <vector>

using namespace std;

typedef unsigned long long ull;

void fill(int i, string & s, char c)
{
  for (int j = i + 1; j < s.length(); j++)
    if (s[j] == '?')
      s[j] = c;
}

void compare(string & s, string & t, pair<string, string> & best)
{
  if (best == make_pair(string(), string()))
  {
    best = make_pair(s, t);
    return;
  }

  ull bs = stoull(best.first);
  ull bt = stoull(best.second);
  ull bd = bs > bt ? bs - bt : bt - bs;

  ull is = stoull(s);
  ull it = stoull(t);
  ull id = is > it ? is - it : it - is;
  
  if (id < bd || 
      (id == bd && is < bs) ||
      (id == bd && is == bs && it < bt))
    best = make_pair(s, t);
}

void complete(string s, string t, int i, pair<string, string> & best)
{
  if (s[i] < t[i])
  {
    fill(i, s, '9');
    fill(i, t, '0');
  }
  else
  {
    fill(i, s, '0');
    fill(i, t, '9');
  }

  compare(s, t, best);
}

int main()
{
  int T;
  cin >> T;
  
  for (int c = 1; c <= T; c++)
  {
    string s, t;
    cin >> s >> t;
    
    pair<string, string> best = make_pair(string(), string());
    
    int i = 0; 
    
    while (i < s.length())
    {
      if (s[i] == '?' && t[i] == '?')
      {
        s[i] = '0'; t[i] = '1';
        complete(s, t, i, best);
        s[i] = '1'; t[i] = '0';
        complete(s, t, i, best);
        s[i] = t[i] = '0';
      }
      else if (s[i] != '?' && t[i] != '?')
      {
        if (s[i] != t[i])
        {
          complete(s, t, i, best);
          break;
        }
      }
      else if (s[i] == '?')
      {
        if (t[i] > '0')
        {
          s[i] = t[i] - 1;
          complete(s, t, i, best);
        }
        if (t[i] < '9')
        {
          s[i] = t[i] + 1;
          complete(s, t, i, best);
        }
        s[i] = t[i];
      }
      else if (t[i] == '?')
      {
        if (s[i] > '0')
        {
          t[i] = s[i] - 1;
          complete(s, t, i, best);
        }
        if (s[i] < '9')
        {
          t[i] = s[i] + 1;
          complete(s, t, i, best);
        }
        t[i] = s[i];
      }
      i++;
    }
    
    if (i == s.length())
      compare(s, t, best); 

    cout << "Case #" << c << ": " << best.first << " " << best.second;
    cout << endl;
  }
  
  return 0;
}
