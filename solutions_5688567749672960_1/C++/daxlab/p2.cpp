#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define dbg(k) cout<<#k<<": "<<k<<endl
#define dbgv(k,i) cout<<#k<<"["<<i<<"]: "<< k[i]<<endl
#define makk 99999999
#define minn -99999999
#define PB push_back
#define MP make_pair
#define ff first
#define ss second
#define mod 1000000007
#define f(i,a,b) for(i = a; i < b; i++)
#define sz(a) int((a).size())
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin() i = (c).begin(); i != (c).end(); i++)
#define present(c,k) ((c).find(k) != (c).end())
#define cpresent(c,k) (find(all(c),k) != (c).end())
#define pii pair< int,int >
#define sc(n) scanf("%lld",&n)
//#define gc getchar_unlocked
//void sc(int &k){register int c = gc();k = 0;int neg = 0;for(;((c<48 || c>57) && c != '-');c = gc());if(c=='-') {neg=1;c=gc();}for(;c>47 && c<58;c = gc()) {k = (k<<1) + (k<<3) + c - 48;}if(neg) k=-k;}
//#define pc(k) putchar_unlocked(k)

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("out.out","w",stdout);
    #endif
    ll t,i,flag,n,k,sol,temp,p,j;
	sc(t);
	f(j,0,t)
	{
		sc(n);
		if(n <= 19)
			printf("Case #%lld: %lld\n",j+1,n);
		else
		{
			k=1;
			flag=0;
			sol=0;
			while(n >= k*10)
			{
				sol += (k-1) + 10;
				k *= 10;
			}
			if(k == n)
				printf("Case #%lld: %lld\n",j+1,sol);
			else
			{
				temp = n;
				i = 0;
				while(temp > 0)
				{
					i++;
					temp /= 10;
				}
				if(i&1)
					flag=1;
				i=(i+1) >> 1;
				temp=1;
				while(i--)
					temp *= 10;
				sol += n%temp;
				n /= temp;
				if(flag == 1 && n ==(temp/100))
					sol--;
				else if(!flag && n==(temp/10))
					sol--;
				p = n*10;
				temp = 0;
				while(n>0)
				{
					temp = temp*10+(n%10);  n /= 10;
				}
				sol += temp;
				printf("Case #%lld: %lld\n",j+1,sol);
			}
		}
	}
	return 0;
}
