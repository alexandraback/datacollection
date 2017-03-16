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
int sb[200];
bool us[200];
int tl[200],tr[200];
int ok=0,cts,n;
const int mod=1000000007;
long long find(int x)
{
	long long s=1;
	if(tot[x])
		for(int i=1;i<=tot[x];i++)
			s=s*i%mod;
	tot[x]=0;
	for(int i=0;i<n;i++)
		if(!us[i]&&lib[i][0]==x)
		{
			us[i]=1;
			ok++;
			s=s*find(lib[i][1])%mod;
		}
	return s;
}
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        bool f=1;
        memset(v,0,sizeof(v));
        memset(lib,0,sizeof(lib));
        memset(in,0,sizeof(in));
        memset(tot,0,sizeof(tot));
        memset(tl,0,sizeof(tl));
        memset(tr,0,sizeof(tr));
        memset(us,0,sizeof(us));
        ok=0;cts=0;
        for(int i=0;i<n;i++)
        {
            scanf("%s",lib[i]);
            int j=strlen(lib[i]);
            j=unique(lib[i],lib[i]+j)-lib[i];
            lib[i][j]=0;
            if(j==1)
            {
                tot[lib[i][j-1]]++;
                us[i]=1;ok++;
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
            tl[lib[i][0]]++;
            tr[lib[i][1]]++;/
            //lib[i][1]=lib[i][j-1];lib[i][2]=0;
            sb[lib[i][0]]=i;
            if(tl[lib[i][0]]>1)f=0;
            if(tr[lib[i][0]]>1)f=0;
        }
        printf("Case #%d: ",ti++);
		if(f==0)
		{
			puts("0");
			continue;
		}
		int t2;
		long long tot1=1;
		for(int i=0;i<26;i++)
			if(tl[i]&&!tr[i])
				if(t2=find(i))
					tot1=tot1*t2%mod,cts++;
				else
					break;
        int j;
		for(int i=0;i<26;i++)
			if(tot[i])
			{
				for(t2=1,j=1;j<=tot[i];j++)
					tot1=tot1*j%mod;
				cts++;
			}
		if(ok<n)
		{
			puts("0");
			continue;
		}
		for(int i=1;i<=cts;i++)
			tot1=tot1*i%mod;
		printf("%I64d\n",tot1);
    }
    return 0;
}
/*
int maz[22][22];
int n,m,k;
void bfs(int i,int j)
{
    queue<int>;
    for(int i=0;i<n;)
}
bool check()
{
    memset(v,0,sizeof(v));
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(v[i][j]==0)bfs(i,j);
}
int main()
{
    freopen("B-small-attempt2.in","r",stdin);
    freopen("B-small-attempt2.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&m,&k);
        int lim=1<<(n*m),ans=0x3fffffff;
        for(int i=0;i<lim;i++)
        {
            int cnt=0;
            for(int j=0;j<n*m;j++)
                if((1<<j)&i)
                    maz[j/m][j%m]=1,cnt++;
                else
                    maz[j/m][j%m]=0;
            if(check())ans=min(ans,cnt);
        }
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}*/
