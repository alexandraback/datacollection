#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define fornn(i, a, b) for (int i = (int)(a); i < (int)(b); ++i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<int>::iterator vi_it;
typedef vector<vi> vvi;

typedef long long i64;
typedef pair<i64, i64> pi64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
int testNumber;
long l,m,n;
int miss[21];

void cal(){
    miss[0]=0;
    miss[1]=0;
    for(int i=2;i<21;i++){
        int sho=(i-1)/2;
        int lon=i-1-sho;
        miss[i]=max(miss[lon],1+miss[sho]);
    }
}


int main(int argc, char* argv[]){
    time_t t0=time(NULL),t1;
    cin>>testNumber;
    cal();
    for(int iTest=0;iTest<testNumber;iTest++){
        long sum=0;
        cin>>m>>n>>l;
        sum+=(m)*(n/l);
        int num=sum+l-1+(n%l>0);
        cout<<"Case #"<<iTest+1<<": "<<num<<endl;
    }
    t1=time(NULL);
    cerr<<difftime(t1,t0)<<" sec elapse"<<endl;
    return 0;
}
