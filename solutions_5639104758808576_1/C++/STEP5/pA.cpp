#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    for(int tt=1; tt<=T; tt++)
    {
      int N;
      cin>>N;
      string s;
      cin>>s;

      int ans = 0;
      int now = 0;
      for(int i=0; i<=N; i++)
      {
        for(int j=0; j<s[i]-'0'; j++)
        {
          while(now < i)
          {
            ans++;
            now++;
          }
          now++;
        }
      }
      cout<<"Case #"<<tt<<": "<<ans<<endl;
    }

    return 0;
}
