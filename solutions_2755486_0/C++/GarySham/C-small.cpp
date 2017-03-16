#include<cstdio>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
#include<set>
using namespace std;
#define INF (1<<29)
#define min(x,y) (((x)<(y))?(x):(y))
#define max(x,y) (((x)>(y))?(x):(y))
#define FOR(i,x,y) for(int i=(x);i<(y);++i)
#define FOE(i,x,y) for(int i=(x);i<=(y);++i)
#define CLR(i) memset(i,0,sizeof(i))
#define ll long long

int T,N;
int wall[1000];

struct node{
	int d,w,e,h;

	node(){}
	node(int d,int w,int e,int h):d(d),w(w),e(e),h(h){}

	bool operator<(const node &d2)const{
		return d<d2.d;
	}

	bool success(){
		FOR(i,w,e){
			if (wall[i+500] < h) return 1;
		}
		return 0;
	}

	void inc(){
		FOR(i,w,e){
			if (wall[i+500] < h) wall[i+500] = h;
		}
	}
} a[200];

int num;

int main(){
	scanf("%d",&T);
	FOE(t,1,T){
		CLR(wall);
		scanf("%d",&N);

		num=0;
		FOR(i,0,N){
			int d0,n0,w0,h0,e0,dd,dp,dh;
			scanf("%d%d%d%d%d%d%d%d",&d0,&n0,&w0,&e0,&h0,&dd,&dp,&dh);

			FOR(j,0,n0){
				a[num++] = node(d0 + dd*j, w0 + dp*j, e0 + dp*j, h0 + dh*j);
			}
		}
		sort(a,a+num);

		int ans=0;
		int pos=0;
		while (pos < num){
			FOR(i,pos,num){
				if (a[i].d != a[pos].d) break;

				if (a[i].success()) ++ans;
			}

			FOR(i,pos,num){
				if (a[i].d != a[pos].d) break;

				a[i].inc();
			}
			++pos;
		}

		printf("Case #%d: %d\n",t,ans);
	}
	return 0;
}
