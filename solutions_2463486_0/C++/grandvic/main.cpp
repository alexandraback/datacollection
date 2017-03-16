/*
 * main.cpp
 *
 *  Created on: 06.04.2013
 *      Author: grand
 */

#include <iostream>
#include <vector>

using namespace std;

const long long N_MAX = 100000000000000LL;

bool isPalindrome(long long x)
{
    vector<int> a;
    while(x!=0)
    {
        a.push_back(x%10);
        x/=10;
    }

    for(int i=0; i<(int)a.size()/2; ++i)
    {
        if(a[i]!=a[a.size()-i-1])
            return false;
    }

    return true;
}

int main()
{
//    for(long long i=1; i*i<=N_MAX; ++i)
//    {
//        if(isPalindrome(i) && isPalindrome(i*i))
//        {
//            printf("%lldLL, ", i*i);
//        }
//    }
//    printf("\n");

    long long p[] = {1LL, 4LL, 9LL, 121LL, 484LL, 10201LL, 12321LL, 14641LL, 40804LL, 44944LL, 1002001LL, 1234321LL, 4008004LL, 100020001LL,
    102030201LL, 104060401LL, 121242121LL, 123454321LL, 125686521LL, 400080004LL, 404090404LL, 10000200001LL, 10221412201LL,
    12102420121LL, 12345654321LL, 40000800004LL, 1000002000001LL, 1002003002001LL, 1004006004001LL, 1020304030201LL, 1022325232201LL,
    1024348434201LL, 1210024200121LL, 1212225222121LL, 1214428244121LL, 1232346432321LL, 1234567654321LL, 4000008000004LL, 4004009004004LL};

    int T;
    cin>>T;

    for(int t=1; t<=T; ++t)
    {
        long long N, M;
        cin>>N>>M;

        int count = 0;

        for(int i=0; i<(int)(sizeof(p)/sizeof(long long)); ++i)
        {
            if(p[i]>M) break;
            if(p[i]>=N) ++count;
        }

        cout<<"Case #"<<t<<": "<<count<<endl;
    }

    return 0;
}
