#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <algorithm>
#include <map>
#include <vector>
#include <cstdio>
#include <cmath>

using namespace std;

int tst,tstt;

int i,j,qq,i1,i2,ost;
char ch, chh;
string s[550000];
int dp[55000][6];
string a,b,c;
map<string, int> q;

int main()
{
int     T=521196;
 freopen("email.txt","r",stdin);
      for (i=1;i<=T;i++){
          getline(cin,s[i]);
          q[s[i]] = 1;
      }

    freopen("c1.sol","w",stdout);
    cin >> tstt;
    for (tst=1;tst<=tstt;tst++){
        printf("Case #%d: ",tst);
        cin >> a;
        for (i=0;i<a.size();i++){
            dp[i+1][0] = 1000000;
            dp[i+1][1] = 1000000;            
            dp[i+1][2] = 1000000;            
            dp[i+1][3] = 1000000;
            dp[i+1][4] = 1000000;                        
            dp[i+1][5] = 1000000;            
            b = "";
            for (j=i;(j>=i-10) && (j>=0);j--){
                qq = 100000;
                b = a[j]+b;
                if (q[b] == 1) 
                   for (ost = 0;ost<=5;ost++)
                       dp[i+1][min(5,ost+(int)b.size())] = min(dp[i+1][min(5,ost+(int)b.size())], dp[j][ost]);
                   
                  for (ost=0;ost<=5;ost++)            
                for (i1=0;(i1<b.size());i1++)
                if (ost+i1>=5)
                    for (ch='a';(ch<='z');ch++){
                        c = b;
                        c[i1] = ch;
                        if (qq==100000)
                        if (q[c]) {
                           dp[i+1][min(5,(int)b.size()-i1)] = min(dp[i+1][min(5,(int)b.size()-i1)], dp[j][ost]+1);
//                        cout << i << " " << c << " " << dp[i+1][min(5,(int)b.size()-i1)] << endl;                           
                        }
                    }
                for (ost = 0;ost<=5;ost++)
                for (i1=0;(i1<b.size());i1++)
                if (ost+i1>=5)
                    for (ch='a';(ch<='z');ch++){
                        for (i2=i1+5;(i2<b.size());i2++)
                            for (chh='a';(chh<='z');chh++){
                                c = b;
                                c[i1] = ch;
                                c[i2] = chh;
                                if (qq==100000)                                
                                   if (q[c]){
                                      dp[i+1][min((int)b.size()-i2,5)] = min(dp[i+1][min((int)b.size()-i2,5)], dp[j][ost]+2);
                                   }
                            }
                    }                      
            }
        }
        int A;
        A = dp[a.size()][0];
        A = min(A, dp[a.size()][1]);
        A = min(A, dp[a.size()][2]);
        A = min(A, dp[a.size()][3]);
        A = min(A, dp[a.size()][4]);                        
        A = min(A, dp[a.size()][5]);        
        cout << A << endl;
    }
//    system("pause");
    return 0;
}
