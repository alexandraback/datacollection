#include <iostream>
#include <cstdio>
#include <cstring>
#define maxn 110
#define M 1000000007
typedef long long ll;
using namespace std;

int next[110],a[26],pure[26],t,N,n,k,cas=0,tuan;
bool get[maxn],vis[26],link[26],flag;
char s[maxn][maxn];
ll ans;

void init()
{
	ans=1;
	flag=true;
	tuan=n=N=k=0;
	memset(get,false,sizeof get);
	memset(a,0,sizeof a);
	memset(vis,false,sizeof vis);
	memset(link,false,sizeof link);
	memset(s,0,sizeof s);
	memset(next,-1,sizeof next);
	memset(pure,0,sizeof pure);
}

bool check(char S[])
{
	for (int i=2; S[i]; i++)
		if (S[i]!=S[i-1]) return false;
	return true;
}

bool success(int x1,int x2,int pos)
{
	if (pos==-1) swap(x1,x2);
	int li=strlen(s[x1]+1);
	if (s[x1][li]==s[x2][1]) return true; 
		else return false;
}

void connect(int x,int pos)
{
	//cout<<x<<' '<<pos<<"  here !\n";
	get[x]=true;
	for (int i=1; i<=n; i++)
	{
		if (i==x) continue;
		if (get[i]) continue;
		if (success(x,i,pos))
		{
			//cout<<"success : "<<x<<' '<<i<<' '<<pos<<endl;
			if (pos==1) next[x]=i;
				else next[i]=x;
			connect(i,pos);
			return ;
		}
	}
}

bool together(char S[],int x1,int x2)
{
	for (int i=x1+1; i<=x2; i++) if (S[i]!=S[i-1]) return false;
	return true;
}

bool process()
{
	int li,cur;
	bool beg[maxn];
	char last;
	memset(beg,false,sizeof beg);
	for (int i=1; i<=n; i++)
		if (next[i]!=-1) beg[next[i]]=true;
	for (int i=1; i<=n; i++)
	{
		cur=i;
		if (beg[i]) continue;
		tuan++;
		//cout<<"here begin with ::: "<<i<<endl;
		//cout<<"next[2]= "<<next[2]<<endl;
		last=s[i][1];
		vis[last-'a']=true;
		while (true)
		{
			li=strlen(s[cur]+1);
			for (int j=2; s[cur][j]; j++)
				if (s[cur][j]!=s[cur][j-1])
				{
					if (vis[s[cur][j]-'a']) return false;
					vis[s[cur][j]-'a']=true;
					if (j!=1 && j!=li)
					{
						if (together(s[cur],1,j) || together(s[cur],j,li)) continue;
						if (pure[s[cur][j]-'a']>0) return false;
					}
				}
			//cout<<"1cur= "<<cur<<endl;
			if (a[s[cur][1]-'a']>1) return false;
			a[s[cur][1]-'a']++;
			//cout<<"2cur= "<<cur<<endl;
			if (a[s[cur][li]-'a']>1) return false;
			a[s[cur][li]-'a']++;
			//cout<<"3cur= "<<cur<<endl;
			if (next[cur]==-1) break;
				else cur=next[cur];
			//cout<<"4cur= "<<cur<<endl;
		}
	}
	return true;
}

ll mul(int x)
{
	ll tot=1;
	while (x>1) 
	{
		tot=(tot*x)%M;
		x--;
	}
	return tot;
}

int main()
{
	
	freopen("e:/B-small-attempt2.in","rb",stdin);
	freopen("e:/data.out","wb",stdout);
	
	scanf("%d",&t);
	while (t--)
	{
		printf("Case #%d: ",++cas);
		init();
		scanf("%d",&N);
		while (N--)
		{
			n++;
			scanf("%s",s[n]+1);
			if (check(s[n]))
			{
				pure[s[n][1]-'a']++;
				memset(s[n],0,sizeof s[n]);
				n--;
			}
		}
		N=0;
		//cout<<n<<endl;
		for (int i=1; i<=n; i++)
		{
			if (get[i]==false)
			{
				connect(i,1);
				connect(i,-1);
			}
		}
		flag=process();
		for (int i=0; i<26; i++) if (link[i]>2) flag=false;
		
		if (flag==false) 
		{
			printf("0\n");
			continue;
		}
		//cout<<"tuam= "<<tuan<<' '<<ans<<endl;
		for (int i=0; i<26; i++)
			if (pure[i]>0 && vis[i]==false) tuan++;
		//cout<<"tuam= "<<tuan<<' '<<ans<<endl;
		ans=(ans*mul(tuan))%M;
		for (int i=0; i<26; i++)
			if (pure[i]>0) ans=(ans*mul(pure[i]))%M;
		printf("%lld\n",ans);
	}
    return 0;
}
