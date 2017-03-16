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

int cases;
int N,S,P;
int a[102];

bool larger(int n) {
	if((n%3) == 0) return n/3 >= P;
	return n/3+1 >= P;
}

bool surprise(int n) {
	if(n==0) return 0>=P;
	if((n%3) == 2) return n/3+2>=P;
	return n/3+1>=P;
}

int f()
{
	int i;
	sort(a,a+N);
	for(i=N-1;i>=0;i--) {
		if(!larger(a[i])) break;
	}
	int cnt = 0;
	for(int j=0;j<=i;j++) {
		if(surprise(a[j])) cnt++;
	}
	return min(cnt,S) + N-i-1;
}

int main()
{
	cout << setprecision(9) ;
	cin >> cases;
	for(int caseno=1;caseno<=cases;caseno++) {
		cin >> N >> S >> P;	
		for(int i=0;i<N;i++) cin >> a[i];
		cout << "Case #" << caseno << ": " << f() << endl;
	}
	return 0;
}


