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

int maxr[102];
int maxc[102];
int N, M;
int a[102][102];

bool isOk()
{
    CLEAR(maxr);
    CLEAR(maxc);
    vector<pair<int, pair<int,int> > > v;
    for(int i=0;i<N;i++) {
        for(int j=0;j<M;j++) {
            maxr[i] = max(maxr[i], a[i][j]);
            maxc[j] = max(maxc[j], a[i][j]);
            v.push_back(make_pair(a[i][j], make_pair(i,j)));
        }
    }
    sort(v.begin(), v.end());
    for(int i=0;i<v.size();i++) {
        int r = v[i].second.first;
        int c = v[i].second.second;
        int val = v[i].first;
        if(val < maxr[r] && val < maxc[c]) return false;
    }
    return true;
}

int main()
{
	cout << setprecision(9) ;
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        cin >> N >> M;
        for(int j=0;j<N;j++) {
            for(int k=0;k<M;k++) {
                cin >> a[j][k];
            }
        }
        cout << "Case #" << i << ": ";
        if(isOk()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
	return 0;
}


