#pragma comment(linker, "/STACK:1024000000,1024000000")  
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <cctype>
#include <cstdio>
#include <string>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;
template<class T> T gcd(T x,T y){while(T t=x%y)x=y,y=t;return y;}
const double eps = 1e-9;
const double PI = acos(-1.);
const int INF = 1000000000;
const int MOD = 1000000007;
const double E = 2.7182818284590452353602874713527;

#define pmul(x1,y1,x2,y2) ((x1)*(x2)+(y1)*(y2))
#define xmul(x1,y1,x2,y2) ((x1)*(y2)-(x2)*(y1))
#define sqr(x) ((x)*(x))

#define FR(i,N) for(int i=0;i<N;i++)
#define FRS(i,S,E) for(int i=S;i<=E;i++)
#define FRD(i,S,E) for(int i=S;i>=E;i--)
#define SZ(x) ((int)(x).size())
#define fill(a,b) memset(a,b,sizeof(a))
#define PII pair<int,int>
#define MP(a,b) make_pair(a,b)
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()
#define PB push_back
#define lowbit(x) ((x)&(-(x)))

bool isdig(char x){return x>='0'&&x<='9';}
bool isup(char x){return x>='A'&&x<='Z';}
bool isdown(char x){return x>='a'&&x<='z';}
bool islet(char x){return isup(x)||isdown(x);}

//--------CODE----------
int R, C, M;
void get_data(){
	scanf("%d%d%d", &R, &C, &M);
}
int draw[55][55];
void run(){
	bool error = false;
	FR(i, R)FR(j, C)draw[i][j] = 2;

	int left = R*C - M;
	if(M == 0){
		FR(i, R)FR(j, C)draw[i][j] = 0;
	}else if(left == 1){
	
	}else if(R == 1){
		FR(i, left - 1)draw[0][i] = 0;
	}else if(C == 1){
		FR(i, left - 1)draw[i][0] = 0;
	}else if(R == 2){
		if(left & 1 || left == 2)error = true;
		else{
			FR(i, left/2 - 1)draw[0][i] = 0;
		}
	}else if(C == 2){
		if(left & 1 || left == 2)error = true;
		else{
			FR(i, left/2 - 1)draw[i][0] = 0;
		}
	}else{
		if(left == 1){}
		else if(left <= 3)error = true;
		else if(left == 4)draw[0][0] = 0;
		else if(left == 5)error = true;
		else if(left == 6){
			if(R == 2){
				draw[0][0] = draw[0][1] = 0;
			}else{
				draw[0][0] = draw[1][0] = 0;
			}
		}
		else if(left == 7)error = true;
		else if(left == 8){
			draw[0][0] = draw[0][1] = draw[1][0] = 0;
		}else{
			draw[0][0] = draw[0][1] = draw[1][0] = 0;
			int inic = 2, inir = 2;
			int secr = 1, secc = 1;
			int now = 8;
			while(now < left){
				
				if(inic < C - 1){
					if(left - now == 1){
						draw[1][1] = 0;
						break;
					}
					draw[0][inic++] = 0;
					now += 2;
				}else if(inir < R - 1){
					if(left - now == 1){
						draw[1][1] = 0;
						break;
					}
					draw[inir++][0] = 0;
					now += 2;
				}else{
					draw[secr][secc++] = 0;
					if(secc == C - 1){
						secc = 1;
						secr++;
					}
					now++;
				}
				
			}
		}
	}
	if(error){
		printf("Impossible\n");
		return;
	}
	
	FR(i, R)FR(j, C){
		if(draw[i][j] != 0)continue;
		FR(ii, 3)FR(jj, 3){
			int iii = i - 1 + ii;
			int jjj = j - 1 + jj;
			if(iii < 0 || iii >= R || jjj < 0 || jjj >= C)continue;
			if(draw[iii][jjj] != 0)draw[iii][jjj] = 1;
		}
	}
	FR(i, R){
		FR(j, C){
			if(i == 0 && j == 0)printf("c");
			else{
				if(draw[i][j] != 2)printf(".");
				else printf("*");
			}
		}
		printf("\n");
	}
}
int main(){
//	get_prime();
	freopen("C-large.in","r",stdin);
	freopen("C-large.out","w",stdout);
	int t;
	scanf("%d", &t);
	FR(i, t)
	{
	get_data();
	printf("Case #%d:\n", i + 1);
	run();
	}
	return 0;
}
