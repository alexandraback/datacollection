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

#define all(x) (x).begin(),(x).end()
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define dbg(args...) {debug,args; cerr << endl;}

#define mp make_pair
#define mt(a,b,c) mp(a,mp(b,c))
#define P1(a) (a).first
#define P2(a) (a).second
#define T1(a) (a).first
#define T2(a) (a).second.first
#define T3(a) (a).second.second
#define INF 1e20
#define EPS 1e-8

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> tiii;

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

void solve(int testnr){
    int R, C, M;
    cin >> R >> C >> M;
    int m = R * C - M;
    int n = min(R,C);
    if (m==1){
        for (int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if (i==0 and j==0) cout << "c";
                else cout << "*";
            }
            cout << "\n";
        }
        return;
    }
    if (n==1){
        int count=0;
        for (int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if (i==0 and j==0) {
                    cout << "c";
                    count++;
                }
                else {
                    if (count < m){
                        count++;
                        cout << ".";
                    }else{
                        cout << "*";
                    }
                }
            }
            cout << "\n";
        }
        return;
    }
    if (m<=3 or m==5 or m==7 or (n==2 and m%2==1)){
        cout << "Impossible\n";
        return;
    }
    if (R==2) {
        for (int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if (i==0 && j==0) {
                    cout << "c";
                }
                else {
                    if ((j+1) * 2 <= m){
                        cout << ".";
                    }else{
                        cout << "*";
                    }
                }
            }
            cout << "\n";
        }
        return;
    }
    if (C==2) {
        for (int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if (i==0 && j==0) {
                    cout << "c";
                }
                else {
                    if ((i+1) * 2 <= m){
                        cout << ".";
                    }else{
                        cout << "*";
                    }
                }
            }
            cout << "\n";
        }
        return;
    }
    int x = 0, y = 0, r1 = 0, r2 = 0;
    
    if (m % 2 == 0 and m <= 2*C){
        x = m/2;
        y = 2;
    } else if (m%2 == 1 and m-3 <= 2*C){
        r1 = 3;
        x = (m-3)/2;
        y = 2;        
    } else {
        x = C;
        y = m/C;
        r1 = m - x*y;
        if (r1 == 1){
            y--;
            r1 = C-1;
            r2 = 2;
        }
    }    
    for (int i=0;i<R;i++){
        for(int j=0;j<C;j++){
            if (i==0 && j==0) {
                cout << "c";
            }
            else {
                if ((i < y and j < x) or (i == y and j < r1) or (i == y+1 and j < r2)){
                    cout << ".";
                }else{
                    cout << "*";
                }
            }
        }
        cout << "\n";
    }
    return;
}

int main(){

    init();
    
    int T;
    cin >> T;
    for(int i=1;i<=T;i++){
        cout << "Case #" << i << ":\n";
        solve(i);
    }
    
    return 0;
}
