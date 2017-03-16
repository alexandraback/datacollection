#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<deque>
#include<map>
#include<set>
#include<utility>
using namespace std;

#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define pob pop_back
#define ll long long
#define MAX_SIZE 200005
#define MOD 1000000007
#define S(x) scanf("%d",&x)
#define SL(x) cin>>x
#define SC(x) scanf("%c",&x)
#define SS(x) scanf("%s",x)
#define SZ(x) x.size()
#define IT iterator
#define PI pair<int,int>
#define PL pair<ll,ll>
#define VI vector<int>
#define VL vector<ll>
#define VVI vector< VI >
#define VVL vector< VL >
#define VVP vector< PI >
#define READ() freopen("/Users/home/Desktop/input.txt","r",stdin)
#define WRITE() freopen("/Users/home/Desktop/output.txt","w",stdout)
#define dump() SC(dump_char)
int dump_char;

int main()
{
    READ();
    WRITE();
    int t;
    cin>>t;
    int i,j,x,y;
    for(i=1;i<=t;i++)
    {
        cin>>x>>y;
        printf("Case #%d: ",i);
        if(x<0)
        {
            char xstr[5]="EW";
            for(j=0;j<abs(x);j++)
            {
                cout<<xstr;
            }
        }
        else
        {
            char xstr[5]="WE";
            for(j=0;j<abs(x);j++)
            {
                cout<<xstr;
            }
        }
        
        if(y<0)
        {
            char ystr[5]="NS";
            for(j=0;j<abs(y);j++)
            {
                cout<<ystr;
            }
        }
        else
        {
            char ystr[5]="SN";
            for(j=0;j<abs(y);j++)
            {
                cout<<ystr;
            }
        }
        
        printf("\n");
    }
    return 0;
}