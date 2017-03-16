#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <functional>
#include <cstdio>
typedef long long ll;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, s, t) for(i = (s); i < (t); i++)
#define rrep(i, s, t) for(i = (s)-1; i >= (t); i--)
using namespace std;
int x,y,t,n,s,p;
int min_,min_s;
vector<int> v;
string ret;
typedef struct {
    int x,y;
    string path;
} S;
void calc()
{
    char ch;
    int x0=0,y0=0;
    ret.clear();
    ret.reserve(500);
    int jump = 1;
    while(abs(x0)+jump<abs(x) || abs(y0)+jump<abs(y)) {
        if(x>0) {
            if(x0+jump<x) {
                x0+=jump;
                ret+='E';
            }
        } else {
            if(x0-jump>x) {
                x0-=jump;
                ret+='W';
            }
        }
        jump = ret.size()+1;
        if(y>0) {
            if(y0+jump<y) {
                y0+=jump;
                ret+='N';
            }
        } else {
            if(y0-jump>y) {
                y0-=jump;
                ret+='S';
            }
        }
        jump = ret.size()+1;
    }
    int l = ret.size();
    int i,j,k;
    if(x>x0) rep(i,0,x-x0) ret+="WE";
    if(x<x0) rep(i,0,x0-x) ret+="EW";
    if(y>y0) rep(i,0,y-y0) ret+="SN";
    if(y<y0) rep(i,0,y0-y) ret+="NS";
}
void input()
{
    cin>>x>>y;
}
void output(int ncase)
{
    printf("Case #%d: %s\n",ncase,ret.c_str());
}
int main(void)
{
    cin>>t;
    for(int i=0;i<t;i++)
    {
        input();
        calc();
        output(i+1);
    }
    return 0;
}
