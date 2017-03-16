#include <cstdio>
#include <vector>
#include <cassert>
using namespace std;
/*
1 = 0
-1 = 1

i = 2
-i = 3

j = 4
-j = 5

k = 6
-k = 7
*/

const int MAXL = 40005;
char str[MAXL];
int A[MAXL],L,X;
int T[10][10],R[10][10];


int inv(int val){
	if(val%2 == 0) return val+1;
	return val-1;
}
void init(){
	for(int i=0;i<8;i++) T[0][i] = T[i][0] = i; // 16
	for(int i=0;i<8;i++) T[1][i] = T[i][1] = inv(i); // 28
	T[2][2] = T[3][3] = T[4][4] = T[5][5] = T[6][6] = T[7][7] = 1;	// 34
	T[2][3] = T[3][2] = T[4][5] = T[5][4] = T[6][7] = T[7][6] = 0; // 40
	T[2][4] = 6; T[4][2] = 7; T[3][4] = 7; T[4][3] = 6; T[2][5] = 7; T[5][2] = 6; T[3][5] = 6; T[5][3] = 7; // 48
	T[2][6] = 5; T[6][2] = 4; T[2][7] = 4; T[7][2] = 5; T[3][6] = 4; T[6][3] = 5; T[3][7] = 5; T[7][3] = 4; // 56
	T[4][6] = 2; T[6][4] = 3; T[4][7] = 3; T[7][4] = 2; T[5][6] = 3; T[6][5] = 2; T[5][7] = 2; T[7][5] = 3; // 64
}
int val(char ch){
	if(ch == 'i') return 2;
	else if(ch == 'j') return 4;
	else if(ch == 'k') return 6;
	assert(false);
}

int LL[MAXL],RR[MAXL];

vector <int> I1,I2,K1,K2;

void run(int test){
	scanf("%d %d",&L,&X);
	scanf("%s",&str[1]);

	bool answer = false;
	
	if(true){		
		for(int i=1;i<=L;i++) A[i] = val(str[i]);
		for(int i=L+1;i<=L*X;i++) A[i] = A[i-L];

		LL[0] = 0;
		RR[L*X+1] = 0;

		int len1=0,len2=0;
		bool have2=false,have3=false,have6=false,have7=false;
		for(int i=1;i<=L*X;i++){
			LL[i] = T[LL[i-1]][A[i]];
			if(LL[i] == 2) have2 = true,len1=len1>0?len1:i;
			if(LL[i] == 3) have3 = true,len1=len1>0?len1:i;
		}
		for(int i=L*X;i>=1;i--){
			RR[i] = T[A[i]][RR[i+1]];
			if(RR[i] == 6) have6 = true,len2=len2>0?len2:L*X-i+1;
			if(RR[i] == 7) have7 = true,len2=len2>0?len2:L*X-i+1;
		}

		int all = LL[L*X];
		assert(LL[L*X] == RR[1]);
		// printf("all = %d %d %d\n",all,have2,have6);
		if(all == 1 && (have2 || have3) && (have6||have7) && len1+len2 < L*X) printf("Case #%d: YES\n",test);
		// else if(all == 1 && have3 && have7) printf("Case #%d: YES\n",test);
		else printf("Case #%d: NO\n",test);	
	}
}

int main(){
	// freopen("C.txt","r",stdin);
	freopen("C-small-attempt6.in","r",stdin);
	freopen("C-small-attempt6.out","w",stdout);

	init();
	int T; scanf("%d",&T);
	for(int i=1;i<=T;i++) run(i);
	return 0;
}