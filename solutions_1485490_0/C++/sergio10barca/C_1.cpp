#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <set>
#include <stack>
#include <deque>
#include <queue>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <cstdio>
#define x first
#define y second
#define IN(x, n) (0 <= (x) && (x) < n)
#define MAX 2010
#define MOD 1000000007
#define EPS 0.0001
#define INF 9223372036854775807LL
using namespace std;

typedef long long int entero;
typedef pair<entero, int> Point;
typedef pair<pair<char, char>, pair<entero, entero> > SPP;

map<SPP, entero> dp;
map<SPP, entero>::iterator it;
vector<Point> box, toy;
int N, M;

entero rec(char bi, char ti, entero A, entero B){
	SPP aux;
	aux.x.x = bi, aux.x.y = ti, aux.y.x = A, aux.y.y = B;
//	cout << "bi = " << bi << " ti = " << ti << endl;
	if((it = dp.find(aux))==dp.end()){		
		if(bi == N || ti == M)
			return 0;
		entero mejor = 0;		
//		cout << "\t\tcbi = " << box[bi].x << " cti = " << toy[ti].x << endl;
		mejor = rec(bi+1, ti, box[bi+1].x, B);		
		//busco juguetes
		if(box[bi].y == toy[ti].y){
			if(A < B)
				mejor = max(mejor, rec(bi+1, ti, box[bi+1].x, B-A)+A);
			else
				mejor = max(rec(bi, ti+1, A-B, toy[ti+1].x)+B, mejor);
		}
		else
			mejor = max(mejor, rec(bi, ti+1, A, toy[ti+1].x));
		return dp[aux] = mejor;
	}
	return (*it).y;	//*/
}

int main(){
	int i, j, k, T, resta;
	set<int> q;
	entero a;
	Point ins;
    cin >> T;
    for(k = 1; k <= T; k++){
		cin >> N >> M;
		resta = 0;
		for(i = 0; i < N; i++){
			cin >> ins.x >> ins.y;
			q.insert(ins.y);
			box.push_back(ins);
		}
		ins.x = 0, ins.y = 0;
		box.push_back(ins);
		for(i = 0; i < M; i++){
			cin >> ins.x >> ins.y;
			if(q.find(ins.y)!=q.end())
				toy.push_back(ins);
			else
				resta++;
		}
		M-=resta;
		ins.x = 0, ins.y = 0;
		toy.push_back(ins);
		a = rec(0, 0, box[0].x, toy[0].x);
		printf("Case #%d: ", k);
		cout << a << endl;
		box.clear();
		toy.clear();
		dp.clear();
		q.clear();
    }
    return 0;
}
