/*	SURENDRA KUMAR MEENA	*/
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <queue>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define FF(i,m,n)	for(int i=m;i<n;i++)
#define F(i,n)	FF(i,0,n)

int ar[102][102];
int r,c;
int dr[4] = {1,-1,0,0};
int dc[4] = {0,0,1,-1};

bool isFine(int i,int j,int x,int y) {
    int val = ar[i][j];
    int i2=i;
    int j2=j;
    while(i2+x>=0 && i2+x<r && j2+y>=0 && j2+y<c) {
        i2+=x; j2+=y;
        if(ar[i2][j2] > val) {
            return false;
        }
    }
    return true;
}

bool isPossible() {
    F(i,r) F(j,c) {
        if(!((isFine(i,j,1,0) && isFine(i,j,-1,0)) || (isFine(i,j,0,1) && isFine(i,j,0,-1))))
            return false;
    }
    return true;
}

int main(){
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<": ";
        cin>>r>>c;
        F(i,r) F(j,c)   cin>>ar[i][j];
        if(isPossible()) cout<<"YES\n";
        else             cout<<"NO\n";
    }
    return 0;
}
