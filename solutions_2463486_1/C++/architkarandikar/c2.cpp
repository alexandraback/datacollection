#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <string>

using namespace std;
typedef long long LL;
typedef pair<int,int> pii;

#define forup(i,a,b) for(int i=a; i<b; ++i)
#define fordn(i,a,b) for(int i=a; i>b; --i)
#define rep(i,a) for(int i=0; i<a; ++i)

#define dforup(i,a,b) for(i=a; i<b; ++i)
#define dfordn(i,a,b) for(i=a; i>b; --i)
#define drep(i,a) for(i=0; i<a; ++i)

#define slenn(s,n) for(n=0; s[n]!='\0'; ++n)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf("%s",x)

#define pis(x) printf("%d ",x)
#define pin(x) printf("%d\n",x)
#define pls(x) cout<<x<<" "
#define pln(x) cout<<x<<"\n"
#define pds(x) printf("%.12f ",x)
#define pdn(x) printf("%.12f\n",x)
#define pnl() printf("\n")

#define fs first
#define sc second

#define pb push_back

const LL inv=numeric_limits<LL>::max();
const LL minv=numeric_limits<LL>::min();

const LL nlim=10000000;

int T;
LL a,b;

LL fas[200]; int fassz;

LL lk[20]; int lksz;
bool pal(LL k)
{
	lksz=0;
	while(k!=0ll)
	{
		lk[lksz++]=k%10ll;
		k/=10ll;
	}
	
	rep(i,lksz)
		if(lk[i]!=lk[lksz-1-i])
			return false;
	
	return true;
}

int binsrcA(LL ref, int l, int r) //(l,r]
{
	if(l+1==r)
		return r;
	else
	{
		int mid=(l+r)/2;
		if(fas[mid]>=ref)
			return binsrcA(ref,l,mid);
		else
			return binsrcA(ref,mid,r);
	}
}

int binsrcB(LL ref, int l, int r) //[l,r)
{	
	if(l+1==r)
		return l;
	else
	{
		int mid=(l+r)/2;
		if(fas[mid]<=ref)
			return binsrcB(ref,mid,r);
		else
			return binsrcB(ref,l,mid);
	}
}

int main()
{
	fassz=0;
	fas[fassz++]=minv;
	for(LL i=1; i<=nlim; ++i)
		if(pal(i) and pal(i*i))
		{
			//cout<<i<<" "<<i*i<<endl;
			fas[fassz++]=i*i;
		}
	fas[fassz++]=inv;

	gi(T);
	
	rep(z,T)
	{
		gl(a); gl(b);
		
		int ixa=binsrcA(a,-1,fassz-1);
		int ixb=binsrcB(b,0,fassz);
		
		//cout<<fassz<<" "<<ixa<<" "<<ixb<<endl;
		//cout<<fassz<<endl;
		int res = ((ixb>=ixa)?(ixb-ixa+1):0);
		printf("Case #%d: %d\n",z+1,res);
	}
	
	return 0;
}