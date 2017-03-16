/*
Original Author: El_Magnifico(Sudhanshu Shekhar)
*/

#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<sstream>
#include<cmath>
#include<list>
#include<climits>
#include<stack>
#include<map>
#include<bitset>
#include<queue>
#include<set>
#include<climits>
#include<cstring>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
typedef long long ll;
ll n,m;
ll arr[15][15];

ll sameelements(ll x)
{
    int i;
    for(i=0;i<m-1;i++)
    if(arr[x][i]!=arr[x][i+1])break;
    return i;
}

bool samecolumn(ll x)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i][x]!=1)return false;
    }
    return true;
}

int main()
{
    freopen("C:\\Users\\Psyduck\\Desktop\\B-small-attempt1.in","r",stdin);
    freopen("C:\\Users\\Psyduck\\Desktop\\output.txt","w",stdout);
    ll i,j,k,t,tcase,temp;
    bool flag=true;
    cin>>tcase;
    for(t=1;t<=tcase;t++)
    {
        cin>>n>>m;
        flag=true;
        cout<<"Case #"<<t<<": ";
        for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>arr[i][j];
        for(i=0;i<n;i++)
        {
            temp=sameelements(i);
            if(temp!=m-1)
            {
                //cout<<"Column check "<<i<<endl;
                for(j=0;j<m;j++)
                {
                    //cout<<"blah "<<j<<endl;
                    if(arr[i][j]==1 && !samecolumn(j)){flag=false;break;}
                }
            }
            if(!flag)break;
        }
        if(!flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
