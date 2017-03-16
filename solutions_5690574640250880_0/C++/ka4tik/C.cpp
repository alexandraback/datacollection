/*
 *Kartik Singal @ ka4tik
 */
#include<bits/stdc++.h>
using namespace std;
#define s(n) scanf("%d",&n)
#define db(x) cerr << #x << ": " << x << endl;
#define db2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define db3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
#define db4(a, b, c, d) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
#define db5(a, b, c, d, e) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
#define db6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;
int dx[]={1,-1,0,0,1,-1,1,-1};
int dy[]={0,0,-1,1,-1,1,1,-1};
char grid[10][10];
int main()
{
    freopen("in","r",stdin);
    freopen("out","w",stdout);

    int test;s(test);
    int kase=0;
    while(test--)
    {
        kase++;
        printf("Case #%d:\n",kase);
        int r,c,m;
        cin>>r>>c>>m;
        int n=r*c;
        int flag=0;
        for(int i=0;i<(1<<n);i++)
        {
            if(__builtin_popcount(i)==m)
            {
                int cnt=0;
                for(int j=0;j<r;j++)
                {
                    for(int k=0;k<c;k++)
                    {
                        if(i&(1<<cnt))
                            grid[j][k]='*';
                        else
                        {
                            grid[j][k]='.';
                        }
                        cnt++;
                    }
                }
                for(int l=0;l<r;l++)
                {
                    for(int t=0;t<c;t++)
                    {
                        if(grid[l][t]=='*')
                            continue;
                        queue<int> q;
                        q.push(l);q.push(t);
                        vector< vector<int> > visit(r,vector<int>(c,0));
                        while(!q.empty())
                        {
                            int cx=q.front();q.pop();
                            int cy=q.front();q.pop();
                            visit[cx][cy]=1;
                            int cnt=0;
                            for(int k=0;k<8;k++)
                            {
                                int nx=cx+dx[k];
                                int ny=cy+dy[k];
                                if(nx>=r||nx<0||ny<0||ny>=c)
                                    continue;
                                if(grid[nx][ny]=='*')
                                    cnt++;
                            }
                            if(cnt==0)
                            {
                                for(int k=0;k<8;k++)
                                {
                                    int nx=cx+dx[k];
                                    int ny=cy+dy[k];
                                    if(nx>=r||nx<0||ny<0||ny>=c)
                                        continue;
                                    if(grid[nx][ny]=='*')
                                        continue;
                                    if(!visit[nx][ny])
                                    {
                                        q.push(nx);q.push(ny);
                                    }
                                }
                            }
                        }
                        cnt=0;
                        for(int j=0;j<r;j++)
                            for(int k=0;k<c;k++)
                                if(visit[j][k])
                                    cnt++;
                        //db2(cnt,m);
                        if(cnt==n-m)
                        {
                            flag=1;
                            grid[l][t]='c';
                            for(int j=0;j<r;j++)
                            {
                                for(int k=0;k<c;k++)
                                {
                                    cout<<grid[j][k];
                                }
                                cout<<endl;
                            }
                            break;
                        }
                    }
                    if(flag)break;
                }
            }
            if(flag)break;
        }
        if(!flag)
            puts("Impossible");
    }

    return 0;
}

