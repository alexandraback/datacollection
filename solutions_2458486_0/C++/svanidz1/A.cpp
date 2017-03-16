#include<math.h>
#include<algorithm>
#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<map>
#include<set>
#include<string>
#include<vector>
#include<queue>
#define Pi 3.141592
#define E 0.000001
#define Pp 1000000009
#define MA(a,b) (a>b?a:b)
#define MI(a,b) (a<b?a:b)
#define minn min_element
#define maxx max_element
#include<time.h>
#define X first
#define Y second
#define mp make_pair
#define pb push_back
using namespace std;
int n,m,i,j,k,l,r,te;
int a[1000],b[1000];
vector <int> v[1000],A;
bool fin,f[1000];
int st;
void go(int L)
{
    if (clock()-st>10000) return ;
    if (fin) return;
    if (L==n)
    {
        fin=1;
        cout<<"Case #"<<te<<":";
        for (i=0;i<n;i++)
            cout<<" "<<A[i];
        cout<<endl;
    }
    for (int i=1;i<=n;i++)
        if (f[i]==0)
        if (a[b[i]])
    {
        a[b[i]]--;
        f[i]=1;
        for (int j=0;j<v[i].size();j++) a[v[i][j]]++;
        A.pb(i);
        if (!fin) go(L+1);
        for (int j=0;j<v[i].size();j++) a[v[i][j]]--;
        A.pop_back();
        f[i]=0;
        a[b[i]]++;
    }
}
int main()
{
    freopen("D-small-attempt3.in","r",stdin);
    freopen("text.txt","w",stdout);
    long long T;
    cin>>T;
   while (T--)
   {
        st=clock();
       te++;
       cin>>m>>n;
       A.clear();
       for (i=1;i<=n;i++)
        v[i].clear(),f[i]=0;
        k=200;
       for (i=1;i<=k;i++)
        a[i]=0;
       for (i=1;i<=m;i++)
        cin>>l,a[l]++;
       for (i=1;i<=n;i++)
       {
           cin>>b[i];
           cin>>m;
           for (j=1;j<=m;j++)
           {
               cin>>l;
               v[i].pb(l);
           }
       }
       fin=0;
       go(0);
       if (fin==0) cout<<"Case #"<<te<<": IMPOSSIBLE"<<endl;

   }
    return 0;
}
