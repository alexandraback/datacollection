//Aditya Shah

#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int,int> pii;

#define vi vector<int>
#define vs vector<string>
#define vpii vector<pii>
#define all(v) v.begin(), v.end()

#define fr freopen("input.in","r",stdin)
#define fw freopen("output.out","w",stdout)

#define foreach(i,X) for(__typeof((X).begin()) i = (X).begin(); i != (X).end(); i++)
#define forup(i,a,b) for(int i=(a); i<(b); ++i)
#define fordn(i,a,b) for(int i=(a); i>(b); --i)
#define rep(i,a) for(int i=0; i<(a); ++i)

#define gi(x) scanf("%d",&x)
#define gl(x) cin>>x
#define gd(x) scanf("%lf",&x)
#define gs(x) scanf(" %s",x)

#define F first
#define S second

#define pb push_back
#define pf push_front
#define mp make_pair

const int inf=numeric_limits<int>::max();
const LL linf=numeric_limits<LL>::max();

int main(){
	fr;
	fw;
	int test,smax;
	string s;
	gi(test);
	forup(c,1,test+1){
		printf("Case #%d: ",c);
		int init = 0, ans = 0, people = 0;
		gi(smax);
		cin >> s;
		rep(i,s.size()){
			people = s[i]-'0';
			init -= i;
			ans = min(ans, init);
			init += (i + people);
		}
		printf("%d\n",-ans);
	}
	return 0;
}