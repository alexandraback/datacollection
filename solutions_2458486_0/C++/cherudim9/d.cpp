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
#define TR(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define SUM(a) accumulate(all(a),string())
#define online1
#define RAND ((rand()<<15)+rand())
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> II;
typedef long long LL;

int a[220][220];
int receive[220];
int ind[220];
int k, n;
bool f[1<<20];

bool CanPushBack(int s, int next){
	int cnt=0;
	Rep(x,0,n)
		if (x==0 || (s&(1<<(x-1)))){
			cnt+=a[x][receive[next]];
			if (receive[x]==receive[next])
				cnt--;
		}
	return cnt>0;
}

bool ok(int s0){
	//cout<<"ok:"<<s0<<endl;
	memset(f,0,sizeof f);
	f[s0]=1;
	Rep(num,0,n-1)
		Rep(s,0,(1<<n)-1)
			if (__builtin_popcount(s)==num && f[s]){
				Rep(next,1,n)
					if ((s&(1<<(next-1)))==0)
						if (CanPushBack(s,next))
							f[s+(1<<(next-1))]=1;//, cout<<s<<" "<<next<<endl;
			}

	return f[(1<<n)-1];
}

void doit(){
	memset(a,0,sizeof a);
	cin>>k>>n;
	while(k--){
		int x;
		cin>>x;
		a[0][x]++;
	}
	Rep(i,1,n){
		cin>>receive[i];
		cin>>k;
		while(k--){
			int x;
			cin>>x;
			a[i][x]++;
		}
	}

	if (!ok(0)){
		puts("IMPOSSIBLE");
		return;
	}

	VI used(n+1,0);
	int s=0;
	Rep(i,1,n){
		Rep(j,1,n) if (!used[j]){
			if (!CanPushBack(s,j))
				continue;
			used[j]=1;
			s+=1<<(j-1);
			if (ok(s)){
				cout<<j<<" ";
				break;
			}
			s-=1<<(j-1);
			used[j]=0;
		}
	}
	cout<<endl;
}

int main(){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);

	int TT;cin>>TT;
	Rep(tt,1,TT){
		printf("Case #%d: ",tt);
		doit();
	}

    return 0;
}
