#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int map[105][105];
bool done[105][105];
int main()
{
    //freopen("a.in","r",stdin);
    //freopen("a.out","w",stdout);
    int cas;
    scanf("%d",&cas);
    for(int z=1; z<=cas; z++)
    {
        memset(map,0,sizeof(map));
        memset(done,0,sizeof(done));
        printf("Case #%d: ",z);
        int m,n;
        scanf("%d %d",&m,&n);
        int mmax=-1;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                scanf("%d",&map[i][j]);
                if(mmax<map[i][j])
                {
                    mmax=map[i][j];
                }
            }
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(map[i][j]==mmax)done[i][j]=1;
            }
        }
        int allfail=0;
        for(int k=mmax-1; k>=1; k--)
        {
            for(int i=0; i<m; i++)
            {
                for(int j=0; j<n; j++)
                {
                    allfail=0;
                    bool fail=0;
                    if(map[i][j]==k&&done[i][j]==0)
                    {
                        for(int cnt=0; cnt<m; cnt++)
                        {
                            if(map[cnt][j]>map[i][j])
                            {
                                fail=1;
                                break;
                            }
                        }
                        if(!fail)
                        {
                            for(int cnt=0; cnt<m; cnt++)
                            {
                                if(map[cnt][j]==k)
                                    done[cnt][j]=1;
                            }
                        }
                        else allfail++;

                        fail=0;
                        for(int cnt=0; cnt<n; cnt++)
                        {
                            if(map[i][cnt]>map[i][j])
                            {
                                fail=1;
                                break;
                            }
                        }
                        if(!fail)
                        {
                            for(int cnt=0; cnt<n; cnt++)
                            {
                                if(map[i][cnt]==k)
                                    done[i][cnt]=1;
                            }
                        }
                        else allfail++;
                        if(allfail==2)break;
                    }
                }
                if(allfail==2)break;
            }
            if(allfail==2)break;
        }
        if(allfail==2)
        {
            printf("NO\n");
            continue;
        }
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(done[i][j]==0)
                {
                    allfail=2;
                    break;
                }
            }
            if(allfail==2)break;
        }
        if(allfail==2)printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
