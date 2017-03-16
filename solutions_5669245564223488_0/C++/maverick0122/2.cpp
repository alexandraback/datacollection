#include<cstdio>
#include<cstring>

int n;
const long long mod = 1000000007;
char car[110][110];
int all[30];
bool head[30],tail[30],mid[30],flag[30];

long long fun()
{
    memset(head,0,sizeof(head));
    memset(tail,0,sizeof(tail));
    memset(mid,0,sizeof(mid));
    memset(all,0,sizeof(all));
    memset(flag,0,sizeof(flag));
		
    for(int i=0; i<n; i++)
    {
        int len = strlen(car[i]);
        
        for(int j=0; j<len; )
        {
            int in = car[i][j]-'a';
            int k = j+1;
            for(; k<len && car[i][k]==car[i][k-1]; k++) ;
            if(j==0 && k==len)
            {
                all[in]++;
            }
            else if(j>0 && k<len)
            {
                if(flag[in]) return 0;
                mid[in] = 1;
            }
            else if(j==0)
            {
                if(head[in] || mid[in]) return 0;
                head[in] = 1; 
            }
            else
            {
                if(tail[in] || mid[in]) return 0;
                tail[in] = 1;
            }
            
            flag[in] = 1;
            j = k;
        }
    }
    
    long long num = n;
    for(int i=0; i<26; i++)
        num -= all[i];
    if(num>0)
    {
        for(int i=0; i<26; i++)
        {
            if(head[i] && tail[i]) num--;
        }
        if(num<=0) return 0;
    }
    
    long long ans = 1;
    for(int i=0; i<26; i++)
    {
        if(all[i]>0) 
        {
            if(!head[i] && !tail[i])
                num++;
            long long tmp = all[i];
            for(; tmp>0; tmp--)
            {
                ans = (ans*tmp)%mod;
            }
        }
    }
    for(; num>0; num--)
    {
        ans = (ans*num)%mod;
    }
    return ans;
}

int main()
{
    freopen("B-small-attempt2.in","r",stdin);
	freopen("B-small-attempt2.out","w",stdout);
	
	int t;
	scanf("%d",&t);
	for(int cnt=1;cnt<=t;cnt++)
	{
		scanf("%d",&n);
		
		for(int i=0; i<n; i++)
        {
            scanf("%s",car[i]);
        }
		printf("Case #%d: %lld\n",cnt,fun());
	} 
} 
