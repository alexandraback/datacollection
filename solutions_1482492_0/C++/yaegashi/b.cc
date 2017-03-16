#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int
main(int argc, char **argv)
{
        int T;

        cout.precision(10);

        string lineT;
        getline(cin, lineT);
        stringstream ssT(lineT);
        ssT >> T;

        for (int i = 0; i < T; i++) {

                string lineD;
                getline(cin, lineD);
                stringstream ssD(lineD);

                double D;
                int N, A;
                ssD >> D >> N >> A;

                vector<double> ts, xs;
                for (int j = 0; j < N; j++) {
                        string line;
                        getline(cin, line);
                        stringstream ss(line);
                        double t, x;
                        ss >> t >> x;
                        ts.push_back(t);
                        xs.push_back(x);
                }

                if (xs[0] > D)
                        N = 1;

                vector<double> us, vs;
                for (int j = 0; j < N-1; j++) {
                        double u = (xs[j]-xs[j+1])/(ts[j]-ts[j+1]);
                        double v = xs[j]-u*ts[j];
                        us.push_back(u);
                        vs.push_back(v);
                }

                double t0, t1, x0, x1;
                t0 = ts[N-2];
                x0 = xs[N-2];
                t1 = ts[N-1];
                x1 = xs[N-1];
                double ul = (x1-x0)/(t1-t0);
                double vl = x0 - ul * t0;
                ts[N-1] = (D-vl)/ul;
                xs[N-1] = D;

#if 1
                cerr << "Case " << i+1 << endl;
                cerr << D << " " << N << " " << A << endl;
                for (int j = 0; j < N; j++) {
                        cerr << ts[j] << " " << xs[j] << endl;
                }
                cerr << endl;
#endif

                string lineA;
                getline(cin, lineA);
                stringstream ssA(lineA);

                cout << "Case #" << i+1 << ":" << endl;

                vector<double> as;
                for (int j = 0; j < A; j++) {
                        double ta;
                        double a;
                        ssA >> a;
                        if (N > 1) {
                                double p0 = 0, v0 = 0;
                                for (int k = 0; k < N-1; k++) {
                                        double t = ts[k+1]-ts[k];
                                        double p1 = p0 + v0*t + 0.5*a*t*t;
                                        if (p1 < xs[k+1]) {
                                                p0 = p1;
                                                v0 = v0 + a*t;
                                        }
                                        else {
                                                p0 = xs[k+1];
                                                v0 = vs[k];
                                        }
                                }
                                if (p0 < D) {
                                        cerr << "p0: " << p0 << endl;
                                        cerr << "v0: " << v0 << endl;
                                        ta = (-v0 + sqrt(v0*v0-2*a*(p0-D))) / a;
                                        ta += ts[N-1];
                                }
                                else {
                                        ta = ts[N-1];
                                }
                        }
                        else {
                                ta = sqrt(2*D/a);
                        }
                        cout << ta << endl;
                }

        }

        return 0;
}
