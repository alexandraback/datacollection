#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<string>
#include<math.h>
#include <algorithm>

using namespace std;

#define LL long long
#define LD long double
#define FM(i,a,b) for(int i=a;i<b;i++) //(b-a) times a ~ b-1
#define P_T "B"
#define I_T "small-attempt1"
#define FILE_OPEN() char name1[50],name2[50];\
sprintf(name1, "%s-%s.in", P_T,I_T );\
sprintf(name2,"%s-%s.out" , P_T,I_T );\
freopen(name1,"r", stdin);freopen(name2, "w" ,stdout) // open file

#define D_INPUT_A(x) int x;scanf( "%d",&x)
#define D_INPUT_B(x,y) int x;int y;scanf( "%d%d",&x,&y)
#define D_INPUT_C(x,y,z) int x;int y;int z;scanf( "%d%d%d",&x,&y,&z)
#define INPUT_A(x) scanf("%d",&x)
#define INPUT_B(x,y) scanf("%d%d",&x,&y)
#define INPUT_C(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define INPUT_STR(x) scanf("%s",x)
#define OUTPUT(x) printf("Case #%d: %d\n",n+1,x)
#define OUTPUT_B(x,y) printf("Case #%d: %d %d\n",n+1,x,y)
#define OUTPUT_STR(x) printf("Case #%d: %s\n",n+1,x)
#define MAX(a,b) (((a)>(b))?(a):(b))
#define MIN(a,b) (((a)<(b))?(a):(b))

const LD EPS = 1e-10;
const LD PI = acos(-1.0);

LL binary[49];

int B;
LL  M;
bool answer[52];

void get_answer() {
	for (int i = B - 2; i >= 0; --i) {
		if (binary[i] <= M) {
			answer[i] = true;
			M -= binary[i];
		}
	}
}

int main() {
	FILE_OPEN();
	
	binary[0] = 1;
	binary[1] = 1;
	FM(i, 2, 49) binary[i] = 2 * binary[i - 1];

	D_INPUT_A(T);
	FM(n, 0, T) {
		memset(answer, 0, sizeof(answer));
		scanf("%d %lld", &B, &M);
		if (M > binary[B - 1]) OUTPUT_STR("IMPOSSIBLE");
		else {
			OUTPUT_STR("POSSIBLE");
			get_answer();
			FM(i, 0, B) {
				FM(j, 0, B - 1) {
					if (j > i) printf("1");
					else printf("0");
				}
				if (answer[i])
					printf("1\n");
				else
					printf("0\n");
			}
		}
	}
	return 0;
}
