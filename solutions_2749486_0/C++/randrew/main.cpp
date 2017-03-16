#include <algorithm>
#include <iostream>
#include <sstream>
#include <string.h>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
#include <cctype>
#include <list>

#define INF 2000000000
#define ll long long
#define PI 3.1415926535897932384626433832795
#define all(a) a.begin(), a.end()
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define y1 olololo1
#define y0 olololo2
#define m0(a) memset(a,0,sizeof(a))

using namespace std;

const int step[4][2]= {{1,0},{-1,0},{0,1},{0,-1}};

const string way="EWNS";

int test;
int x, y;
bool f[601][601][42];
int pred[601][601][42];


bool ok(int x, int y){
    return (x>=0 && x<=600 && y>=0 && y<=600);
}

void out(int x, int y, int k){
    if (k==0) return;
    int q=pred[x][y][k];
    int nx=x-(k)*step[q][0], ny=y-(k)*step[q][1];
    out(nx,ny,k-1);
    cout << way[q];
}

void solve(int x, int y){
    for (int k=0;k<=40;++k)
        for (int i=0;i<=600;++i)
            for (int j=0;j<=600;++j){
                f[i][j][k]=0;
                pred[i][j][k]=0;
            }
    f[300][300][0]=1;
    for (int k=0;k<=40;++k)
        for (int i=0;i<=600;++i)
            for (int j=0;j<=600;++j){
                if (!f[i][j][k]) continue;
                for (int _=0;_<4;++_){
                    int nx=i+(k+1)*step[_][0], ny=j+(k+1)*step[_][1];
                    if (!ok(nx,ny)) continue;
                    f[nx][ny][k+1]=1;
                    pred[nx][ny][k+1]=_;
                }
            }
    for (int k=0;k<=40;++k)
        if (f[x][y][k]) {
            out(x,y,k);
            break;
        }
}

int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin >> test;
    for (int it=0;it<test;++it){
        cin >> x >> y;
        x+=300, y+=300;
        cout << "Case #"<<it+1<<": ";
        solve(x,y);
        cout << endl;
    }
    return 0;
    
}