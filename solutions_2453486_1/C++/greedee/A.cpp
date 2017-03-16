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

bool isWinningPos(vector<string> vs, char ch)
{
    for(int i=0;i<4;i++) {
        int rc = 0;
        for(int j=0;j<4;j++) {
            if(vs[i][j] == ch || vs[i][j] == 'T') rc++;
        }
        if(rc == 4) return true;
    }
    for(int i=0;i<4;i++) {
        int rc = 0;
        for(int j=0;j<4;j++) {
            if(vs[j][i] == ch || vs[j][i] == 'T') rc++;
        }
        if(rc == 4) return true;
    }
    int c = 0;
    for(int i=0;i<4;i++) if(vs[i][i] == ch || vs[i][i] == 'T') c++;
    if(c==4) return true;

    c = 0;
    for(int i=0;i<4;i++) if(vs[i][3-i] == ch || vs[i][3-i] == 'T') c++;
    if(c==4) return true;

    return false;
}

int main()
{
	cout << setprecision(9) ;
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        vector<string> vs;
        for(int j=0;j<4;j++) {
            string s;
            cin >> s;
            vs.push_back(s);
        }
        if(isWinningPos(vs, 'X')) cout << "Case #" << i << ": " << "X won" << endl;
        else if(isWinningPos(vs, 'O')) cout << "Case #" << i << ": " << "O won" << endl;
        else {
            int numChars = 0;
            for(int j=0;j<4;j++) for(int k=0;k<4;k++) if(vs[j][k] == '.') numChars++;
            if(numChars == 0) cout << "Case #" << i << ": " << "Draw" << endl;
            else cout << "Case #" << i << ": " << "Game has not completed" << endl;
        }
    }
	return 0;
}


