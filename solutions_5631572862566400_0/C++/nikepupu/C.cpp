#include <iostream>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

using namespace std;

int n[1200];
int used[1200];
int circle[1200];
int m,N;

void search(int cnt)
{
  while(true)
  {
    int temp = 0;
    for(int i = 0; i < N; i++ )
      if(used[i])
        temp++;

    if(temp == N)
        break;

    if( ! used[n[circle[cnt-1]]] )//no mutual friend
    {
      circle[cnt] = n[circle[cnt-1]];
      used[n[circle[cnt-1]]] = 1;
      cnt++;
    

      if( n[circle[cnt-1]] == circle[0] || ( (cnt-2 >= 0) && n[circle[cnt-1]] == circle[cnt-2] ) )
         m = max(m, cnt);
    }

    else
    {
      if(cnt-2 >= 0 && n[circle[cnt-1]] == circle[cnt-2])
        for(int i = 0 ; i < N; i++)
        {
          if( !used[i])
          {
             used[i] = 1;
             circle[cnt] = i;
             cnt++;
       
            if( n[circle[cnt-1]] == circle[0]|| ( (cnt-2 >= 0) && n[circle[cnt-1]] == circle[cnt-2] ))
               m = max(m, cnt);
             search(cnt+1);
             used[i] = 0;
             cnt--;  
        }
      }
      break;

    }
   
   
  }
}

int main()
{
  	int T;
  	cin >> T;
	for(int t = 1; t <= T; t++)
	{
		cout << "Case #"<<t<<": ";
    cin >> N;
    memset(n, 0, sizeof(n));
    memset(used, 0, sizeof(used));
    memset(circle, 0, sizeof(circle));
    m = -1;

    for(int i = 0; i < N; i++)
    {
      int temp;
      cin >> temp;
      n[i] = temp-1;
    }
    for(int i = 0; i < N; i++)
    {
      used[i] = 1;
      circle[0] = i;
      search(1);
      used[i] = 0;
    }
    if(m > 0)
    cout << m << endl;
  else
    cout << 0 << endl;
  		
	}
  

  return 0;
}