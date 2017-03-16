#include<stdio.h>
#include<utility>
#include<set>
#include<algorithm>
using namespace std;
struct sort_pred {
	bool operator()(const pair<int,int> &left, const pair<int,int> &right) {
		return left.second < right.second;
	}
};

int main(){
	int T,n,a,b;
	scanf("%d",&T);
	for(int iT=1;iT<=T;iT++){
		int scr=0,ans=0,rp=0;
		pair<int,int> d[1001];
		multiset<pair<int,int> > s;
		scanf("%d",&n);
		for(int in=0;in<n;in++){
			scanf("%d%d",&a,&b);
			d[in]=make_pair(a,b);
			s.insert(d[in]);
		}
		sort(d,d+n,sort_pred());
		while(rp<n){
			if(d[rp].second<=scr){
				int cnt=s.count(d[rp]);
				if(cnt>0){
					scr+=2;
					s.erase(d[rp]);
					for(int i=1;i<cnt;i++)
						s.insert(d[rp]);
				}
				else
					scr++;
				rp++;
				ans++;
				continue;
			}
			else{
				int max=-1;
				pair<int,int> mp;
				multiset<pair<int,int> >::iterator it;
				for(it=s.begin();it!=s.end();it++){
					if((*it).first<=scr && (*it).second>max){
						max=(*it).second;
						mp=*it;
					}
				}
				if(max<0)
					break;
				else{
					int cnt=s.count(mp);
					s.erase(mp);
					for(int i=1;i<cnt;i++)
						s.insert(mp);
					scr++;
					ans++;
				}
			}
		}
		if(rp<n)
			printf("Case #%d: Too Bad\n",iT);
		else
			printf("Case #%d: %d\n",iT,ans);
	}
	return 0;
}
