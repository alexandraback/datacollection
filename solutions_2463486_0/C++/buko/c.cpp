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

vector <long long> wek;
int i,tab[14],d,z,q,res;
LL a,b;

bool pal (long long a) {
     d=0;
     while (a>0) {
           tab[d++] = a%10;
           a/=10;
     }
     for (int j=0;j<d/2;j++) if (tab[j]!=tab[d-1-j]) return false;
     return true;
}

int main() {
wek.resize(0);
for (i=1;i<=9999999;i++) if (pal(i*1LL) && pal(i*1LL*i)) {
    wek.pb(i*1LL*i);
    //cout << i*1LL*i << endl;
}
scanf("%d",&z);
for (q=1;q<=z;q++) {
    cin >> a >> b;
    res = 0;
    for (i=0;i<wek.size();i++) if (wek[i] >= a && wek[i] <= b) res++;
    printf("Case #%d: %d\n",q,res);
}
return 0;
}
