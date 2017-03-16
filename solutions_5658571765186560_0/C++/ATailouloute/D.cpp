/*
 * author ATailouloute
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <stack>
#include <climits>
#include <deque>

using namespace std;

#define F(i,L,R)   for(int i=L; i<R;  i++)
#define FE(i,L,R)  for(int i=L; i<=R; i++)
#define FF(i,L,R)  for(int i=L; i>R;  i--)
#define FFE(i,L,R) for(int i=L; i>=R; i--)
#define DBG(vari) cerr<<#vari<<" = "<<(vari)<<endl;
#define ll long long

bool isOk(int x, int r, int c){
    if(x == 1) return true;
    if(((r*c)%2==0) && x==2 &&(r>=2 || c>=2)) return true;
    if((x==3)&&((r*c)%3==0)&&(r>=3||c>=3)&&(r>1&&c>1)) return true;
    if((x==4)&&((r*c)%4==0)&&(r>=4||c>=4)&&(r>2&&c>2)) return true;
    return false;
}

int main() {
    
    int T, X, R, C;
    scanf("%d", &T);
    
    FE(caseID, 1, T){
        scanf("%d %d %d", &X, &R, &C);
        bool ok = isOk(X, R, C);
        printf("Case #%d: %s\n", caseID, ok ? "GABRIEL" : "RICHARD");
    }
    
	return 0;
}
