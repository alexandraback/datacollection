#include <vector> 
#include <list> 
#include <map> 
#include <set> 
#include <deque> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <utility> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <cctype> 
#include <string> 
#include <cstring> 
#include <cstdio> 
#include <cmath> 
#include <cstdlib> 
#include <ctime> 

using namespace std; 


#define PI acos(-1)
#define CLEAR(A) memset(A,0,sizeof(A))
#define SETMAX(A) memset(A,0x7f,sizeof(A))
#define SETM1(A) memset(A,-1,sizeof(A))
#define SQ(A) (A)*(A)

int sum[3000000];
int a[502];
int N;

int main()
{
	cout << setprecision(9) ;
	int cases;
	cin >> cases;
	for(int caseno=1;caseno<=cases;caseno++) {
		cin >> N;
		CLEAR(sum);
		for(int i=0;i<N;i++) cin >> a[i];
		bool found = false;
		for(int i=1;i<(1<<N);i++) {
			int s = 0;
			for(int j=0;j<N;j++) {
				if(i & (1<<j)) {
					s += a[j];
				}
			}
			if(sum[s]) {
				cout << "Case #" << caseno << ": " << endl;
				for(int j=0;j<N;j++) {
					if(sum[s] & (1<<j)) cout << a[j] << " ";
				}
				cout << endl;
				for(int j=0;j<N;j++) {
					if(i & (1<<j)) cout << a[j] << " ";
				}
				cout << endl;
				found = true;
				break;
			} else {
				sum[s] = i;
			}
		}
		if(!found) {
			cout << "Impossible" << endl;
		}		
	}
	return 0;
}


