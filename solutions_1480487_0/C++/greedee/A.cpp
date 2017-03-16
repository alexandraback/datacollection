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

int T;
int N;
int a[300];
int zeros[300];
double ret[300];
int sum;

void f()
{
	while(1) {
		int total = 0;
		int cnt = 0;
		for(int i=0;i<N;i++) {
			if(zeros[i]) continue;
			total += a[i];
			cnt++;
		}
		total += sum;
		for(int i=0;i<N;i++) {
			if(zeros[i]) ret[i] = 0;
			else ret[i] = 100.0*(1.0*total/cnt-a[i])/sum;
		}
		bool ok = false;
		for(int i=0;i<N;i++) {
			if(ret[i] < -1e-8) {
				zeros[i] = 1;
				ok = true;
			}
		}
		if(!ok) break;
	}
}

int main()
{
	cout << setprecision(9) ;
	cin >> T;
	for(int i=1;i<=T;i++) {
		cin >> N;
		sum = 0;
		CLEAR(zeros);
		CLEAR(ret);
		for(int j=0;j<N;j++) cin >> a[j];
		for(int j=0;j<N;j++) sum += a[j];
		f();
		cout << "Case #" << i << ": ";
		for(int j=0;j<N;j++) cout << ret[j] << " ";
		cout << endl;
	}
	return 0;
}


