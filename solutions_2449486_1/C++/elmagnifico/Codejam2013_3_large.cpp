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
int main()
{
    freopen("C:\\Users\\Psyduck\\Desktop\\B-large.in","r",stdin);
    freopen("C:\\Users\\Psyduck\\Desktop\\output.txt","w",stdout);
    ll i,j,k,n,m,t,tcase,maxe,mine;
    bool flag=true;
    cin>>tcase;
    for(t=1;t<=tcase;t++)
    {
        cin>>n>>m;
        ll maxrow[n],maxcol[m],arr[n][m];
        flag=true;
        for(i=0;i<n;i++)for(j=0;j<m;j++)cin>>arr[i][j];
        for(i=0;i<n;i++)
        {
            maxe=INT_MIN;
            for(j=0;j<m;j++)maxe=max(maxe,arr[i][j]);
            maxrow[i]=maxe;
        }
        for(j=0;j<m;j++)
        {
            maxe=INT_MIN;
            for(i=0;i<n;i++)maxe=max(maxe,arr[i][j]);
            maxcol[j]=maxe;
        }
        //cout<<endl;for(i=0;i<n;i++)cout<<maxrow[i]<<" ";cout<<endl;
        //cout<<endl;for(i=0;i<m;i++)cout<<maxcol[i]<<" ";cout<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
            {
                if(arr[i][j]!=maxrow[i] && arr[i][j]!=maxcol[j]){flag=false;break;}
            }
            if(flag==false)break;
        }
        cout<<"Case #"<<t<<": ";
        if(!flag)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
    return 0;
}
