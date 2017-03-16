#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000001LL

long long Num[39]={
    1,
    4,
    9,
    121,
    484,
    10201,
    12321,
    14641,
    40804,
    44944,
    1002001,
    1234321,
    4008004,
    100020001LL,
    102030201LL,
    104060401LL,
    121242121LL,
    123454321LL,
    125686521LL,
    400080004LL,
    404090404LL,
    10000200001LL,
    10221412201LL,
    12102420121LL,
    12345654321LL,
    40000800004LL,
    1000002000001LL,
    1002003002001LL,
    1004006004001LL,
    1020304030201LL,
    1022325232201LL,
    1024348434201LL,
    1210024200121LL,
    1212225222121LL,
    1214428244121LL,
    1232346432321LL,
    1234567654321LL,
    4000008000004LL,
    4004009004004LL
};


bool par(long long X)
{
    vector<int> m;
    while(X> 0)
    {
        m.push_back(X%10);
        X/=10;
    }
    for(int i=0;i<m.size()/2; i++)
    {
        if(m[i]!=m[m.size()-1-i]) return false;

    }
    return true;
}
int main()
{
    /*
       for(long long i = 1LL; i< MAX ; i++)
       {
       if(par(i) && par(i*i)) cout<<i*i<<endl;
       }
     */
    int T; cin>>T;
    long long A,B;
    for(int t=1; t<=T; t++)
    {
        cin>>A>>B;
        int X=39; int Y= 39;
        for(int i=0;i<39;i++)
        {
            if(Num[i]==A-1)
            {
                X=i+1;
                break;
            }else if(Num[i]> A-1)
            {
                X=i;
                break;
            }
        }
        for(int i=0; i<39; i++)
        {
            if(Num[i]==B)
            {
                Y= i+1;
                break;
            }else if(Num[i]> B)
            {
                Y= i;
                break;
            }
        }
        cout<<"Case #"<<t<<": "<<Y-X<<endl;
    }
    return 0;
}
