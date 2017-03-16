#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>

#define type long long

using namespace std;

bool cab[300];

void zr()
{
  for(int i=0; i<300;i++)
    cab[i]= 0;
}

bool check(string s)
{
  zr();
  cab[s[0]] = 1;
  for(int i=1; i<s.length(); i++)
  {
    if(s[i] != s[i-1] && cab[s[i]])
      return false;
    cab[s[i]] = 1;
  }
  return true;
}

string shorten(string s)
{
  for(int i=0; i<s.length()-1; i++)
    if(s[i] == s[i+1])
    {
      return s.substr(0, i) + shorten( s.substr(i+1, s.length()-i-1)  );
    }

  return s;
}


void permutation(vector< vector<int> > &perms, vector<int> &arr, int n)
{
  if(n == 1)
  {
    perms.push_back(arr);

    return;
  }
  
  for(int i=0; i<n; i++ )
  {
    permutation(perms, arr, n-1);

    if(n % 2 == 0)
      swap(arr[0], arr[n-1]);
    else
      swap(arr[i], arr[n-1]);
  }
}

vector< vector<int> > gen_perm(int n)
{ 
  vector< vector<int> > perms;
  vector<int> id;
  for(int i=0; i<n; i++)
    id.push_back(i);

  permutation(perms, id, n);
  return perms;
}

int main()
{

  // cin.tie(NULL);
  // std::ios::sync_with_stdio(false);
// 
  int T;
  cin>>T;
  int t=0;
  while(t<T)
  {
  	int n;
    cin>>n;
    string tab[10];
    for(int i=0; i<n; i++) 
      {
        string ss;
        cin>>ss;
        tab[i] = shorten(ss);
      }



    vector< vector<int> > perms = gen_perm(n);
  type res = 0;
  for(int j=0; j<perms.size(); j++)
  {
    string str = "";
    for(int x=0;x<n;x++)
      str += tab[perms[j][x]];

    res += check(str);

  }

	cout <<"Case #"<<t+1<<": "<<res<<"\n";

	t++;

  }

  return 0;
 
}