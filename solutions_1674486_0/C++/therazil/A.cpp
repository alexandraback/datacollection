#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
#include<fstream>
using namespace std;
vector<int> a[1024];
queue<int> q;
int t,d,n,m,i,j,x,used[1024],s;
bool fl;

int main()
{
  FILE *in=fopen("A-small-attempt0.in","r");
  FILE *out=fopen("A-small-attempt0.out","w");
  fscanf(in,"%d",& t);
  for(d=1;d<=t;d++)
  {
    fscanf(in,"%d",& n);

    memset(used,0,(n+3)*sizeof(int));
    for(i=1;i<=n;i++) a[i].clear();

    for(i=1;i<=n;i++)
    {
        fscanf(in,"%d",& m);
        for(j=1;j<=m;j++)
        {
            fscanf(in,"%d", & x);
            a[i].push_back(x);
        }
    }

    for(i=1;i<=n;i++)
    {
        q.push(i);
        fl=false;
        while(!q.empty())
        {
        x=q.front();
        q.pop();

        s=a[x].size();
        for(j=0;j<=s-1;j++)
        {
            if (used[a[x][j]] == i) { fl=true;break;}
            q.push(a[x][j]);
            used[a[x][j]]=i;
        }
        if (fl) break;
        }
        while(!q.empty()) q.pop();
        if (fl) break;
    }

    if (fl) fprintf(out,"Case #%d: Yes\n", d);
    else fprintf(out,"Case #%d: No\n", d);
  }
  fclose(in);
  fclose(out);
return 0;
}
