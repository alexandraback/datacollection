#include<iostream>
#include<string>
using namespace std;

long long T,A,B,K;
string a,b,k;

string st(long long num)
{
       string res;
       if(num == 0)
              return "0";
       while(num)
       {
                 res += (num & 1) + '0';
                 num /= 2;
       }       
       reverse(res.begin(),res.end());
       return res;
}

long long dp[15][3][3][3];

long long sol(long long idx,long long ga,long long gb,long long gk)
{
    if(idx == a.size())
           return 1;
    long long& ret = dp[idx][ga][gb][gk];
    if(ret != -1)return ret;
    ret = 0;
    for(long long i = 0 ; i <= 1; i++)
            for(long long j = 0 ; j <= 1; j++)
            {
                long long ia = a[idx] - '0',ja = b[idx] - '0',ka = k[idx] - '0',na = 0,nb = 0,nk = 0;
                long long an = (i & j);
                if((ga == 0 && i > ia) || (gb == 0 && j > ja) || (gk == 0 && an > ka))
                       continue;
                if(ga == 1 || (ga == 0 && i < ia))
                      na = 1;
                if(gb == 1 || (gb == 0 && j < ja))
                      nb = 1;
                if(gk == 1 || (gk == 0 && an < ka))
                      nk = 1;
                ret += sol(idx + 1,na,nb,nk);
            }
     return ret;
}

int main()
{
    
    freopen("in2.in","r",stdin);
    freopen("out.out","w",stdout);
    cin >> T;
    long long t = 1;
    while(T--)
    {
              memset(dp,-1,sizeof dp);
              cin >> A >> B >> K;
              A--;B--;K--;
              
              a = st(A);
              b = st(B);
              k = st(K);
              
              long long mx = max(a.size(),max(b.size(),k.size()));
              string tmp = a;
              for(long long i = a.size(); i < mx; i++)
                      tmp = '0' + tmp;
              a = tmp;tmp = b;
              for(long long i = b.size(); i < mx; i++)
                      tmp = '0' + tmp;
              b = tmp;tmp = k;
              for(long long i = k.size(); i < mx; i++)
                      tmp = '0' + tmp;
              k = tmp;
              
              long long res = sol(0,0,0,0);
              cout << "Case #"<<t++<<": " << res << endl;          
              
    }   
}
