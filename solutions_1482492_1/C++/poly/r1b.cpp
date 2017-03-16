#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <set>
#include <map>
#include <list>
#include <algorithm>
#include <cmath>

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define gp(ans) {cout << "Case #" << ((test)+1) << ": " << (ans) << endl;}

using namespace std;

typedef vector<int> vi;
typedef vector<double> vd;
typedef vector<string> vs;
typedef long long ll;

int main () {
  int test, T;
	
  cin >> T;
  REP (test, T) {
		double d;
		int n,A;
		cin >> d >> n >> A;
		int i,j;
		vd tv;
		vd xv;
		REP(i,n){
			double t,x;
			cin >> t >> x;
			tv.push_back(t);
			xv.push_back(x);
		}
		vd ans;
		REP(i,A){
			double res = 0;
			double a;
			cin >> a;
			// test a
			double e = 0;
			double f = 0;
			double p = a/2.0;
			REP(j,n-1){
				// j to j+1
				//printf("t=%f v=%f x=%f\n", tv[j], e, f);
				double ov = (xv[j+1]-xv[j]) / (tv[j+1]-tv[j]);
				double q = e - ov;
				double r = f - xv[j];
				double kai = (-q + pow((q*q - 4.0*p*r), 0.5)) / (2.0*p);
				double kai2 = (-q - pow((q*q - 4.0*p*r), 0.5)) / (2.0*p);
				//printf("ov=%f kai1=%f kai2=%f\n", ov, kai, kai2);
				
				// 二次曲線の進みがおわったときにどこにいるか
				double u = min(tv[j+1], kai+f) - tv[j];
				double pos = p*u*u + e*u + f;
				//printf("enf of dual time=%f x=%f\n", u, pos);
				if (pos >= d) {
					// already goal
					double tg = (-e + pow(e*e - 4.0*p*(f-d), 0.5)) / (2.0*p);
					res = tv[j]+tg;
					break;
				}
				
				if (kai+f > tv[j+1]) {
					// can't reach but other is already goal
					if (xv[j+1] >= d) {
						//printf("** %f %f %f \n", p, e, (f-d));
						double tg = (-e + pow(e*e - 4.0*p*(f-d), 0.5)) / (2.0*p);
						//printf("kenzan!! %f = %f\n", tg, tg*tg*a/2 + e*tg + f);
						
						res = tv[j]+tg;
						break;						
					}
					
					// can't reach
					double td = tv[j+1]-tv[j];
					f = p*td*td + e*td + f;
					e = a*td + e;					
				} else {
					// can reach
					if (xv[j+1] >= d){
						// already goal
						double tg = (d-xv[j]) / ov;
						res = tv[j] + tg;
						break;
					}
					//e = ov;
					// xv[j+1]にいくまでぎりぎりまでひっぱる
					double z = (-e + pow(e*e - 4.0*p*(f-xv[j+1]), 0.5)) / (2.0*p);
					e = max(z*a, ov);
					f = xv[j+1];
				}
			}
			if (res==0) {
				double tg = (-e + pow(e*e - 4.0*p*(f-d), 0.5)) / (2.0*p);
				res = tv[j] + tg;
			}
			ans.push_back(res);
		}
		
		gp("");
		REP(i,A){
			printf("%0.9f\n", ans[i]);
		}
  }
  return 0;
}

