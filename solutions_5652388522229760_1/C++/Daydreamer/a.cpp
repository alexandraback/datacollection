#include <iostream>
using namespace std;
int main()
{
    int T; 
    cin >> T;

    for (int kase = 1; kase <= T; kase++)
{   

    int n;
    long long t = 0;
    cin >> n;

    cout << "Case #" << kase <<": ";
    if (n == 0) {cout << "INSOMNIA" << endl; continue;}
    
    t = n;
    bool a[10] = { 0 };
    
    while (true)
    {   int i = 0;
        
        long long cpy = t;
        while (cpy > 0)
        {   a[cpy % 10] = 1;
            cpy /= 10;
        }
        for (i = 0; i < 10; i++)
            if (a[i] != 1)
                break;
        
        if (i == 10) { cout << t << endl; break; }
        t += n;
    }
}
    return 0;
}
