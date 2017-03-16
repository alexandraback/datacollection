#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef long long LL;

#define fi first
#define se second
#define mp make_pair
#define pb push_back
const double pi = acos(-1);
int t;
int main(){
	scanf("%d", &t);
	for(int tc = 1; tc <= t; ++tc){
		int cnt[10];
		memset(cnt, 0, sizeof cnt);
		string s;
		cin>>s;
		int len = s.size();
		sort(s.begin(),s.end());
		//Z
		int low0 = lower_bound(s.begin(),s.end(), 'Z') - s.begin();
		int up0 = upper_bound(s.begin(),s.end(), 'Z') - s.begin();
		cnt[0] = up0 - low0;
		int low8 = lower_bound(s.begin(),s.end(), 'G') - s.begin();
		int up8 = upper_bound(s.begin(),s.end(), 'G') - s.begin();
		cnt[8] = up8 - low8;

		int low6 = lower_bound(s.begin(),s.end(), 'X') - s.begin();
		int up6 = upper_bound(s.begin(),s.end(), 'X') - s.begin();
		cnt[6] = up6 - low6;

		int low7 = lower_bound(s.begin(),s.end(), 'S') - s.begin();
		int up7 = upper_bound(s.begin(),s.end(), 'S') - s.begin();
		cnt[7] = up7 - low7 - cnt[6];

		int low5 = lower_bound(s.begin(),s.end(), 'V') - s.begin();
		int up5 = upper_bound(s.begin(),s.end(), 'V') - s.begin();
		cnt[5] = up5 - low5 - cnt[7];

		int low4 = lower_bound(s.begin(),s.end(), 'F') - s.begin();
		int up4 = upper_bound(s.begin(),s.end(), 'F') - s.begin();
		cnt[4] = up4 - low4 - cnt[5];

		int low3 = lower_bound(s.begin(),s.end(), 'R') - s.begin();
		int up3 = upper_bound(s.begin(),s.end(), 'R') - s.begin();
		cnt[3] = up3 - low3 - cnt[0] - cnt[4];

		int low2 = lower_bound(s.begin(),s.end(), 'T') - s.begin();
		int up2 = upper_bound(s.begin(),s.end(), 'T') - s.begin();
		cnt[2] = up2 - low2 - cnt[3] - cnt[8];

		int low9 = lower_bound(s.begin(),s.end(), 'I') - s.begin();
		int up9 = upper_bound(s.begin(),s.end(), 'I') - s.begin();
		cnt[9] = up9 - low9 - cnt[5] - cnt[6] - cnt[8];

		int low1 = lower_bound(s.begin(),s.end(), 'O') - s.begin();
		int up1 = upper_bound(s.begin(),s.end(), 'O') - s.begin();
		cnt[1] = up1 - low1 - cnt[0] - cnt[2] - cnt[4];
		printf("Case #%d: ", tc);
		for(int i = 0;i < 10; ++i){
			for(int j = 0;j < cnt[i];j++)printf("%d", i);
		}
		puts("");
	}
	return 0;
}