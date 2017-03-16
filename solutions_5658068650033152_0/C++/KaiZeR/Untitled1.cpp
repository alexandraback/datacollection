#include<iostream>
#include<cstdio>
#include<stack>
#include<queue>
#include<set>
#include<iomanip>
#include<complex>
#include<vector>
#include<map>
#include<algorithm>
#include<cmath>
#include<string>
#include<bitset>
#include<memory.h>
#include<cassert>
#include<ctime>
 
 
#pragma comment(linker, "/stack:30000000")
 
using namespace std;
 
#define For(i,l,r) for (int i = l ;i < (int)(r + 1) ; ++ i )
#define ForI(it , s , T) for (T :: iterator it = s.begin(); it != s.end() ; ++ it )
#define LL long long
#define iinf 2000000000
#define linf 4000000000000000000LL
#define MOD  1000000007
#define Pi 3.1415926535897932384
#define bit(mask,i) ((mask>>i)&1)
#define pb(x) push_back(x)
#define mk(x,y) make_pair(x,y)
#define sqr(x) ((x)*(x))
#define pause cin.get();cin.get();
#define fir first
#define sec second
#define ln(x) log(x)
 
const int Direction[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
const int Nmax = 200100;

int Color;
int MASK;
int n,m,k;
int used[25][25];
bool busy(int x,int y){
     if (used[x][y] == Color) return 1;
     if (bit(MASK,x*m+y)) return 1;
     return 0;
}
int dfs(int x,int y){
    if (busy(x,y)) return 0;
    used[x][y] = Color;
    int Res = 1;
    for (int i = 0; i < 4; i ++)
    {
        int nx = x + Direction[i][0];
        int ny = y + Direction[i][1];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
        Res += dfs(nx,ny);
    }
    return Res;
}
int Count(int mask){
    int res =0;
    while (mask > 0)
     res ++ , 
     mask = mask & (mask - 1);
    return res;
}
int main()
{ 
   freopen("C-small-attempt0.in","r",stdin);
   freopen("output.txt","w",stdout);
   int test;
   cin >> test;
   for (int tt = 1 ; tt <= test ; tt ++ ){
   scanf("%d%d%d",&n,&m,&k);
   Color = 0;
   for (int i = 0; i < n ; i ++)
    for (int j = 0 ;j < m ; j ++ )
     used[i][j] = 0;
   int answer = k;
   for (int mask = 0 ; mask < (1<<(n*m)) ; mask ++ )
   {
       MASK = mask;
       int cur = n*m;
       Color ++;
       for (int i = 0 ; i < m ; i ++)
        cur -= dfs(0,i),
        cur -= dfs(n-1,i);
       for (int i = 0 ;i < n ; i ++)
        cur -= dfs(i,0) ,
        cur -= dfs(i,m-1);
       if (cur >= k)
        answer = min(answer , Count(mask));
   }
   printf("Case #%d: %d\n",tt,answer);
   }
   return 0;
} 
