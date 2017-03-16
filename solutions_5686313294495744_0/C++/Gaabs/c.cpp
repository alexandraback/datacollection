#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < b; i++)
#define fre(i,a,b) for(int i = a; i <= b; i++)
#define frd(i,a,b) for(int i = a; i > b; i--)
#define fred(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define SET(a,v) memset(a,v,sizeof a)

#define INF 1e8
#define N 2010
#define S 50

typedef long long ll;
typedef pair<int,int> ii;
typedef pair<string,string> ss;

int t,n,ans;
char str1[S],str2[N];

map<string,int> f,s;
ss topics[N];

void solve(){
	string first,second;
	ans = 0;
	fr(i,0,n){
		first = topics[i].first;
		second = topics[i].second;
		if (f[first] > 1 && s[second] > 1){
			ans++;
			f[first]--;
			s[second]--;
		}
	}
	printf("%d\n",ans);
}

int main(){
	scanf("%d",&t);
	fr(t2,0,t){
		printf("Case #%d: ",t2+1);
		scanf("%d",&n);
		f.clear(); s.clear();
		ans = 0;
		fr(i,0,n){
			scanf("%s%s",str1,str2);
			topics[i] = ss(str1,str2);
			
			if (f.find(str1) == f.end()) f[str1] = 1;
			else f[str1]++;
			
			if (s.find(str2) == s.end()) s[str2] = 1;
			else s[str2]++;
			
		}
		solve();

	}

	return 0;
}