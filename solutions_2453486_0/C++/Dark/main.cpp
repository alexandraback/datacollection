#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <ctime>
using namespace std;

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef pair<int,int> PII;
#define For(i,n) for(int i=0;i<n;i++)
#define sz(i) int(i.size())
#define mst(i,n) memset(i,n,sizeof(i))
#define eps 1e-11
#define MOD 1000000007
#define LL long long
#define pi acos(-1)
#define ALL(n) n.begin(),n.end()
#define pb push_back
#define mp make_pair
#define iFor(i,n) for(typeof(n.begin()) i=n.begin();i!=n.end();i++)
int x,t,d,o;
void update(char g){
    if(g=='X')x++;
    if(g=='T')t++;
    if(g=='O')o++;
    if(g=='.')d++;
}
int res;
void judge(){
    if(x==4||(x==3&&t==1)) res = 1;
    else if(o==4||(o==3&&t==1)) res = 2;
}
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int ca = 0;
    scanf("%d",&ca);
    For(c, ca){
        char g[9][9];
        For(i,4) scanf(" %s",g[i]);
        res = 0;//0-draw 1-X 2-O
        For(i,4){
            x=0,t=0,d=0,o=0;
            For(j,4)
                update(g[i][j]);
            judge();
            x=0,t=0,o=0;
            For(j,4)
                update(g[j][i]);
            judge();
        }
        x=0,t=0,o=0;
        For(j,4)
            update(g[j][j]);
        judge();
        x=0,t=0,o=0;
        For(j,4)
            update(g[3-j][j]);
        judge();
        printf("Case #%d: ",c+1);
        if(res == 1) printf("X won\n");
        else if(res == 2) printf("O won\n");
        else if(d) printf("Game has not completed\n");
        else printf("Draw\n");
    }
}
