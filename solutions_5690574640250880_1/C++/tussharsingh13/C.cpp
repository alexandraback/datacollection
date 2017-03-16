#include<bits/stdc++.h>

using namespace std;

#define s(a) scanf("%d",&a)
#define lls(a) scanf("%lld",&a)
#define ss(a) scanf("%s",a)
#define FOR(i,a,b) for(i=a;i<b;i++)

void solve(int r,int c,int m)
{
        int arr[100][100];
        for(int i=0;i<100;i++)
                        for(int j=0;j<100;j++)
                                arr[i][j]='.';
        if(r==1)
        {
                if(m==c)
                        cout<<"Impossible\n";
                else
                {
                        int i;
                        for(i=0;i<m;i++)
                                cout<<"*";
                        for(i;i<c-1;i++)
                                cout<<".";
                        cout<<"c\n";
                }
        }
        else if(c==1)
        {
                if(m==r)
                        cout<<"Impossible\n";
                else
                {
                        int i;
                        for(i=0;i<m;i++)
                                cout<<"*\n";
                        for(i;i<r-1;i++)
                                cout<<".\n";
                        cout<<"c\n";
                }
        }
        else if(r==2)
        {
                if(r*c-1==m)
                {
                        for(int i=0;i<r;i++)
                        {
                                for(int j=0;j<c;j++)
                                {
                                        if(i==r-1&&j==c-1)
                                        cout<<"c";
                                        else
                                        cout<<"*";
                                }
                                cout<<endl;
                        }
                                        
                }
                else if(m%2==0&&(m/2<c-1))
                {
                        for(int i=0;i<r;i++)
                        {
                                for(int j=0;j<c;j++)
                                {
                                        if(i==r-1&&j==c-1)
                                        cout<<"c";
                                        else if(j<m/2)
                                        cout<<"*";
                                        else
                                        cout<<".";
                                }
                                cout<<endl;
                        }
                }
                else
                        cout<<"Impossible\n";
        }
        else if(c==2)
        {
                if(r*c-1==m)
                {
                        for(int i=0;i<r;i++)
                        {
                                for(int j=0;j<c;j++)
                                {
                                        if(i==r-1&&j==c-1)
                                        cout<<"c";
                                        else
                                        cout<<"*";
                                }
                                cout<<endl;
                        }
                                        
                }
                else if(m%2==0&&(m/2<r-1))
                {
                        for(int i=0;i<r;i++)
                        {
                                for(int j=0;j<c;j++)
                                {
                                        if(i==r-1&&j==c-1)
                                        cout<<"c";
                                        else if(i<m/2)
                                        cout<<"*";
                                        else
                                        cout<<".";
                                }
                                cout<<endl;
                        }
                }
                else
                        cout<<"Impossible\n";
        }
}

int main()
{
        freopen ("C-large.in","r",stdin);
        freopen ("output.txt","w",stdout);
        int t;
        cin>>t;
        int test;
        FOR(test,1,t+1)
        {
                int r,c,m;
                cin>>r>>c>>m;
                cout<<"Case #"<<test<<":\n";
                int temp=r*c-m;
                if(r<3||c<3)
                {
                        solve(r,c,m);
                        continue;
                }
               if(temp==0||temp==2||temp==3||temp==5||temp==7)
               {
                        cout<<"Impossible\n";
                        continue;
               }
               char arr[100][100];
               for(int i=0;i<100;i++)
                        for(int j=0;j<100;j++)
                                arr[i][j]='.';
               //spl case
               if(r*c-1==m)
               {
                        for(int i=0;i<100;i++)
                        for(int j=0;j<100;j++)
                                arr[i][j]='*';
                        arr[r-1][c-1]='c';
                        for(int i=0;i<r;i++)
                        {
                                for(int j=0;j<c;j++)
                                {
                                        cout<<arr[i][j];
                                }
                                cout<<endl;
                        }
                        continue;
               }
               int row=0,col=0;
               row=m/c;
               row=min(row,r-3);
               for(int i=0;i<row;i++)
                        for(int j=0;j<c;j++)
                                arr[i][j]='*';
               
               m-=row*c;
               
               if(row<r-3&&m>0)         //not last 2 rows
               {
                        if(m==c-1)
                        {
                                for(int i=0;i<c-2;i++)
                                        arr[row][i]='*';
                                arr[row+1][0]='*';
                        }
                        else
                        {
                                for(int i=0;i<m;i++)
                                        arr[row][i]='*';
                        }
               }
               else             //last 2 rows
               {        
                       if(m>c-2)
                       {
                               if((m-c)%2==0)
                               {
                                        for(int i=0;i<c;i++)
                                                arr[row][i]='*';
                                        for(int i=0;i<(m-c)/2;i++)
                                        {
                                                arr[row+1][i]='*';
                                                arr[row+2][i]='*';
                                        }   
                               }
                               else
                               {
                                        for(int i=0;i<c-3;i++)
                                                arr[row][i]='*';
                                        for(int i=0;i<(m-c+3)/2;i++)
                                        {
                                                arr[row+1][i]='*';
                                                arr[row+2][i]='*';
                                        }
                               }
                       }
                       else
                       {
                               for(int i=0;i<m;i++)
                               {
                                        arr[row][i]='*';
                               } 
                       }
               }
               arr[r-1][c-1]='c';
               for(int i=0;i<r;i++)
               {
                        for(int j=0;j<c;j++)
                                {
                                        cout<<arr[i][j];
                                }
                                cout<<endl;
               }
        }
        return 0;
}
