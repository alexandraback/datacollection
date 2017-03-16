#include<set>
#include<map>
#include<cmath>
#include<queue>
#include<string>
#include<cstdio>
#include<vector>
#include<cassert>
#include<cstring>
#include<cstdlib>
#include<utility>
#include<iostream>
#include<algorithm>
#include<functional>
#define REP(x,y,z) for(int x=y;x<=z;x++)
#define FORD(x,y,z) for(int x=y;x>=z;x--)
#define MSET(x,y) memset(x,y,sizeof(x))
#define FOR(x,y) for(__typeof(y.begin()) x=y.begin();x!=y.end();x++)
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define SZ size()
#define M 35
using namespace std;
typedef long long LL;
//////////////////////////////////////////////////////
const int size = 10000;
const int BN_AZ=40;
struct BigNum
{
	int len,x[BN_AZ];
	
	void print()
	{
		printf("%d", x[len-1]);
		FORD(i,len-2,0)
			printf("%04d", x[i]);
	}
	
	void reset()
	{
		len = 1;
		MSET(x,0);
	}
	
	void clear_trash()
	{
		while (len>1 && !x[len-1])
			len--;
	}
	
	void str_change(char s[])
	{
		reset();
		len = strlen(s) / 4;
		int remain = strlen(s)%4, j=0;
		if (remain) len++;
		else remain = 4;
		REP(i,0,remain-1)
			x[len-1] = x[len-1]*10 + s[i]-'0';
		FORD(i,len-2,0)
		{
			sscanf(s+remain+j, "%04d", &x[i]);
			j+=4;
		}
		clear_trash();
	}
	
	void int_change(LL num)
	{
		reset();
		if (num==0) return;
		len = 0;
		while (num)
		{
			x[len++] = num%size;
			num /= size;
		}
	}
	
	bool operator > (const BigNum &ag)
	{
		if (len != ag.len) return len > ag.len;
		FORD(i,len-1,0)
			if (x[i] != ag.x[i])
				return x[i] > ag.x[i];
		return false;
	}
	
	bool operator < (const BigNum &ag)
	{
		if (len != ag.len) return len < ag.len;
		FORD(i,len-1,0)
			if (x[i] != ag.x[i])
				return x[i] < ag.x[i];
		return false;
	}
	
	bool operator == (const BigNum &ag)
	{
		if (len != ag.len) return false;
		REP(i,0,len-1)
			if (x[i] != ag.x[i])
				return false;
		return true;
	}
	
	bool operator != (const BigNum &ag)
	{
		return !(*this==ag);
	}
	
	bool operator >= (const BigNum &ag)
	{
		return !(*this<ag);
	}
	
	bool operator <= (BigNum ag)
	{
		return !(*this>ag);
	}
	
	BigNum (){ reset(); }
	BigNum (int num){ int_change(num); }
	BigNum (LL num){ int_change(num); }
	BigNum (char s[]){ str_change(s); }
	
	BigNum operator + (const BigNum &ag)
	{
		BigNum ans;
		ans.reset();
		int l = std::max(ag.len,len);
		REP(i,0,l-1)
		{
			ans.x[i] += x[i] + ag.x[i];
			if (ans.x[i] >= size)
			{
				ans.x[i+1]++;
				ans.x[i] -= size;
			}
		}
		if (ans.x[l]) l++;
		ans.len = l;
		ans.clear_trash();
		
		return ans;
	}
	
	BigNum operator - (const BigNum &ag)
	{
		BigNum ans;
		ans.reset();
		int l = std::max(ag.len, len);
		REP(i,0,l-1)
		{
			ans.x[i] += x[i] - ag.x[i];
			if (ans.x[i] < 0)
			{
				ans.x[i] += size;
				ans.x[i+1]--;
			}
		}
		ans.len = l;
		ans.clear_trash();
		
		return ans;
	}
	
	BigNum operator * (const BigNum &ag)
	{
		BigNum ans;
		ans.reset();
		REP(i,0,len-1)
		{
			REP(j,0,ag.len-1)
			{
				int l = i+j;
				ans.x[l] += x[i] * ag.x[j];
				while (ans.x[l] >= size)
				{
					ans.x[l+1] += ans.x[l] / size;
					ans.x[l++] %= size;
				}
			}
		}
		ans.len = len+ag.len+1;
		ans.clear_trash();
		
		return ans;
	}
	
	BigNum operator / (BigNum ag2)
	{
		int l,r,m;
		BigNum ag1=*this, ans, tmp, minus;
		ans.len = ag1.len;
		FORD(i,ag1.len-1,0)
		{
			l = 0;
			r = size;
			while (l < r)
			{
				m = (l + r) / 2;
				tmp=ag2*BigNum(m);
				minus.reset();
				REP(j,0,tmp.len-1)
					minus.x[i+j] = tmp.x[j];	
				minus.len = tmp.len + i;
				if (minus <= ag1)
					l = m + 1;
				else
					r = m;
			}
			tmp=ag2*BigNum(ans.x[i]=l-1);
			minus.reset();
			REP(j,0,tmp.len-1)
				minus.x[i+j] = tmp.x[j];	
			minus.len = tmp.len+i-1;
			ag1 = ag1-minus;
		}
		ans.clear_trash();
		
		return ans;
	}
	
	BigNum operator % (BigNum ag)
	{
		return *this-*this/ag*ag;
	}
}ans;
/////////////////////////////////////////////////////
int t,ba[M],bb[M],bk[M],pw[M];
//long long ans;
void read(int x[])
{
	memset(x,0,sizeof(int)*M);
	int tmp,pos=0;
	scanf("%d",&tmp);

	while(tmp)
	{
		if(tmp&1)x[pos]=1;
		else     x[pos]=0;
		pos++;
		tmp>>=1;
	}
}
void dfs(int pos,bool sa,bool sb,bool sk)
{
	if(!sa && !sb && !sk)
	{
		ans = ans + (long long)pw[pos+1]*pw[pos+1];
		return;
	}
	
	if(pos==-1)
	{
		return;
	}
	
	int nk;
	bool nsa,nsb,nsk;
	REP(na,0,1)REP(nb,0,1)
	{
		nk=na&nb;
		nsa=sa;
		nsb=sb;
		nsk=sk;
		if(na<ba[pos])nsa=false;
		if(nb<bb[pos])nsb=false;
		if(nk<bk[pos])nsk=false;

		if(na>ba[pos] && nsa)continue;
		if(nb>bb[pos] && nsb)continue;
		if(nk>bk[pos] && nsk)continue;

		dfs(pos-1,nsa,nsb,nsk);
	}
}
int main()
{
	pw[0]=1;REP(i,1,M-1)pw[i]=pw[i-1]*2;
	
	scanf("%d",&t);
	REP(tt,1,t)
	{
		ans=0;
		read(ba);read(bb);read(bk);
		dfs(31,true,true,true);

		printf("Case #%d: ",tt);
		ans.print();
		puts("");
		//printf("%I64d\n",ans);
	}
	return 0;
}

