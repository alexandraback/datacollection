#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cmath>

#define ulli unsigned long long int
#define MOD 1000000007

using namespace std;

int check_palindrome(int x)
{
    int temp=x;
    
    int c=0;
    
    while(temp)
    {
              c=c*10;
              c+=(temp%10);
              temp=temp/10;
    }
    if(c==x)
            return 1;
    return 0;
}   

int main()
{
    /* uncomment the following two lines to fectch input from input.txt and write to output.txt (after you have completed rest of your code) */
    
    freopen("C-small-attempt0.in","r",stdin);
    freopen("Coutput.txt","w",stdout);
    
    int T;
    cin>>T;
    int t=1;
    
    while(T--)
    {
              int a,b;
              cin>>a>>b;
              
              int ss=sqrt(a);
              
              int count=0;
              if((ss*ss)<a) ss++;
              for(ss;1;ss++)
              {
                      if(ss*ss>b)
                                 break;
                      if(check_palindrome(ss) && check_palindrome(ss*ss))
                      {
                                              count++;
                      }
              }
              
              
              cout<<"Case #"<<t++<<": "<<count<<endl;        //replace OUTPUT by your answer ;)
    }
    
    return 0;
}
