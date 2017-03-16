#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;

#define bignum 1000000000

struct Event{
	int day,w,e,s;
	Event(int a,int b,int c,int d):day(a),w(b),e(c),s(d){}
};
vector<Event>eve;
vector<int>pt,h;
int need[111111];

int T,n;

bool cmp(const Event &a,const Event &b){
	return a.day<b.day;
}

int query(const Event e){
	int res=0;
	for(int i=0;i<pt.size()-1;i++)
		if(pt[i]>=e.w&&pt[i+1]<=e.e){
			need[i]=max(need[i],e.s);
			if(e.s>h[i])res=1;
		}
	return res;
}

int main(){
	scanf("%d",&T);
	for(int _=1;_<=T;_++){
		eve.clear();
		pt.clear();pt.push_back(-bignum);pt.push_back(bignum);
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			int d,nn,w,e,s,delta_d,delta_p,delta_s;
			scanf("%d%d%d%d%d%d%d%d",&d,&nn,&w,&e,&s,&delta_d,&delta_p,&delta_s);
			for(int j=0;j<nn;j++){
				eve.push_back(Event(d,w,e,s));
				d+=delta_d;
				w+=delta_p;e+=delta_p;
				s+=delta_s;
			}
		}
		sort(eve.begin(),eve.end(),cmp);
		
		for(int i=0;i<eve.size();i++){
			pt.push_back(eve[i].w);
			pt.push_back(eve[i].e);
		}
		sort(pt.begin(),pt.end());
		pt.resize(unique(pt.begin(),pt.end())-pt.begin());
		h.clear();
		for(int i=0;i<pt.size();i++)
			h.push_back(0);
			
		int cur=0,nxt,ans=0;
		while(cur<eve.size()){
			nxt=cur+1;
			while(nxt<eve.size()&&eve[cur].day==eve[nxt].day)
				nxt++;
			memset(need,0,sizeof need);
			for(int i=cur;i<nxt;i++)
				ans+=query(eve[i]);
			for(int i=0;i<h.size();i++)
				h[i]=max(h[i],need[i]);
			cur=nxt;
		}
		
		printf("Case #%d: %d\n",_,ans);
	}

	return 0;
}