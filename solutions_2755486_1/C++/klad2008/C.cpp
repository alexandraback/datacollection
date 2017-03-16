#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <bitset>
#include <vector>
#include <cstdio>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const long long con=4000000;
class rec{
	public:
	long long d,n,w,e,s,ded,dep,des;
}p[con+10];
class leaf{
	public:
	long long Min,l,r,s;
}segtr[4*con];
long long N,last,rr,ll,ans,test,tim,len;
long long ls[con+10],f[con+10],q[con+10];
void read(long long &x){char ch=getchar();bool flag=false;while ((ch<'0'||ch>'9')&&ch!='-')ch=getchar();if (ch=='-'){flag=true;ch=getchar();}x=0;while (ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}if (flag)x=-x;}
bool heapcmp(long long a,long long b){return p[f[a]].d<p[f[b]].d;}
void updn(long long x){
	for (;x>1&&!heapcmp(x/2,x);){swap(f[x/2],f[x]);x=x/2;}
	long long x1=x*2;
	for (;x1<=last;){
		if (x1<last&&!heapcmp(x1,x1+1))x1++;
		if (!heapcmp(x,x1)){swap(f[x],f[x1]);x=x1;x1=x*2;}else break;
	}
}
bool cmp(const long long &a,const long long &b){return a<b;}
void build(const long long &x,const long long &l,const long long &r){
	segtr[x].l=l;segtr[x].r=r;segtr[x].Min=0;segtr[x].s=0;
	if (l+1<r){
		build(2*x,l,(l+r)/2);
		build(2*x+1,(l+r)/2,r);
	}
}
long long findls(long long x){
	long long l=1,r=ll;
	for (;l<r;){
		long long mid=(l+r)/2;
		if (ls[mid]>=x)r=mid;
		else l=mid+1;
	}
	return l;
}
void make(long long x){
	segtr[2*x].s=max(segtr[2*x].s,segtr[x].s);
	segtr[2*x].Min=max(segtr[2*x].Min,segtr[2*x].s);
	segtr[2*x+1].s=max(segtr[2*x+1].s,segtr[x].s);
	segtr[2*x+1].Min=max(segtr[2*x+1].Min,segtr[2*x+1].s);
	segtr[x].s=0;
}
bool calc(long long x,long long l,long long r,long long data){
	make(x);
	if (l==segtr[x].l&&r==segtr[x].r){
		return data>segtr[x].Min;
	}
	if (r<=segtr[2*x].r)return calc(2*x,l,r,data);
	else if (l>=segtr[2*x+1].l)return calc(2*x+1,l,r,data);
	else return calc(2*x,l,segtr[2*x].r,data)|calc(2*x+1,segtr[2*x+1].l,r,data);
}
void change(long long x,long long l,long long r,long long data){
	make(x);
	if (l==segtr[x].l&&r==segtr[x].r){
		segtr[x].s=max(segtr[x].s,data);
		segtr[x].Min=max(segtr[x].Min,segtr[x].s);
		return;
	}
	if (r<=segtr[2*x].r)change(2*x,l,r,data);
	else if (l>=segtr[2*x+1].l)change(2*x+1,l,r,data);
	else change(2*x,l,segtr[2*x].r,data),change(2*x+1,segtr[2*x+1].l,r,data);
	segtr[x].Min=min(segtr[2*x].Min,segtr[2*x+1].Min);
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	read(test);
	for (long long tt=1;tt<=test;tt++){
		read(N);
		for (long long i=1;i<=N;i++)
		read(p[i].d),read(p[i].n),read(p[i].w),read(p[i].e),read(p[i].s),
		read(p[i].ded),read(p[i].dep),read(p[i].des);
		rr=0;
		for (long long i=1;i<=N;i++)
		for (long long j=1;j<=p[i].n;j++)
		ls[++rr]=p[i].e+(j-1)*p[i].dep,ls[++rr]=p[i].w+(j-1)*p[i].dep;
		sort(ls+1,ls+rr+1,cmp);
		ll=1;
		for (long long i=2;i<=rr;i++)
		if (ls[i]!=ls[ll])ls[++ll]=ls[i];
		build(1,1,ll);
		last=0;ans=0;
		for (long long i=1;i<=N;i++)
		f[++last]=i,updn(i);
		while (last){
			tim=p[f[1]].d;len=0;
			while (last&&p[f[1]].d==tim){
				q[++len]=f[1];
				swap(f[1],f[last]);
				last--;updn(1);
			}
			for (long long i=1;i<=len;i++){
				long long l=p[q[i]].w,r=p[q[i]].e;
				l=findls(l),r=findls(r);
				ans+=calc(1,l,r,p[q[i]].s);
			}
			for (long long i=1;i<=len;i++){
				long long l=p[q[i]].w,r=p[q[i]].e;
				l=findls(l),r=findls(r);
				change(1,l,r,p[q[i]].s);
				p[q[i]].d+=p[q[i]].ded;
				p[q[i]].n--;
				p[q[i]].s+=p[q[i]].des;
				p[q[i]].e+=p[q[i]].dep;
				p[q[i]].w+=p[q[i]].dep;
				if (p[q[i]].n){
					f[++last]=q[i];
					updn(last);
				}
			}
		}
		printf("Case #%I64d: %I64d\n",tt,ans);
	}
}
