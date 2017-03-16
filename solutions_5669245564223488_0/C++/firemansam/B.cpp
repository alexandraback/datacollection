#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int tcs, n;
int recur(int bm, vector<string> trains, int ct[], string result){
	bitset<15> bs(bm);
	if(bs.count() == n){
		int ctr[1000] = {0};
		char lc = '-';
		for(int i=0;i<result.length();i++){
			if(result[i] != lc){
				if(ctr[lc] != ct[lc]) return 0;
				lc = result[i];
			}
			ctr[result[i]]++;
		}
		return 1;
	}else{
		int ans = 0;
		for(int i=0;i<n;i++){
			if(bm & (1 << i)) continue;
			bm += 1 << i;
			ans += recur(bm, trains, ct, result + trains[i]);
			bm -= 1 << i;
		}
		return ans;
	}
}
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i", &n);
		int ans = 0;
		vector<string> trains;
		char buf[1000];
		int ct[1000] = {0};
		for(int i=0;i<n;i++){
			scanf("%s", buf);
			for(int i=0;i<strlen(buf);i++){
				ct[buf[i]]++;
			}
			trains.push_back(string(buf));
		}
		ans = recur(0, trains, ct, "");
		/*do{
			for(int i=0;i<n;i++){
				printf("%s\t", trains[i].c_str());
			}
			bool ok = true;
			int ctr[1000] = {0};
			char lc = '-';
			for(int i=0;i<n;i++){
				for(int j=0;j<trains[i].length();j++){
					if(trains[i][j] != lc){
						if(ctr[lc] != ct[lc]) {ok = false; break;}
						lc = trains[i][j];
					}
					ctr[trains[i][j]]++;
				}
				if(!ok) break;
			}
			printf("%i\n", ok);
			ans = (ans + ok) % MOD;
		}while(permute(trains.begin(), trains.end()));*/
		printf("Case #%i: %i\n", tc, ans);
	}
}