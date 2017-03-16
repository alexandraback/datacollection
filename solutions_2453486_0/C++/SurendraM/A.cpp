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

string inp[4];

bool isValid(int& x,int& y) {
    return (x>=0 && y>=0 && x<4 && y<4);
}

bool isFull(int x,int y,int i,int j,char ch) {
    while(isValid(x,y)) {
        if(inp[x][y]!='T' && inp[x][y]!=ch) return false;
        x += i; y += j;
    }
    return true;
}

int getResult() {
    bool xWon=false, oWon=false;
    
    F(i,4) {
        xWon |= isFull(i,0,0,1,'X');
        xWon |= isFull(0,i,1,0,'X');
    }
    xWon |= isFull(0,0,1,1,'X');
    xWon |= isFull(0,3,1,-1,'X');
    
    F(i,4) {
        oWon |= isFull(i,0,0,1,'O');
        oWon |= isFull(0,i,1,0,'O');
    }
    oWon |= isFull(0,0,1,1,'O');
    oWon |= isFull(0,3,1,-1,'O');
    
    if(xWon && oWon)    return 0;
    if(xWon)            return 1;
    if(oWon)            return 2;
    F(i,4) F(j,4)   if(inp[i][j]=='.')  return 3;
    return 0;
}

int main(){
    int t;
    cin>>t;
    FF(kase,1,t+1){
        cout<<"Case #"<<kase<<": ";
        F(i,4)  cin>>inp[i];
        int res = getResult();
        if(res==0)      cout<<"Draw\n";
        else if(res==1) cout<<"X won\n";
        else if(res==2) cout<<"O won\n";
        else cout<<"Game has not completed\n";
    }
    return 0;
}
