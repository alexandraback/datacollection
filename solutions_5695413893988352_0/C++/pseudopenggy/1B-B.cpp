#include <algorithm>
#include <cmath>
#include <cctype>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>

#define FOR(i,a,b) for (int i = a; i <= b; i++)
#define FORN(i,N) for (int i = 0; i < N; i++)
#define FORD(i,a,b) for (int i = a; i >= b; i--)


using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
bool get(int x, char comp[200]) {
	char xStr[200];
	char fmt[200];
	sprintf(fmt,"%%0%dd",strlen(comp));
	//cout << fmt << endl;
	sprintf(xStr,fmt,x);
	if(strlen(xStr) != strlen(comp)) return false;
	FORN(i,strlen(comp)) {
		//cout << comp[i] << "" << xStr[i] <<endl;
		if(comp[i] != '?' && comp[i]!=xStr[i]) return false;
	}
	return true;
}
int main() {

	int T;
	char C[200];
	char J[200];
	scanf("%d",&T);
	FOR(i,1,T) {
	scanf("%s",C);
	scanf("%s",J);
	int len = strlen(C);
	char fmt[200];
	sprintf(fmt,"%%0%dd",len);
	int limit = (int)pow(10,len);
	int minVal = limit;
	int minC = limit;
	int minJ = limit;
	FORN(c,limit) {
		if(get(c,C))
		FORN(j,limit) {
			if(get(j,J)) {
				if(abs(c-j) < minVal) {
					minC = c;
					minJ = j;
					minVal = abs(c-j);
				//	cout << minC << " " << minJ << endl;
				}
				else if(abs(c-j) == minVal){
					if(c < minC) {
						minC = c;
						minJ = j;
				//		cout << minC << " " << minJ << endl;
					}
					else if(c == minC){
						if(j < minJ) {
							minC = c;
							minJ = j;
				//			cout << minC << " " << minJ << endl;
						}
					}
				}
			}
		}
	}
	cout << "Case #" << i <<": ";
	printf(fmt,minC);
	printf(" ");
	printf(fmt,minJ);
	cout << endl;

	//LOL WORSE CODE EVER
	}
	return 0;
}
