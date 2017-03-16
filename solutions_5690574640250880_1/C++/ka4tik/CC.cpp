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
char grid[200][200];
int r,c,m,n;
int flag=0;
int trytofind()
{
    if(flag)
        return 0;
    int cnt=0;
    for(int l=0;l<r;l++)
    {
        for(int t=0;t<c;t++)
        {
            if(grid[l][t]=='.')
                cnt++;
        }
    }
    if(cnt==1)
    {
        for(int l=0;l<r;l++)
        {
            for(int t=0;t<c;t++)
            {
                if(grid[l][t]=='.')
                    grid[l][t]='c';
            }
        }
        flag=1;
        for(int l=0;l<r;l++)
        {
            for(int t=0;t<c;t++)
            {
                cout<<grid[l][t];
            }
            cout<<endl;
        }
        return 0;

    }
    int reached=0;
    for(int l=0;l<r;l++)
    {
        for(int t=0;t<c;t++)
        {
            //db2(l,t);
            if(grid[l][t]=='*')
                continue;
            int cnt=0;
            //for(int k=0;k<8;k++)
            //{
                //int nx=l+dx[k];
                //int ny=t+dy[k];
                //if(nx>=r||nx<0||ny<0||ny>=c)
                    //continue;
                //if(grid[nx][ny]=='*')
                    //cnt++;
            //}
            //if(cnt==0)
            //{
                //cout<<"here"<<endl;
                reached=1;
                queue<int> q;
                q.push(l);q.push(t);
                vector< vector<int> > visit(r,vector<int>(c,0));
                while(!q.empty())
                {
                    int cx=q.front();q.pop();
                    int cy=q.front();q.pop();
                    //db2(cx,cy);
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
                                visit[nx][ny]=1;
                            }
                        }
                    }
                }
                cnt=0;
                for(int j=0;j<r;j++)
                    for(int k=0;k<c;k++)
                        if(visit[j][k])
                            cnt++;
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
                //if(reached) break;
            }
            if(flag)break;
            //if(reached) break;
        //}
    }
    return flag;
}
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
        cin>>r>>c>>m;
        n=r*c;
        flag=0;
        int f=0;
        int cnt=0;
        if(1||(r%2==0&&c%2==0))
        {
            int t=m;
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    grid[i][j]='.';
            while(t--)
            {
                int done=0;
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        if(grid[i][j]=='.')
                        {
                            grid[i][j]='*';
                            done=1;
                            break;
                        }
                    }
                    if(done)break;
                }
            }
            trytofind();
            t=m;
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    grid[i][j]='.';
            while(t--)
            {
                int done=0;
                for(int i=0;i<c;i++)
                {
                    for(int j=0;j<r;j++)
                    {
                        if(grid[j][i]=='.')
                        {
                            grid[j][i]='*';
                            done=1;
                            break;
                        }
                    }
                    if(done)break;
                }
            }
            trytofind();
            t=m;
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    grid[i][j]='.';
            int f=0;
            while(t--)
            {
                f=1-f;
                int done=0;
                if(!f)
                {
                    for(int i=0;i<c;i++)
                    {
                        for(int j=0;j<r;j++)
                        {
                            if(grid[j][i]=='.')
                            {
                                grid[j][i]='*';
                                done=1;
                                break;
                            }
                        }
                        if(done)break;
                    }
                }
                else
                {
                    for(int i=0;i<r;i++)
                    {
                        for(int j=0;j<c;j++)
                        {
                            if(grid[i][j]=='.')
                            {
                                grid[i][j]='*';
                                done=1;
                                break;
                            }
                        }
                        if(done)break;
                    }
                }
            }
            trytofind();
            t=m;
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    grid[i][j]='.';
            f=0;
            while(t--)
            {
                if(t&1)
                    f=1-f;
                int done=0;
                if(!f)
                {
                    for(int i=0;i<c;i++)
                    {
                        for(int j=0;j<r;j++)
                        {
                            if(grid[j][i]=='.')
                            {
                                grid[j][i]='*';
                                done=1;
                                break;
                            }
                        }
                        if(done)break;
                    }
                }
                else
                {
                    for(int i=0;i<r;i++)
                    {
                        for(int j=0;j<c;j++)
                        {
                            if(grid[i][j]=='.')
                            {
                                grid[i][j]='*';
                                done=1;
                                break;
                            }
                        }
                        if(done)break;
                    }
                }
            }
            trytofind();
            t=m;
            for(int i=0;i<r;i++)
                for(int j=0;j<c;j++)
                    grid[i][j]='.';
            f=1;
            while(t--)
            {
                if(t&1)
                    f=1-f;
                int done=0;
                if(!f)
                {
                    for(int i=0;i<c;i++)
                    {
                        for(int j=0;j<r;j++)
                        {
                            if(grid[j][i]=='.')
                            {
                                grid[j][i]='*';
                                done=1;
                                break;
                            }
                        }
                        if(done)break;
                    }
                }
                else
                {
                    for(int i=0;i<r;i++)
                    {
                        for(int j=0;j<c;j++)
                        {
                            if(grid[i][j]=='.')
                            {
                                grid[i][j]='*';
                                done=1;
                                break;
                            }
                        }
                        if(done)break;
                    }
                }
            }
            trytofind();
            for(int k=2;k<=60;k++)
            {
                //db(k);
                if(flag)break;
                t=m;
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++)
                        grid[i][j]='.';
                f=0;
                while(t--)
                {
                    if(t%k==0)
                        f=1-f;
                    int done=0;
                    if(!f)
                    {
                        for(int i=0;i<c;i++)
                        {
                            for(int j=0;j<r;j++)
                            {
                                if(grid[j][i]=='.')
                                {
                                    grid[j][i]='*';
                                    done=1;
                                    break;
                                }
                            }
                            if(done)break;
                        }
                    }
                    else
                    {
                        for(int i=0;i<r;i++)
                        {
                            for(int j=0;j<c;j++)
                            {
                                if(grid[i][j]=='.')
                                {
                                    grid[i][j]='*';
                                    done=1;
                                    break;
                                }
                            }
                            if(done)break;
                        }
                    }
                }
                trytofind();
                t=m;
                for(int i=0;i<r;i++)
                    for(int j=0;j<c;j++)
                        grid[i][j]='.';
                f=1;
                while(t--)
                {
                    if(t%k==0)
                        f=1-f;
                    int done=0;
                    if(!f)
                    {
                        for(int i=0;i<c;i++)
                        {
                            for(int j=0;j<r;j++)
                            {
                                if(grid[j][i]=='.')
                                {
                                    grid[j][i]='*';
                                    done=1;
                                    break;
                                }
                            }
                            if(done)break;
                        }
                    }
                    else
                    {
                        for(int i=0;i<r;i++)
                        {
                            for(int j=0;j<c;j++)
                            {
                                if(grid[i][j]=='.')
                                {
                                    grid[i][j]='*';
                                    done=1;
                                    break;
                                }
                            }
                            if(done)break;
                        }
                    }
                }
                trytofind();
            }
        }

        if(!flag)
        {
            puts("Impossible");
        }
        else
        {
            //cout<<kase<<endl;
        }
    }

    return 0;
}

