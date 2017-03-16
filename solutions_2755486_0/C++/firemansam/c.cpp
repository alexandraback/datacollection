#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int tcs, ans;
int n;
struct attack{
	int day, e, len, strength;
};
int wall[500], zero = 250;
vector<attack> atk;
bool fail = 0;
bool cmp(attack a, attack b){
	if(a.day == b.day) return a.strength < b.strength;
	else return a.day < b.day;
}
int main(){
	scanf("%i", &tcs);
	for(int tc=1;tc<=tcs;tc++){
		memset(wall, 0, sizeof wall);
		atk.clear();
		ans = 0;
		scanf("%i", &n);
		for(int i=0;i<n;i++){
			int di, ni, ei, wi, si, ddi, dpi, dsi;
			scanf("%i%i%i%i%i%i%i%i", &di, &ni, &ei, &wi, &si, &ddi, &dpi, &dsi);
			int len = wi - ei;
			for(int i=0;i<ni;i++){
				attack ak;
				ak.day = di;
				ak.e = ei + zero,
				ak.len = len;
				ak.strength = si;
				di += ddi;
				ei += dpi;
				si += dsi;
				atk.push_back(ak);
			}
		}

		sort(atk.begin(), atk.end(), cmp);

		//printf("begin simulation: %i attacks incoming\n", atk.size());

		for(int i=0;i<atk.size();i++){
			fail = 0;
			attack a = atk[i];
			//printf("on day %i:\n", a.day);
			for(int w=a.e;w<a.e+a.len;w++){
				if(wall[w] < a.strength){
					fail = 1;
					//printf("attack has succeeded, there is a hole %i at %i, we are sending %i\n", wall[w], w, a.strength);
					wall[w] = a.strength;
				}
			}
			if(!fail) continue;
			ans++;
		}
		printf("Case #%i: %i\n", tc, ans);
	}
}