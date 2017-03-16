#include <bits/stdc++.h>
using namespace std;
const long long oo = 1LL << 60;

string a, b;
int n, id;
long long bestA, bestB;

int isBetter(long long curA, long long curB)
{
  if (llabs(curA - curB) < llabs(bestA - bestB))
    return 1;
  if (llabs(curA - curB) > llabs(bestA - bestB))
    return 0;
  if (curA < bestA)
    return 1;
  if (curA > bestA)
    return 0;
  return curB < bestB;
}

void att(int i, long long curA, long long curB)
{
  if (i == n)
  {
    if (isBetter(curA, curB))
    {
      bestA = curA;
      bestB = curB;
    }
  }
  else
  {
    curA *= 10;
    curB *= 10;
    if (a[i] == '?' && b[i] == '?')
    {
      att(i + 1, curA, curB);
      if (curA < curB) att(i + 1, curA + 9, curB);
      else if (curA > curB) att(i + 1, curA, curB + 9);
      else if (i < id)
      {
        if (a[id] > b[id]) att(i + 1, curA, curB + 1);
        else att(i + 1, curA + 1, curB);
      }
    }
    else if (a[i] == '?')
    {
      int digit = b[i] - '0';
      att(i + 1, curA + digit, curB + digit);
      if (curA < curB) att(i + 1, curA + 9, curB + digit);
      else if (curA > curB) att(i + 1, curA, curB + digit);
      else if (i < id)
      {
        if (a[id] > b[id]) att(i + 1, curA + (digit + 9) % 10, curB + digit);
        else att(i + 1, curA + (digit + 1) % 10, curB + digit);
      }
    }
    else if (b[i] == '?')
    {
      int digit = a[i] - '0';
      att(i + 1, curA + digit, curB + digit);
      if (curB < curA) att(i + 1, curA + digit, curB + 9);
      else if (curB > curA) att(i + 1, curA + digit, curB);
      else if (i < id)
      {
        if (b[id] > a[id]) att(i + 1, curA + digit, curB + (digit + 9) % 10);
        else att(i + 1, curA + digit, curB + (digit + 1) % 10);
      }
    }
    else att(i + 1, curA + a[i] - '0', curB + b[i] - '0');
  }
}

int len(long long x)
{
  return x < 10 ? 1 : len(x / 10) + 1;
}

void write(long long x)
{
  for (int i = len(x); i < n; i++)
    cout << 0;
  cout << x;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int test;
  cin >> test;
  for (int iTest = 1; iTest <= test; iTest++)
  {
    cerr << "Running test " << iTest << "..." << endl;
    cin >> a >> b;
    n = a.size(); 
    id = -1;
    for (int i = 0; i < n; i++)
      if (b[i] != '?' && a[i] != '?' && b[i] != a[i])
      {
        id = i;
        break;
      }

    bestA = oo;
    bestB = 0;
    att(0, 0, 0);
    cout << "Case #" << iTest << ": ";
    write(bestA);
    cout << ' ';
    write(bestB);
    cout << endl;
  }
}