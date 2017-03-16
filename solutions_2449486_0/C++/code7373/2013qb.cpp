#include <cstdio>
#include <conio.h>
#include <ctime>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <cassert>
#include <queue>
using namespace std;

int C, TC=1;
int n,m,i,j,ii,jj,l[100][100];
int main()
{
	//freopen("C:\\Users\\root\\Downloads\\B-small-attempt2.in", "r+", stdin);
	//freopen("C:\\Users\\root\\Downloads\\B-small-attempt2.out", "w+", stdout);
    for (scanf ("%d", &C); TC <= C; TC++)
    {
////////////////////////////////////
        cin>>n>>m;
        memset(l, 0, sizeof(l));
        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
                cin>>l[i][j];

        for(i=0;i<n;++i)
            for(j=0;j<m;++j)
            {
                bool p=false;
                for(ii=0;ii<n&&l[ii][j]<=l[i][j];++ii);
                if(ii==n)
                    p=true;
                for(jj=0;(!p)&&(jj<m)&&(l[i][jj]<=l[i][j]);++jj);
                if(jj==m)
                    p=true;
                if(!p)
                {
                    cout<<"Case #"<<TC<<": "<<"NO"<<endl;
                    goto out1;
                }
            }

        cout<<"Case #"<<TC<<": "<<"YES"<<endl;
////////////////////////////////////
out1:;    }
    return 0;
}
