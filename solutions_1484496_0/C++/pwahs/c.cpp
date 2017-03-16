#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define all(x) ((x).begin(),(x).end())
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

class debu{
	public:
	template<class someClass>
	debu & operator,(someClass arg){
		cerr << arg << " ";
		return *this;
	}
} debug;


void init(){
    cout << setprecision(8)<< fixed;
}

typedef long long ll;

void solve(int testnr){
    int N;
    cin >> N;
    vector<ll> a(N);
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    
    int f=0;
    map<ll,ll> m[2];
    m[f][0]=0;
    for(int i=0;i<N;i++){
        m[f^1].clear();
        for(map<ll,ll>::iterator it=m[f].begin();it!=m[f].end();it++){
            if (m[f].find((*it).first+a[i])!=m[f].end()){
                //found
                
                set<ll> s1,s2;
                s1.insert(a[i]);
                int p1=(*it).first,p2=(*it).first+a[i];
                while (p1!=0) {
                    s1.insert(m[f][p1]);
                    p1-=m[f][p1];
                }
                while (p2!=0) {
                    s2.insert(m[f][p2]);
                    p2-=m[f][p2];
                }
                bool first=true;
                for(set<ll>::iterator it1=s1.begin();it1!=s1.end();it1++){
                    if (s2.find(*it1)==s2.end()){
                        if (first) cout << *it1;
                          else cout << " " << *it1;
                        first=false;
                    }
                }
                cout << "\n";
                first=true;
                for(set<ll>::iterator it1=s2.begin();it1!=s2.end();it1++){
                    if (s1.find(*it1)==s1.end()){
                        if (first) cout << *it1;
                          else cout << " " << *it1;
                        first=false;
                    }
                }
                return;
                
            }else{
                m[f^1][(*it).first]=m[f][(*it).first];
                m[f^1][(*it).first+a[i]]=a[i];
            }
        }
        
        f^=1;
    }
    cout << "Impossible";
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ":\n";
        solve(i); 
        cout << "\n";
    }
    
    return 0;
}
