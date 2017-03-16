#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("C-small-1-attempt1.in");
ofstream fout("output.txt");
double eps = 1e-6;
class Hiker{
public:
    double d;
    double m;
};

bool cmp(Hiker h1, Hiker h2) {
    return h1.d < h2.d || (h1.d == h2.d && h1.m < h2.m);
}

int main(int argc, const char * argv[]) {
    int t;
    fin >> t;
//    cout << t << endl;
    for (int ti = 1; ti <= t; ++ ti) {
        int ans = 2e9;
        vector<Hiker> v;
        int n;
        fin >> n;
        for (int i = 0; i < n; i ++) {
            double d, m;
            int h;
            fin >> d >> h >> m;
            for (int j = 0; j < h; j ++) {
                Hiker hiker;
                hiker.d = d; hiker.m = m + j;
                v.push_back(hiker);
            }
        }
        sort(v.begin(), v.end(), cmp);
//        for (int i = 0; i < v.size(); ++ i) {
//            double m1 = v[i].m;
//            double d1 = v[i].d;
//            int tans;
//            // back
//            tans = 0;
//            for (int j = 0; j < v.size(); ++ j) {
//                double m2 = v[j].m;
//                double d2 = v[j].d;
//                double t1 = m1 * (360.0 - d1) / 360.0;
//                double t2 = m2 * (360.0 - d2) / 360.0;
//                if (d1 < d2) { // after
//                    if (t1 == t2);
//                    else if (t1 > t2) // slower
//                        tans += ((m2 - t2) / (t1 - t2) + eps);
//                    else
//                        tans +=
//                }
//            }
        //        }
        if (v.size() == 1) ans = 0;
        else {
            double m0 = v[0].m;
            double m1 = v[1].m;
            double d0 = v[0].d;
            double d1 = v[1].d;
            double t0 = v[0].m * (360.0 - v[0].d) / 360.0;
            double t1 = v[1].m * (360.0 - v[1].d) / 360.0;
            if (t0 < t1 + m1 - eps && t1 < t0 + m0 - eps)
                ans = 0;
            else ans = 1;
        }
        
        fout << "Case #" << ti << ": " << ans << endl;
    }
    return 0;
}
