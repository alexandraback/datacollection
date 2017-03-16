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

int p10[9];
int col[2000002];
int numdigits[2000002];
int color;

int T,A,B;

int g(int n) {
	col[n] = color;
	for(int i=1;i<numdigits[n];i++) {
		int next = (n%p10[i])*p10[numdigits[n]-i]+n/p10[i];
		if(next > 2000000) continue;
		if(!col[next]) col[next] = color;
	}
}


long long f() {
	long long output = 0;
	vector<int> ret;
	for(int i=A;i<=B;i++) {
		ret.push_back(col[i]);
	}
	sort(ret.begin(),ret.end());
	if(ret.size() == 0 || ret.size() == 1) return 0;
	int cnt = 1;
	for(int i=1;i<ret.size();i++) {
		if(ret[i] != ret[i-1]) {
			output += cnt*(cnt-1)/2;
			cnt = 1;
		} else {
			cnt++;
		}

	}
	output += (cnt)*(cnt-1)/2;
	return output;
}


int main()
{
	cout << setprecision(9) ;
	cin >> T;
	p10[0] = 1;
	for(int i=1;i<9;i++) p10[i] = 10*p10[i-1];
	for(int i=1;i<=2000000;i++) {
		if(i<10) numdigits[i] = 1;
		else if(i<100) numdigits[i] = 2;
		else if(i<1000) numdigits[i] = 3;
		else if(i<10000) numdigits[i] = 4;
		else if(i<100000) numdigits[i] = 5;
		else if(i<1000000) numdigits[i] = 6;
		else numdigits[i] = 7;
	}
	color = 1;
	for(int i=12;i<=2000000;i++) {
		if(col[i]) continue;
		g(i);
		color++;
	}
	for(int i=1;i<=T;i++) {
		cin >> A >> B;
		cout << "Case #" << i << ": " << f() << endl;
	}
	return 0;
}


