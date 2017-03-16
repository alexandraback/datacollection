#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <iostream>
#include <cstring>

#define pb push_back
#define fs first
#define sc second
#define mp make_pair

using namespace std;

int T,N,M;
int v[101010],ind;
char sir[101010];
int sum[101010];
int calc[505][505][505];
int limit;


string find(int x,int y,int nr)
{

    if(abs(x)>200)
        return "Q";
    if(abs(y)>200)
        return "Q";
    if(nr>limit)
        return "Q";
    if(calc[x+250][y+250][nr]==limit)
        return "Q";
    if(x == N && y == M){
        //printf("ok");
        return "";
        }
  //  printf("%d %d\n",x,y);
    string ret="";
    ret = find(x+nr,y,nr+1);
    if(ret!="Q"){
    return "E"+ret;
    }
    ret = find(x-nr,y,nr+1);
    if(ret!="Q")
        return "W" + ret;

    ret = find(x,y+nr,nr+1);
    if(ret!="Q")
        return "N" + ret;
    ret = find(x,y-nr,nr+1);
    if(ret!="Q")
        return "S" + ret;

    calc[x+250][y+250][nr]=limit;
    return "Q";

}

void reset()
{
    for(int i=1;i<=500;++i)
        for(int j=1;j<=500;++j)
            for(int k=0;k<=500;++k)
                calc[i][j][k]=0;
}

void make()
{
//fprintf(stderr,"%d %d %d\n",ind,N,M);
for(int i=4;i<=500;++i)
{

    limit =i;
    string ret = find(0,0,1);
    if(ret!="Q"){
        cout<<ret<<"\n";
        return;
        }
}

}

int main()
{
freopen("b.in","r",stdin);
freopen("b.out","w",stdout);
    scanf("%d",&T);
    while(T--){
    reset();
    ++ind;
    scanf("%d%d",&N,&M);
    printf("Case #%d: ",ind);
    make();
    }

return 0;
}
