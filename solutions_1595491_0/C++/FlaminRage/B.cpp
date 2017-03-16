#include<iostream>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<utility>
#include<iomanip>
#include<queue>
#include<functional>
#define eps 1e-9
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define pb(a) push_back(a)
#define mp(a,b) make_pair(a,b)
#define pi acos(-1.0)
#define SET(a) memset(a,-1,sizeof a)
#define CLR(a) memset(a,0,sizeof a)
#define inf 1000000000
using namespace std;

int main()
{
/*
freopen("B-small-attempt1.in","r",stdin);
freopen("Bout.txt","w",stdout);
*/
int t,kk=1,n,s,p,arr[10];
cin>>t;
while(t--)
    {
    cin>>n>>s>>p;
    CLR(arr);
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int ans=0,a,b,c,d;
    sort(arr,arr+n,greater<int>());
    for(int i=0;i<n;i++)
        {
        if(arr[i]>1)
            {
            d=arr[i]/3;
            a=b=c=d;
            if(((d*3)+1)==arr[i]) c++;
            else if(((d*3)+2)==arr[i]) {b++;c++;}
            if(c>=p) ans++;
            else if(s>0)
                {
                b--;
                c++;
                if(abs(c-a)<=2 && abs(c-b)<=2 && c>=p){s--;ans++;}
                }
            }
        else {
             if(arr[i]>=p)ans++;
             }
        }
    cout<<"Case #"<<kk++<<": "<<ans<<endl;
    }
return 0;
}
