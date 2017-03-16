#include <cstdio>
#include <cstring>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;
typedef pair<long long,long long> ii;
ii v[10005];
long long E,R,N,ans,sum;
long long temp1,temp,cnt[10005];
set <long long> s;
set <long long>::iterator i;
bool cmp(ii a, ii b){
	return a.first>b.first;
}
int main(){
	int t,cnt2=0;
	scanf("%d",&t);
	while(t--){
		cnt2++;
		ans=0;
		sum=0;
		s.clear();
		memset(cnt,0,sizeof(cnt));
		scanf("%lld %lld %lld",&E,&R,&N);
		for(int x=0;x<N;x++){
			scanf("%lld",&v[x].first);
			v[x].second=x;
			sum+=v[x].first;
		}
		if(R>=E){
			printf("Case #%d: %lld\n",cnt2,E*sum);
			continue;
		}
		sort(v,v+N,cmp);
		for(int x=0;x<N;x++){
			s.insert(v[x].second);
			i=s.find(v[x].second);
			if(i==s.begin()) temp1=E;
			else{
				i--;
				temp1=min(E,R*(v[x].second-(*i)));
				i++;
			}
			i++;
			if(i==s.end()){
				cnt[v[x].second]=temp1;
				ans+=temp1*v[x].first;
			}
			else{
				temp=temp1-(max(0ll,cnt[(*i)]-R*((*i)-v[x].second)));
				cnt[v[x].second]=temp;
				ans+=temp*v[x].first;
			}
		}
		printf("Case #%d: %lld\n",cnt2,ans);
	}
	return 0;
}
