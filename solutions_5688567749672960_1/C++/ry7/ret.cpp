#include <bits/stdc++.h>	//ry

//my program
//orignal
using namespace std;

typedef long long ll;

int nd(ll p)      
{
    if (p == 0)
    {
        return 0;
    }
    
    int res=0;
    while (p>0)
    {
        p /= 10;
        res += 1;
    }
    return res;
}

ll lst(ll N, int len, int MSB)
{
    ll ans = N - MSB*(pow(10, len-1));
    return ans;
}

ll min(int x)
{
    if (x == 0)
    {
        return 0;
    }
    
    if (x == 1)
    {
        return 0;
    }
    
    if (x == 2)
    {
        return 10;
    }
    
    if (x >= 3)
    {
        ll ans = 10;
        ans = ans + (x-2)*9;
        
        for (int i = 1; i <= x-2; i++)
        {
            ans = ans + pow(10, i);
        }
        return ans;
        
    }
}


int main()
{
   
    int test, i;
    scanf("%d",&test);
    
    for (i = 1; i <= test; i++)
    {
        ll ans,N;
       
        cin>>N;
        
        int len = nd(N);
        
        ll ns = min(len);

       
        int MSB = N/pow(10, len-1);
      
        ll dg = lst(N, len, MSB);
       

        if (N <= 10)
        {
            ans = N;
        }


        else if (MSB == 1)
        {
            ans = ns + dg;
        }


        else if (MSB != 1)
        {
            ans = ns + MSB + dg;
        }
        
        printf("Case #%d: %lld\n",i,ans);
        
    }
    return 0;
}