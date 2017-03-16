#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <algorithm>
#include <stack>
#include <math.h>
#include <queue>


using namespace std;

string word[100];

int main()
{
    int t, n, m, j, k, req, en, min;
    cin>>t;
    for(int i=1; i<=t; i++)
    {
        cin>>n>>m>>k;
        if(k<=4)
        {
            cout<<"Case #"<<i<<": "<<k<<endl;
        }
        else
        {
            if(n<m)
            {
                int temp = n;
                n = m;
                m = temp;
            }

            min  = -1;
            if(n<m)
            {
                int temp = m;
                m = n;
                n = temp;
            }

            for(j=3; j<=n; j++)
            {
                req = 2*(2+j)-4;
                en = 2*j;
                if(en>=k && (min==-1 || req<min))
                    min = req;
            }

            for(j=3; j<=n; j++)
            {
                for(int l=3; l<=m; l++)
                {
                    req = 2*(l+j)-4-4;
                    en = (l-2)*(j-2) + req;
                    if(en>=k && (min==-1 || req<min))
                        min = req;
                }
            }

            cout<<"Case #"<<i<<": "<<min<<endl;
        }
    }
    return 0;
}
