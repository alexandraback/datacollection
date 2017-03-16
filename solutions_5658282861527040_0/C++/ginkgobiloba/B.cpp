#include <iostream>
using namespace std;

int bits(long long a)
{
    int b=0;
    while(a)
    {
        ++b;
        a=a/2;
    }
    return b;
}

void calculate(long long A, long long B, long long K)
{
    long long ans = 0;
    long long one = 1;
    
    --A;
    --B;
    --K;

    /*ans = (A + 1) * (K + 1);
    if(B > K)
        ans += (B - K) * (K + 1);
    */
    //long long limit = (one << bits(K)) - 1;
    long long AA = A;//limit < A ? limit : A;
    long long BB = B;//limit < B ? limit : B;
    //cout<<AA<<" "<<BB<<endl;
    for(long long a = 0; a <= AA; ++a)
        for(long long b = 0; b <= BB; ++b)
        {
            if((a & b) <= K)
                ++ans;
            //cout<<a<<" "<<b<<" "<<(a&b)<<endl;
        }

    /*for(long long a = 0; a<=A; ++a)
        for(long long b = 0; b<=B; ++b)
            cout<<a<<" "<<b<<" "<<(a&b)<<endl;
            */
    cout<<ans<<endl;
}

int main()
{
    int numOfCases;
    cin>>numOfCases;
    for(int t=1; t<=numOfCases; ++t)
    {
        cout<<"Case #"<<t<<": ";
        long long A, B, K;
        cin>>A>>B>>K;
        calculate(A, B, K);
    }
    return 0;
}
