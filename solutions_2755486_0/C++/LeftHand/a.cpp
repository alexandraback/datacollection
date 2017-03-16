#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<queue>
#include<set>
#include<map>
#include<sstream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int inf=1<<29;

struct node{
	int d,w,e,s;
};
vector<node> E;
int cmp(node x,node y)
{
	return x.d<y.d;
}
map<int,int> mp;
int main()
{
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	int T,N,d,n,w,e,s,dd,pp,ss,ri=1;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		node t;
		E.clear();
		for(int i=0;i<N;i++){
			scanf("%d%d%d%d%d%d%d%d",&d,&n,&w,&e,&s,&dd,&pp,&ss);
			for(int j=0;j<n;j++){
				t.d=d;t.w=w;t.e=e;
				t.s=s;
				E.push_back(t);
				d+=dd;s+=ss;
				w+=pp;e+=pp;
			}
		}
		sort(E.begin(),E.end(),cmp);
		mp.clear();
		int ans=0;
		for(int i=0;i<(int)E.size();i++){
			int j=i;
			while(j<E.size()&&E[j].d==E[i].d){
				j++;
			}
			for(int k=i;k<j;k++){
				int flag=0;
				for(int kk=E[k].w;kk<E[k].e;kk++){
					if(mp.find(kk)==mp.end()) mp[kk]=0;
					if(E[k].s>mp[kk]) flag=1;
				}
				ans+=flag;
			}
			for (int k = i; k < j; k++) {
				for (int kk = E[k].w; kk < E[k].e; kk++) {
					if (mp.find(kk) == mp.end())
						mp[kk] = 0;
					mp[kk]=max(mp[kk],E[k].s);
				}
			}
		}


		printf("Case #%d: %d\n",ri++,ans);


	}
}
