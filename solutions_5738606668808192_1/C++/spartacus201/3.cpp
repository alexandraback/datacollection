#include<bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define MAX 100000007
using namespace std;

ll int numArr[20];
bool isprime[MAX + 10];
void sieve()
{
    ll int i,j;
    for(i=0;i<=MAX;i++)
        isprime[i] = 1;
    isprime[1]=0;
    for(i=2;i<=MAX;i++)
    {
        if(isprime[i])
        {
            for(j=2;i*j<=MAX;j++)
                isprime[i*j] = 0;
        }
    }
    //cout<<"\ndone\n";

}

bool checkPrime_(ll int n)
{
    ll int i;
    for(i=2;i<=sqrt(n);i++)
    {
        if(n%i == 0)
            return 0;
    }
    return 1;
}
bool checkPrime(ll int n)
{
    if(n<=MAX)
        return isprime[n];
    //cout<<"\nerror checkPrime\n";
    return (checkPrime_(n));
    return 0;
}

bool isvalid(ll int num,ll int n)
{
    int c;
    c = (1<<(n-1));
    if(num < c)
        return 0;
    if(num & 1)
        return 1;
    return 0;
}

string getBit(ll int num)
{
    string str;
    str = "";
    while(num > 0)
    {
        if(num & 1)
            str = str + '1';
        else str = str+'0';
        num = num >> 1;
    }
    reverse(str.begin() , str.end());
    return str;
}

ll int getDivisor(ll int num)
{
    ll int i;
    for(i=2;i<num;i++)
    {
        if(num % i == 0)
            return i;
    }
    cout<<"\ndivisor error\n";
    return 1;
}

ll int getNumber(ll int n,ll int base)
{
    ll int res,temp;
    res = 0;
    temp = 1;
    while(n > 0)
    {
        if(n & 1)
        {
            res += (temp);

        }
        temp*=base;
        n =  n >> 1;
    }
    return res;
}
int main()
{
    ll int t,n,i,k,j,ans,base,flag,num,loop;
    string str;
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);
    cin>>t;
    sieve();
    for(k=1;k<=t;k++)
    {
        cout<<"Case #"<<k<<":\n";
        cin>>n>>j;
        ans = 0;
        loop = (1<<n);
        for(i=0;i<loop;i++)
        {
            //if(i == 9)
                //cout<<"\nisvlid : "<<isvalid(i)<<"\n";
            if(isvalid(i,n))
            {
                flag = 0;
                for(base=2;base<=10;base++)
                {
                    num = getNumber(i,base);
            //if(i == 9)
                //cout<<"\nnum : "<<num<<"\n";
                    numArr[base]=num;
                    if(checkPrime(num))
                    {
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    str = getBit(i);
                    cout<<str<<str<<" ";
                    for(base=2;base<=10;base++)
                    {
                        cout<<getDivisor(numArr[base])<<" ";
                    }
                    cout<<"\n";
                    ans++;
                    if(ans == j)
                        break;
                }
            }
        }
        //cout<<ans<<"\n";
    }
    return 0;
}
