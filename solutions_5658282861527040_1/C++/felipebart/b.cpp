#include <iostream>

using namespace std;

long long rightmostbitpos(long long k)
{
    long long ret = 0;
    while((1 << ret) <= k)
    {
        ++ret;
    }
    
    --ret;
    return ret;
}

long long calc(long long a, long long b, long long k)
{
    //cout << a << " " << b << " " << k << "\n";
    if(a < b)
    {
        return calc(b, a, k);
    }
    
    if(k == 0)
    {
        return (a+1)*(b+1);
    }
    
    if (b < k)
    {
        return 0;
    }
    
    int ia = rightmostbitpos(a);
    int ib = rightmostbitpos(b);
    int ik = rightmostbitpos(k);
    //cout << ia << " " << ib << " " << ik << "\n";
    
    if(ia > ib)
    {
        return calc(a - (1 << ia), b, k) + calc((1 << ia) - 1, b, k);
    }
    else if(ib > ik)
    {
        return (a - (1 << ia) + 1) * (b - (1 << ib) + 1) + calc(a - (1 << ia), (1 << ib) - 1, k) + calc((1 << ia) - 1, b - (1 << ib), k) + calc((1 << ia) - 1, (1 << ib) - 1, k);
    }
    
    return calc(a - (1 << ia), b - (1 << ib), k - (1 << ik));
    
}

int main()
{
    int t;
    cin >> t;
    for(int lp=1;lp<=t;++lp)
    {
        long long a, b, k;
        cin >> a >> b >> k;
        cout << "Case #" << lp << ": " << a*b - calc(a-1,b-1,k) << "\n";
    }
    
    return 0;
}