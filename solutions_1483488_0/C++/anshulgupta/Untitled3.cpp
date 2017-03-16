#include <iostream>
#include <set>

using namespace std;

int count(int n, int B)
{
    int _n = n, rem, n_digits = 0, pow = 1, cnt = 0;
    set<int> s;
    
    while(_n > 0)
    {
        n_digits++;
        pow *= 10;
        _n /= 10;
    }
    pow /= 10;
    _n = n;
    while(n_digits--)
    {
        rem = n%10;
        n /= 10;
        n += rem*pow;
        if(n > _n && n <= B)
            s.insert(n);
    }
    
    return s.size();
}

int main()
{
    
    int T, A, B, n, num = 1, result;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        result = 0;
        cin >> A >> B;
        
        for(n = A; n < B; n++)
            result += count(n, B);    
        
        cout << "Case #" << num++ << ": " << result << endl;
    }

    return 0;
}
