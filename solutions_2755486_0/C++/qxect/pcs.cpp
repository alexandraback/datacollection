#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<string>
#include<set>
#include<vector>
using namespace std;

#define pb push_back
#define mp make_pair
#define x first
#define y second
#define sz(a) (int((a).size()))
#define all(a) (a).begin(), (a).end()
#define For(it,c) for(typeof(c) it = ((c).begin()); it != ((c).end()) ; ++it)

#define forn(i,n) for (int i=0; i<int(n); ++i)
#define fornd(i,n) for (int i=int(n)-1; i>=0; --i)
#define forab(i,a,b) for (int i=int(a); i<int(b); ++i)
#define xx(a) (a+210)
typedef complex<int> cI;
typedef pair<int,pair<int,int> > pII;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int xBnd = 500;

int day[15], num[15], w[15], e[15], pi[15], ddi[15], dpi[15], dsi[15];
priority_queue< pII, vector<pII>, greater<pII> > heap;

int hei[xBnd+10], tmpHei[xBnd+10];

int main()
{
  int tn,n;
  int ans;

  int i;
  int nowD;
  int flag;
  int tD, tI, tN, tW, tE, tP;
  pII now;

  cin >> tn;
  for(int z=1;z<=tn;z++){
    while(!heap.empty())
      heap.pop();

    printf("Case #%d: ",z);
    cin >> n;
    for(i=0;i<n;i++){
      cin >> day[i] >> num[i] >> w[i] >> e[i] >> pi[i] >> ddi[i] >> dpi[i] >> dsi[i];
      //printf("i %d day %d\n",i,day[i]);
      heap.push(mp(day[i], mp(i, 0)));
    }
    ans = 0;
    nowD = 0;
    memset(hei,0,sizeof(hei));
    memset(tmpHei,0,sizeof(tmpHei));
    while(!heap.empty()){
      now = heap.top();
      heap.pop();

      tD = now.x;
      tI = now.y.x;
      tN = now.y.y;

      if(tD != nowD){
        //printf("Day Change nowD %d tD %d\n",nowD, tD);
        for(i=0; i < xBnd;i++){
          hei[i] = max(hei[i], tmpHei[i]);
          tmpHei[i] = 0;
          //if(hei[i]) printf("i %d: %d\n",i-210, hei[i]);
        }
        nowD = tD;
      }
      tW = w[tI] + tN * dpi[tI];
      tE = e[tI] + tN * dpi[tI];
      tP = pi[tI] + tN * dsi[tI];
      flag = 0;
      for(i=tW;i<tE;i++){
        if(hei[xx(i)] < tP){
          flag = 1;
          tmpHei[xx(i)] = max(tmpHei[xx(i)], tP);
        }
      }
      ans += flag;
      if(tN + 1 < num[tI]){
        heap.push(mp(tD + ddi[tI], mp(tI, tN+1)));
      }
      //printf("tD %d tI %d tN %d tW %d tE %d tP %d\n",tD, tI, tN, tW, tE, tP);
    }
    printf("%d\n",ans);

  }
  return 0;
}
