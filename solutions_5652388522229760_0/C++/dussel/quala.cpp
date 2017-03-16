/* attention to overflow */
#include <bits/stdc++.h>

#define dump(x) cerr<< #x << " = " << x <<endl
#define ALL(container) (container).begin(),(container).end()

using namespace std;
const int INF = 1 << 25;
void io() { cin.tie(0); ios::sync_with_stdio(false);}
template <class S,class T> ostream& operator<<(ostream& os, const pair <S,T> &s){return os<<'('<<s.first<<','<<s.second<<')';}
/*printf("%.9Lf\n",cf);*/
const int MOD = 1000000007;
const double EPS=1e-8;

string cs(int n){ return "Case #"+to_string(n)+": "; }

int main() {
	io();
	int T;
	cin>>T;
	string s="INSOMNIA";

	for(int i=1;i<=T;i++){
		long long N;
		cin>>N;
		bool cnt[10]={0};
		long long now=0;
		while(any_of(cnt,cnt+10,[](bool flg){return !flg;})){
			if(now>=N*1000000LL){ now=-1;break;}
			now+=N;
			for(long long tmp=now;tmp>0;tmp/=10){
				long long val=tmp%10;
				cnt[val]=true;
			}
		}

		if(now==-1) cout<<cs(i)<<s<<endl;
		else cout<<cs(i)<<now<<endl;
	}

	return 0;
}
