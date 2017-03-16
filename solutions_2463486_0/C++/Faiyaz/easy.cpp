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

vector <int> num;
vector <int> sq;
vector <int> nor;
void gen(){
    for(int i=1;i<=1000;i++){
        int sqr = i * i;
        sq.pb(sqr);
        nor.pb(i);
    }
    for(int i=0;i<sq.size();i++){
        stringstream ss,ss1;
        ss<<(sq[i]);
        ss1<<(nor[i]);
        string s , rev;
        ss>>s;
        rev= s;
        reverse(all(rev));
        int ok =1;
        if(rev != s){
            ok=0;
        }
        ss1>>s;
        rev= s;
        reverse(all(rev));

        if(rev != s){
            ok= 0;
        }

        if(ok){
            num.pb(sq[i]);
        }
    }
}

int main(){
    #if defined( faiyaz_pc )
        READ("C-small-attempt0.in");
        WRITE("c.txt");
    #endif
    gen();
    int t,chk=1,a,b;
    cin>>t;
    while(t--){
        cin>>a>>b;
        int cnt=0;
        for(int i=0;i<num.size();i++){
            if(num[i]>= a && num[i]<=b){
               // cout<<num[i]<<endl;
                cnt++;
            }
        }
        printf("Case #%d: %d\n",chk++,cnt);
    }
    return 0;
}
