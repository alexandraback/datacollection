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
int N,S,P;
int t;

int main() { 
	FILE *fin = fopen("P2.txt", "r");
	FILE *fout = fopen("P2ans.txt", "w");
	fscanf(fin, "%d", &T);
	for (int z = 1; z <= T; z++) {
        //printf("Case #%d: ", z);
         fprintf(fout, "Case #%d: ", z);
        /*** start here ***/
        fscanf(fin, "%d%d%d", &N,&S,&P);
        int i,j;
        int ans = 0;
        REP(i,N) {
        	fscanf(fin, "%d", &t);
        	int tt = t/3;
        	if (t == 0) {
                if (tt >= P) ans++;
            } else if (t%3 == 0) {
        		if (tt >= P) ans++;
        		else if (S > 0 && tt+1 >= P) {
        			ans++; S--;
        		}
        	} else if (t%3 == 1) {
        		if (tt+1 >= P) ans++;
        	} else if (t%3 == 2) {
        		if (tt+1 >= P) ans++;
        		else if (S > 0 && tt+2 >= P) {
        			ans++; S--;
        		}
        	}
        }
        //printf("%d\n", ans);
        fprintf(fout, "%d\n", ans);
	}
	
	//cin.get();
	//cin.get();
	
    return 0;
}

