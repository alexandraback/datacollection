#include <iostream>
#include <string>

using namespace std;

int main()
{
    int t;
    cin>>t;
    
    int cnt = 1;
    while(t--)
    {
        string s;
        cin>>s;

        int n;
        cin>>n;
        
        int las = -1;
        long long count = 0;
        int i;

        int dp[1000006];
        if(s[0]!='a' && s[0]!='e' && s[0]!='i' && s[0]!='o' && s[0]!='u')
          dp[0] = 1;
        else
          dp[0] = 0;
      
        for(i=1;i<s.length();i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] =='o' || s[i] =='i' || s[i] == 'u')
              dp[i] = 0;
            else
              dp[i] = dp[i-1] + 1;
        
        }
        for(i=0;i<=s.length()-n;i++)
        {
            
            if(dp[i+n-1]>=n)
            {
                long long mul = (i-las)*(s.length()-i-n+1);
                //cout<<"--"<<i<<" "<<mul<<endl;
                las = i;
                count = count + mul;
            
            
            }
        
        
        }
        cout<<"Case #"<<cnt<<": "<<count<<endl;
        cnt++;

    }

}
