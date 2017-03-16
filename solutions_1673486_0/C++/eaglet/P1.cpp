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
double dbl[100005];

int main() { 
	
	FILE *fin = fopen("P1.txt", "r");
	FILE *fout = fopen("P1ans.txt", "w");
	fscanf(fin, "%d", &T);
	for (int z = 1; z <= T; z++) {
        //printf("Case #%d: ", z);
        fprintf(fout, "Case #%d: ", z);
        fscanf(fin, "%d%d",&A,&B);
        int i,j;
        dbl[0] = 1.0;
        REP(i,A) {
        	fscanf(fin,"%lf",&dbl[i+1]);
        }
        double ans = B+2;
        double mult = 1;
        for (i = A; i >= 0; i--) {
        	mult *= dbl[A-i];
        	//printf("%.3f\n", mult);
        	ans = min(ans, 2*i + (2*B-A+2) - (B+1)*mult);
        }
        //printf("%.8f\n", ans);
        fprintf(fout,"%.8f\n", ans);
	}
	
	//cin.get();
	//cin.get();
	
    return 0;
}

