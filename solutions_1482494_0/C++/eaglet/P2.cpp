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
int N;
pii arr[1005];
int used[1005];

int main() { 
	
	FILE *fin = fopen("P2.txt", "r");
	FILE *fout = fopen("P2ans.txt", "w");
	fscanf(fin, "%d", &T);
	for (int z = 1; z <= T; z++) {
        //printf("Case #%d: ", z);
        fprintf(fout, "Case #%d: ", z);
        fscanf(fin,"%d",&N);
        int i,j;
        REP(i,N) {
        	fscanf(fin,"%d%d",&arr[i].second,&arr[i].first);
        }
        sort(arr,arr+N);
        CLEAR(used,0);
        int bad=0;
        int star=0,cur=0,move=0;
        while(1) {
        	if (cur==N)break;
        	if (arr[cur].first<=star) {
        		if (used[cur]==1) star += 1;
        		else star += 2;
        		cur++; move++; continue;
        	}
        	int usefirst = 0;
        	for (i = N-1; i >= cur; i--) {
        		if (arr[i].second <= star && used[i] == 0) {
        			used[i]=1; usefirst = 1;
        			star++; move++;
        			break;
        		}
        	}
        	if (usefirst) continue;
        	else {
        		bad = 1; break;
        	}
        }
        if (bad) {
        	//printf("Too bad\n");
        	fprintf(fout,"Too Bad\n");
    
        } else {
        	//printf("%d\n", move);
        	fprintf(fout,"%d\n", move);
        }
	}
	
	//cin.get();
	//cin.get();
	
    return 0;
}

