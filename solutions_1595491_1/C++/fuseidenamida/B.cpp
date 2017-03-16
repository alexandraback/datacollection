#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#define REP(i,m) for(int i=0;i<m;++i)
#define REPN(i,m,in) for(int i=in;i<m;++i)
#define pb push_back
#define mp make_pair
#define fr first
#define ALL(t) (t).begin(),(t).end()
#define sc second
#define INF ((int)5e8)
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define prl cerr<<"called:"<< __LINE__<<endl;
using namespace std;
template<class T> void debug(T a,T b){ for(;a!=b;++a) cerr<<*a<<' ';cerr<<endl;}
typedef long long int lint;
typedef pair<int,int> pi;
int main(){
	int t;scanf("%d",&t);
	REP(setn,t){
		printf("Case #%d: ",setn+1);
		int n,s,p,res=0,useS=0;scanf("%d%d%d",&n,&s,&p);
		REP(i,n){
			int a;scanf("%d",&a);
			if(p*3-2<=a) ++res;
			else if(p*3-4<=a && p!=1) ++useS;
		}
		res+=min(useS,s);
		printf("%d\n",res);
	}
	return 0;
}



