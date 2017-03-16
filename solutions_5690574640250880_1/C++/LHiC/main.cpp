#include <iostream>

using namespace std;

char arr[100][100];

bool was[100][100];

int n,m;

int DFS(int x,int y)
{
    was[x][y]=true;
    for (int i=-1;i<2;++i)
        for (int j=-1;j<2;++j)
        {
            if (x+i<0 || x+i >= n)
                continue;
            if (y+j<0 || y+j >= m)
                continue;
            if (arr[x+i][y+j]=='*')
                return 1;
        }
    int res=1;
    for (int i=-1;i<2;++i)
        for (int j=-1;j<2;++j)
        {
            if (x+i<0 || x+i >= n)
                continue;
            if (y+j<0 || y+j >= m)
                continue;
            if (was[x+i][y+j])
                continue;
            res+=DFS(x+i,y+j);
        }
    return res;
}

bool check(int n,int m,int k)
{
    ::n=n;
    ::m=m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            was[i][j]=false;
    int cnt=0;
    //for (int i=0;i<n;++i)
    //    for (int j=0;j<m;++j)
    //    {
    //        if (arr[i][j]=='*')
    //            ++cnt;
    //    }
    cnt=DFS(0,0);
    //cout<<cnt;
    if (cnt!=n*m-k)
        return false;
    else
        return true;
}

int main()
{
    int t;
    cin>>t;
    for (int tt=1;tt<=t;++tt)
    {
        int n,m,k;
        cout<<"Case #"<<tt<<":\n";
        cin>>n>>m>>k;
        //cout<<n<<" "<<m<<" "<<k<<"\n";
        for (int i=0;i<n;++i)
        {
            for (int j=0;j<m;++j)
                arr[i][j]='*';
        }
        arr[0][0]='c';
        int fr=n*m-k;
        if (n==1)
        {
            for (int i=1;i<fr;++i)
                arr[0][i]='.';
        }
        else if (m==1)
        {
            for (int i=1;i<fr;++i)
                arr[i][0]='.';
        }
        else
        {
            if (fr==1)
            {
                arr[0][0]='c';
            }
            else
            {
                int gg=false;
                for (int x=2;x<=n;++x)
                {
                    for (int y=2;y<=m;++y)
                    {
                        if (x*y<fr || 2*x+2*y-4>fr)
                            continue;
                        int d[100] {};
                        for (int i=0;i<y;++i)
                            d[i]=2;
                        d[0]=x;
                        d[1]=x;
                        fr-=2*x+2*y-4;
                        for (int i=2;i<y;++i)
                        {
                            d[i]+=min(fr,x-2);
                            fr-=d[i]-2;
                        }
                        for (int i=0;i<n;++i)
                            for (int j=0;j<m;++j)
                            {
                                if (d[j]>i)
                                    arr[i][j]='.';
                            }
                        arr[0][0]='c';
                        gg=true;
                        break;
                    }
                    if (gg)
                        break;
                }
                if (!gg)
                {
                    cout<<"Impossible\n";
                    continue;
                }
            }
        }


        for (int i=0;i<n;++i)
        {
            for (int j=0;j<m;++j)
                cout<<arr[i][j];
            cout<<"\n";
        }
    }
    return 0;
}

