#include <cstdio>
#include <cstring>
#include <set>
#include <algorithm>
using namespace std;
double w;
int c=0,t,n,a[1005],b[1005];
set <int> s1,s2;
set <int>::iterator i;
int main(){
	scanf("%d",&t);
	while(t--){
		s1.clear();
		s2.clear();
		scanf("%d",&n);
		for(int x=0;x<n;x++){
			scanf("%lf",&w);
			a[x]=int(w*100000.0);
		}
		sort(a,a+n);
		for(int x=0;x<n;x++){
			scanf("%lf",&w);
			b[x]=int(w*100000.0);
			s1.insert(b[x]);
			s2.insert(b[x]);
		}
		sort(b,b+n);
		int l=0,r=n-1,cnt1=0,cnt2=0,cnt3=0;
		for(int x=0;x<n;x++){
			if(a[x]>b[l]){++l;++cnt1;}
			else --r;
			i=s1.lower_bound(a[x]);
			if(i==s1.end()){
				++cnt2;
				s1.erase(s1.begin());
			}
			else s1.erase(i);
			i=s2.lower_bound(a[n-1-x]);
			if(i==s2.end()){
				++cnt3;
				s2.erase(s2.begin());
			}
			else s2.erase(i);
		}
		printf("Case #%d: %d %d\n",++c,cnt1,max(cnt2,cnt3));
	}
	return 0;
}
			
