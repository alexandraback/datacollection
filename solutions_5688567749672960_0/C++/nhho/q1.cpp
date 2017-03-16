#include <cstdlib>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <map>
#include <set>
#include <deque>
#include <cstring>
#include <functional>
#include <climits>
#include <list>

#define F1(x,y,z) for(int x=y;x<z;x++)
#define F2(x,y,z) for(int x=y;x<=z;x++)
#define F3(x,y,z) for(int x=y;x>z;x--)
#define F4(x,y,z) for(int x=y;x>=z;x--)
#define W(x) while(x-->0)
#define SI(x) scanf("%d",&x)
#define pb push_back

using namespace std;

int t,n;
int rev[1000005];
int dis[1000005];
vector<int> ii[1000005];
queue<int> q;

int re(int a){
	int b=0;
	while(a>0){
		b=b*10+a%10;
		a/=10;
	}
	return b;
}

int main(){
	SI(t);
	F2(tt,1,t){
		memset(dis,0,sizeof(dis));
		memset(ii,0,sizeof(ii));
		SI(n);		
		F2(a,1,n){
			rev[a]=re(a);
			if(rev[a]>n)rev[a]=0;
			else ii[rev[a]].pb(a);
		}
		dis[n]=1;
		q.push(n);
		while(!q.empty()){
			//printf("%d %d\n",q.front(),dis[q.front()]);
			if(q.front()==1){
				q=queue<int>();
				break;
			}
			if(q.front()>1)if(dis[q.front()-1]==0){
				dis[q.front()-1]=dis[q.front()]+1;
				q.push(q.front()-1);
			}
			F1(a,0,ii[q.front()].size())if(dis[ii[q.front()][a]]==0){
				dis[ii[q.front()][a]]=dis[q.front()]+1;
				q.push(ii[q.front()][a]);
			}
			q.pop();
		}
		//F2(a,1,n)printf("%d %d\n",a,dis[a]);
		printf("Case #%d: %d\n",tt,dis[1]);
	}
	//system("pause");
    return 0;
}
