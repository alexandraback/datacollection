#include <stdio.h>
#include <map>
#include <algorithm>
using namespace std;

int main(){
	freopen("C-small-attempt0.in","r",stdin);
	freopen("C-small-attempt0.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T-->0){
		int A, B;
		scanf("%d %d",&A,&B);
		int n, m;
		int sol = 0;
		for (n = A; n< B; n ++ ){
			int tn = n;
			int d = 0, dd = 1;
			while(tn > 0) {
				tn = tn / 10;
				dd *= 10;
			}
			dd /= 10;
			tn = n;
			m = n;
			map<int ,int> chk;
			while(tn > 0) {
				m = m / 10 + dd * (tn % 10);
				tn = tn / 10;
				if (n < m && m <= B && chk.find(m) == chk.end()){
					sol ++;
					chk[m] = true;
				}
			}

		}
		static int cs = 1;
		printf("Case #%d: %d\n",cs ++, sol);
	}
	return 0;
}