#include <iostream>
#include <set>

using namespace std;

int pailie(int n, int k) 
{
    if(k == 0 || n == k) return 1;
    int res = 1;
    for(int i = 1; i <= n; i++)
    {
        res *= i;
    }
    for(int i = 1; i <= k; i++)
    {
        res /= i;
    }
    for(int i = 1; i <= (n - k); i++)
    {
        res /= i;
    }
    return res;
}
int calc(int d, int bit)
{
    if(bit == 1) return 0;
    if(d < 1) return 0;
    int res = 0;
    for(int j = 0; j < (bit - 1); j++)
    {
        int c = 1;
        for(int i = 0; i < (bit - j); i++) 
        {
            c *= d;
        }
        for(int i = 0; i < j; i++)
        {
            c *= (10 - d);
        }
        c *= pailie(bit - 1, j);
        if(j == 0) c -= d;
        c *= (bit -j - 1);
        res += c / 2;
    }
    return res;
}

int count(int a, int b) 
{
    int s = 1;
    int ta = a;
    int tb = b;
    int res = 0;
    int bit = 1;
    while(ta / 10)
    {
        s *= 10;
        ta /= 10;
        tb /= 10;
        bit++;
    }
    res += calc(tb - ta, bit);
    ta = ta * s;
    tb = tb * s;
    
    return res;
}

int bad(int a, int b) 
{
    int ta = a;
    int s = 1;
    int e = 1;
    int bit = 1;
    set<int> cache;
    while(ta / 10)
    {
        s *= 10;
        ta /= 10;
        bit++;
    }
    int res = 0;
    for(int i = a; i < b; i++) 
    {
        int ts = s * 10;
        int te = e;
        cache.clear();
        for(int j = 0; j < (bit - 1); j++)
        {
            ts /= 10;
            te *= 10;
            //cout << "ts " << ts << " te " << te << endl;
            int t = (i / te + (i % te) * ts);
            //cout << "t " << t << endl;
            if(t > i && t <= b && cache.count(t) == 0)
            {
                res++;
                cache.insert(t);
            }
        }
    }
    return res;
}

int main()
{
    int t;
    cin >> t;
    int a, b;
    for(int i = 0; i < t; i++) 
    {
        cin >> a >> b;

        cout << "Case #" << (i + 1) << ": ";
        cout << bad(a, b);
        cout << endl;
    }
    return 0;
}
