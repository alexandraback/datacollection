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

vector<long long> v;

int f(long long j, long long k)
{
    while(j) {
        int rem = j%10;
        j /= 10;
        k = k*10 + rem;
    }
    long long sq = k*k;
    long long num = sq;
    string s;
    while(num) {
        s += '0' + (num%10);
        num /= 10;
    }
    bool ok = true;
    for(int j=0;j<s.size()/2;j++) {
        if(s[j] != s[s.size()-1-j]) {
            ok = false;
            break;
        }
    }

    if(ok && sq < 100000000000000LL) {
        v.push_back(sq);
    }
}

int main()
{
	cout << setprecision(9) ;
    for(int i=1;i<100000;i++) {
        f(i,i);
        f(i/10,i);
    }
    sort(v.begin(), v.end());

    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        long long A, B;
        int c = 0;
        cin >> A >> B;
        for(int j=0;j<v.size();j++) if(v[j] >= A && v[j] <= B) c++;
        cout << "Case #" << i << ": " << c << endl;
    }

	return 0;
}


