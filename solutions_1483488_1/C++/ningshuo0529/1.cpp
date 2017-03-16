#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdlib>
using namespace std;

int lenth(int num)
{
    int len=0;
    while(num)
    {
        num/=10;
        len++;
    }
    return len;
}

int flip(int num, int n)
{
    int p = lenth(num)-n;
    return (num%(int)(pow(10, p)))*pow(10, n) + num/(pow(10, p));
}

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int nt;
    cin>>nt;
    for(int i=1; i<=nt; i++)
    {
        int a,b;
        int ans=0;
        cin>>a>>b;
        cout<<"Case #" << i<<": ";
        for(int j=a; j<=b; j++)
        {
            int len = lenth(j);
            for(int k=1; k<len; k++)
            {
                int tmp=flip(j,k);
                if(tmp==j)
                    break;
                if(tmp<=b&&tmp>=a)
                    ans++;
            }
        }
        cout<<ans/2<<endl;
    }
}
