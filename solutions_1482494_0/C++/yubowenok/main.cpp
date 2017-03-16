#include <iostream>
#include <cstring>

using namespace std;

double ans;

int n;
int a[2005], b[2005];
bool ma[2005], mb[2005];
int nc;

int main(){
	int cs;

	freopen("output", "w", stdout);

	cin>>cs;

	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d: ", csn);

		cin>>n;
		for(int i=0;i<n;i++) cin>>a[i]>>b[i];

		memset(ma, 0, sizeof(ma));
		memset(mb, 0, sizeof(mb));

		int s = 0;
		int cnt = 0;
		nc = 0;
		while(nc<n){
			bool act = false;
			for(int i=0;i<n;i++){
				if(!mb[i] && s>=b[i]){
					if(!ma[i])
						s += 2;
					else 
						s++;
					mb[i] = true;
					nc++;
					act = true;
					cnt ++;
					//cout<<"clear b"<<i<<endl;
					break;
				}
			}
			if(act) continue;
			int maxb = -10000;
			int maxbidx = -1;
			for(int i=0;i<n;i++){
				if(!ma[i] && !mb[i] && s>=a[i]){
					if(b[i]>=maxb){
						maxb = b[i];
						maxbidx = i;
					}
				}
			}
			if(maxbidx!=-1){
				s ++;
				ma[maxbidx] = true;
				act = true;
				//cout<<"clear a"<<maxbidx<<endl;
				cnt ++;
			}
			if(!act) break;
		}
		if(nc==n) cout << cnt <<endl;
		else cout << "Too Bad"<<endl;

	}
	return 0;
}