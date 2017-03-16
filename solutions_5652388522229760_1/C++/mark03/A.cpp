#include<bits/stdc++.h>
using namespace std;

void update(int a, int &m)
{
    while(a)
    {
        m |= (1<<(a%10));
        a /= 10;
    }
}

void calcola()
{
    int N, mask=0;
    cin >> N;
    
    if(N == 0)
    {
        cout << "INSOMNIA";
        return;
    }

    for(int i=1; ; ++i)
    {
        update(i*N, mask);
        if(mask == (1<<10)-1)
        {
            cout << i*N;
            return;
        }
    }
}


int main()
{
    int T;
    cin>>T;

    for(int i=0; i<T; ++i)
    {
        cout << "Case #" << i+1 << ": ";
        calcola();
        cout << "\n";
    }

    return 0;
}
