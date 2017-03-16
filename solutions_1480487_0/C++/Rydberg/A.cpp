#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <math.h>
#include <set>
#include <queue>
using namespace std;
typedef long long LL;
#define INF 1000000000
#define SZ(v) ((int)(v).size())
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) FOR(i,0,n)
#define FORE(i,a,b) for(int i=(a);i<=(b);i++) 
#define FS first
#define SD second
#define MP make_pair


int main(){
	int T;scanf("%d",&T);
	FORE(test,1,T){
    printf("Case #%d: ", test);
		int n;scanf("%d",&n);
    vector<int> s;
    double sum = 0.0;
    FOR(i,0,n) {
      int a;scanf("%d",&a);
      s.push_back(a);
      sum += a;
    }
    
    FOR(i,0,n) {
      double left = 0.0, right = 1.0;
      FOR(tr,0,100) {
        double mid = (left + right) / 2.0;
        double res = s[i] + mid * sum;
        double need = 0.0;
        FOR(j,0,n) {
          double r = res - s[j];
          if (r > 0.0) {
            need += r / sum; 
          }
        }
        if (need > 1.0) {
          right = mid; 
        }
        else left = mid;
      }
      printf("%.10lf ", left * 100.0);
    }
    printf("\n");
	}
}
