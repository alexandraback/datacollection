#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define PII pair<int, int>
#define VPII vector<PII, PII>
typedef long long int ll;
typedef long double ld;

int main()
{
  ios::sync_with_stdio(false);  cin.tie(0);  cout.tie(0);
  int n, teste=1;
  string s;

  cin >> n;
  while(n--)
  {
    cin >> s;
    string neue;
    neue += s[0];
    for(int i = 1; i < s.size(); i++)
    {
      if(s[i] >= neue[0])
        neue = s[i] + neue;
      else
        neue = neue + s[i];
    }
    cout << "Case #" << teste++ << ": " << neue << endl;
  }
  
  
  return 0;
}
