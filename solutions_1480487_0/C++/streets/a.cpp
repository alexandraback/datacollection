
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cmath>
#include <cassert>

using namespace std;
typedef vector<int> VI;

struct L {
    double level;
    int N;
};

bool feq(double a, double b) {
    if (fabs(a - b) < 0.00000001)
        return true;
    return false;
}

bool flt(double a, double b) {
    if (b - a > 0.00000001)
        return true;
    return false;
}

int main(int argc, char **argv)
{
    int num_tests;

    assert(feq(3.0, 3.0));
    assert(flt(2.0, 3.0));
    
    cin >> num_tests;
    for (int i = 0; i < num_tests; i++) {

        int N;
        cin >> N;

        VI points(N);
        for (int j = 0; j < N; j++) {
            cin >> points[j];
        }

        vector<double> pts(points.size());
        for (int j = 0; j < N; j++)
            pts[j] = points[j];
                                     

        double tot = std::accumulate(points.begin(), points.end(), 0);

        double t = tot;
        while (true) {
            double min = *min_element(pts.begin(), pts.end());

            int n = 0;
            for (int j = 0; j < N; j++) {
                if (feq(min, pts[j]))
                    n++;
            }

            if (n == pts.size())
                break;
            
            double min2 = numeric_limits<double>::max();
            for (int j = 0; j < N; j++) {
                if (flt(pts[j], min2) && flt(min, pts[j]))
                    min2 = pts[j];
            }

            if (t / n >= (min2 - min)) {
                for (int j = 0; j < N; j++) {
                    if (feq(pts[j], min)) {
                        pts[j] += min2 - min;
                        t -= min2 - min;
                    }
                }
            } else {
                for (int j = 0; j < N; j++) {
                    if (feq(pts[j], min)) {
                        pts[j] += t/n;
                    }
                }
                t = 0.0;
                break;
            }
        }
        
        for (int j = 0; j < N; j++) {
            pts[j] += t/N;
        }

        printf("Case #%d: ", i + 1);

        for (int j = 0; j < N; j++) {
            printf("%.6f ", 100 * ((pts[j] - points[j]) / tot));
        }


        printf("\n");
        
    }
}
