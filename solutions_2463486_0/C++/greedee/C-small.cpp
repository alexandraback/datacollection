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

int main()
{
	cout << setprecision(9) ;
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        long long A, B;
        int c = 0;
        cin >> A >> B;
        if(1 >= A && 1 <= B) c++;
        if(4 >= A && 4 <= B) c++;
        if(9 >= A && 9 <= B) c++;
        if(121 >= A && 121 <= B) c++;
        if(484 >= A && 484 <= B) c++;
        cout << "Case #" << i << ": " << c << endl;
    }
	return 0;
}


