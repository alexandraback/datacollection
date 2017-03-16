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
  int t, n, teste=1, a;
  
  cin >> t;
  while(t--)
  {
    cin >> n;
    
    map<int, int> count; 
    for(int i = 0; i < 2*n-1; i++)
    {
      for(int j = 0; j < n; j++)
      {
        cin >> a;
        count[a]++;
      }
    }
    
    cout << "Case #" << teste++ << ":";
    for(map<int, int>::iterator it = count.begin(); it != count.end(); it++)
      if(it->second%2) cout << " " << it->first;
    cout << endl;
  }
  
  
  return 0;
}
