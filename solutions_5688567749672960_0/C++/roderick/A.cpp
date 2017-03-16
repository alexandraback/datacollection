#include<cstdio>
#include<cstring>
#include<algorithm>
#define fou(i,j,k) for (int i=j;i<=k;i++)
#define fod(i,j,k) for (int i=j;i>=k;i--)
using namespace std;

typedef long long LL;

const int maxn=1000010;
const int maxm=2000010;
const int oo=1000000000;

struct node{
	int y,d,next;
}a[maxm];

int d[maxn],list[maxn],n,st,ed;
int len,first[maxn];
bool v[maxn];

void init()
{
	scanf("%d",&n);
}

void ins(int x,int y,int d)
{
	len++;
	a[len].y=y;a[len].d=d;a[len].next=first[x];first[x]=len;
}

void spfa()
{
	int i,k,x,y,head,tail;
	
	for (i=1;i<=n;i++){
		d[i]=oo;v[i]=false;
	}
	d[st]=1;v[st]=true;head=1;tail=2;
	if (ed==1) return;
	list[1]=st;
	while (head!=tail){
		x=list[head++];
		if (head==n+1) head=1;
		v[x]=false;
		for (k=first[x];k!=-1;k=a[k].next){
			y=a[k].y;
			if (d[y]>d[x]+a[k].d){
				d[y]=d[x]+a[k].d;
				if (!v[y]){
					v[y]=true;
					if (d[y]<d[list[head]]){
						head--;if (head==0) head=n;
						list[head]=y;
					}else
					{
						list[tail++]=y;
						if (tail==n+1) tail=1;
					}
				}
			}
		}
	}
}

void solve()
{
	st=1;ed=n;
	spfa();
	printf("%d\n",d[ed]);
}

int change(int x)
{
	int tmp=0;
	while (x){
		tmp*=10;
		tmp+=x%10;
		x/=10;
	}
	return tmp;
}

int main()
{
	int T;
	len=0;memset(first,-1,sizeof(first));
	fou(i,1,1000000){
		ins(i,change(i),1);
		ins(i,i+1,1);
	}
	scanf("%d",&T);
	fou(i,1,T){
		printf("Case #%d: ",i);
		init();
		solve();
	}
	return 0;
}
