#include <cstdio>
#include <cmath>

const int power[9]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int Case,len,ans,a,b,T,p;
int f[100]; 

bool judge(int a)
{
	for (int i=1;i<=p;i++) if (f[i]==a) return 1;
	return 0;
}

int main()
{
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	scanf("%d",&Case);
	while (Case--){
		scanf("%d%d",&a,&b);
		ans=0;
		len=int(log10(b))+1;
		for (int i=a;i<b;i++){
			int now=i,t=0;
            p=0;
			for (int j=1;j<len;j++){
				t+=now%10*power[j-1];
				now/=10;
				if (t*power[len-j]+now>i && t*power[len-j]+now<=b && !judge(t*power[len-j]+now)){
					ans++;
					f[++p]=t*power[len-j]+now;
				}
			}
		}
		printf("Case #%d: %d\n",++T,ans);
	}
}
