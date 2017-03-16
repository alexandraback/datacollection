/*
	amitbaranwal53@gmail.com
	IIT (BHU),VARANASI
*/
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <ctime>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <iostream>
#include <algorithm>

using namespace std;

int temp,i,j,k,T;

#define CASE s(T);while(T--)
#define FOR(I,A,B) for(I=A;I<B;++I)
#define REP(i,n) FOR(i,0,n)
#define FORR(I,J,K) for(I=J;I>K;--I)
#define JAM(N) printf("Case #%d: ",N)
#define INPUT(A) freopen(A,"r",stdin);
#define OUTPUT(A) freopen(A,"w",stdout);

#define all(x) x.begin(), x.end()
#define fill(a, val) memset(a, val, sizeof(a))
#define INDEX(a, val) (lower_bound(all(a), val) - a.begin())

#define EXP 1e-10
#define INF (int)1e9

#define F first
#define S second
#define MP make_pair
#define PB push_back

typedef long long LL;
typedef vector<int> VI;
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
typedef pair<int,PII> TRI;
typedef unsigned long long ULL;

#define deb(n) cout<<"(<<< DEBUG "<<n<<" >>>)"<<endl;

#define s(n)					scanf("%d",&n)
#define sl(n) 					scanf("%ld",&n)
//#define sll(n) 					scanf("%lld",&n)
#define sf(n) 					scanf("%f",&n)
#define slf(n) 					scanf("%lf",&n)
#define ss(n) 					scanf("%s",n)

LL pow_r(LL d,LL n)
{
	LL x=1ll;
	while(n>0)
	{
		if(n&1)	x=(x*d);
		d=(d*d);
		n>>=1;
	}
	return x;
}
/*
inline int next(){
    char c;int num=0;
    c=getchar_unlocked();
    while(!(c>='0' && c<='9')) c=getchar_unlocked();
    while(c>='0' && c<='9'){
        num=(num<<3)+(num<<1)+c-'0';
        c=getchar_unlocked();
    }
    return num;
}
*/
//main code is here
int N,d[15],n[15],w[15],e[15],s[15],deltad[15],deltap[15],deltas[15],x;
struct myds
{
	int day,tribe,s,w,e;
}attack[10005];
bool cmp(struct myds p,struct myds q)
{
	if(p.day != q.day) return p.day<q.day;
	else return p.tribe<q.tribe;
}
int arr[4000000],ans;
main()
{
	INPUT("C-small-attempt1.in");
	OUTPUT("outputs.txt");
	int cn=1;
	CASE
	{
		fill(arr,0);
		ans=0;
		k=0;
		s(N);
		REP(i,N)
		{
			cin>>d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>deltad[i]>>deltap[i]>>deltas[i];
			attack[k].day=d[i];
			attack[k].tribe=i;
			attack[k].s=s[i];
			attack[k].w=100000+10*w[i];
			attack[k].e=100000+10*e[i];
			if(attack[k].e>attack[k].w) swap(attack[k].e,attack[k].w);
			++k;
			FOR(j,1,n[i])
			{
				d[i]+=deltad[i];
				s[i]+=deltas[i];
				w[i]+=deltap[i];
				e[i]+=deltap[i];
				attack[k].day=d[i];
				attack[k].tribe=i;
				attack[k].s=s[i];
				attack[k].w=100000+10*w[i];
				attack[k].e=100000+10*e[i];
				if(attack[k].e>attack[k].w) swap(attack[k].e,attack[k].w);
				++k;
			}
		}
		sort(attack,attack+k,cmp);
		for(i=0;i<k;)
		{
			int curday=attack[i].day,p=i;
			while(i<k && attack[i].day==curday)
			{
				int mn=INF;
				for(j=attack[i].e;j<=attack[i].w;++j)	mn=min(arr[j],mn);
				if(attack[i].s>mn)	++ans;
				++i;
			}
			i=p;
			while(i<k && attack[i].day==curday)
			{
				int mn=INF;
				for(j=attack[i].e;j<=attack[i].w;++j)	mn=min(arr[j],mn);
				if(attack[i].s>mn)
				for(j=attack[i].e;j<=attack[i].w;++j)
				arr[j]=max(attack[i].s,arr[j]);
				++i;
			}
		}
		JAM(cn++);cout<<ans<<endl;
	}
	return 0;
}
