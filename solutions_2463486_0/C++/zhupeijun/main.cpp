#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

bool check(int x)
{
    vector<int> ar;
    while(x)
    {
        ar.push_back(x%10);
        x /= 10;
    }

    int i,N = ar.size(),n;
    n = N / 2;
    for(i = 0;i < n;i++)
    {
        if(ar[i] != ar[N - i - 1]) return false;
    }
    return true;
}

int res [5] = {
    1,4,9,121,484
};

int main()
{
    int ca,cn,i;

    freopen("CS.in","r",stdin);
    freopen("CS.out","w",stdout);

    cin >> cn;
    for(ca = 1;ca <= cn;ca++)
    {
        int a,b,cnt = 0;
        cin >> a >> b;
        for(i = 0;i < 5;i++)
        {
            if(res[i] >= a && res[i] <= b)
                cnt++;
        }
        cout << "Case #"<< ca <<": ";
        cout << cnt << endl;
    }
    return 0;
}
