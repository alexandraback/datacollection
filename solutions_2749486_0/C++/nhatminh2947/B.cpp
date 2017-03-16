//******************************************************************
// Author: Huynh Nhat Minh
// Problem Name: 
// Verdict: 
//******************************************************************
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <cctype>
#include <deque>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <map>
#include <sstream>
#include <cmath>
#include <bitset>
#include <utility>
#include <set>

using namespace std;

#define fr(i,a,b) for (int i = (a), _b = (b); i <= _b; i++)
#define dw(i,a,b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i,n) for (int i = 0, _n = (n); i < _n; i++)
#define sz(s) s.size()
#define read(x) cin >> x
#define read2(x,y) cin >> x >> y
#define read3(x,y,z) cin >> x >> y >> z
#define out(x) cout << x
#define DEBUG(x) cout << #x << " = " << x << endl

#define ull unsigned long long
#define ll long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define mp make_pair
#define ff first
#define ss second

#define BIT(n) (1<<(n))
#define AND(a,b) ((a) & (b))
#define OR(a,b) ((a)  (b))
#define XOR(a,b) ((a) ^ (b))
#define sqr(x) ((x) * (x))

typedef pair<int,int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define PI 3.1415926535897932385
#define INF 1000111222
#define eps 1e-7
#define maxN 100000

ii end;
int tcs;
int step[205][205][505];
int d[300],b[5];

int dx[] = {-1, 1, 0, 0};
int dy[] = { 0, 0,-1, 1};

void init()
{
    d[0] = 'W';
    d[1] = 'E';
    d[2] = 'S';
    d[3] = 'N';
    
    b[0] = 1;
    b[1] = 0;
    b[2] = 3;
    b[3] = 2;
    
    rep(i,201) rep(j,201) rep(k,505) step[i][j][k] = INF;
}

bool inside(int y, int x)
{
    return (0 <= y && y <= 200 && 0 <= x && x <= 200);
}

void BFS()
{
    int cnt = 1;
    queue< pair<ii,int> > q; 
    q.push(mp(mp(100,100),0));
    step[100][100][0] = 0;
    
    while(!q.empty())
    {
        int y = q.front().ff.ff;
        int x = q.front().ff.ss;
        int s = q.front().ss;
        //DEBUG(x);
        //DEBUG(y);
        //DEBUG(s);
        q.pop();
        
        for(int k = 0 ; k < 4 ; k++)
        {
            int yy = y + dy[k]*(s+1);
            int xx = x + dx[k]*(s+1);
            
            if(inside(yy,xx) && step[yy][xx][s+1] == INF)
            {
                //DEBUG(xx);
                //DEBUG(yy);
                step[yy][xx][s+1] = k;
                q.push(mp(mp(yy,xx),s+1));
            }
        }
        //printf("------------\n");
    }
    
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("B.INP","r",stdin);
    freopen("B.OUT","w",stdout);
    #endif
    
    read(tcs);
    init();
    BFS();
    fr(t,1,tcs)
    {
        printf("Case #%d: ",t);
        read2(end.ff,end.ss);
        end.ff += 100;
        end.ss += 100;
        
        BFS();
        int x = end.ff;
        int y = end.ss;
        int s = 0;
        for(int i = 0 ; i <= 500 ; i++)
            if(step[y][x][i] != INF)
            {
                //DEBUG(y);
                //DEBUG(x);
                //DEBUG(i);
                s = i;
                //DEBUG(step[y][x][i]);
                break;
            }
        
        string ans = "";
        while(s != 0)
        {
            //DEBUG(x);
            //DEBUG(y);
            //DEBUG(s);
            int k = step[y][x][s];
            //DEBUG(k);
            ans += d[k];
            
            y += dy[b[k]]*s;
            x += dx[b[k]]*s;
            s--;
        }
        reverse(all(ans));
        cout << ans << endl;
    }

    return 0;
}