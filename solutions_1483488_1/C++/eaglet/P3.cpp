#include <iostream> 
#include <vector> 
#include <cstdio> 
#include <cstring> 
#include <algorithm> 
#include <set> 
#include <map> 
#include <queue> 
#include <stack> 
#include <string> 
#include <sstream> 
#include <ctime> 
#include <cmath> 

using namespace std; 

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++) 
#define FE(v,itr) for(__typeof((v).begin()) itr=(v).begin();itr!=(v).end();itr++) 
#define SZ(x) ((int) (x).size())
#define RA(x) (x).begin(), (x).end()
#define CLEAR(a, b) memset(a, b, sizeof(a)) 
#define PB push_back 
#define MP make_pair 
#define INF 2000000000

typedef long long ll; 
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii; 

int T,z;
int A,B;

int main() { 
	FILE *fin = fopen("P3.txt", "r"); // CORRECT!!!!!!!
	FILE *fout = fopen("P3ans.txt", "w"); // CORRECT!!!!!!!
	fscanf(fin, "%d", &T);
	for (int z = 1; z <= T; z++) {
        fprintf(fout,"Case #%d: ", z);
        // fprintf(fout, "Case #%d: ", z);
        /*** start here ***/
        fscanf(fin, "%d%d", &A, &B);
        int numdig=0;
        int AA = A;
        while(AA>0) {
        	AA /= 10;
        	numdig++;
        }
        int i,j;
        int powten = 1;
        REP(i,numdig-1) {
        	powten *= 10;
        }
        int ans = 0;
        for(i=A;i<=B;i++) {
            set<int> myset;
        	int ii = i;
        	REP(j,numdig) {
                
        		int lastdig = ii%10;
        		ii /= 10;
        		ii += (powten * lastdig);
        		if (ii > i && ii <= B) {
                    if (myset.count(ii) != 0) continue;
                    ans++;
                    myset.insert(ii);
                    //printf("%d %d\n", i, ii);
                }
        	}
        }
        fprintf(fout,"%d\n", ans);
	}
	
	//cin.get();
	//cin.get();
	
    return 0;
}

