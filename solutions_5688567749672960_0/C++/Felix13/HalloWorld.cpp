#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag,
		tree_order_statistics_node_update> ordered_tree;
typedef long long LL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<int> VI;

#define FOR(i,a,b) for(int (i)=(a);i<(b);++(i))
#define RFOR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define For(i,a,b) for(int (i)=(a);i<(b);++(i))
#define FoR(i,a,b) for(int (i)=(a)-1;(i)>=(b);--(i))
#define INF 1000000001
#define LINF 1000000000000000001ll
#define PB push_back
#define EPS 1e-7
#define X first
#define Y second
#define MP make_pair
#define ITER(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
#define FILL(A,value) memset(A,value,sizeof(A))
#define ALL(V) V.begin(), V.end()

LL reverse(LL a) {
	LL rev = 0;
	while (a) {
		rev = rev * 10 + a % 10;
		a /= 10;
	}
	return rev;
}
LL n;
int brut(LL n) {
	map<LL, int> d;
	queue<LL> q;
	if(n==1)return 1;
	q.push(1ll);
	d[1] = 1;
	int iter = 0;
	while (q.size()) {
		iter++;
		LL t = q.front();
		q.pop();
		int dt = d[t];
		LL rev = reverse(t);
		if (rev <= n && d.count(rev) == 0) {
			if (rev == n) {
				return d[t] + 1;
			}
			d[rev] = dt + 1;
			q.push(rev);
		}

		if (d.count(t + 1) == 0) {
			if (t + 1 == n) {
				return dt + 1;
			}
			d[t + 1] = dt + 1;
			q.push(t + 1);
		}

	}
	return -1;
}

LL pn;
LL solve(LL n) {
	if(n<10)return n;
	LL cur = 10;

	LL ans = 10;
	if(n%10==0){n--;ans++;}
	LL ad;
	int len=2;
	while (1) {
		 ad=pow(10,len/2)-1;
		 LL nnum=ad*pow(10,(len+1)/2)+1;
		 if(nnum<n){
			 LL target = pow(10,len-1)+ad;
			 ans+=target-cur+1;
			 cur=nnum;
		 }
		 else {
			 LL a1=n-cur;
			 LL ned=n/pow(10,(len+1)/2);
			 ned=reverse(ned);
			 ned=pow(10,len-1)+ned;
			 if(ned<=cur){ans+=n-cur;break;}
			 LL a2=ned-cur+1;
			 LL cr=n-n%((int)pow(10,(len+1)/2))+1;
			 a2+=n-cr;
			 ans+=min(a1,a2);
			 break;
		 }
		 len++;
	}

	return ans;
}
int main() {
	//ios::sync_with_stdio(0);
	freopen("A.in","r",stdin);freopen("A.out","w",stdout);
	int t;
	cin>>t;
	FOR(tt,0,t){
		cin>>n;
		cout<<"Case #"<<tt+1<<": "<<solve(n)<<"\n";
	}
	return 0;
}
