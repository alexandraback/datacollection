#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int T, n;

int getseen(int n)
{
    int seen = 0;
    int m = n;
    while (m > 0)
    {
        int d = m % 10;
        seen = seen | (1 << d);
        m = m / 10;
    }
    return seen;
}

int main()
{
    ifstream cin("A-large.in");
    ofstream cout("output.txt");
    
    cin >> T;
    for (int c = 0; c < T; c++) 
    {
        cin >> n;
        if (n == 0)
        {
            cout << "Case #" << c+1 << ": INSOMNIA" << endl;
            continue;
        }
        int seen = 0;
        int k = 1;
        while (seen < 1023)
        {
            seen = seen | getseen(k*n);
            k++;
            if (k > 1000)
            {
                cout << "ERROR" << endl;
                return 0;
            }
        }
        cout << "Case #" << c+1 << ": " << (k-1)*n << endl;                          
    }
    
    return 0;

}
