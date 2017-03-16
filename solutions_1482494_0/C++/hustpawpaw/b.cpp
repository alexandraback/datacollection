#include<iostream>
using namespace std;
bool flag[1010][100];
int ans , n;
int r2[1010];
int r1[1010];
int t;
int now;
bool getAns;
int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out", "w", stdout);
    cin >> t;
    for (int test = 1 ; test <= t; ++test)
    {
        cin >> n;
        ans = 0;
        int total = 0;
        for (int i = 0 ; i <n; ++i)
        {
            flag[i][1] = false;
            flag[i][2] = false;
        }
        for (int i = 0; i < n; ++i)
        {
            cin >> r1[i];
            cin >> r2[i];
        }
        getAns = true;
        now = 0 ;
        while (total < n && getAns)
        {
             // cout << "sdasdas ";
              getAns = false;
              for (int i = 0 ; i < n ; ++i)
              {
              // cout << i << "    ";
                  if (flag[i][2])
                     continue;
                  if (r2[i] <= now)
                  {
                     flag[i][2] = true;
                     if (flag[i][1]) 
                     {
                         now ++;
                         getAns = true;
                         total++;
                         ++ans;
                         break;
                     } 
                     else
                     {
                         now +=2;
                         getAns = true;
                         total++;
                         ++ans;
                         break;
                     }
                  }
              }
              if (getAns)
              continue;
           
               for (int i = 0 ; i < n ; ++i)
              {
                     if (flag[i][1] || flag[i][2])
                     continue;
                  if (r1[i] <= now)
                  {
                      //          cout << "No second"<<i << " \n   ";
                     flag[i][1] = true;
                     now++;
                      getAns = true;  
                      ++ans;
                      break;
                   }
                }                
              
        }
        cout <<"Case #"<<test<<": ";
        if (!getAns)
        {
          cout << "Too Bad" << endl;
        }
        else
        {
            cout << ans <<endl;
        }
    }
    return 0;
}
