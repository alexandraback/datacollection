#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int N=1010;
struct ATT{
	int d,n,l,r,s,dd,dp,ds;
	void read()
	{
		scanf("%d%d%d%d%d%d%d%d",&d,&n,&l,&r,&s,&dd,&dp,&ds);
		l*=2;r*=2;dp*=2;
	}
}att[N];
struct Event{
	int D,L,R,S;
	Event(int d=0,int l=0,int r=0,int s=0):R(r),L(l),S(s),D(d){}
	bool operator<(const Event &A)const
	{return D<A.D;}
};
vector<Event>V;
void add_events(const ATT &A)
{
	int d=A.d,l=A.l,r=A.r,s=A.s;
	for(int i=0;i<A.n;i++){
		V.push_back(Event(d,l,r,s));
		s+=A.ds;
		d+=A.dd;
		l+=A.dp;
		r+=A.dp;
	}
}
int len[1010],off=500;
bool succ(const Event &A)
{
	for(int i=A.L;i<=A.R;i++)
		if(len[i+off] < A.S)
			return true;
	return false;
}
void clean(queue<int>&Q)
{
	while(!Q.empty())
	{
		Event A=V[Q.front()];Q.pop();
		//printf("in clean :%d %d %d %d\n",A.D,A.S,A.L,A.R);
		for(int i=A.L;i<=A.R;i++)
			if(len[i+off] < A.S){
				len[i+off]=A.S;
				//printf("%d=%d\n",i,A.S);
			}
	}
}
int main()
{
	int T,w=1;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		V.clear();
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			att[i].read();
			add_events(att[i]);
		}
		memset(len,0,sizeof(len));
		sort(V.begin(),V.end());
		//for(int i=0;i<V.size();i++)
		//	printf("%d %d %d %d\n",V[i].D,V[i].S,V[i].L,V[i].R);
		int ans=0;
		queue<int>Q;
		for(int i=0;i<V.size();i++)
		{
			//if(!Q.empty())printf("-- %d\n",Q.front());
			if(Q.empty() || V[Q.front()].D != V[i].D)
				clean(Q);
			if(succ(V[i])){
				ans++;
				Q.push(i);
			}
		}
		printf("Case #%d: %d\n",w++,ans);
	}
}
