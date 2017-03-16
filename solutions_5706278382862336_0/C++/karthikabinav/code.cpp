#include <iostream>
#include <string>

using namespace std;
int gcd(int a, int b)
{
    if(b>a)
    {
        int t = a;
        a = b;
        b = t;
    
    }
    if (b==0) return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    cin>>t;  
    int qq = 1;
      while(t--)
      {
          string a;
          cin>>a;
          int p=0,q=0;
          int i;
          for(i=0;i<a.length();i++)
          {
              if(a[i] == '/')
                break;
              p = p*10+a[i]-'0';
          }
          for(i++;i<a.length();i++)
            q = q*10+a[i]-'0';
          int r = gcd(p,q);
          p = p/r;
          q = q/r;
          int w = q;
          while(w>1)
          {
            if(w%2!=0)
            {
              cout<<"Case #"<<qq<<": "<<"impossible"<<endl;
              qq++;
              break;
            }
            w/=2;
          }
          if(w>1)
            continue;
          int ans = 1;
          while((2*p)<q)
          {
              ans++;
              p = p*2; 
          }
          cout<<"Case #"<<qq<<": "<<ans<<endl;
          qq++;
      }



}
