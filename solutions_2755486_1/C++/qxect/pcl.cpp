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

typedef complex<int> cI;
typedef pair<int,pair<int,int> > pII;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const int INF = (int) 1e9;
const long long INF64 = (long long) 1e18;


int day[1100], num[1100], pi[1100], w[1100], e[1100], ddi[1100], dsi[1100], dpi[1100];
priority_queue< pII, vector<pII>, greater<pII> > heap;
queue< pII > JobQ;
vector<int> xTree;

int arr[20000000];
int bit[20000000];

int query(int ss, int ee, int pw, int ls, int le, int nodeNum){
  int flag = 0;
  if(ls<=ss && ee<=le)
    flag |= (arr[nodeNum] < pw);

  if(ls+1 != le){
    if(bit[nodeNum]){
      arr[2*nodeNum] = max(arr[nodeNum], arr[nodeNum]);
      arr[2*nodeNum+1] = max(arr[2*nodeNum+1], arr[nodeNum]);
      bit[2*nodeNum] = 1;
      bit[2*nodeNum+1] = 1;
      bit[nodeNum] = 0;
    }
    if(bit[2*nodeNum]){
      arr[4*nodeNum] = max(arr[4*nodeNum], arr[2*nodeNum]);
      arr[4*nodeNum+1] = max(arr[4*nodeNum+1], arr[2*nodeNum]);
      bit[4*nodeNum] = 1;
      bit[4*nodeNum+1] = 1;
      bit[2*nodeNum] = 0;
    }
    if(bit[2*nodeNum+1]){
      arr[4*nodeNum+1] = max(arr[4*nodeNum+1], arr[2*nodeNum+1]);
      arr[4*nodeNum+3] = max(arr[4*nodeNum+3], arr[2*nodeNum+1]);
      bit[4*nodeNum+1] = 1;
      bit[4*nodeNum+3] = 1;
      bit[2*nodeNum+1] = 0;
    }
  }
  if(ss==ls && ee==le)
    return arr[nodeNum] < pw;

  int mid = (ls+le)/2;
  if(ss >= mid){
    return flag|query(ss, ee, pw, mid, le, nodeNum*2 + 1);
  }else if(ee <= mid){
    return flag|query(ss, ee, pw, ls, mid, nodeNum*2);
  }else{
    return flag|(query(ss, mid, pw, ls, mid, nodeNum*2) | query(mid, ee, pw, mid, le, nodeNum*2 + 1));
  }
}

void build(int ss, int ee, int nodeNum){
  int mid = (ss+ee) /2;
  if(ss+1!=ee){
    build(ss, mid, nodeNum*2);
    build(mid, ee, nodeNum*2+1);
  }
  arr[nodeNum] = 0;
  bit[nodeNum] = 0;
}
void fixMax(int ss, int ee, int pw, int ls, int le, int nodeNum){
  if(ls+1 != le){
    if(bit[nodeNum]){
      arr[2*nodeNum] = max(arr[nodeNum], arr[nodeNum]);
      arr[2*nodeNum+1] = max(arr[2*nodeNum+1], arr[nodeNum]);
      bit[2*nodeNum] = 1;
      bit[2*nodeNum+1] = 1;
      bit[nodeNum] = 0;
    }
    if(bit[2*nodeNum]){
      arr[4*nodeNum] = max(arr[4*nodeNum], arr[2*nodeNum]);
      arr[4*nodeNum+1] = max(arr[4*nodeNum+1], arr[2*nodeNum]);
      bit[4*nodeNum] = 1;
      bit[4*nodeNum+1] = 1;
      bit[2*nodeNum] = 0;
    }
    if(bit[2*nodeNum+1]){
      arr[4*nodeNum+1] = max(arr[4*nodeNum+1], arr[2*nodeNum+1]);
      arr[4*nodeNum+3] = max(arr[4*nodeNum+3], arr[2*nodeNum+1]);
      bit[4*nodeNum+1] = 1;
      bit[4*nodeNum+3] = 1;
      bit[2*nodeNum+1] = 0;
    }
  }
  
  if(ss==ls && ee==le){
    bit[nodeNum] = 1;
    arr[nodeNum] = max(arr[nodeNum], pw);
    return ;
  }

  int mid = (ls+le)/2;
  if(ss >= mid){
    fixMax(ss, ee, pw, mid, le, nodeNum*2 + 1);
    arr[nodeNum]  = max(arr[nodeNum*2+1], arr[nodeNum]);
  }else if(ee <= mid){
    fixMax(ss, ee, pw, ls, mid, nodeNum*2);
    arr[nodeNum]  = max(arr[nodeNum*2] , arr[nodeNum] );
  }else{

    fixMax(ss, mid, pw, ls, mid, nodeNum*2);
    fixMax(mid, ee, pw, mid, le, nodeNum*2 + 1);
    arr[nodeNum]  = max(arr[nodeNum*2+1] , arr[nodeNum] );
    arr[nodeNum]  = max(arr[nodeNum*2] , arr[nodeNum] );
  }
}

void update(){
  int tD, tI, tN, tW, tE, tP;
  pII now;

  while(!JobQ.empty()){
    now = JobQ.front();
    JobQ.pop();

    tD = now.x;
    tI = now.y.x;
    tN = now.y.y;
    tW = lower_bound(all(xTree), w[tI] + tN * dpi[tI]) - xTree.begin();
    tE = lower_bound(all(xTree), e[tI] + tN * dpi[tI]) - xTree.begin();
    tP = pi[tI] + tN * dsi[tI];

    fixMax(tW, tE, tP, 0, sz(xTree)-1, 1);

  }
}


int main()
{
  int tn,n;
  int i,j;
  int nowD;
  int ans;
  pII now;
  int tD, tI, tN, tW, tE, tP;

  cin >> tn;
  for(int z=1;z<=tn;z++){
    cin >> n;
    xTree.clear();
    while(!heap.empty())heap.pop();
    while(!JobQ.empty())JobQ.pop();

    for(i=0;i<n;i++){
      cin >> day[i] >> num[i] >> w[i] >> e[i] >> pi[i] >> ddi[i] >> dpi[i] >> dsi[i];
      heap.push(mp(day[i], mp(i, 0)));
      for(j=0;j<num[i];j++){
        xTree.pb(w[i] + j*dpi[i]);
        xTree.pb(e[i] + j*dpi[i]);
      }
    }
    sort(all(xTree));
    xTree.resize(unique(all(xTree))-xTree.begin());
    
    build(0, sz(xTree)-1, 1);

    nowD = 0;
    ans = 0;
    while(!heap.empty()){
      now = heap.top();
      heap.pop();

      tD = now.x;
      tI = now.y.x;
      tN = now.y.y;
      tW = lower_bound(all(xTree), w[tI] + tN * dpi[tI]) - xTree.begin();
      tE = lower_bound(all(xTree), e[tI] + tN * dpi[tI]) - xTree.begin();
      tP = pi[tI] + tN * dsi[tI];
      //printf("tD %d tI %d tN %d tW %d tE %d tP %d\n",tD,tI, tN, tW,tE, tP);
      
      if(tD != nowD){
        update();
        nowD = tD;
      }

      ans += query(tW, tE, tP, 0, sz(xTree)-1,  1);
      
      JobQ.push(mp(tD, mp(tI, tN)));

      if(tN + 1 < num[tI])
        heap.push(mp(tD + ddi[tI], mp(tI, tN + 1)));
    }
    printf("Case #%d: %d\n",z,ans);

  }
  return 0;
}
