#include<cstdio>
#include<algorithm>
#include<set>
int i1[2000],i2[2000],b1[2000],b2[2000],l[2000];
bool cmp1(int x,int y){ return i1[x]<i1[y]?true:false; }
bool cmp2(int x,int y){ return i2[x]<i2[y]?true:false; }
using namespace std;
struct node{ int i; long long v; } nt;
struct comp{ bool operator()(node x,node y){ if( x.v>y.v || x.v==y.v && x.i<y.i ) return true; return false; } };
set<node,comp> h;
set<node,comp>::iterator it;
int main()
{
	int a,n,t1,t2,p1,p2,c,c2;
int T,N;
scanf("%d",&N);
for(T=1;T<=N;T++)
{
	scanf("%d",&n);
	for(a=0;a<n;a++){ scanf("%d%d",&i1[a],&i2[a]); b1[a]=a; b2[a]=a; l[a]=0; }
//printf("!");
	sort(b1,b1+n,cmp1);
	sort(b2,b2+n,cmp2);
//printf("!");
	i1[n]=2*n+1;
	i2[n]=2*n+1;
	b1[n]=n;
	b2[n]=n;
	l[n]=0;
	p1=0;
	p2=0;
	c=0; c2=0;
//printf("!");
	while(1)
	{
		t1=b1[p1]; t2=b2[p2];
//printf("%d %d %d %d %d %d\n",t1,t2,i1[t1],i2[t2],c,h.size());
//if( p1+p2>10 ) break;
		if( l[t1]>0 ) p1++;
		else if( i2[t2]<=c )
		{
//printf("2 %d\n",t2);
			c2++; c+=2-l[t2]; l[t2]=2; p2++;
		}
		else if( i1[t1]<=c ){ nt.i=t1; nt.v=i2[t1]; h.insert(nt); p1++; }
		else if( h.size()>0 )
		{
			it=h.begin();
			if( l[it->i]==0 )
			{
//printf("1 %d\n",it->i);
				c2++; c++; l[it->i]=1;
			}
			h.erase(it);
		}
		else break;
	}
	if( c<2*n ) printf("Case #%d: Too Bad\n",T);
	else printf("Case #%d: %d\n",T,c2);
}
	return 0;
}
