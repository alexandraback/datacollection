#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct _data {
	int p, s;

	inline bool operator < (const _data &rhs) const { return s < rhs.s; }
} data;

int main(){
	ifstream fin("A.in");
	ofstream fout("A.out");

	int T;
	fin >> T;
	int c=0;
	while(T--){
		int N;


		data a[1001];

		//int A[1001], B[1001];
		fin >> N;
		for(int i = 0; i < N; i++)
			fin >> a[i].p >> a[i].s;

		sort(a, a+N);

		int star = 0;
		int ans = 0;

		for(int i = 0; star < N*2; i++){
			if( a[i].s == -1 )
				continue;
			else if( a[i].s <= star ){
				if( a[i].p == -1 )					
					star++;
				else{
					a[i].p = -1;					
					star += 2;
				}
				a[i].s = -1;
				//i=-1;
				ans++;
				continue;
			}
			else{
				int te = ans;
				for(int j = N-1; j >= 0; j--){
					if( a[j].p != -1 && a[j].p <= star ){
						a[j].p = -1;
						ans++;
						star++;
						i--;
						break;						
					}					
				}
				if( ans == te ){
					ans = -1;
					break;
				}				
			}
		}
		if(ans > -1)
			fout << "Case #" << ++c << ": " << ans << endl;
		else
			fout << "Case #" << ++c << ": " << "Too Bad" << endl;

	}
	return 0;
}