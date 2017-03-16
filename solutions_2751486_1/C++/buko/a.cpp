#include<cstdio>
#include<iostream>
#include<sstream>
#include<cmath>
#include<algorithm>
#include<map>
#include<set>
#include<list>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<iomanip>
#include<fstream>
#include<ctime>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair <int,int> ii;
typedef long long LL;
#define pb push_back
const int INF = 2147483647;
const int N = 1000005;

int tab[N],k,d,i,n,z,q,cons,last;
long long res;
char t[N];
string s;

int main() {
scanf("%d",&z);
for (q=1;q<=z;q++) {
    scanf("%s %d",t,&n);
    s = t;
    k = s.size();
    for (i=0;i<k;i++) tab[i+1] = 1 - (s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u');
    res = 0;
    cons = 0;
    last = 0;
    for (i=1;i<=k;i++) {
        if (tab[i]) cons++; else cons = 0;
        if (cons >= n) {
           res += (i-n+1);
           last = i-n+1;
        }
        else if (last != 0) res+=last;
        //cout << res << endl;
    }
    cout << "Case #" << q << ": " << res << endl;
}
return 0;
}
