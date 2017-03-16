#include<iostream>
#include<vector>
#include<set>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int z=0;z<t;z++)
    {
        int r,c,m;
        cin>>r>>c>>m;
        int mn=m;
        char tab[r][c];
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                tab[i][j]='.';
            }
        }
        tab[r-1][c-1]='c';
        if(m+1==r*c)
        {
            for(int i=0;i<r && mn!=0;i++)
            {
                for(int j=0;j<c && mn!=0;j++)
                {
                    tab[i][j]='*';
                    mn--;
                }
            }
            cout<<"Case #"<<z+1<<": "<<endl;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    cout<<tab[i][j];
                }
                cout<<endl;
            }
        }
        else if(r==1 || c==1)
        {
            for(int i=0;i<r && mn!=0;i++)
            {
                for(int j=0;j<c && mn!=0;j++)
                {
                    tab[i][j]='*';
                    mn--;
                }
            }
            cout<<"Case #"<<z+1<<": "<<endl;
            for(int i=0;i<r;i++)
            {
                for(int j=0;j<c;j++)
                {
                    cout<<tab[i][j];
                }
                cout<<endl;
            }
        }
        else if(r==2 || c==2)
        {
            if(mn%2==1)
            {
                cout<<"Case #"<<z+1<<": "<<endl;
                cout<<"Impossible"<<endl;
            }
            else
            {
                if(mn+2==r*c)
                {
                    cout<<"Case #"<<z+1<<": "<<endl;
                    cout<<"Impossible"<<endl;
                }
                else if(c==2)
                {
                    for(int i=0;i<r && mn!=0;i++)
                    {
                        for(int j=0;j<c && mn!=0;j++)
                        {
                            tab[i][j]='*';
                            mn--;
                        }
                    }
                    cout<<"Case #"<<z+1<<": "<<endl;
                    for(int i=0;i<r;i++)
                    {
                        for(int j=0;j<c;j++)
                        {
                            cout<<tab[i][j];
                        }
                        cout<<endl;
                    }
                }
                else
                {
                    for(int i=0;i<c && mn!=0;i++)
                    {
                        tab[0][i]='*';
                        mn--;
                        tab[1][i]='*';
                        mn--;
                    }
                    cout<<"Case #"<<z+1<<": "<<endl;
                    for(int i=0;i<r;i++)
                    {
                        for(int j=0;j<c;j++)
                        {
                            cout<<tab[i][j];
                        }
                        cout<<endl;
                    }
                }
            }
        }
        else
        {
            int upp=r-3,left=c-3;
            bool flag=true;
            for(int i=0;i<upp && mn!=0;i++)
            {
                for(int j=0;j<c-2 && mn!=0;j++)
                {
                    tab[i][j]='*';
                    mn--;
                }
                if(mn==1)
                {
                    tab[i+1][0]='*';
                    mn--;
                    break;
                }
                else if(mn!=0)
                {
                    tab[i][c-2]='*';
                    mn--;
                    tab[i][c-1]='*';
                    mn--;
                }
            }
            for(int i=upp;i<r-2 && mn!=0;i++)
            {
                for(int j=0;j<left && mn!=0;j++)
                {
                    tab[i][j]='*';
                    mn--;
                }
            }
            for(int j=0;j<left && mn!=0;j++)
            {
                if(mn==1)
                {
                    tab[upp][left]='*';
                    mn--;
                }
                else
                {
                    tab[r-2][j]='*';
                    mn--;
                    tab[r-1][j]='*';
                    mn--;
                }
            }
            if(mn==1)
            {
                tab[upp][left]='*';
                mn--;
            }
            else if(mn==3)
            {
                tab[upp][left]='*';
                mn--;
                tab[upp+1][left]='*';
                mn--;
                tab[upp+2][left]='*';
                mn--;
            }
            else if(mn==5)
            {
                tab[upp][left]='*';
                mn--;
                tab[upp+1][left]='*';
                mn--;
                tab[upp+2][left]='*';
                mn--;
                tab[upp][left+1]='*';
                mn--;
                tab[upp][left+2]='*';
                mn--;
            }
            if(mn==0)
            {
                cout<<"Case #"<<z+1<<": "<<endl;
                for(int i=0;i<r;i++)
                {
                    for(int j=0;j<c;j++)
                    {
                        cout<<tab[i][j];
                    }
                    cout<<endl;
                }
            }
            else
            {
                cout<<"Case #"<<z+1<<": "<<endl;
                cout<<"Impossible"<<endl;
            }
        }
    }
    return 0;
}
