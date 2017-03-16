#include <iostream>
#include <cmath>

using namespace std;

inline bool all_seen(int* seen)
{
    for(int i=0; i<10; i++)
        if(seen[i]==0)
            return false;
    return true;
}

inline void check_digits(int N, int* seen)
{
    while(N!=0)
    {
        seen[N%10] = 1;
        N /= 10;
    }
}

void last_number(int N)
{
    int seen[10];
    int N_orig = N;
    for(int i=0; i<10; i++)
        seen[i] = 0;
    int i=1;
    if(N == 0)
    {
        cout << "INSOMNIA" << endl;
        return;
    }
    while(true)
    {
        if(all_seen(seen))
        {
            cout << N << endl;
            return;
        }
        N = N_orig*i;
        check_digits(N,seen);
        i++;
    }
}

int main()
{
    int T, N;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        cin >> N;
        cout << "Case #" << i+1 << ": ";
        last_number(N);
    }
}

