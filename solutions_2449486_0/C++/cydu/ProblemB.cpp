#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <list>

using namespace std;

int main()
{
	int N=0;
	cin >> N;
	for(int n=1;n<=N;n++) {
		int x, y;
		cin >> x >> y;
		vector<vector<int> > init_lawn(x,vector<int>(y,100));
		vector<vector<int> > lawn = init_lawn;
		int lmax = 2;
		for(int i=0;i<x;i++) {
			for(int j=0;j<y;j++) {
				int t;
				cin >> t;
				lawn[i][j] = t;
				lmax = max(lmax, t);
			}	
		}
		for(int cut = lmax;cut >= 1; cut--) {
			for(int i=0;i<x;i++) {
				int can_cut = true;	
				for(int j=0;j<y;j++) {
					if(lawn[i][j] > cut ) { 
						can_cut = false;
						break;
					}
				}
				if(can_cut) {
					for(int j=0;j<y;j++) {
						init_lawn[i][j] = cut;
					}	
				}
			}
			for(int i=0;i<y;i++) {
				int can_cut = true;	
				for(int j=0;j<x;j++) {
					if(lawn[j][i] > cut) {
						can_cut = false;
						break;
					}
				}
				if(can_cut) {
					for(int j=0;j<x;j++) {
						init_lawn[j][i] = cut;
					}	
				}
			}
		}	
		
		int flag = true;
		for(int i=0;i<x && flag;i++) {
			for(int j=0;j<y && flag;j++) {
				if(lawn[i][j] != init_lawn[i][j]) {
					flag = false;
				}
			}	
		}
		if(flag) {
			cout << "Case #"<<n<<": YES" << endl;
		}else {
			cout << "Case #"<<n<<": NO" << endl;
		}
	}
	return 0;
}


/* vim: set ts=4 sw=4 sts=4 tw=100 noet: */
