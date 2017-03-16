#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <set>
#include <vector>
using namespace std;

int b,m;
int a[6][6];
int result,cnt;

void go(int n)
{
    if (result>m) return;
    if (cnt>10000) return;
    cnt++;
    if (n==b-1) {result++;return;}

    for (int j=0;j<b;j++)
    {
        if (a[n][j]==1)
        {
            go(j);
            //cout<<n<<" go to "<<j<<endl;
        }

    }
}

int main()
{
    freopen("B-small-attempt2.in", "r", stdin);
    freopen("op.txt", "w", stdout);

    long long T,TT;
    long long i,j,k;
    srand((unsigned)time(NULL));


    cin>>T;
    for(TT=1;TT<=T;TT++)
    {
        cin>>b;
        cin>>m;

        int t=0;
        while (t!=100000)
        {
            cnt=0;
            result=0;
            for (i=0;i<b;i++)
                for (j=0;j<b;j++)
                {
                    if (i==b-1 || i==j || j==0) a[i][j]=0;
                    else a[i][j]=rand()%2;
                }

            go(0);
            if (result==m)
            {
                cout<<"Case #"<<TT<<": POSSIBLE"<<endl;
                for (i=0;i<b;i++)
                {
                    for (j=0;j<b;j++)
                    {
                        cout<<a[i][j];
                    }
                    cout<<endl;
                }
                break;
            }
            t++;
        }
        if (t==100000) cout<<"Case #"<<TT<<": IMPOSSIBLE"<<endl;
    }


    return 0;
}
