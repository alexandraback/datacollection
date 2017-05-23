#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
#include<cmath>

#define ulli unsigned long long int
#define MOD 1000000007

using namespace std;

ulli fns[40]={ 1,4,9,121,484,10201,12321,14641,40804,44944,1002001,1234321,4008004,100020001,102030201,104060401,121242121,123454321,125686521,400080004,404090404,10000200001LL,10221412201LL,12102420121LL,12345654321LL,40000800004LL,1000002000001LL,1002003002001LL,1004006004001LL,1020304030201LL,1022325232201LL,1024348434201LL,1210024200121LL,1212225222121LL,1214428244121LL,1232346432321LL,1234567654321LL,4000008000004LL,4004009004004LL};


int check_palindrome(ulli x)
{
    ulli temp=x;
    
    ulli c=0;
    
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
    
    freopen("C-large-1.in","r",stdin);
    freopen("large_C.txt","w",stdout);
    
    int T;
    cin>>T;
    int t=1;
    
    while(T--)
    {
              ulli a,b;
              cin>>a>>b;
              
              int count=0;
              
              for(int i=0;i<39;i++)
              {
                      if(fns[i]>=a && fns[i]<=b)
                      count++;
              }
              
              /*
              ulli ss=sqrt(a);
              if((ss*ss)<a) ss++;
              for(ss;1;ss++)
              {
                      if(ss*ss>b)
                                 break;
                      if(check_palindrome(ss) && check_palindrome(ss*ss))
                      {
                                              count++;
                                              cout<<ss*ss<<",";
                      }
              }
              */
              
              cout<<"Case #"<<t++<<": "<<count<<endl;        //replace OUTPUT by your answer ;)
    }
    
    return 0;
}
