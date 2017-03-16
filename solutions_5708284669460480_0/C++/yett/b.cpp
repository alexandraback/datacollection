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
int cnt[26];
string alpha,target;

int findP(string &s){
    for(int i=1;i<s.length();i++){
        bool match=true;
        for(int j=0;j+i<s.length();j++){
            if(s[j]!=s[i+j]){
                match=false;
                break;
            }
        }
        if(match){
            return i;
        }
    }
    return s.length();
}
void count(string &s){
    memset(cnt,0,sizeof(cnt));
    for(int i=0;i<s.length();i++){
        cnt[s[i]-'A']++;
    }
}
double prob(char c){
    return double(cnt[c-'A'])/l;
}
double expect(int u){
    double p=1;
    for(int i=0;i<m;i++){
        p*=prob(target[i]);
    }
    cerr<<"p"<<p<<endl;
    double expt[n+1];
    for(int i=0;i<m-1;i++)expt[i]=0;
    for(int i=m;i<=n;i++){
        expt[i]=expt[i-1]+p;     
    }
    return expt[n];
}


int main(int argc, char* argv[]){
    time_t t0=time(NULL),t1;
    cin>>testNumber;
    for(int iTest=0;iTest<testNumber;iTest++){
        cin>>l>>m>>n;
        cin>>alpha>>target;
        int u=findP(target);
        int taken=(n-(m-u))/u;
        count(alpha);
        for(int i=0;i<target.length();i++){
            if(prob(target[i])==0){
                taken=0;break;
            }
        }
        double ins;
        if(taken!=0)
        ins=expect(u);
        else
            ins=0;
        cerr<<"taken"<<taken<<endl;
        cerr<<"ins"<<ins<<endl;
        cout<<fixed<<setprecision(7)<<"Case #"<<iTest+1<<": "<<taken-ins<<endl;
    }
    t1=time(NULL);
    cerr<<difftime(t1,t0)<<" sec elapse"<<endl;
    return 0;
}
