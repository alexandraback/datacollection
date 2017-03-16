#include<bits/stdc++.h>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 1000005
using namespace std;
typedef long long LL;
int t,len;
LL n,ans;
char buf[200],buf2[200];
int Dig(LL x)
{
	int re=0;
	while(x)
	{
		re++;
		x/=10;
	}
	return re;
}
int main()
{
	scanf("%d",&t);
	REP(tt,1,t)
	{
		scanf("%I64d",&n);
		if(n<=11)
		{
			printf("Case #%d: %d\n",tt,(int)n);
			continue;
		}
		
		int dig = Dig(n);
		LL tmp=19, tmp2=9;
		ans=0;
		REP(i,2,dig)
		{
			if(i==2) ans+=10;
			else if(i==3)ans+=19;
			else
			{
				if(i%2==0) tmp2*=10;
				tmp += tmp2;
				ans += tmp;
			}
		}
	
		sprintf(buf, "%I64d", n);
		len = strlen(buf);
		int pos = len/2-1; //0~pos pos+1~len-1

		//special
		bool flg = true;
		bool flg2 = true;

		if(buf[0]!='1') flg2 = false;
		REP(i,1,pos) if(buf[i]!='0') flg2 = false;
		REP(i,pos+1,len-1) if(buf[i]!='0') flg=false;
		if(flg2) flg = false;
		if(flg)
		{
			LL m;
			REP(i,0,pos) buf2[i] = buf[i]; buf2[pos+1] = 0;
			sscanf(buf2, "%I64d", &m);
			sprintf(buf2, "%I64d", m-1);
			REP(i,0,pos) buf[i] = buf2[i];
			buf[len-1] = '1';

			sscanf(buf, "%I64d", &m);
			ans += n-m;

			//printf("sp = %s\n",buf);

			/*ans++;
			n--;
			sprintf(buf, "%I64d", n);*/

			flg2 = true;
			if(buf[0]!='1') flg2 = false;
			REP(i,1,pos) if(buf[i]!='0') flg2 = false;
		}

		LL m;
		if(!flg2)
		{
			REP(i,0,pos) buf2[i] = buf[i]; buf2[pos+1] = 0;
			reverse(buf2, buf2+pos+1);
			sscanf(buf2, "%I64d", &m);
			ans += m+1;

			sscanf(buf+pos+1, "%I64d", &m);
			ans += m-1;
		}
		else
		{
			sscanf(buf+pos+1, "%I64d", &m);
			ans += m;
		}

		printf("Case #%d: %I64d\n",tt,ans);
	}
	return 0;
}


