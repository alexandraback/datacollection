#include <iostream>
#include <string>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <utility>
#include <algorithm>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <list>

#define FORST(X,S,T) for(int X=S; X<=T; X++)  
#define RFORST(X,S,T) for(int X=S; X>=T; X--)  
#define FOR(X,XB) for(int X=0; X<XB; X++)
#define RFOR(X,XB) for(int X=(XB)-1; X>=0; X--)
#define FORSTL(X,C) for(X=C.begin();X!=C.end();X++)
#define SQR(X) ((X)*(X))
#define MID(X,Y) (((X)+(Y))/2)
#define FILL(X,V) memset(X,V,sizeof(X))
#define FILE_R(X) freopen(X, "r", stdin)  
#define FILE_W(X) freopen(X, "w", stdout)  
#define MIN(X,Y) ((X)<(Y)?(X):(Y))
#define MAX(X,Y) ((X)>(Y)?(X):(Y))
#define ERREQ(X,Y) (fabs((X)-(Y))<EPS)
#define DBGL cout << "here" << endl;
#define SZ(X) sizeof(X)
const double PI = acos(-1.0);
const double EPS = 1E-9;
const int INF = (int)1E9;
typedef long long INT;
using namespace std;

#define MAXN 1005

int R, N, M, K;
int pro[MAXN];
struct ss{
	int x,y,z;
	int score;
	bool operator < (const ss &ano) const{
		return score < ano.score;
	}
};
priority_queue<ss> pq;


int x, y, z;
int save[5];
int hit[MAXN];
int L;

void solve(int k){
	if(k==4){
		int T = 100;
		int score = 0;
		while(T--){


			int p = 1;
			FOR(t, 3){
				if(rand()%2==0){
					p *= save[t];
				}
			}
			score += hit[p];
		}
		ss a;
		a.x =save[0];
		a.y = save[1];
		a.z = save[2];
		a.score = score;
		pq.push(a);
		return;

	}

	FORST(s, 2, M){
		save[k-1] = s;
		solve(k+1);
	}

}

bool must[10];

int main(){
	int cs;

	FILE_W("output");


	cin>>cs;
	srand(time(NULL));
	for(int csn=1;csn<=cs;csn++){
		printf("Case #%d:\n", csn);
		cin >> R >> N >> M >> K;
		FOR(ttt, R){

			while(!pq.empty()) pq.pop();
			FILL(must, 0);
			FILL(hit, 0);
			int cnt = 0;
			L = 0;
			FOR(i, K){
				cin >> pro[i];
				hit[pro[i]]++;
				if(pro[i]%3==0 && !must[3]) {
					must[3] = 1;
					cnt ++;
					save[L++] = 3;
				}else if(pro[i]%5==0 && !must[5]){
					must[5] = 1;
					cnt ++;
					save[L++] = 5;
				}else if(pro[i]%4==0 && !must[4]){
					must[4] = 1;
					cnt ++;
					save[L++] = 4;
				}
			}
			if(cnt==3){
				cout << "345" << endl;
				continue;
			}

			solve(cnt+1);

			ss a = pq.top();

			printf("%d%d%d\n",a.x,a.y,a.z);
		}
	}
	return 0;
}