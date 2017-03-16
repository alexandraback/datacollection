#include<iostream>
#include <stdlib.h>
#include<list>
#include<string>
#include<cstring>
#include<sstream>
#include<cctype>
#include<string.h>
#include<algorithm>
#include<cmath>
#include<stack>
#include<fstream>
#include<cstdlib>
#include<vector>
#include<map>
#include<set>
#include<utility>
#include<iomanip>
#include<queue>

using namespace std;

#define INF (1<<29)
#define SET(a) memset(a,-1,sizeof(a))
#define ALL(a) a.begin(),a.end()
#define CLR(a) memset(a,0,sizeof(a))
#define FILL(a,v) memset(a,v,sizeof(a))
#define PB push_back
#define FOR(i,n) for(int i = 0;i<n;i++)
#define PI acos(-1.0)
#define EPS 1e-9
#define MP(a,b) make_pair(a,b)
#define min3(a,b,c) min(a,min(b,c))
#define mai3(a,b,c) mai(a,mai(b,c))
#define READ freopen("input.tit", "r", stdin)
#define WRITE freopen("output.tit", "w", stdout)
#define LL long long
#define MX 100000000000014

#define F first
#define S second
#define pii pair<int,int>
#define p(i) printf("%d",i)
#define inp(i) scanf("%d",&i)
#define inpll(i) scanf("%lld",&i)
#define getci getchar_unlocked
/*inline void inp( int &n )
 {
 n=0;
 int ch=getci();int sign=1;
 while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getci();}
 
 while(  ch >= '0' && ch <= '9' )
 n = (n<<3)+(n<<1) + ch-'0', ch=getci();
 n=n*sign;
 }*/

using namespace std;
int c,d,v,n;
bool a[1001];
vector<int> numbers;
set<int> denomi;
set<int>::iterator it;

void markReached(int idx, int num){
    if(idx>=n || num > v)
        return;
    a[num+numbers[idx]] = 1;
    markReached(idx+1, num + numbers[idx]);
    markReached(idx+1, num);
}
void canReach(){
    CLR(a);
    n = denomi.size();
    markReached(0,0);
}

bool isAllReached(){
    for(int i=1;i<=v;i++)
        if(!a[i]) return false;
    return true;
}

int firstUnreached(){
    for(int i=1;i<=v;i++)
        if(!a[i]) return i;
    return -1;
}

int getMinNumber(){
    int result = 0;
    while(!isAllReached()){
        canReach();
        int idx = firstUnreached();
        if(idx != -1){
            denomi.insert(idx);
            numbers.PB(idx);
            result++;
        }
    }
    return result;
}

int main(){
    int t;
    cin>>t;
    for(int i=0;i<t;i++){
        cin>>c>>d>>v;
        denomi.clear();
        numbers.clear();
        CLR(a);
        for(int j=0;j<d;j++){
            cin>>n;
            denomi.insert(n);
            numbers.PB(n);
        }
//        for(it=denomi.begin(); it!=denomi.end(); ++it)
//            cout << ' ' << *it;
        int number = getMinNumber();
        cout<<"Case #"<<i+1<<": "<<number<<endl;
    }
    return 0;
}