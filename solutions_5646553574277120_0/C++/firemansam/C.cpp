#include<bits/stdc++.h>
using namespace std;
int tcs, ans, c, d, v;
int cs[1000];
bitset<1000000005> pos;
vector<int> avail, potent;
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		scanf("%i%i%i", &c, &d, &v);
		avail.clear();
		pos.reset();
		potent.clear();
		for(int i=0;i<d;i++){
			scanf("%i", &cs[i]);
		}
		avail.push_back(0);
		do{
			for(int i=0;i<d;i++){
				int csum = 0;
				for(int j=i;j<d;j++){
					csum += cs[j];
					pos[csum] = 1;
					avail.push_back(csum);
				}
			}
		} while(next_permutation(cs, cs + d));
		sort(avail.begin(), avail.end());
		for(int i=1;i<=v;i++){
			if(pos[i]) continue;
			bool ok = 0;
			for(int k=0;k<avail.size();k++){
				do{
					int csum = avail[k];
					for(int j=0;j<potent.size();j++){
						csum += potent[j];
						if(csum == i) {  ok = 1; break;}
					}
				} while(next_permutation(potent.begin(), potent.end()));
				if(ok) break;
			}
			if(ok) continue;
			int bs = *(lower_bound(avail.begin(), avail.end(), i)-1);
			potent.push_back(i-bs);
		}
		printf("Case #%i: %i\n", tc, potent.size());
	}
}