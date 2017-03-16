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
#define P_T "C"
#define I_T "small-attempt0"
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

int J, P, S, K;
int JP[11][11];
int PS[11][11];
int JS[11][11];

int answer[1000][3];
int sum;

void get_answer() {
	FM(x, 1, J + 1) {
		FM(y, 1, P + 1) {
			FM(z, 1, S + 1) {
				if (JP[x][y] >= K || PS[y][z] >= K || JS[x][z] >= K)
					continue;
				else {
					answer[sum][0] = x;
					answer[sum][1] = y;
					answer[sum][2] = z;
					++JP[x][y];
					++PS[y][z];
					++JS[x][z];
					sum++;
				}
			}
		}
	}
}
int main() {
	FILE_OPEN();

	D_INPUT_A(T);
	FM(n, 0, T) {
		memset(JP, 0, sizeof(JP));
		memset(PS, 0, sizeof(PS));
		memset(JS, 0, sizeof(JS));
		//
		INPUT_C(J, P, S); INPUT_A(K);
		//
		sum = 0;
		get_answer();
		OUTPUT(sum);
		FM(i, 0, sum) {
			printf("%d %d %d\n", answer[i][0], answer[i][1], answer[i][2]);
		}
	}
	return 0;
}
