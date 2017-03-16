#include <bits/stdc++.h>

#include <stdio.h>
#include <iostream>
#include <sstream>
#include <math.h>
#include <limits.h>
#include <limits>
#include <string.h>
#include <string>
#include <algorithm>
#include <stack>
#include <set>
#include <ctime>
#include <queue>
#include <vector>
#include <map>
#include <assert.h>
#include <utility>
#define ms(a,b) memset(a,b,sizeof(a))
#define inf 1<<28
#define mp make_pair
#define pi acos(-1)
#define pii pair<int,int>
#define fs first
#define sc second
#define cffi ios_base::sync_with_stdio(0);cin.tie(0);
#define pob pop_back
#define vec_ vector
#define clr(a) a.clear()
#define pb push_back
#define eps 1E-7
#define sf scanf
#define pf printf
#define all(a) a.begin(),a.end()
#define allr(a) a.rbegin(),a.rend()
#define scch(a) scanf(" %c",&a)
#define scll1(a) scanf(" %I64d",&a)
#define scll2(a,b) scanf(" %I64d %I64d",&a,&b)
#define scll3(a,b,c) scanf(" %I64d %I64d %I64d",&a,&b,&c)
#define sci1(a) scanf(" %d",&a)
#define sci2(a,b) scanf(" %d %d",&a,&b)
#define sci3(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scd1(a) scanf(" %lf",&a)
#define scd2(a,b) scanf(" %lf %lf",&a,&b)
#define scd3(a,b,c) scanf(" %lf %lf %lf",&a,&b,&c)
#define sz(a) a.size()
#define ll long long
#define ull unsigned long long
#define dd double
using namespace std;

template<class T1> void deb(T1 e)
{
    cout<<e<<endl;
}
template<class T1,class T2> void deb(T1 e1,T2 e2)
{
    cout<<e1<<" "<<e2<<endl;
}
template<class T1,class T2,class T3> void deb(T1 e1,T2 e2,T3 e3)
{
    cout<<e1<<" "<<e2<<" "<<e3<<endl;
}
template<class T1,class T2,class T3,class T4> void deb(T1 e1,T2 e2,T3 e3,T4 e4)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<endl;
}
template<class T1,class T2,class T3,class T4,class T5> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<endl;
}
template<class T1,class T2,class T3,class T4,class T5,class T6> void deb(T1 e1,T2 e2,T3 e3,T4 e4,T5 e5,T6 e6)
{
    cout<<e1<<" "<<e2<<" "<<e3<<" "<<e4<<" "<<e5<<" "<<e6<<endl;
}


//double dur(int x1,int y1,int x2,int y2)
//{
//    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
//}
//template<class T> string toString(T n){ostringstream oss;oss<<n;oss.flush();return oss.str();}
//int toInt(string s){int r=0;istringstream sin(s);sin>>r;return r;}
//struct point{int x, y; point () {} point(int a, int b) {x = a, y = b;}};
//template <class T> T lcm(T a, T b){return (a/__gcd(a,b)) * b;}
//ll bigmod(ll B,ll P,ll M){ll R=1;while(P>0){if(P%2==1){R=(R*B)%M;}P/=2;B=(B*B)%M;}return R;}
//int X[]={0,-1,-1,-1,0,1,1,1};
//int Y[]={-1,-1,0,1,1,1,0,-1};
//int X[]={-1,0,1,0};
//int Y[]={0,1,0,-1};
//int X[]={1,1,2,2,-1,-1,-2,-2};//knight move//
//int Y[]={2,-2,1,-1,2,-2,1,-1};//knight move//

#define fop   freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define mt 10010
#define mod

int mat[6][6];

void pre()
{
    mat[1][1]=1;
    mat[1][2]=2;
    mat[1][3]=3;
    mat[1][4]=4;

    mat[2][1]=2;
    mat[2][2]=-1;
    mat[2][3]=4;
    mat[2][4]=-3;

    mat[3][1]=3;
    mat[3][2]=-4;
    mat[3][3]=-1;
    mat[3][4]=2;

    mat[4][1]=4;
    mat[4][2]=3;
    mat[4][3]=-2;
    mat[4][4]=-1;
}

string arr;

int arr1[mt],arr2[mt],n;

bool check(int num)
{
    int len=n-num-1;
    if(len < 0)
        return 0;
    return arr2[len]==4;
}

void pre2()
{
    int a,b,i,chinno,j,k,maan;
    a=arr[0]-'i'+2;
    arr1[0]=a;
    chinno=1;

    for(i=1; i<n; i++)
    {
        a=abs(arr1[i-1]);
        b=arr[i]-'i'+2;
        arr1[i]=mat[a][b] * chinno;
        if(arr1[i] < 0)
            chinno=-1;
        else
            chinno=1;
    }

    a=arr[n-1]-'i'+2;
    arr2[0]=a;
    chinno=1;

    for(i=1; i<n; i++)
    {
        b=abs(arr2[i-1]);
        a=arr[n-i-1]-'i'+2;

        arr2[i]=mat[a][b] * chinno;
        if(arr2[i] < 0)
            chinno=-1;
        else
            chinno=1;
    }
}

bool solve()
{
    pre2();
    int a,b,i,chinno,j,k,maan;

    for(i=0; i<n; i++)
    {
        if(arr1[i] != 2)
            continue;
        if(i == n-1)
            continue;

        a=arr[i+1]-'i'+2;
        maan=a;
        chinno=1;
        if(maan == 3 && check(i+2))
        return 1;

        for(j=i+2; j<n; j++)
        {
            a=abs(maan);
            b=arr[j]-'i'+2;
            maan=mat[a][b] * chinno;
            if(maan < 0)
                chinno=-1;
            else
                chinno=1;

            if(maan == 3 && check(j+1))
            return 1;
        }
    }

    return 0;
}

int main ()
{
//    cffi;
    fop;
    pre();
    int i,j,test,t=1,x;
    bool flag;

    cin>>test;
    string temp;
    while(test--)
    {
        arr="";
        cin>>n>>x>>temp;
        for(i=0; i<x; i++)
            arr+=temp;
        n=sz(arr);
        flag=solve();
        if(flag)
            printf("Case #%d: YES\n",t++);
        else
            printf("Case #%d: NO\n",t++);
    }

    return 0;
}

