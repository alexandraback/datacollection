#include<iostream>
#include<algorithm>
#include<cstdio>
#include<set>
#include<cstring>
#include<vector>
#include<sstream>
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
		string s,tmp;
		stringstream ss;
		int a,b;scanf("%d%d",&a,&b);
		int res=0;
		for(int i=a;i<=b;++i){
			ss.str("");ss.clear();
			ss<<i;
			tmp=s=ss.str();
			set<int> done;
			REP(j,s.size()){
				rotate(tmp.begin(),tmp.begin()+1,tmp.end());
				if(tmp[0]=='0') continue;
				ss.clear();ss.str("");
				ss<<tmp;
				int tmp2;ss>>tmp2;
				if(i<tmp2 && tmp2<=b && done.count(tmp2)==0){
					++res;
					done.insert(tmp2);
				}
			}
		}
		printf("Case #%d: %d\n",setn+1,res);
	}



	return 0;
}



