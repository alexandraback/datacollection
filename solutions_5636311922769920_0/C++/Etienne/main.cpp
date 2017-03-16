#include <iostream>

using namespace std;

void doCase()
{
    int k, c, s;
    cin >> k >> c >> s;
    int groups = (k-1)/c + 1;
    if(groups > s)
    {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    int cur=0;
    for(int i=0; i<groups; i++)
    {
        long long pos = 0;
        for(int j=0; j<c; j++)
        {
            pos *= k;
            pos += (cur < k ? cur : 0);
            cur++;
        }
        pos++;
        if(i != 0)
            cout << " ";
        cout << pos;
    }
    cout << endl;
    return;
}

int main()
{
    int cases;
    cin >> cases;
    for(int i=0; i<cases; i++)
    {
        cout << "Case #" << i+1 << ": ";
        doCase();
    }
    return 0;
}
