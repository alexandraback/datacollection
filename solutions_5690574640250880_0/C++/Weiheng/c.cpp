#include <iostream>
using namespace std;

int main()
{
    int n,t;
    cin>>n;
    int r,c,m;
    t=1;
    char mr[200][200];
    int i,j;
    int x,y;
    int ans;
    while(t<=n)
    {
        cin>>r>>c>>m;
        //int ori=m;
        ans=0;

        for(i=0;i<r;i++)
            for(j=0;j<c;j++)
                mr[i][j]='.';

        if( r==1 || c==1) {
            ans=1;
            for(i=0;i<r;i++)
                for(j=0;j<c;j++)
                {
                    if(m>0)mr[i][j]='*';
                    m--;
                }
        } else if( m <= (r-2)*(c-2) ) {
            ans = 1;
            for(i=0;i<r-2;i++)
                for(j=0;j<c-2;j++)
                {
                    if(m>0)mr[i][j]='*';
                    m--;
                }
        } else if(r*c-m<4){
            ans = 0;
            if( r*c-m <= 1){
                for(i=0;i<r;i++)
                    for(j=0;j<c;j++)
                    {
                        if(m>0)mr[i][j]='*';
                        m--;
                    }
                ans=1;
            }
        } else {
            if( (m-(r-2)*(c-2))%2==1) {
                int k=r*c-m;
                ans = 0;
                if(k>=9 && c>=3 && r>=3){
                    for(i=0;i<r;i++)
                        for(j=0;j<c;j++)
                            mr[i][j]='*';
                    for(i=1;i<=3;i++)
                        for(j=1;j<=3;j++)
                        {
                            if(k>0)mr[r-i][c-j]='.';
                            k--;
                        }
                    for(i=r-4;i>=0;i--)
                        for(j=c-1;j>=c-2;j--)
                        {
                            if(k>0)mr[i][j]='.';
                            k--;
                        }
                    for(j=c-4;j>=0;j--)
                        for(i=r-1;i>=r-2;i--)
                        {
                            if(k>0)mr[i][j]='.';
                            k--;
                        }
                    ans=1;
                }
            }
            else {
                for(i=0;i<r-2;i++)
                    for(j=0;j<c-2;j++)
                    {
                        if(m>0)mr[i][j]='*';
                        m--;
                    }
                for(i=0;i<r-2;i++)
                    for(j=c-2;j<c;j++)
                    {
                        if(m>0)mr[i][j]='*';
                        m--;
                    }
                for(j=0;j<c-2;j++)
                    for(i=r-2;i<r;i++)
                    {
                        if(m>0)mr[i][j]='*';
                        m--;
                    }
                ans=1;
            }
        }
        mr[r-1][c-1]='c';

        if( ans == 0) {
            //fprintf(stderr,"%d\t%d\t%d\n", r,c,ori);
            cout<<"Case #"<<t<<":\n"<<"Impossible"<<endl;
        } else {
            cout<<"Case #"<<t<<":"<<endl;
            for(i=0;i<r;i++)
            {
                for(j=0;j<c;j++)
                    cout<<mr[i][j];
                cout<<endl;
            }
        }
        t++;
    }
    return 0;
}
