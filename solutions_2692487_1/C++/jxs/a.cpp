#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <algorithm>

using namespace std;

void testcase(int _t)
{
    int A, N;
    int min = 10000000;

    cin >> A;
    cin >> N;
    
    int n[N];
    for (int i=0; i < N; i++)
    {
        cin >> n[i];
    }  
    sort(n, n + N);

    if (A == 1) 
    {
        min = N; 
        
    } else {
        
    int count[N+1];
    for (int j=0; j<=N; j++)
    {
        count[j] = j;

        int x = A;
        for (int i=0; i<N-j; i++)
        {
            if (x > n[i])
            {
                x += n[i];
            } else
            {
                while (x <= n[i])
                {
                    x += x-1;
                    count[j]++;
                }
                x += n[i];
            }
        }
    }
    
    for (int i = 0; i<=N; i++)
    {
        if (count[i] < min) min = count[i];
    }
    }
    
    cout << "Case #" << _t << ": ";
    // Result goes here
    cout << min;
    cout << endl;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;
    
    for (int t=1; t<=T; t++) {
        testcase(t);
    } 
}
