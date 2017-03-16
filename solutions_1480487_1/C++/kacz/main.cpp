#include <QtCore/QCoreApplication>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <QVector>
#include "malloc.h"

#define ABS(x) ((x<0) ? (-(x)) : (x))
using namespace std;

int main(int argc, char *argv[])
{
    int cases;
    cin >> cases;
    for(int i = 0; i<cases;++i)
    {
        int n;
        cin >> n;
        QVector<int> s;
        int si;
        int x = 0;
        for(int j =0;j<n;++j) {
            cin >> si;
            s << si;
            x += si;
        }
        cout << "Case #" << i+1 << ": ";
        int sum = 2*x;
        int lastsum = 2*x;
        int notbig = n;
        while(true) {
            double avg = (double)sum/notbig;
            sum = 2*x;
//            cout << " sum " << sum << " avg " << avg << " ";
            int bigenough = 0;
            for(int j=0;j<n;++j) {
                if(s.at(j)>=avg) {
                    sum -= s.at(j);
                    ++bigenough;
                }
            }
//            cout << " big " << bigenough << " ";
            if(sum == lastsum) break;
            lastsum = sum;
            notbig = n-bigenough;
        }
        double avg = (double)sum/notbig;
//        cout << "avg " <<setprecision(10)<< avg;

        for(int j =0;j<n;++j) {
            if(s.at(j) >= avg)
                cout << 0 << " ";
            else {
                double diff = (avg - s.at(j)) /x * 100;
//                cout << setprecision(10) << "avg" << avg << "s" << s.at(j) << "diff" << diff;
                cout << setprecision(10) << diff << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
