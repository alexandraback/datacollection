#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<cassert>
#include<set>
#include<queue>
#include<map>

using namespace std;

#define vi vector < int >
#define pb push_back
#define ll long long
#define llu unsigned long long
#define MOD 1000000007
#define INF 2000000000
#define dbg(x) { cout<< #x << ": " << (x) << endl; }
#define all(x) x.begin(),x.end()

int nao[1001],ken[1001];

int main()
{
    freopen("D.in","r",stdin);
    freopen("D.out","w",stdout);
    int t,tc=1;
    scanf("%d",&t);
    //t = 50;
    while(t--)
    {
              int n,i,j;
              scanf("%d",&n);
              //n=1000;
              double x;
              for(i=0;i<n;i++)
              {
                  scanf("%lf",&x);
                  nao[i] = (int)(100000*x + 0.5);
                  //nao[i] = rand()%100000;
              }
              for(i=0;i<n;i++)
              {
                  scanf("%lf",&x);
                  ken[i] = (int)(100000*x + 0.5);
                  //ken[i] = rand()%100000;
              }
              sort(nao,nao+n);
              sort(ken,ken+n);
              int ans1 = 0 , ans2 = n;
              i=j=0;
              while(i<n && j<n)
              {
                   if(nao[i] > ken[j])
                   i++,j++,ans1++;
                   else
                   i++;
              }
              i=j=0;
              while(i<n&&j<n)
              {
                   if(nao[i] < ken[j])
                   i++,j++,ans2--;
                   else
                   j++;
              }
              printf("Case #%d: %d %d\n",tc++,ans1,ans2);
    }
    //system("pause");
    return 0;
}

