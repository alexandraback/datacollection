#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <queue>
#include <map>
#include <vector>
#include <string>
#include <iomanip>
#include <stack>
#include <fstream>
using namespace std;
#define mo 1000000007ll
#define eps 1e-8
#define inf 2147480000
ifstream in("C-large.in");
ofstream out("ans.txt");
int n,t;
int r,c,m;
char box[52][52];
bool dfs(int layer,int num,int form)
{
    if(num==0 && layer!=r-1)
        return 1;
    if(layer==0) return 0;

    if(layer==r-1)
    {
        if(num>=form)
        {
            for(int j=c;j>=c-form+1;j--)
                box[layer][j]='.';
            if(dfs(layer-1,num-form,form))
                return 1;
            for(int j=c;j>=c-form+1;j--)
                box[layer][j]='*';
        }
    }
    else
    {
        for(int i=min(num,form);i>=2;i--)
        {
            for(int j=c;j>=c-i+1;j--)
                box[layer][j]='.';
            if(dfs(layer-1,num-i,i))
                return 1;
            for(int j=c;j>=c-i+1;j--)
                box[layer][j]='*';
        }
    }
    return 0;
}
void ou()
{
    for(int i=1;i<=r;i++)
    {
      for(int j=1;j<=c;j++)
        out<<box[i][j];
      out<<endl;
    }
}
int main()
{
    in>>t;
    int cac=0;
    while(t--)
    {
       cac++;
       in>>r>>c>>m;
       out<<"Case #"<<cac<<":"<<endl;
       if(m==0)
       {
            for(int i=1;i<=r;i++)   for(int j=1;j<=c;j++)   box[i][j]='.';
            box[1][1]='c';
            ou();
            continue;
       }
       if(m==r*c-1)
       {
            for(int i=1;i<=r;i++)   for(int j=1;j<=c;j++)   box[i][j]='*';
            box[1][1]='c';
            ou();
            continue;
       }
       if(r==1)
       {
            for(int i=1;i<=m;i++)
                box[1][i]='*';
            for(int i=m+1;i<=c;i++) box[1][i]='.';
            box[1][c]='c';
            ou();
            continue;
       }
       if(c==1)
       {
            for(int i=1;i<=m;i++)   box[i][1]='*';
            for(int i=m+1;i<=r;i++) box[i][1]='.';
            box[r][1]='c';
            ou();
            continue;
       }
       for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            box[i][j]='*';
       if(dfs(r,r*c-m,c))
       {
            box[r][c]='c';
            ou();
            continue;
       }
       swap(r,c);
       for(int i=1;i<=r;i++) for(int j=1;j<=c;j++)  box[i][j]='*';
       if(dfs(r,r*c-m,c))
       {
            for(int i=1;i<=c;i++)
            {
                for(int j=1;j<=r;j++)
                    out<<box[i][j];
                out<<endl;
            }
            continue;
       }
       out<<"Impossible"<<endl;
    }
    return 0;
}
