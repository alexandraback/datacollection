#include<bits/stdc++.h>


using namespace std;
 
 
int NN(long long int n)       
{
    if (n == 0)
    {
        return 0;
    }
    int res=0;
    while (n>0)
    {
        n /= 10;
        res += 1;
    }
    return res;
}
 
long long MM(long long int N, int len, int MSB)
{
    long long int res = N - MSB*(pow(10, len-1));
    return res;
}
 
long long int minNoOfSteps(int N)
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
        long long res = 10;
        res= res + (N-2)*9;
        for (int i = 1; i <= N-2; i++)
        {
            res = res + pow(10, i);
        }
        return res;
    }
}
 
 
int main()
{
    int t, i;
    scanf("%d",&t);
    for (i = 1; i <= t; i++)
    {
        long long int ans;
        long long int N;
        scanf("%lld",&N);
        int len = NN(N);
 
        long long int noOfSteps = minNoOfSteps(len);
 
        int MSB = N/pow(10, len-1);

        long long int digitsExceptMSB = MM(N, len, MSB);

 
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