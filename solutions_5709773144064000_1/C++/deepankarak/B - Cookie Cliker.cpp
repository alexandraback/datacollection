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

int main()
{
    freopen("B.in","r",stdin);
    freopen("B.out","w",stdout);
    int t,tc=1;
    scanf("%d",&t);
    while(t--)
    {
              double C,F,X;
              scanf("%lf%lf%lf",&C,&F,&X);
              double tim = 0.0;
              double rate = 2.0;
              int cnt = 0;
              while(1)
              {
                  if( (C/rate) + (X/(rate+F)) < (X/rate)  )
                  {
                      tim += (C/rate);
                      rate += F;
                      //cout<<tim<<endl;
                      //getchar();
                  }
                  else
                  {
                      tim += (X/rate);
                      break;
                  }
                  cnt++;
              }
              printf("Case #%d: %.7lf\n",tc++,tim);
    }
    //system("pause");
    return 0;
}
