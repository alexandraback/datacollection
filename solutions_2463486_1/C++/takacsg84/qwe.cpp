#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <list>
#include <map>
#include <queue>
#include <functional>
#include <memory>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <bitset>
#include <sstream>
#include <limits.h>

#define EPS (1e-9) 
#define PI (2 * acos(0.0)) 
#define XOR(exp1,exp2) ( ( (exp1)&&!(exp2) ) || (!(exp1) && (exp2)) ) 
#define REP(x,n)  for(int x=0;x<(int)(n);x++) 
#define FOR(x,y,n) for(int x=(int)y;x<(int)(n);x++) 
#define RREP(x,n) for(int x=(int)(n)-1;x>=0;--x) 
#define EACH(itr, cont) for(typeof((cont).begin()) itr = (cont).begin(); itr != (cont).end(); ++itr) 
#define ALL(X)    (X).begin(),(X).end() 
#define mem0(X)    memset((X),0,sizeof(X)) 
#define mem1(X)    memset((X),255,sizeof(X)) 

typedef long long LL;

template<class T> inline T & max(T&a, T&b) {
    return a > b ? a : b;
}
using namespace std;

LL allGood[] = {0, 1, 4, 9, 121, 484, 10201, 12321, 14641, 40804, 44944, 1002001, 1234321, 4008004, 100020001, 102030201, 104060401, 121242121, 123454321, 125686521, 400080004, 404090404, 10000200001, 10221412201, 12102420121, 12345654321, 40000800004, 1000002000001, 1002003002001, 1004006004001, 1020304030201, 1022325232201, 1024348434201, 1210024200121, 1212225222121, 1214428244121, 1232346432321, 1234567654321, 4000008000004, 4004009004004, 100000020000001, 100220141022001, 102012040210201, 102234363432201, 121000242000121, 121242363242121, 123212464212321, 123456787654321, 400000080000004, 10000000200000001, 10002000300020001, 10004000600040001, 10020210401202001, 10022212521222001, 10024214841242001, 10201020402010201, 10203040504030201, 10205060806050201, 10221432623412201, 10223454745432201, 12100002420000121, 12102202520220121, 12104402820440121, 12122232623222121, 12124434743442121, 12321024642012321, 12323244744232321, 12343456865434321, 12345678987654321};

LL dostuff() {
    LL result = 0, A, B;
    cin >> A >> B;
    REP(i, 100) if (allGood[i] >= A && allGood[i] <= B)result++;
    else if (allGood[i] > B)break;
    return result;
}

int main(int argc, char** argv) {
    int T;
    cin >> T;
    REP(t, T) cout << "Case #" << t + 1 << ": " << dostuff() << endl;
    return 0;
}