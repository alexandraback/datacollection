#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;

char lib[20][105];
int a[20];
bool v[200],in[200];
int s[20000];
int tot[200];
const int mod=1000000007;
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        bool f=1;
        memset(v,0,sizeof(v));
        memset(lib,0,sizeof(lib));
        memset(in,0,sizeof(in));
        memset(tot,0,sizeof(tot));
        for(int i=0;i<n;i++)
        {
            scanf("%s",lib[i]);
            int j=strlen(lib[i]);
            j=unique(lib[i],lib[i]+j)-lib[i];
            lib[i][j]=0;
            if(j==1)
            {
                //tot[lib[i][j-1]]++;
                //i--;n--;
                continue;
            }
            if(lib[i][0]==lib[i][j-1])f=0;
            else
            {
                if(in[lib[i][0]]||in[lib[i][j-1]])f=0;
                for(int z=1;z<j-1;z++)
                    if(v[lib[i][z]-'a']==0)v[lib[i][z]-'a']=1;
                    else f=0;
                v[lib[i][0]-'a']=1;
                v[lib[i][j-1]-'a']=1;
                for(int z=1;z<j-1;z++)
                    in[lib[i][z]-'a']=1;
            }
            lib[i][1]=lib[i][j-1];lib[i][2]=0;
        }

        //dfs();

        int ans=0;
        printf("Case #%d: ",ti++);
        if(f)
        {
            for(int i=0;i<n;i++)a[i]=i;
            do
            {
                int k=0;
                for(int i=0;i<n;i++)
                {
                    int p=a[i];
                    for(int j=0;lib[p][j];j++)
                        s[k++]=lib[p][j];
                }
                s[k]=0;
                bool fs=0;
                k=unique(s,s+k)-s;
                memset(v,0,sizeof(v));
                for(int i=0;i<k;i++)
                    if(v[s[i]]==0)v[s[i]]=1;
                    else fs=1;
                if(fs==0)ans++;
            }while(next_permutation(a,a+n));
        }
        printf("%d\n",ans);
    }
    return 0;
}
