#include<cstdio>
#include<iostream>
#include<fstream>
#include<map>

using namespace std;
int grid[105][105];
int col[105];
int row[105];
map<int,int,greater<int> > m2;

int main()
{
    freopen("codejam2.in","r",stdin);
    freopen("codejam2out.txt","w",stdout);
    int tc,m,n;
    scanf("%d",&tc);
    //cout << tc << endl;
    for (int i=0; i<tc; i++)
    {
        m2.clear();
        bool success=true;
        scanf("%d%d",&m,&n);
        for (int j=0; j<m; j++)
        {
            for (int k=0; k<n; k++)
            {
                scanf("%d",&(grid[j][k]));
                m2[grid[j][k]]=1;
            }
        }
        //Set rows, columns to 1
        for (int j=0; j<m; j++)
        {
            row[j]=1;
        }
        for (int j=0; j<n; j++)
        {
            col[j]=1;
        }
        //Checks through all possible values
        for (map<int,int,greater<int> >::iterator it=m2.begin(); it!=m2.end(); ++it)
        {
            //Does the grid satisfy?
            for (int j=0; j<m; j++)
            {
                for (int k=0; k<n; k++)
                {
                    if (grid[j][k]<=(*it).first)
                    {
                       if (row[j]==0 && col[k]==0)
                       {
                          success=false;
                          break;
                       }
                    }
                }
                if (!success)
                {
                   break;
                }
            }
            for (int j=0; j<m; j++)
            {
                for (int k=0; k<n; k++)
                {
                    if (grid[j][k]==(*it).first)
                    {
                       row[j]=0;
                       col[k]=0;
                    }
                }
            }
            if (!success)
            {
               break;
            }
        }
        printf("Case #%d: ",i+1);
        if (!success)
        {
           printf("NO\n");
        }
        else
        {
            printf("YES\n");
        }
    }
}
