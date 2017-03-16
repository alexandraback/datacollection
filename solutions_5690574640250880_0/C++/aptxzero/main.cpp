#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
using namespace std;

void solve(int R,int C,int M)
{
    int L=R*C-M;
    if(R==1)
    {
        for(int i=1;i<C;++i)
        {
            cout<<(i<=M?'*':'.');
        }
        cout<<"c\n";
    }
    else if(C==1)
    {
        for(int i=1;i<R;++i)
        {
            cout<<(i<=M?"*\n":".\n");
        }
        cout<<"c\n";
    }
    else if(L==1)
    {
        for(int i=1;i<=R;++i)
        {
            for(int j=1;j<=C;++j)
            {
                if(i==R && j==C)cout<<'c';
                else cout<<'*';
            }
            cout<<'\n';
        }
    }
    else if( (L==2 || L==3 || L==5 || L==7) || ((R==2 || C==2) && L&1) )
    {
        cout<<"Impossible\n";
    }
    else
    {
        char m[50][50];
        memset(m,'*',sizeof(m));
        m[0][0]='c';
        m[0][1]=m[1][0]=m[1][1]='.';
        L-=4;
        for(int i=2;i<C&&L>=2&&L!=3;++i,L-=2)
        {
            m[0][i]=m[1][i]='.';
        }
        for(int i=2;i<R&&L>=2;++i,L-=2)
        {
            m[i][0]=m[i][1]='.';
        }
        for(int i=2;i<R&&L>0;++i)
        {
            for(int j=0;j<C&&L>0;++j)
            {
                if(m[i][j]!='.')
                {
                    m[i][j]='.';
                    --L;
                }
            }
        }
        for(int i=0;i<R;++i)
        {
            for(int j=0;j<C;++j)
            {
                cout<<m[i][j];
            }
            cout<<'\n';
        }
    }
}

int main()
{
#ifdef LOCALMACHINE
    freopen("C:\\Users\\zero\\Desktop\\C-small-attempt0.in","r",stdin);
    freopen("C:\\Users\\zero\\Desktop\\C-small-attempt0.txt","w",stdout);
#endif
    int T,R,C,M;
    cin>>T;
    for(int i=1;i<=T;++i)
    {
        cout<<"Case #"<<i<<":\n";
        cin>>R>>C>>M;
        solve(R,C,M);
    }
    return 0;
}
