#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#define REP(x,y) for(x=0;x<y;x++)
#define REPI(x,y) for(x=1;x<=y;x++)
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second
#define pb push_back

using namespace std;

int N,M,n,m,k,i,xx,yy;
//map<int, int> m[10005];
pii p[2000];
pii drop[2000];

void find(int n){
	int a,b,c,l,r;
	int mx=-2;
//	printf("n=%d %d\n",n,N);
	if(n==N){
		k++;
		REP(a, N){
			if(drop[a]==mp(xx,yy)){
				i++;
				return;
			}
		}
		return;
	}
	REP(a, n){
		if(drop[a].fi==0)
			mx = max(drop[a].se, mx);
	}
//	printf(">> %d\n",mx);
	if(mx < 0){
		drop[n].fi=0;
		drop[n].se=0;
//		printf("set 0 0\n");
		find(n+1);
	}
	else {
		mx+=2;
		l=r=1;
		REP(a, n){
			if(drop[a]==mp(-1,mx-1)){
				l=0;break;
			}
		}
		REP(a, n){
			if(drop[a]==mp(1,mx-1)){
				r=0;break;
			}
		}
		if(l and r)
		{
//			printf("L and R!\n");
			b=-2;
			REP(a, n){
				if(drop[a].se-drop[a].fi==mx){
					b = max(b, drop[a].se);
				}
			}
			if(b<0){
				drop[n]=mp(-mx, 0);
			}
			else {
				drop[n]=mp(b+1-mx, b+1);
			}
			find(n+1);

			b=-2;
			REP(a, n){
				if(drop[a].se+drop[a].fi==mx){
					b = max(b, drop[a].se);
				}
			}
			if(b<0){
				drop[n]=mp(mx, 0);
			}
			else {
				drop[n]=mp(mx-b-1, b+1);
			}
			find(n+1);
		}
		else if(l){
			b=-2;
			REP(a, n){
				if(drop[a].se-drop[a].fi==mx){
					b = max(b, drop[a].se);
				}
			}
			if(b<0){
				drop[n]=mp(-mx, 0);
			}
			else {
				drop[n]=mp(b+1-mx, b+1);
			}
			find(n+1);
		}
		else if(r){
			b=-2;
			REP(a, n){
				if(drop[a].se+drop[a].fi==mx){
					b = max(b, drop[a].se);
				}
			}
			if(b<0){
				drop[n]=mp(mx, 0);
			}
			else {
				drop[n]=mp(mx-b-1, b+1);
			}
			find(n+1);
		}
		else {
			drop[n]=mp(0,mx);
			find(n+1);
		}
	}
	
}

int t1[1000],t2[1000];

void db(int x, int n){
	int a,b,c;
	if(x==n){
		b=0;
		k++;
		REP(a, n){
			if(t1[a]==1)b++;
		}
		if(b>=yy)i++;
		return;
	}
	b=0;
	REP(a, x){
		if(t1[a]==1)b++;
	}
}

int main()
{
    int a,b,c,d,R,xc;
	double tmp;
	cin >> R;
	for(int ax=0;ax<R;ax++)
	{
		k=0;i=0;
		cin >> N >> xx >> yy;
		xc = (xx>0?xx:-xx);
		d = xc+yy;
		d/=2;
		d++;
		c=1;
		b=0;
		while(c <= N){
			c+=(b+1)*4+1;
			b++;
		}
		if(d<=b){
		printf("Case #%d: 1.0\n",ax+1);
			continue;
		}
		if(d > b+1){
		printf("Case #%d: 0.0\n",ax+1);
			continue;
		}
		c-=b*4+1;
		M=0;
		REP(a, b){
			for(int x=a*2;x>=0;x-=2)drop[M++]=mp(x,a*2-x);
			for(int x=a*2;x>=0;x-=2)drop[M++]=mp(-x,a*2-x);
			drop[M++]=mp(0,a*2);
		}
		find(c);
//		printf("%d %d %d\n",b,N-c,c);
		//REP(a,10000)m[a].clear();
//		find(0);
		tmp=i;
		tmp/=(double)k;
		printf("Case #%d: %.10lf\n",ax+1,tmp);
//		cout << "Case #" << ax+1 << ": " << tmp << "\n";
	}
	
    return 0;
}
