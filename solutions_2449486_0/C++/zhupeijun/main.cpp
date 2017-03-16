#include <iostream>
#include <cstdio>

using namespace std;

int mtx[105][105],mxc[105],mxr[105];

int main()
{
    int n,m,cn,ca,i,j;

    freopen("BS.in","r",stdin);
    freopen("BS.out","w",stdout);

    cin >> cn;

    for(ca = 1;ca <= cn;ca++)
    {
        cin >> n >> m;

        for(i = 0;i < n;i++)
            mxr[i] = 1;

        for(j = 0;j < m;j++)
            mxc[j] = 1;

        for(i = 0;i < n;i++)
        {
            for(j = 0;j < m;j++)
            {
                cin >> mtx[i][j];

                if(mtx[i][j] > mxr[i]) mxr[i] = mtx[i][j];
                if(mtx[i][j] > mxc[j]) mxc[j] = mtx[i][j];
            }
        }

        int ans = true;
        for(i = 0;i < n;i++)
        {
            for(j = 0;j < m;j++)
            {
                if(mxr[i] > mtx[i][j] && mxc[j] > mtx[i][j])
                {
                    ans = false;
                    goto loop;
                }

            }
        }

        loop:

        cout << "Case #"<< ca <<": ";
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;
}
