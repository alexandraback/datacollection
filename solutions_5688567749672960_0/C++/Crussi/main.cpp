#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstring>
#include <climits>
#include <iostream>
#include <sstream>
#include <set>
#include <stack>
#include <queue>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <bitset>
#define ll long long
#define ull unsigned long long
#define inf 0x3f3f3f3f
#define infll 0x3FFFFFFFFFFFFFFFLL
#define np next_permutation
#define pp prev_permutation
#define mp make_pair
#define abs(x) (((x) < 0) ? - (x) : (x))
#define pi 3.1415926535897932384626433832795
#define sz(a) int((a).size()) 
#define fr first
#define sc second
#define pb push_back 
#define fors(i, s) for(int i = 0; i < sz(s); i++)
#define all(c) (c).begin(),(c).end() 
#define rall(c) (c).rbegin(),(c).rend() 
#define tr(c,i) for (__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define TRvii(c, it) for (vii::iterator it = (c).begin(); it != (c).end(); it++)
#define present(c,x) ((c).find(x) != (c).end()) 
using namespace std;
int dx[]={1,0,-1,0};int dy[]={0,1,0,-1}; //4 Direction
//int dx[]={1,1,0,-1,-1,-1,0,1};int dy[]={0,1,1,1,0,-1,-1,-1};//8 direction
//int dx[]={2,1,-1,-2,-2,-1,1,2};int dy[]={1,2,2,1,-1,-2,-2,-1};//Knight Direction
//int dx[]={2,1,-1,-2,-1,1};int dy[]={0,1,1,0,-1,-1}; //Hexagonanivel Direction
typedef vector<string> vs;
typedef vector<int> vi; 
typedef vector<vi> vvi; 
typedef pair<ll,int> ii; 
typedef pair<ii,int> iii; 
typedef vector<ii> vii;
typedef vector<iii> viii;
typedef map<string, int> si;
typedef map<int, string> is;

ll n;
//set<ll> vis;
int vis[1000005];
ll inverte(ll n, ll res)
{   
    if(n/10 == 0)
        return res*10 + n%10;
    return inverte(n/10, res*10 + n%10);  
}
  
int bfs()
{
    queue<ii> fila;
    fila.push(ii(1,1));
    while(!fila.empty())
    {
        ii num = fila.front();
        fila.pop();
        if(num.fr >= 1000005) continue;
        if(vis[num.fr]) continue;
        vis[num.fr] = true;
        //if(present(vis,num.fr)) continue;
        //vis.insert(num.fr);
        if(num.fr == n) 
           return num.sc;
        fila.push(ii(num.fr+1, num.sc+1));
        fila.push(ii(inverte(num.fr, 0), num.sc+1));
    }
}

int main(){
    //freopen("A-small-attempt1.in", "r", stdin);
    //freopen("saida.txt","w",stdout);
    int t,c=1;
    scanf("%d",&t);
    while(t--){
       //vis.clear();
       memset(vis,false,sizeof vis);
       scanf("%lld",&n);
       printf("Case #%d: %d\n",c++, bfs());
    }
    //system("PAUSE");
    return 0;
}
