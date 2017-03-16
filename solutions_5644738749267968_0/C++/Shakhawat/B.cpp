#include <iostream>
#include <vector>
#include <map>
#include <cstring>
#include <list>
#include <queue>
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <sstream>
#include <bitset>
#include <set>

using namespace std;

double a[1010],b[1010];
bool ta[1010],tb[1010];

int main()
{
    int T,cased=0,n,x,y;
    freopen("a.txt","r",stdin);
    freopen("b.txt","w",stdout);
    cin>>T;
    while(T--)
    {
        cin>>n;
        x=y=0;
        memset(ta,false,sizeof(ta));
        memset(tb,false,sizeof(tb));
        for(int i=0; i<n; i++)cin>>a[i];
        for(int i=0; i<n; i++)cin>>b[i];
        sort(a,a+n);
        sort(b,b+n);
//        for(int i=0;i<n;i++)cout<<a[i]<<" ";
//        cout<<endl;
//        for(int i=0;i<n;i++)cout<<b[i]<<" ";
//        cout<<endl;
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
            {
                if(a[i]>b[j] and ta[i]==false and tb[j]==false)
                {
                    x++;
                    ta[i]=tb[j]=true;
                    break;
                }
                if(a[i]<b[j])break;
            }
        memset(ta,false,sizeof(ta));
        memset(tb,false,sizeof(tb));
        bool pos;
        for(int i=n-1; i>=0; i--)
        {
            pos=true;
            for(int j=0; j<n; j++){
                  if(a[i]<b[j] and tb[j]==false){ pos=false;tb[j]=true;break;}

                       }
             if(pos==true)y++;

        }

        printf("Case #%d: %d %d\n",++cased,x,y);

    }
}
