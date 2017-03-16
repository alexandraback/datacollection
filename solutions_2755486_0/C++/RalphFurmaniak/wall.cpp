

#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
using namespace std;
typedef long long i64;
#define fu(i,m,n) for(int i=m; i<n; i++)
#define fr(i,m,n) for(typeof(m) i=m; i!=n; i++)
#define fa(i,c) fr(i,(c).begin(),(c).end())

int wall[2000000];
vector<int> days[10000000];

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
		memset(wall,0,sizeof(wall));
		int N;
		cin >> N;
		int d[100], n[100], w[100], e[100], s[100], delta_d[100], delta_p[100], delta_s[100];
		for(int D=0; D<10000000; D++) days[D].clear();
		for(int i=0; i<N; i++) {
			cin >> d[i]>>n[i]>>w[i]>>e[i]>>s[i]>>delta_d[i]>>delta_p[i]>>delta_s[i];
			days[d[i]].push_back(i);
		}
		int ret=0;
		for(int D=0; D<10000000; D++) if(days[D].size()) {
			fa(i, days[D]) {
				bool success=false;
				for(int x=w[*i]; x<e[*i]; x++) if(wall[1000000+x]<s[*i]) { success=true; break; }
				if(success) ret++;
				//cout << D << ": " << w[*i] << " " << e[*i] << " " << s[*i] << " " << success << endl;
			}
			fa(i, days[D]) {
				for(int x=w[*i]; x<e[*i]; x++) if(wall[1000000+x]<s[*i]) wall[1000000+x]=s[*i];
				d[*i] += delta_d[*i];
				n[*i]--;
				if(n[*i]==0) continue;
				w[*i]+=delta_p[*i];
				e[*i]+=delta_p[*i];
				s[*i]+=delta_s[*i];
				days[d[*i]].push_back(*i);
			}
			vector<int> v;
			days[D].swap(v);
		}
		cout << ret << endl;
        }
}
