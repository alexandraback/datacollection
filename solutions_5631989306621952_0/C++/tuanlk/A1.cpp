#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<queue>
using namespace std;

typedef pair<int,int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;

#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define DFOR(i,a,b) for(int i=a;i>=b;i--)
#define mp(x,y) make_pair((int)x,(int)y)
#define fi first
#define se second
#define all(a) (a).begin(),(a).end()
#define BUG(x) {cout << #x << " = " << x << endl;}
#define PR(x,a,b) {cout << #x << " = "; FOR(i,a,b) cout << x[i] << ' '; cout << endl;}
#define ll long long
#define DEBUG 1

int main(){
    if (DEBUG==1){
        freopen("A1.in","r",stdin);
        freopen("output.txt","w",stdout);
    }
    int test;
    cin>>test;
    string s;
    getline(cin,s);
    char a[3000];
    int middle=1500;
    int lo,hi;
    int n;
    FOR(t,1,test){
        getline(cin,s);
        n=s.length();
        lo=hi=middle;
        a[lo]=s[0];
        FOR(i,1,n-1){
            if (s[i]>=a[lo]){
                lo--;
                a[lo]=s[i];
            }else{
                hi++;
                a[hi]=s[i];
            }
        }
        cout<<"Case #"<<t<<": ";
        FOR(i,lo,hi) cout<<a[i];
        if (t<test) cout<<endl;
    }
    return 0;
}
/*
7
CAB
JAM
CODE
ABAAB
CABCBBABC
ABCABCABC
ZXCASDQWE
*/
