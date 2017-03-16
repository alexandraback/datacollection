#include "../../jam.h"



double eps = 1e-10;

void solve(int casenum) {
   double D;
   in >> D;
   int N;
   in >> N;
   int A;
   in >> A;

   double temp1;
   vector<double> t;
   vector<double> x;
   vector<double> a;
   t.pb(0.0);
   x.pb(0.0);
   for (int i=0;i<N;i++) {
      in >> temp1; t.pb(temp1);
      in >> temp1; x.pb(temp1);
   }

   for(int i=0;i<A;i++) {
       in >> temp1;
       a.pb(temp1);
   }

   vector<long double>ret(A,0.0);


   for (int i=0;i<A;i++) {
       double curr_pos = 0;
       double curr_speed = 0;
       double curr_speed1 = 0.0;
       double curr_speed2 = 0.0; 
      // solve ith case

       for(int j=1;j<=N;j++) {
          if (t[j] - t[j-1] < eps && (x[j] < D-eps)) continue;

          if(x[j] < D-eps) {
              long double maxx = curr_pos+(curr_speed)*(t[j]-t[j-1]) + (0.5) * a[i] * (t[j]-t[j-1]) * (t[j]-t[j-1]);
              if (maxx < x[j]+eps) { curr_pos = maxx; curr_speed = curr_speed + a[i]*(t[j]-t[j-1]); ret[i]+= t[j]-t[j-1]; }
              else { curr_pos = x[j]; 
                     curr_speed = pow(10.0, log10(x[j]-x[j-1]) - log10(t[j]-t[j-1]));
                     curr_speed1 = a[i]*pow(10.0, 0.5*(log10(2*(x[j]-x[j-1])) - log10(a[i])));
                     curr_speed2 = 0;
                     if (curr_speed < (x[j]-x[j-1])/(t[j]-t[j-1]))
                     curr_speed2 = curr_speed + a[i]*pow(10.0, 0.5*(log10(2*(x[j]-x[j-1]-curr_speed*(t[j]-t[j-1]))- log10(a[i]))));
 
                   curr_speed = max(curr_speed,curr_speed1);
                   curr_speed = max(curr_speed,curr_speed2);
                   ret[i]+= t[j]-t[j-1];
              }
              // if(casenum == 3) { cout << "pos and speed " << curr_pos << " " << curr_speed <<  " " << curr_speed1 << " " << maxx << " " << j << 
              // " " << (t[j]-t[j-1]) << "\n"; } 
          }
          else {
              long double num = -(curr_speed);
              num += pow(10, 0.5 * log10(curr_speed*curr_speed -2*a[i]*(curr_pos-D)));
              long double den =  a[i];
              long double reta = pow(10.0, log10(num)-log10(den));
              long double retb = pow(10.0, log10(t[j]-t[j-1]) + log10(D-x[j-1]) - log10(x[j]-x[j-1]));
              // if(casenum == 3) { cout << reta << " " << retb << "\n";  }

              ret[i] += max(reta, retb);
              break;
          }
       }
   }



   out << "Case #" << casenum << ":" << endl;
   for(int i=0;i<A;i++) {
      out << setprecision(15) << ret[i] << endl;
   }

}




int main() {
	cout << "!!!Hello World!!!" << endl;

	in.open("B-large.in");
	out.open("output2.txt");
	int T;
	in >> T;

	for (int i = 0; i < T; i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
