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

int K,N;
map<int,int> initKeyCnt;
int chestToOpeningKey[202];
map<int,int> chestToNewKeys[202];

int seen[1<<20];
vector<int> ret;

int isPossible(int mask)
{
    if(mask == (1<<N)-1) return true;
    if(seen[mask] != -1) return seen[mask];
    bool ok = false;
    map<int,int> avaiKeyCnt = initKeyCnt;
    /*
    for(map<int,int>::iterator iter=avaiKeyCnt.begin();iter!=avaiKeyCnt.end();++iter) {
        cout << "avaiKeyCnt : " << iter->first << " " << iter->second << endl; 
    }*/
    for(int i=0;i<N;i++) {
        if(!(mask & (1<<i))) continue;
        for(map<int,int>::iterator iter=chestToNewKeys[i].begin();iter!=chestToNewKeys[i].end();++iter) {
            avaiKeyCnt[iter->first] += iter->second;
        }
        avaiKeyCnt[chestToOpeningKey[i]]--;
    }
    for(int i=0;i<N;i++) {
        if(mask & (1<<i)) continue;
        if(avaiKeyCnt[chestToOpeningKey[i]] && isPossible(mask | (1<<i))) {
            ret.push_back(i);
            ok = true;
            break;
        }
    }
    seen[mask] = ok;
    return ok;
}

int main()
{
	cout << setprecision(9) ;
    int T;
    cin >> T;
    for(int i=1;i<=T;i++) {
        cin >> K >> N;
        initKeyCnt.clear();
        for(int j=0;j<K;j++) {
            int keyType;
            cin >> keyType;
            initKeyCnt[keyType]++;
        }
        for(int j=0;j<N;j++) {
            int Ti, Ki;
            cin >> Ti >> Ki;
            chestToOpeningKey[j] = Ti;
            chestToNewKeys[j].clear();
            for(int k=0;k<Ki;k++) {
                int key;
                cin >> key;
                chestToNewKeys[j][key]++;
            }
        }
        SETM1(seen);
        ret.clear();
        cout << "Case #" << i << ": " ;
        if(isPossible(0)) {
            reverse(ret.begin(), ret.end());
            for(int j=0;j<N;j++) cout << 1+ret[j] << " ";
            cout << endl;
        } else {
            cout << "IMPOSSIBLE" << endl;
        }
    }
	return 0;
}


