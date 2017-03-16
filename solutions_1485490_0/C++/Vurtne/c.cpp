#include<iostream>
#include<fstream>

using namespace std;

struct nodes{
       long long num,id;
       }a[105],b[105];
long long n,m,ans;

ifstream fin("1cc.in");
ofstream fout("1cc.out");

void dfs(int x,int y,long long z)
{
     if (z>ans) ans=z;
     if (x>=n || y>=m) return;
     if (a[x].id==b[y].id){
        if (a[x].num==b[y].num){
           dfs(x+1,y+1,z+a[x].num);
           } else
        if (a[x].num>b[y].num){
           a[x].num-=b[y].num;
           dfs(x,y+1,z+b[y].num);
           a[x].num+=b[y].num;
           } else
           {
           b[y].num-=a[x].num;
           dfs(x+1,y,z+a[x].num);
           b[y].num+=a[x].num;
           }
        }else
        {
             dfs(x+1,y,z);
             dfs(x,y+1,z);
        }
}

int main()
{
    int t,o;
    fin>>t;
    for (int o=1;o<=t;o++){
        fin>>n>>m;
        for (int i=0;i<n;i++) fin>>a[i].num>>a[i].id;
        for (int i=0;i<m;i++) fin>>b[i].num>>b[i].id;
        ans=0;
        dfs(0,0,0);
        fout<<"Case #"<<o<<": "<<ans<<endl;
        }
    return 0;
}
