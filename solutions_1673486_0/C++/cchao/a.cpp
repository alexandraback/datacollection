#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <list>
using namespace std;
#define PB push_back
#define MP make_pair
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);++i)
#define REPE(i,n) FORE(i,0,n)
#define FORSZ(i,a,v) FOR(i,a,SZ(v))
#define REPSZ(i,v) REP(i,SZ(v))
#define PCS cout << "Case #" << i << ": "
typedef long long ll;
//int right[100000]={0};
int type,total;
int main(){
    int tt;
    cin >> tt;
    scanf("\n");
    FORE(i,1,tt){
        cin >> type >> total;
        double poss[100000]={0};
        double best=total+2;
        for(int k=0;k<type;k++) cin >> poss[k];
        //case 1;
        double ca,p=1;
//        for(int k=0;k<type;k++){
//            p*=poss[k];
//        }
//        ca=p*(total-type+1) + (1-p)*(2*total-type+2);
        ca = type + total +1;
        if(ca<best) best=ca;
        //double cn[100000];
        //cout << ' ' << ca << endl;
        for(int k=0;k<type;k++){
            p=1;
            for(int j=0;j<=k;j++){
                p*=poss[j];
            }
            int tmp= 2*(type-k-1) + (total-type+1);
            ca = (p)*(tmp) + (1-p)*(tmp+total+1);
            //cout << k << ' ' << p << ' ' << ca << endl;
            if(ca<best) best=ca;
        }
        PCS;
        printf("%.6f\n",best);
    }
    return 0;
}
