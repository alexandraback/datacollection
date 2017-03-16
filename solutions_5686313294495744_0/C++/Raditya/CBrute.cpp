#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
map<string,bool> AKiri, AKanan;
int t;
int n;
const int MaxN = 20;
string kiri[MaxN];
string kanan[MaxN];
int main(){
	scanf("%d", &t);
	for(int tc = 1; tc <= t; ++tc){
		scanf("%d", &n);
		for(int i = 0;i < n; ++i){
			cin>>kiri[i]>>kanan[i];
		}
		int maxcnt = 0;
		for(int i = 0;i < (1<<n); ++i){//brutenya
			AKiri.clear();
			AKanan.clear();
			for(int j = 0;j < n; ++j){
				if(i & (1<<j)){
					AKiri[kiri[j]] = true;
					AKanan[kanan[j]] = true;
				}
			}
			int cnt = 0;
			for(int j = 0;j < n; ++j){
				
				if(!(i& (1<<j))){
					if(AKiri.count(kiri[j]) && AKanan.count(kanan[j])){
						cnt++;
					}
				}
			}
			maxcnt = max(maxcnt, cnt);
		}
		printf("Case #%d: %d\n", tc, maxcnt);
	}
	return 0;
}