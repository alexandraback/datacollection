#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <set>
using namespace std;

vector<string> cars;
int n;

string uni(string x)
{
  string un;
  un += x[0];
  for (int i = 1; i<x.length();i++)
    if (x[i]!=x[i-1])
      un += x[i];
  return un;
}

bool test(int* order,int l)
{
  string train;
  for (int i = 0; i<n;i++)
    train += cars[order[i]];
  string un = uni(train);
  return un.length()==l;
}

int main()
{
  int T;
  cin>>T;
  for (int t = 1;t<T+1;t++)
  {
    cin>>n;
    cars.clear();
    cars.resize(n);
    set<char> chars;
    for (int i = 0;i<n;i++)
    {
      cin>>cars[i];
      for (int j = 0;j<cars[i].length();j++)
        chars.insert(cars[i][j]);
      cars[i] = uni(cars[i]);
    }
    int order [n];
    for (int i = 0;i<n;i++)
      order[i] = i;
    int answer = 0;
    do
    {
      if (test(order,chars.size()))
        answer++;
      answer %= 1000000007;
    } while(next_permutation(order,order+n));
    cout<<"Case #"<<t<<": "<<answer<<endl;
  }
}