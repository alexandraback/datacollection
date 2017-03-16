#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
#include <math.h>
#include <queue>
#include <set>
#include <map>

#define pb push_back
#define mk make_pair
#define mod 1000000007

using namespace std;

int t,m,b,x;
int a[10][10];
int main() {
    freopen("B-small-attempt0.in","r",stdin);
    freopen("datab.out","w",stdout);
    cin>>t;
    for(int j=1; j<=t; j++)
    {
        cin>>b>>m;
        cout<<"Case #"<<j<<": ";
        if(m>(b*(b+1))/2)
            cout<<"IMPOSSIBLE\n";
        else
        {
            int c=0;
            for(int i=1; i<=b; i++)
                for(int k=1; k<=b; k++)
                    a[i][k]=0;
            for(int i=1; i<b; i++)
            {
                x=i;
                if(c==m)
                    break;
                for(int k=i; k<b; k++)
                {
                    c++;
                    a[k][b]=1;
                    if(x!=k)
                        a[x][k]=1;
                    x=k;
                    if(c==m)
                        break;
                }
            }
            cout<<"POSSIBLE\n";
            for(int i=1; i<=b; i++)
            {
                for(int k=1; k<=b; k++)
                    cout<<a[i][k];
                cout<<'\n';
            }
        }

    }
}
