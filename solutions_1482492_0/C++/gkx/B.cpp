#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;

double yol(double a, double t) {
    return 0.5*a*t*t;
}

double time2(double d, double a) {
    return max( -1*(sqrt((2*d)/a)), sqrt((2*d)/a));
}

double time(double d, double a, double v) {
    return max( (v - sqrt((2*a*d)+(v*v))) / a, (v + sqrt((2*a*d)+(v*v))) / a);
}



double carT[2000];
double carP[2000];
double cases[250];
double D;

int main(){
	
	freopen("input.txt","rt",stdin);
	freopen("out.txt","wt",stdout); 
    
    string temp;
    int i,j,k,l,t,N,A;
    double a,b;
	int flag=0;
	cin>>t;

    for ( k=1; k<=t; k++) {
		
        cin>>D>>N>>A;
        for (int i = 0; i < N; ++i) {
            cin>>a>>b;
            carT[i] = a;
            carP[i] = b;
        }
        for (int i = 0; i < A; ++i) {
            cin>>a;
            cases[i] = a;
        }

        double v = (carP[1]-carP[0]) / (carT[1]-carT[0]);

        cout<<"Case #"<<k<<":"<<endl;
        for (int i = 0; i < A; ++i) {
            double t = time(carP[0], cases[i], v);
            if(D >  yol(cases[i], t)) {
                double rem = D - yol(cases[i], t);
                double remTime = rem / v;
                printf("%.8lf\n", t+remTime);
            }
            else {
                printf("%.8lf\n", time2(D,cases[i]));
            }
        }
    }
	
	return 0;
	
}
		
			
			
			
			
			
			

        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
