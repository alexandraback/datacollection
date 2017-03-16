#include <iostream>
#include <cstdio>

using namespace std;
#define LL long long

#define MAXN 2000005

int s[MAXN];
int x[MAXN];
int f[MAXN], fs[MAXN];
int rf[MAXN], rfs[MAXN];

const int mp[5][5] =
{
    {0, 0, 0, 0, 0},
    {0, 1, 2, 3, 4},
    {0, 2, 1, 4, 3},
    {0, 3, 4, 1, 2},
    {0, 4, 3, 2, 1}
};

const int mps[5][5] =
{
    {1, 1, 1, 1, 1},
    {0, 1, 1, 1, 1},
    {0, 1, -1, 1, -1},
    {0, 1, -1, -1, 1},
    {0, 1, 1, -1, -1}
};


int main()
{
//    cout << "Hello world!" << endl;
    freopen("inputC.in", "r", stdin);
    freopen("outputC.out", "w", stdout);
    int t;
    cin >> t;
    int cas = 1;
    long long X, L;
    while(t--)
    {
        cin >> L >> X;
        if(X > 12)
        {
              X  = X%4 + 8;
        }
        char temp;
        for(int i=0; i<L; i++)
        {
            cin >> temp;
            x[i] = temp - 'i' + 2;
        }
        for(int i=1; i<X; i++)
        {
            for(int j=0; j<L; j++)
                x[i*L+j] = x[j];
        }
        f[0] = x[0];
        fs[0] = 1;
        for(int i=1; i<X*L; i++)
        {
            fs[i] = mps[f[i-1]][x[i]]*fs[i-1];
            f[i] = mp[f[i-1]][x[i]];
        }
        rf[X*L-1] = x[X*L-1];
        rfs[X*L-1] = 1;
        for(int i=X*L-2; i>=0; i--)
        {
            rfs[i] = mps[x[i]][rf[i+1]]*rfs[i+1];
            rf[i] = mp[x[i]][rf[i+1]];
        }
        int l = -1;
        for(int i=0; i<X*L; i++)
        {
            if(f[i] == 2 && fs[i] == 1)
            {
                l = i;
                break;
            }
        }
        int r = -1;
        for(int i=L*X-1; i>=0; i--)
        {
            if(rf[i] == 4 && rfs[i] == 1)
            {
                r = i;
                break;
            }
        }
        bool flag = false;
        if(l < r)
        {
            int tmp = 1, tmps = 1;
            for(int i=l+1; i<r; i++)
            {
                tmps = tmps*mps[tmp][x[i]];
                tmp = mp[tmp][x[i]];
            }
            if(tmp == 3 && tmps == 1)
                flag = true;
            else
                flag = false;
        }
        cout << "Case #" << cas++ << ": ";
        if(!flag)
            cout << "NO" << endl;
        else
            cout << "YES" << endl;
    }
    return 0;
}
