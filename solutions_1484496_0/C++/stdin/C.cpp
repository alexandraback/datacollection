#include <iostream>
#include <cstring>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	int case_nr, T;

	cin >> T;

	for (case_nr=1; case_nr<=T; case_nr++) {
		cout << "Case #" << case_nr << ":" << endl;
		
		static int sums[2000200];
		memset(sums, 0, sizeof(sums));
		int N;
		cin >> N;
		
		int S[20];
		for (int i=0; i<N; i++)
			cin >> S[i];
		
		bool ok = false;
		for (int set=0; set < (1 << 20); set++) {
			int sum=0;
			
			int set_cpy = set;
			for (int i=0; i<20; i++) {
				if (set_cpy & 1)
					sum += S[i];
				set_cpy >>= 1;
			}
			
			if (sums[sum]) {
				set_cpy = set;
				
				for (int i=0; i<20; i++) {
					if (set_cpy & 1)
						cout << S[i] << " ";
					set_cpy >>= 1;
				}
				cout << endl;
				for (set=0; set < (1 << 20); set++) {
					int sum2=0;
					
					int set_cpy = set;
					for (int i=0; i<20; i++) {
						if (set_cpy & 1)
							sum2 += S[i];
						set_cpy >>= 1;
					}
					if (sum2 == sum) {
						set_cpy = set;
						
						for (int i=0; i<20; i++) {
							if (set_cpy & 1)
								cout << S[i] << " ";
							set_cpy >>= 1;
						}
						break;
					}
				}
				
				ok = true;
				break;
			}
			sums[sum] = 1;
		}
		
		if (!ok)
			cout << "Impossible";
		cout << endl;
	}
}
