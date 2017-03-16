#include <cassert>
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


int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		cout << "Case #" << ts << ": ";
        vector<pair<long,int> > events;
        int N; cin >> N;
        int H=0;
        fu(i,0,N) {
            long Di,Hi,Mi;
            cin >> Di >> Hi >> Mi;
            H += Hi;
            fu(h,0,Hi) {
                long D = Di;
                long M = Mi + h;
                long t0 = M*(360-D);
                events.push_back(make_pair(t0,1));
                fu(j,1,20) {
                    events.push_back(make_pair(t0+360*M*j,-1));
                }
            }
            sort(events.begin(), events.end());
        }
        int best=H;
        int cur=H;
        for(auto e: events) {
            cur -= e.second;
            //cout << cur << endl;
            best = min(best, cur);
        }
        cout << best << endl;
	}
}
