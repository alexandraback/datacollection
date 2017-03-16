#include <bits/stdc++.h>	//ry

using namespace std;

typedef long long ll;

int noOfDigits(ll n)      
{
    if (n == 0)
    {
        return 0;
    }
    
    int ans=0;
    while (n>0)
    {
        n /= 10;
        ans += 1;
    }
    return ans;
}

ll lst(ll N, int len, int MSB)
{
    ll ans = N - MSB*(pow(10, len-1));
    return ans;
}

ll minNoOfSteps(int N)
{
    if (N == 0)
    {
        return 0;
    }
    
    if (N == 1)
    {
        return 0;
    }
    
    if (N == 2)
    {
        return 10;
    }
    
    if (N >= 3)
    {
        ll ans = 10;
        ans = ans + (N-2)*9;
        
        for (int i = 1; i <= N-2; i++)
        {
            ans = ans + pow(10, i);
        }
        return ans;
        
    }
}


int main()
{
    freopen("file.in", "r",stdin);
    freopen("file.out", "w",stdout);
    int test, i;
    scanf("%d",&test);
    
    for (i = 1; i <= test; i++)
    {
        ll ans,N;
       
        cin>>N;
        
        int len = noOfDigits(N);
        
        ll noOfSteps = minNoOfSteps(len);

       
        int MSB = N/pow(10, len-1);
      
        ll digitsExceptMSB = lst(N, len, MSB);
       

        if (N <= 10)
        {
            ans = N;
        }


        else if (MSB == 1)
        {
            ans = noOfSteps + digitsExceptMSB;
        }


        else if (MSB != 1)
        {
            ans = noOfSteps + MSB + digitsExceptMSB;
        }
        
        printf("Case #%d: %lld\n",i,ans);
        
    }
    return 0;
}