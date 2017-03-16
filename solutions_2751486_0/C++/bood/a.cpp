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
int t,n,s,p,l;
int min_,min_s;
vector< vector<int> > f;
vector<int> g;
string name;
int ret;
bool isvow(int i) {
    char ch = name[i];
    return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u');
}
int calc2(int i, int j)
{
    if(f[i][j]>=0) ;
    else if(i==j) f[i][j]=(isvow(i)?0:1);
    else if(isvow(j)) {
        f[i][j]=calc2(i,j-1);
    }
    else {
        f[i][j]=max(calc2(i,j-1),min(g[j],j-i+1));
    }
    return f[i][j];
}
void calc()
{
    int i,j,k;
    f.clear();g.clear();
    f.resize(l);g.resize(l,0);
    rep(i,0,l) {
        f[i].clear();
        f[i].resize(l,-1);
    }
    rep(i,0,l) {
        j=0;
        while(i<l && !isvow(i)) {
            j++;
            g[i]=j;
            i++;
        }
    }
    // rep(i,0,l) {
    //     cout<<g[i]<<" ";
    // }
    ret = 0;
    rep(i,0,l) rep(j,i,l) {
        if(calc2(i,j)>=n) ret++;
        //cout<<i<<","<<j<<":"<<f[i][j]<<"\n";
    }
}
void input()
{
    cin>>name>>n;
    l = name.size();
}
void output(int ncase)
{
    printf("Case #%d: %d\n",ncase,ret);
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
