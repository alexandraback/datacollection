#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define abs(X) ((X)<0?-(X):(X))
#define rst(X) memset(X,0,sizeof(X))
#define pb push_back
#define mp make_pair
#define sz(X) ((int)X.size())
#define ff first
#define ss second

int N, X, Y;
int maxH;
#define MAX_D 400
int FIELD[MAX_D*2][MAX_D];
double P[MAX_D*2][MAX_D];
void foo(int dn, int x, int y, double p){
	//~ cout<<dn<<", "<<x<<" - "<<y<<" p= "<<p<<endl;
	if (dn==N)
		return;
	if (y==0){//Buried
		P[x+MAX_D][y]+=p;
		int oldMaxH = maxH;
		if (x==0 && y==maxH) maxH += 2;
		FIELD[x+MAX_D][y] = 1;
		if (x!=X || y!=Y) foo(dn+1, 0, maxH, p);
		FIELD[x+MAX_D][y] = 0;
		maxH = oldMaxH;
		return;
	}
	if (FIELD[x-1+MAX_D][y-1] && FIELD[x+1+MAX_D][y-1]){//Down blocked
		P[x+MAX_D][y]+=p;
		int oldMaxH = maxH;
		if (x==0 && y==maxH) maxH += 2;
		FIELD[x+MAX_D][y] = 1;
		if (x!=X || y!=Y) foo(dn+1, 0, maxH, p);
		FIELD[x+MAX_D][y] = 0;
		maxH = oldMaxH;
		return;
	} else if (FIELD[x-1+MAX_D][y-1]){//Slide to the right
		return foo(dn,x+1,y-1,p);
	} else if (FIELD[x+1+MAX_D][y-1]){//Slide to the left
		return foo(dn,x-1,y-1,p);
	} else if (FIELD[x+MAX_D][y-2]){//Choice
		foo(dn,x-1,y-1,p*0.5);
		foo(dn,x+1,y-1,p*0.5);
		return;
	}
	return foo(dn, x, y-1, p);
}
int main(){
	freopen("B.in","r",stdin);
	freopen("B.out","w",stdout);
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++){
		scanf("%d%d%d", &N, &X, &Y);
		rst(FIELD); rst(P);
		if (X+MAX_D>=0 && X<MAX_D && Y<MAX_D){
			maxH = 0;
			foo(0,0,maxH,1.0);
			printf("Case #%d: %.9lf\n", t+1, P[X+MAX_D][Y]);
		} else
			printf("Case #%d: 0\n", t+1);
	}
	return 0;
}
