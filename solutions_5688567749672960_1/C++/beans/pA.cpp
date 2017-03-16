#include<bits/stdc++.h>
#define LL long long
using namespace std;
int kase;
char num[200];
LL x;
void process()
{
	LL ans=0;
	if(x%10==0) x--,ans++;
	int len=0;
	while(x) {num[len]=x%10+'0';x/=10;len++;}
	//printf("len=%d\n",len);
	while(len>1)
	{
		LL toadd=0;
		for(int i=(len%2==1?len/2:len/2-1);i>=0;i--)
		{
			toadd*=10;
			toadd+=num[i]-'0';
			num[i]='0';
		}
		num[0]='1';
		toadd--;

		bool thesame=1;
		for(int i=0;i<len;i++) if(num[i]!=num[len-1-i]) {thesame=0;break;}
		if(!thesame) toadd++;
		//printf("toadd=%lld\n",toadd);

		ans+=toadd,toadd=0;
		reverse(num,num+len);

		//for(int i=len-1;i>=0;i--) printf("%c",num[i]);puts("");

		for(int i=len/2-1;i>=0;i--)
		{
			toadd*=10;
			toadd+=num[i]-'0';
			num[i]='0';
		}
		toadd++;
		ans+=toadd;
		len--;
		for(int i=0;i<len;i++) num[i]='9';
	}
	ans+=num[0]-'0';
	printf("Case #%d: %lld\n",++kase,ans);
}
int main()
{
	//freopen("largeA.in","r",stdin);
	//freopen("largeA.out","w",stdout);
	int T;
	kase=0;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld",&x);
        process();
	}
}
