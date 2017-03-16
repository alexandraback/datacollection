#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <queue>
#include <vector>
#include <string>
#include <cstring>
#include <ctime>
#include <cmath>
#include <algorithm>
#define msg(var) cout << #var << " = " << var << endl
using namespace std;

int main()
{
    cin.sync_with_stdio(0); cin.tie(0);
    freopen("ss.in", "r", stdin);
    freopen("ss.out", "w", stdout);
    int t,i,j,k,n,temp,jeOtvoren[401],kutija[401][401],p,q,r,kljucevcici[401],start[401],out[401],n1,neZnamStaJeOvo[401],s;
    cin >> t;
    for(i=0;i<t;i++)
    {
        memset(kljucevcici,0,201*4);
        memset(start,0,201*4);
        memset(jeOtvoren,0,201*4);
        cin >> k >> n;
        for(j=1;j<=k;j++)
        {
                cin >> temp;
                start[temp]++;
        }
        for(j=1;j<=n;j++)
        {
                cin >> neZnamStaJeOvo[j] >> n1;
                for(p=0;p<n1;p++)
                                cin >> kutija[j][p];
                kutija[j][p]=0;
        }


        for(j=1;j<=n;j++)
        {
                memset(jeOtvoren,0,201*4);
                memset(kljucevcici,0,201*4);
                for(s=1;s<=k;s++)
                        kljucevcici[s]=start[s];
                if(start[neZnamStaJeOvo[j]])
                {
                        kljucevcici[neZnamStaJeOvo[j]]--;
                        jeOtvoren[j]=1;
                        p=0;
                        q=0;
                        while(kutija[j][p])
                        {
                                kljucevcici[kutija[j][p]]=1;
                                p++;
                        }
                        out[q++]=j;
                        for(r=1;r<=n;r++)
                        {
                                if((!jeOtvoren[r]) && kljucevcici[neZnamStaJeOvo[r]])
                                {
                                        jeOtvoren[r]=1;
                                        kljucevcici[neZnamStaJeOvo[r]]--;
                                        p=0;
                                        while(kutija[r][p])
                                        {
                                                kljucevcici[kutija[r][p]]++;
                                                p++;
                                        }
                                        out[q++]=r;
                                        r=0;
                                        if(q==n)
                                                break;
                                }
                        }
                        if(q==n)
                                break;
                }
          }
                if(q==n)
                {

                        printf("Case #%d: ",i+1);
                        for(j=0;j<n;j++)
                                printf("%d ",out[j]);
                        printf("\n");
                }
                else
                        printf("Case #%d: IMPOSSIBLE\n",i+1);
    }
 return 0;
}
