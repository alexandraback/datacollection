#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <math.h>
#define MAX_N 20005
#define MAX_Q 100005
#define MAX_M 200005
#define MAXK 100000
#define MAX_V 50005
#define MAX_E 100005
#define MAX_K 10005
#define MAX_X 15
#define MAX_Y 15
#define inf 1000005
using namespace::std;
typedef long long ll;
int N;
vector<string> C;
string s;
bool check(char p){
    int start=s.find(p),end=s.rfind(p);
    for (int i=start+1; i<end; i++) {
        if (s[i]!=p) {
            return false;
        }
    }
    return true;
}
void solve(){
    vector<int> index;
    for (int i=0; i<N; i++) {
        index.push_back(i);
    }
    int ans=0;
    do{
        s="";
        for (int i=0; i<N; i++) {
            s+=C[index[i]];
        }
        char p;
        for (p='a'; p<='z'; p++) {
            if (!check(p)) {
                break;
            }
        }
        if (p=='z'+1) {
            ans++;
        }
    }while (next_permutation(index.begin(), index.end()));
    cout<<ans<<endl;
}
int main()
{
	freopen("/Users/mascure/Desktop/B-small-attempt1.in", "r", stdin);
	freopen("/Users/mascure/Desktop/B-small-attempt1.out", "w", stdout);
    int caseN;
    cin>>caseN;
    for (int i=1; i<=caseN; i++) {
        cin>>N;
        C.clear();
        C.resize(N);
        for (int j=0; j<N; j++) {
            cin>>C[j];
        }
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}
