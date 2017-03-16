/*
Bismillahir Rahmanir Rahim
Coder: Ahmad Faiyaz
Problem: CodeJam Qualification 2013
*/

#include <algorithm>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include <fstream>

# define FOR(i, a, b) for (int i=a; i<b; i++)
# define REP(i, a) FOR(i,0,a)

#define EPS 1e-11
#define inf 1234567891
#define LL long long

#define abs(x) (((x)< 0) ? (-(x)) : (x))
#define all(x) (x).begin(), (x).end()
#define ms(x, a) memset((x), (a), sizeof(x))

#define pb push_back

#define READ(f) {ifstream infile(f) ;if(infile.good()) freopen(f, "r", stdin);}
#define WRITE(f) freopen(f, "w", stdout)
using namespace std;

LL num [39]={1LL ,4LL ,9LL ,121LL ,484LL ,10201LL ,12321LL ,14641LL ,40804LL ,44944LL ,1002001LL ,1234321LL ,4008004LL ,100020001LL ,102030201LL ,104060401LL ,121242121LL ,123454321LL ,125686521LL ,400080004LL ,404090404LL ,10000200001LL ,10221412201LL ,12102420121LL ,12345654321LL ,40000800004LL ,1000002000001LL ,1002003002001LL ,1004006004001LL ,1020304030201LL ,1022325232201LL ,1024348434201LL ,1210024200121LL ,1212225222121LL ,1214428244121LL ,1232346432321LL ,1234567654321LL ,4000008000004LL ,4004009004004LL};


int main(){
    #if defined( faiyaz_pc )
        READ("C-large-1.in");
        WRITE("cL.txt");
    #endif
   // gen();
    int t,chk=1;
    LL a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int cnt=0;
        for(int i=0;i<39;i++){
            if(num[i]>= a && num[i]<=b){
                cnt++;
            }
        }
        printf("Case #%d: %d\n",chk++,cnt);
    }
    return 0;
}
