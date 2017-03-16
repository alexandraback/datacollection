// #includes {{{
#include <algorithm>
#include <numeric>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cmath>
using namespace std;
// }}}
// pre-written code {{{
#define REP(i,n) for(int i=0;i<(int)(n);++i)
#define RREP(i,a,b) for(int i=(int)(a);i<(int)(b);++i)
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
//#define IFOR(i,it,c) for(__typeof((c).begin())it=(c).begin();it!=(c).end();++it,++i)
#define ALL(c) (c).begin(), (c).end()
#define MP make_pair
//#define PB push_back
#define CLEAR(c,d) memset((c),(d),sizeof(c))
#define TO_STRING(VariableName) # VariableName
//#define DB(c) cout<<TO_STRING(c)<<"="<<(c)<<endl

#define EXIST(e,s) ((s).find(e)!=(s).end())
#define dump(x) cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;
#define debug2(x) cerr << #x << " = [";REP(__ind,(x).size()){cerr << (x)[__ind] << ", ";}cerr << "] (L" << __LINE__ << ")" << endl;

#define clr(a) memset((a),0,sizeof(a))
#define nclr(a) memset((a),-1,sizeof(a))
#define pb push_back

typedef long long Int;
typedef unsigned long long uInt;
typedef long double rn;

typedef pair<int,int> pii;
// }}}

const int M=2010;
const int INF=1000000000;

int n;
int a[M],b[M];
vector<pair<int,pii> > v;
int dp[M][M];//level-one num

/*
int calc(int i,int num){//lev1, num-star :return 回数
	if(dp[i][num]>=0)return dp[i][num];
	if(i==v.size())return dp[i][num]=0;
	int ans=INF;
	if(v[i].second==0){
		if(v[i].first>num)ans=INF;
		else ans=calc(i+1,num+2)+1;
	}else{
		ans=INF;
		ans=min(ans,calc(i+1,num));//not apply
		if(v[i].first>num)
		ans=min(ans,calc(i+1,num+1)+1);//apply
	}
	return dp[i][num]=ans;
}
*/

void main2(){
	v.clear();
	cin>>n;
	REP(i,n)cin>>a[i]>>b[i];
	REP(i,n)v.push_back(MP(a[i],MP(1,i))),v.push_back(MP(b[i],MP(0,i)));
	sort(ALL(v));
	int sol=INF;
	for(int k=0;k<=n;k++){
		int s=0,ans=0,num2=0;
		REP(i,v.size()){
//			cout<<num2<<" "<<n<<endl;
//			if(num2==n)break;
			int t=v[i].second.first,j=v[i].second.second;
			if(t==0){
				if(s<v[i].first){
					ans=INF;
					break;
				}else{
					ans++;num2++;
					if(j<k)s+=1;
					else s+=2;
					if(num2==n)break;
				}
			}else{
				if(j<k){
					if(s<v[i].first){
						if(num2<n){
							ans=INF;
						}
						break;
					}else{
						ans++;s++;
					}
				}else{

				}
			}
		}
		sol=min(ans,sol);
	}
	//	memset(dp,-1,sizeof(dp));
	//	int ans=calc(0,0);
	if(sol==INF){
		cout<<"Too Bad"<<endl;
	}else{
		cout<<sol<<endl;
	}
}

//{{{ main function
int main() {
	int T;scanf("%d", &T);
	REP(ct, T){ printf("Case #%d: ",ct+1);main2();}
	return 0;
}
//}}}

