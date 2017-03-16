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
char trans[26];
char cur[105];

int main() { 
	trans[0]='y';
	trans[1]='h';
	trans[2]='e';
	trans[3]='s';
	trans[4]='o';
	trans[5]='c';
	trans[6]='v';
	trans[7]='x';
	trans[8]='d';
	trans[9]='u';
	trans[10]='i';
	trans[11]='g';
	trans[12]='l';
	trans[13]='b';
	trans[14]='k';
	trans[15]='r';
	trans[16]='z';
	trans[17]='t';
	trans[18]='n';
	trans[19]='w';
	trans[20]='j';
	trans[21]='p';
	trans[22]='f';
	trans[23]='m';
	trans[24]='a';
	trans[25]='q';
	FILE *fin = fopen("P1.txt", "r");
	FILE *fout = fopen("P1ans.txt", "w");
	fscanf(fin, "%d", &T);
	fgets(cur, sizeof cur, fin);
	for (int z = 1; z <= T; z++) {
        fprintf(fout, "Case #%d: ", z);
        
        fgets(cur, sizeof cur, fin);
        int i=0;
        while(1) {
            if (cur[i] == '\n') break;
        	if (cur[i] >= 'a' && cur[i] <= 'z') cur[i] = trans[cur[i]-'a'];
        	i++;
        }
        i=0;
        while(1) {
            if (cur[i] == '\n') break;
        	fprintf(fout, "%c", cur[i]);
        	i++;
        }
        fprintf(fout, "\n");
	}
	
	//cin.get();
	//cin.get();
	
    return 0;
}

