#include <vector>
#include <cstdio>
#include <set>
#include <map>
#include <algorithm>
#include <cstdlib>
#include <sstream>
#include <numeric>
#include <queue>
#include <iostream>
#include <string>
#include <cstring>
#include <utility>
#include <ctime>
#define sz(a) ((int)(a).size())
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define Rep(i,j,k) for (int i=(j); i<=(k); i++)
#define Repd(i,j,k) for (int i=(j); i>=(k); i--)
#define ALL(c) (c).begin(),(c).end()
#define TR(c,i) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

int id[10], n, m, k;
bool possible[10][130][6][6][6];
	int aa[3];

void doit(){
		VI a;
		Rep(i,1,k){
			int x;
			cin>>x;
			a.pb(x);
		}

	for(aa[0]=2; aa[0]<=5; aa[0]++)
	for(aa[1]=2; aa[1]<=5; aa[1]++)
	for(aa[2]=2; aa[2]<=5; aa[2]++){
		bool f1=1;
		TR(a,x){
			bool f2=0;
			Rep(s,0,7)
				if (possible[s][*x][aa[0]][aa[1]][aa[2]])
					f2=1;
			if (!f2)
				f1=0;
		}
		if (f1){
			cout<<aa[0]<<aa[1]<<aa[2]<<endl;
			return;
		}
	}

	cout<<"222"<<endl;
}

int main(){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);

	int TC;cin>>TC; printf("Case #1:\n");

	for(aa[0]=2; aa[0]<=5; aa[0]++)
	for(aa[1]=2; aa[1]<=5; aa[1]++)
	for(aa[2]=2; aa[2]<=5; aa[2]++)
			{
				Rep(s,0,7){
					int prod=1;
					Rep(i,0,2)
						if ( (s>>i)&1 )
							prod*=aa[i];
					possible[s][prod][aa[0]][aa[1]][aa[2]]=1;
				}
			}

	cin>>TC>>n>>m>>k;
	memset(id,0xff,sizeof id);
	while(TC--){
		doit();
	}

    return 0;
}
