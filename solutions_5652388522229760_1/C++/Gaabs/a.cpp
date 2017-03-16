#include <bits/stdc++.h>
using namespace std;

#define fr(i,a,b) for(int i = a; i < b; i++)
#define fre(i,a,b) for(int i = a; i <= b; i++)
#define frd(i,a,b) for(int i = a; i > b; i--)
#define fred(i,a,b) for(int i = a; i >= b; i--)
#define pb push_back
#define SET(a,v) memset(a,v,sizeof a)

#define INF 1e8
#define N 22

typedef long long ll;
typedef pair<int,int> ii;
int t,n,ans;

void solve(){
	if (n == 0){ 
		ans = -1;
		return;
	}
	set<int> s;
	int n2 = n;
	while (n2){
		s.insert(n2%10);
		n2 /= 10;
	}
	
	ans = n;
	int n0 = n;
	while (s.size() != 10){
		n += n0;
		n2 = n;
		while (n2){
			s.insert(n2%10);
			n2 /= 10;
		}
		ans = n;
		//printf("n:%d size:%d\n",n,(int) s.size());
	}

}

int main(){
	scanf("%d",&t);
	fr(t2,0,t){
		printf("Case #%d: ",t2+1);
		scanf("%d",&n);
		solve();
		if (ans > 0) printf("%d\n",ans);
		else puts ("INSOMNIA");
	}

	return 0;
}