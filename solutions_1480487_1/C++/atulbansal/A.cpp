#include "../../jam.h"


double solve(int i,  vector<int> S, int X) {
    double ret = 0;
    double filled = 0; // % of votes distributed so far

    int N = S.size();
    for(int j = 0; j < N; j++) {
       if (S[i] > S[j] && i != j) {
          filled += (double(S[i]-S[j])/X);
          //cout << filled << "\n";
          S[j] = S[i];
       }
    }
    if (filled >= 1) { return 0; }


    while (1) {
        // find the next min element and calc. min votes needed
        int next = 0;
        int next_min = S[0];
        for (int x=0; x<N; x++) {
           if (S[x] > next_min) { next_min = S[x]; next = x; }
        }
        for (int x=0; x<N; x++) {
           if (S[x] < next_min && S[x] != S[i]) { next_min = S[x]; next = x; }
        }

        if (next_min == S[i]) { ret += (1-filled)/N; return ret; }
        else {
            int count = 0;
            for (int x=0; x<N; x++) {
               if (S[x] < next_min) count++ ;
            }
            // cout << i << " " << next_min << "\n";
            // case 1 we have to use full diff. of next_min -S[i]
            if ((filled) + double(count*(next_min-S[i])/X) < 1) {
               ret += double(next_min-S[i])/X;
               filled += double(count*(next_min-S[i]))/X;
               for (int x=0;x<N;x++) {
                   if(S[x] < next_min) { S[x] = next_min; }
               }
            }

            // case 2 we are almost done
            else {
               ret += (1-filled)/count;
               return ret;
               break;
            }
        }

        if(filled >=1) break;
    }

    return ret;
}

void solve(int casenum) {
   int N;
   in >>  N;
   vector<int> S;
   int s;
   for (int i=0;i<N;i++) {
      in >> s;
      S.pb(s);
   }

   int X = 0;
   for (int i=0;i<N;i++) {
      X += S[i];
   }

   vector<double> ret(N,0);

   for (int i=0; i<N; i++) {
      ret[i] = solve(i, S, X);
   }

   out << "Case #" << casenum << ": ";
   for (int i=0; i<N ; i++) {
      out << setprecision(9) << ret[i]*100 << " ";
   }
   out << endl;
}




int main() {
	cout << "!!!Hello World!!!" << endl;

	in.open("A-large.in");
	out.open("output.txt");
	int T;
	in >> T;

	for (int i = 0; i < T; i++) {
        solve(i+1);
    }
    
    system ("pause");
	return 0;
}
