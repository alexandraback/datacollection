#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;
typedef long long i64;

int main(void) {
	int T;
	cin >> T;
	for(int ts=1; ts<=T; ts++) {
		int N;
		cin >> N;
		vector<i64> v(N);
		for(int i=0; i<N; i++) cin >> v[i];
		cout << "Case #" << ts << ":";
		i64 diff[25];
		int dmsk[25], dmsk2[25];
		for(int st=0; st<500; st+=20) {
			map<i64,i64> sn;
			for(int msk=1; msk<(1<<20); msk++) {
				i64 su = 0;
				for(int i=0; i<20; i++) if(msk&(1<<i)) su+=v[st+i];
				i64& msk2 = sn[su%1000000];
				if(msk2) {
					//for(int i=0; i<N; i++) if(msk2&(1<<i)) cout << " " << v[i]; cout << endl;
					//for(int i=0; i<N; i++) if(msk&(1<<i)) cout << " " << v[i]; cout << endl;
					i64 su = 0;
					for(int i=0; i<20; i++) if(msk&(1<<i)) su+=v[st+i];
					for(int i=0; i<20; i++) if(msk2&(1<<i)) su-=v[st+i];
					diff[st/20] = su;
					dmsk[st/20] = msk;
					dmsk2[st/20] = msk2;
					//cout << st << " " << su << " " << msk << " " << msk2 << endl;
					break;
				}
				// Impossible?
				msk2 = msk;
			}
		}

		map<i64, int> tdiff;

		for(int msk=1; msk<(1<<24); msk++) {
			i64 su = 0;
			bool bad=false;
			for(int i=0; i<12; i++) {
				int type = (msk>>(i+i))&3;
				switch(type) {
					case 0: break;
					case 1: su+=diff[i]; break;
					case 2: su-=diff[i]; break;
					case 3: bad=true;
				}
			}
			if(!bad) tdiff[su] = msk;
		}

		for(int msk=1; msk<(1<<26); msk++) {
			i64 su = 0;
			bool bad=false;
			for(int i=0; i<13; i++) {
				int type = (msk>>(i+i))&3;
				switch(type) {
					case 0: break;
					case 1: su+=diff[12+i]; break;
					case 2: su-=diff[12+i]; break;
					case 3: bad=true;
				}
			}
			if(!bad) if(tdiff[su]) {
				int msk2=tdiff[su];
				vector<i64> v1,v2;

				for(int i=0; i<12; i++) {
					int type = (msk2>>(i+i))&3;
					if(type==1) {
						int mm = dmsk[i], mm2=dmsk2[i];
						for(int j=0; j<20; j++) if(mm&(1<<j)) v1.push_back(v[i*20+j]);
						for(int j=0; j<20; j++) if(mm2&(1<<j)) v2.push_back(v[i*20+j]);
					}

					if(type==2) {
						int mm = dmsk[i], mm2=dmsk2[i];
						for(int j=0; j<20; j++) if(mm&(1<<j)) v2.push_back(v[i*20+j]);
						for(int j=0; j<20; j++) if(mm2&(1<<j)) v1.push_back(v[i*20+j]);
					}
				}


				for(int i=0; i<13; i++) {
					int type = (msk>>(i+i))&3;
					if(type==2) {
						int mm = dmsk[12+i], mm2=dmsk2[12+i];
						for(int j=0; j<20; j++) if(mm&(1<<j)) v1.push_back(v[(12+i)*20+j]);
						for(int j=0; j<20; j++) if(mm2&(1<<j)) v2.push_back(v[(12+i)*20+j]);
					}

					if(type==1) {
						int mm = dmsk[12+i], mm2=dmsk2[12+i];
						for(int j=0; j<20; j++) if(mm&(1<<j)) v2.push_back(v[(12+i)*20+j]);
						for(int j=0; j<20; j++) if(mm2&(1<<j)) v1.push_back(v[(12+i)*20+j]);
					}
				}
				i64 su1=0, su2=0;
				for(int i=0; i<v1.size(); i++) su1+=v1[i];
				for(int i=0; i<v2.size(); i++) su2+=v2[i];
				//cout << su << " " << su1 << " " << su2 << endl;
				if(su1!=su2) cout << "Impossible?" << endl;
				for(int i=0; i<v1.size(); i++) cout << (i?' ':'\n') << v1[i];
				for(int i=0; i<v2.size(); i++) cout << (i?' ':'\n') << v2[i];
				break;
			}
		}
		cout << endl;
	}
}
