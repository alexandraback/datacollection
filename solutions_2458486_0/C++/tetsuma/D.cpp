#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;
#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)

typedef long long ll;
#define INF (1<<29)

int t, K, N, cnt;
bool f;
vector<pair<int, vector<int> > > chest;

void dfs(vector<int> keys, vector<int> ret){
	if(f)return;
	cnt++;
	if(cnt>4000000){
		puts("");
		return;
	}

	for(int i=1;i<=N;i++){
		bool ch=true;
		for(int j=0;j<ret.size();j++)
			if(i==ret[j]){
				ch=false;
				break;
			}
		if(ch){
			for(int j=0;j<keys.size();j++){
				if(keys[j]==chest[i].first){
					vector<int> w, z;
					if(keys.size()!=0)for(int k=0;k<keys.size();k++)if(k!=j)w.push_back(keys[k]);
					if(ret.size()!=0)for(int k=0;k<ret.size();k++)z.push_back(ret[k]);
					z.push_back(i);
					if(z.size()==N){
						f=true;
						for(int k=0;k<z.size();k++){
							if(k!=0)cout << " ";
							cout << z[k];
						}
						return;
					}
					if(chest[i].second.size()!=0)
						for(int k=0;k<chest[i].second.size();k++)w.push_back(chest[i].second[k]);
					dfs(w,z);
				}
			}
		}
	}
	return;
}

int main(){
	cin >> t;
	vector<int> keys, ret;
	for(int tc=1;tc<=t;tc++){
		int a[30], b[30];
		for(int i=0;i<30;i++){
			a[i]=0;
			b[i]=0;
		}
		cnt=0;
		f=false;
		cin >> K >> N;
		keys.clear();
		ret.clear();
		for(int i=0;i<K;i++){
			int tmp;
			cin >> tmp;
			b[tmp]++;
			keys.push_back(tmp);
		}
		vector<int> v;
		chest.clear();
		chest.push_back(make_pair(0,v));
		for(int i=0;i<N;i++){
			v.clear();
			int tmp1, n, tmp2;
			cin >> tmp1 >> n;
			a[tmp1]++;
			if(n!=0)for(int j=0;j<n;j++){
				cin >> tmp2;
				b[tmp2]++;
				v.push_back(tmp2);
			}
			chest.push_back(make_pair(tmp1,v));
		}
		printf("Case #%d: ",tc);
		bool ng=true;
		for(int i=0;i<30;i++)if(a[i]>b[i])ng=false;
		if(ng)dfs(keys,ret);
		if(!f)puts("IMPOSSIBLE");
		else puts("");
	}
	return 0;
}

