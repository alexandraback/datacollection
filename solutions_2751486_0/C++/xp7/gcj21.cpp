/* Paras Narang */
#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <list>
#include <deque>
#include <bitset>
#include <cmath>
#include <set>
#include <sstream>

using namespace std;

#define oo 0x7F7F7F7F
#define LET(x,a)     __typeof(a) x(a)
#define EACH(it,v)   for(LET(it,v.begin());it!=v.end();++it)
#define REP(i,n)     for(__typeof(n) i(0); i<n; i++)
#define ALL(x)       (x).begin(), (x).end()
#define gint(t)      scanf("%d", &t);
#define pint(t)      printf("%d\n", t);
#define pb           push_back
#define mp           make_pair

typedef long long int   ll;
typedef unsigned long long int ull;
typedef unsigned int    uint;
typedef pair<int, int>  pii;
typedef vector<int>     vi;
typedef vector<vi>      vii;
typedef vector<pii>     vpii;

int main(){
    int t; gint(t);
    REP(ti, t){
        ll res=0, n=0;
        string str; cin >> str >> n;
        ll len = str.length(), ctr=0;
        for(int i=0; i<len; i++){
            for(int j=i; j<len; j++){
                ctr = 0;
                for(int k=i; k<=j; k++){
                    ctr++;
                    if(str[k]=='a' || str[k]=='e' || str[k]=='i' || str[k]=='o' || str[k]=='u' )
                        ctr = 0;
                    if(ctr>=n){ 
                      //cout << " @@ " << str[k] << k << " " << ctr << " " << i << " " << j << endl;
                      res++; ctr=0; break;}
                }
            }
        }
        printf("Case #%d: %lld\n", ti+1, res);
    }
    return 0;
}
