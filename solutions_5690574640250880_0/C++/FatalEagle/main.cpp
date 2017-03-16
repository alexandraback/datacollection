#include <bits/stdc++.h>

using namespace std;

int R, C, M, K;
long long tot;

struct grid
{
    vector<vector<bool>> data;
    void init(int r, int c)
    {
        data.resize(r);
        for(int i=0; i<r; i++)
            data[i].resize(c);
    }
    vector<bool>& operator[] (int idx)
    {
        return data[idx];
    }
    size_t size()
    {
        return data.size();
    }
    bool empty()
    {
        return data.empty();
    }
} cache[51][51][2500];
bool seen[51][51][2500];
bool possible[51][51][2500];

grid& make(int r, int c, int m)
{
    if(seen[r][c][m])
        return cache[r][c][m];
    grid& ret=cache[r][c][m];
    seen[r][c][m]=true;
    if(m==0)
    {
        possible[r][c][m]=true;
        return ret;
    }
    if(r<=2 && c<=2)
    {
        if(r==1 && c==2 && m==1)
            ret[0][1]=true;
        else if(r==2 && c==1 && m==1)
            ret[1][0]=true;
        else if(r==2 && c==2 && m==3)
            ret[0][1]=true,
            ret[1][0]=ret[1][1]=true;
        else
            return ret;
        possible[r][c][m]=true;
        return ret;
    }
    if(r<=3 && c<=3)
    {
        if(r==1 && c==3)
        {
            if(m==1)
                ret[0][2]=true;
            else if(m==2)
                ret[0][1]=ret[0][2]=true;
            possible[r][c][m]=true;
        }
        if(r==3 && c==1)
        {
            if(m==1)
                ret[2][0]=true;
            else if(m==2)
                ret[1][0]=true,
                ret[2][0]=true;
            possible[r][c][m]=true;
        }
        else if(r==2 && c==3)
        {
            if(m==1)
                return ret;
            else if(m==2)
                ret[0][2]=ret[1][2]=true;
            else if(m==3)
                return ret;
            else if(m==4)
                return ret;
            else if(m==5)
                ret[0][1]=ret[0][2]=true,
                ret[1][0]=ret[1][1]=ret[1][2]=true;
            possible[r][c][m]=true;
        }
        else if(r==3 && c==2)
        {
            if(m==1)
                return ret;
            else if(m==2)
                ret[2][0]=ret[2][1]=true;
            else if(m==3)
                return ret;
            else if(m==4)
                return ret;
            else if(m==5)
                ret[0][1]=true,
                ret[1][0]=ret[1][1]=true,
                ret[2][0]=ret[2][1]=true;
            possible[r][c][m]=true;
        }
        else if(r==3 && c==3)
        {
            if(m==1)
                ret[2][2]=true;
            else if(m==2)
                return ret;
            else if(m==3)
                ret[2][0]=ret[2][1]=ret[2][2]=true;
            else if(m==4)
                return ret;
            else if(m==5)
                ret[0][2]=true,
                ret[1][2]=true,
                ret[2][0]=ret[2][1]=ret[2][2]=true;
            else if(m==6)
                return ret;
            else if(m==7)
                return ret;
            else if(m==8)
                ret[0][1]=ret[0][2]=true,
                ret[1][0]=ret[1][1]=ret[1][2]=true,
                ret[2][0]=ret[2][1]=ret[2][2]=true;
            possible[r][c][m]=true;
        }
        return ret;
    }
    if(r==2)
    {
        if(m==r*c-1)
        {
            for(int i=0; i<r; i++)
                for(int j=0; j<c; j++)
                    ret[i][j]=i || j;
            possible[r][c][m]=true;
            return ret;
        }
        if(m&1)
            return ret;
        if(m==r*c-2)
            return ret;
        for(int i=0; i*2<m; i++)
            ret[0][c-1-i]=ret[1][c-1-i]=true;
        possible[r][c][m]=true;
        return ret;
    }
    if(c==2)
    {
        if(m==r*c-1)
        {
            for(int i=0; i<r; i++)
                for(int j=0; j<c; j++)
                    ret[i][j]=i || j;
            possible[r][c][m]=true;
            return ret;
        }
        if(m&1)
            return ret;
        if(m==r*c-2)
            return ret;
        for(int i=0; i*2<m; i++)
            ret[r-1-i][0]=ret[r-1-i][1]=true;
        possible[r][c][m]=true;
        return ret;
    }
    if(c>r)
    {
        if(m>=c)
        {
            grid& g=make(r-1, c, m-c);
            if(possible[r-1][c][m-c])
            {
                for(unsigned int i=0; i<g.size(); i++)
                    for(unsigned int j=0; j<g[0].size(); j++)
                        ret[i][j]=g[i][j];
                for(int i=0; i<c; i++)
                    ret[r-1][i]=true;
                possible[r][c][m]=true;
                return ret;
            }
        }
        if(m>=r)
        {
            grid& g=make(r, c-1, m-r);
            if(possible[r][c-1][m-r])
            {
                for(unsigned int i=0; i<g.size(); i++)
                    for(unsigned int j=0; j<g[0].size(); j++)
                        ret[i][j]=g[i][j];
                for(int i=0; i<r; i++)
                    ret[i][c-1]=true;
                possible[r][c][m]=true;
                return ret;
            }
        }
        else
        {
            if(m==r-1)
            {
                for(int i=0; i<m-1; i++)
                    ret[r-1-i][c-1]=true;
                ret[r-1][c-2]=true;
            }
            else
            {
                for(int i=0; i<m; i++)
                    ret[r-1-i][c-1]=true;
            }
            possible[r][c][m]=true;
        }
    }
    else
    {
        if(m>=r)
        {
            grid& g=make(r, c-1, m-r);
            if(possible[r][c-1][m-r])
            {
                for(unsigned int i=0; i<g.size(); i++)
                    for(unsigned int j=0; j<g[0].size(); j++)
                        ret[i][j]=g[i][j];
                for(int i=0; i<r; i++)
                    ret[i][c-1]=true;
                possible[r][c][m]=true;
                return ret;
            }
        }
        if(m>=c)
        {
            grid& g=make(r-1, c, m-c);
            if(possible[r-1][c][m-c])
            {
                for(unsigned int i=0; i<g.size(); i++)
                    for(unsigned int j=0; j<g[0].size(); j++)
                        ret[i][j]=g[i][j];
                for(int i=0; i<c; i++)
                    ret[r-1][i]=true;
                possible[r][c][m]=true;
                return ret;
            }
        }
        else
        {
            if(m==c-1)
            {
                for(int i=0; i<m-1; i++)
                    ret[r-1][c-1-i]=true;
                ret[r-2][c-1]=true;
            }
            else
            {
                for(int i=0; i<m; i++)
                    ret[r-1][c-1-i]=true;
            }
            possible[r][c][m]=true;
        }
        return ret;
    }
    return ret;
}

void solve()
{
    printf("\n");
    cin>>R>>C>>M;
    grid& g=make(R, C, M);
    if(!possible[R][C][M])
        printf("Impossible\n");
    else
    {
        for(int i=0; i<R; i++)
            for(int j=0; j<C; j++)
                printf("%c%s", (i || j)?(g[i][j]?'*':'.'):'c', j==C-1?"\n":"");
    }
}

int main()
{
    for(int i=1; i<=50; i++)
        for(int j=1; j<=50; j++)
            for(int k=0; k<i*j; k++)
                cache[i][j][k].init(i, j);
    freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-small.out", "w", stdout);
    int T;
    scanf("%d", &T);
    for(int i=1; i<=T; i++)
    {
        printf("Case #%d:", i);
        solve();
    }
    return 0;
}
